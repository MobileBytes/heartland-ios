
#import "HpsC2xDevice.h"
#import "C2XEnums.h"
#import "HpsTerminalResponse.h"
#import <CoreBluetooth/CoreBluetooth.h>

@implementation HpsC2xDevice

- (instancetype)initWithConfig:(HpsConnectionConfig*)config {
    if (self = [super init]) {
        self.config = config;
        self.peripherals = [NSMutableArray new];
    }
    return self;
}

-(void)initialize
{
    if (_centralManager == nil) {
               _centralManager = [[CBCentralManager alloc] initWithDelegate:self queue:nil];
           }

}

- (void)centralManagerDidUpdateState:(CBCentralManager *)central
{
    NSString *currentState = @"";
    switch (central.state)
    {
        case CBManagerStateUnknown:
            currentState = @"CBManagerStateUnknown";
            break;

        case CBManagerStateResetting:
            currentState = @"CBManagerStateResetting";
            break;

        case CBManagerStateUnsupported:
            currentState = @"CBManagerStateUnsupported";
            break;

        case CBManagerStateUnauthorized:
            currentState = @"CBManagerStateUnauthorized";
            break;

        case CBManagerStatePoweredOff:
        {
            currentState = @"CBManagerStatePoweredOff";
            break;
        }

        case CBManagerStatePoweredOn:
            currentState = @"CBManagerStatePoweredOn";            
            [self scan];
            break;
    }

    NSLog(@"State - %@", currentState);
}
- (void)scan
{
    NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:NO], CBCentralManagerScanOptionAllowDuplicatesKey, nil];
    [self.centralManager scanForPeripheralsWithServices:nil options:options];

    NSLog(@"Scanning started");
}
- (void)centralManager:(CBCentralManager *)central
 didDiscoverPeripheral:(CBPeripheral *)peripheral
     advertisementData:(NSDictionary<NSString *,id> *)advertisementData
                  RSSI:(NSNumber *)RSSI
{
     NSLog(@"%@",peripheral.name);

    if (peripheral.name != nil && ![self.peripherals containsObject:peripheral]) {
        [self.peripherals addObject:peripheral];
    }
    if (self.deviceDelegate!= nil && [self.deviceDelegate respondsToSelector:@selector(onBluetoothDeviceList:)])
    {
        [self.deviceDelegate onBluetoothDeviceList:self.peripherals];
    }
}
- (void)connectDevice:(CBPeripheral *)device
{
    [self.terminalConifguration setHost:device.name];
    
    if ([self isTransactionManagerConnected]) {
        return;
    }
      
    if (self.transactionManager == nil)
    {
        self.transactionManager = [TransactionManager sharedInstance];
    }
    [self.terminalConifguration setConnectionType:BLUETOOTH];
    
    [self initializeTransactionManagerwithSelectedDevice:device];
    
    NSLog(@"%d",self.transactionManager.isInitialized);
    
    if ([self.transactionManager isInitialized]) {
        [self.transactionManager connect:self];
    }
}
 -(void)stopScan
{
    [self.centralManager stopScan];
}
-(BOOL)isTransactionManagerConnected
{
    return (self.transactionManager != nil && [self.transactionManager isConnected]);
}

-(void)disConnect
{
    if ([self isTransactionManagerConnected]) {
        [self.transactionManager disconnect];
    }
}

-(void)getDeviceInfo
{
    if ([self isTransactionManagerConnected]) {
        [self.transactionManager deviceInfo:self];
    }
}
        
-(void)initializeTransactionManagerwithSelectedDevice:(CBPeripheral *)device
{
    self.transactionConfiguration = [self.config transactionConfiguration];
    self.gatewayCofiguration = [self.config gatewayConfig:GatewayTypePortico];
    self.terminalConifguration = [self.config terminalConfig:BBPOS_CHIPPER_2X
                                                                 withTerminalName:device.name];
    [self.transactionManager initializeWithTerminalConfiguration:self.terminalConifguration
                                               transactionConfiguration:self.transactionConfiguration
                                                   gatewayConfiguration:self.gatewayCofiguration];
    
   
}

-(void)processTransactionWithRequest:(TransactionRequest*)transactionRequest
{
    if (self.transactionManager == nil) {
         self.transactionManager = [TransactionManager sharedInstance];
    }
    
    if (![self.transactionManager isInitialized]) {
        //[self initializeTransactionManager];
    }
    
    if ([self.transactionManager isInitialized]) {
          [self.transactionManager startTransaction:transactionRequest withTransactionDelegate:self];
       }
    
}

#pragma mark - Transaction Delegates

- (void)onStatusUpdate:(TransactionStatus)transactionStatus
{
    if (self.transactionDelegate!= nil && [self.transactionDelegate respondsToSelector:@selector(onStatusUpdate:)])
               {
                   [self.transactionDelegate onStatusUpdate:[C2XEnums transactionStatusFromVitalSDK:transactionStatus]];
               }
    
}
- (void)onCardholderInteractionRequested:(CardholderInteractionRequest *)request
{
    if (self.transactionDelegate!= nil && [self.transactionDelegate respondsToSelector:@selector(onCardholderInteractionRequested:)])
    {
        self.interactionResult = [CardholderInteractionResult new];        
        [self.transactionDelegate onCardholderInteractionRequested:(HpsCardholderInteractionRequest *) request];
    }
    
    [self.transactionManager sendCardholderInteractionResult:self.interactionResult];
    
}
- (void)onTransactionComplete:(TransactionResponse *)response
{
    if (self.transactionDelegate!= nil && [self.transactionDelegate respondsToSelector:@selector(onTransactionComplete:)])
    {
        [self.transactionDelegate onTransactionComplete:[HpsTerminalResponse terminalResponseFromVitalSDK:response]];
    }
}

- (void)onError:(NSError *)emvError
{
    if (self.transactionDelegate!= nil && [self.transactionDelegate respondsToSelector:@selector(onError:)])
       {
           [self.transactionDelegate onError:emvError];
       }
    
}

#pragma mark - TerminalConnectionDelegate & TerminalInfo Delegates

- (void)onConnected:(TerminalInfo *)terminalInfo
{
    if (self.deviceDelegate!= nil && [self.deviceDelegate respondsToSelector:@selector(onConnected:)])
                  {
                      [self.deviceDelegate onConnected:(HpsTerminalInfo *)terminalInfo];
                  }
}
- (void)onDisconnected
{
    
}
- (void)onTerminalInfoReceived:(nullable TerminalInfo *)terminalInfo
{
    if (self.deviceDelegate!= nil && [self.deviceDelegate respondsToSelector:@selector(onTerminalInfoReceived:)])
                     {
                         [self.deviceDelegate onTerminalInfoReceived:(HpsTerminalInfo *)terminalInfo];
                     }
}

- (void)onError
{
    if (self.deviceDelegate!= nil && [self.deviceDelegate respondsToSelector:@selector(onError:)])
    {
        [self.deviceDelegate onError:@"Device not connected"];
      
    }
}
@end
