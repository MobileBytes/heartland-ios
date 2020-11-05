#import <Foundation/Foundation.h>
#import <HeartlandSDK/HeartlandSDK.h>
#import "HpsC2xDeviceDelegate.h"
#import "HpsC2xTransactionDelegate.h"
#import "HpsConnectionConfig.h"


NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xDevice : NSObject<CBCentralManagerDelegate,TransactionDelegate,TerminalInfoDelegate,TerminalConnectionDelegate,IC2xDeviceInterface>


@property (nonatomic, strong) HpsConnectionConfig *config;
@property (nonatomic, strong, nullable) CBCentralManager *centralManager;
@property (nonatomic, strong) TransactionManager *transactionManager;
@property (nonatomic, strong) CardholderInteractionResult *interactionResult;

@property (nonatomic, strong) id<HpsC2xTransactionDelegate> transactionDelegate;
@property (nonatomic, strong) id<HpsC2xDeviceDelegate> deviceDelegate;

@property (nonatomic, strong) NSMutableArray *peripherals;
// Configurations
@property (nonatomic, strong, nullable) TransactionConfiguration *transactionConfiguration;
@property (nonatomic, strong, nullable) TerminalConfiguration *terminalConifguration;
@property (nonatomic, strong, nullable) GatewayConfiguration *gatewayCofiguration;

- (instancetype)initWithConfig:(HpsConnectionConfig*)config;
-(void)initialize;
-(void)stopScan;
-(void)getDeviceInfo;
- (void)connectDevice:(CBPeripheral *)device;

-(void)processTransactionWithRequest:(TransactionRequest*)transactionRequest;
@end

NS_ASSUME_NONNULL_END
