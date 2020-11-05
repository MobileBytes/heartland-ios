#import <XCTest/XCTest.h>
#import "HpsC2xDevice.h"
#import "HpsC2xCreditSaleBuilder.h"
#import "HpsC2xCreditReturnBuilder.h"
#import "HpsC2xCreditAuthBuilder.h"
#import "HpsCreditCard.h"
#import "HpsAddress.h"
#import "HpsC2xBatchCloseBuilder.h"
#import "HpsTerminalResponse.h"
#import "HpsC2xCreditAdjustBuilder.h"

@interface Hps_C2x_Credit_Test : XCTestCase<HpsC2xDeviceDelegate,HpsC2xTransactionDelegate>
{
    XCTestExpectation *deviceConnectionExpectation;
    XCTestExpectation *transactionExpectation;
}
@property HpsC2xDevice *device;
@property HpsTerminalResponse *response;
@end

@implementation Hps_C2x_Credit_Test

-(void)deviceSetUp
{
     HpsConnectionConfig *config = [[HpsConnectionConfig alloc] init];
     config.VersionNumber = @"3409";
     config.DeveloperID = @"002914";
     config.Username = @"701389328";
     config.Password = @"$Test1234";
     config.SiteID = @"142914";
     config.DeviceID = @"6399854";
     config.LicenseID = @"142827";
     self.device = [[HpsC2xDevice alloc]initWithConfig:config];
}
- (HpsCreditCard*) getCC
{
    HpsCreditCard *card = [[HpsCreditCard alloc] init];
//    card.cardNumber = @"4242424242424242";
//    card.expMonth = 12;
//    card.expYear = 2025;
//    card.cvv = @"123";
    //Master Card
//    card.cardNumber = @"5410330089604111";
//    card.expMonth = 12;
//    card.expYear = 2022;
//    card.cvv = @"4315";
    //Discover
//    card.cardNumber = @"6510000000000133";
//    card.expMonth = 12;
//    card.expYear = 2019;
//    card.cvv = @"1234";
    
    //visa
    card.cardNumber = @"4716739001010119";
    card.expMonth = 12;
    card.expYear = 2022;
    card.cvv = @"1234";
    return card;
}


- (HpsAddress*) getAddress
{
    HpsAddress *address = [[HpsAddress alloc] init];
    address.address = @"1 Heartland Way";
    address.zip = @"95124";
    return address;
}


-(void)test_initialize
{
     deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_Initialize"];
     [self deviceSetUp];
     [self.device initialize];
     self.device.deviceDelegate = self;
     [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
                  }];
    XCTAssert(YES, @"Device Connected");
}

-(void)test_Credit_Sale_Manual
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Credit_Sale_Manual"];
        HpsC2xCreditSaleBuilder *builder = [[HpsC2xCreditSaleBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:11.00];
        builder.gratuity = [[NSDecimalNumber alloc]initWithDouble:0.0];
        builder.creditCard = [self getCC];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");            
            XCTAssertNotNil(self.response);
            XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
            }];
    
    }];
    XCTAssert(YES, @"Device Connected");
}
 
-(void)test_Credit_Sale
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Credit_Sale"];
        HpsC2xCreditSaleBuilder *builder = [[HpsC2xCreditSaleBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:12.00];
        builder.gratuity = [[NSDecimalNumber alloc]initWithDouble:0.0];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");
            XCTAssertNotNil(self.response);
            XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
            }];
    
    }];
    XCTAssert(YES, @"Device Connected");
}

-(void)test_Credit_Auth
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_CreditSale"];
        HpsC2xCreditAuthBuilder *builder = [[HpsC2xCreditAuthBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:11.00];
        builder.gratuity = [[NSDecimalNumber alloc]initWithDouble:0.0];
        builder.creditCard = [self getCC];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");
            XCTAssertNotNil(self.response);
            XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
            }];
    
    }];
    XCTAssert(YES, @"Device Connected");
}
-(void)test_Credit_Refund
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Credit_Refund"];
        HpsC2xCreditReturnBuilder *builder = [[HpsC2xCreditReturnBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:11.00];
        builder.referenceNumber = [NSString stringWithFormat:@"%d", 6];
        builder.creditCard = [self getCC];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");
                        XCTAssertNotNil(self.response);
                       XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
            }];
    
    }];
    XCTAssert(YES, @"Device Connected");
}

-(void)test_Credit_Refund_By_TransactionId
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Credit_Refund"];
        HpsC2xCreditReturnBuilder *builder = [[HpsC2xCreditReturnBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:1.00];
        builder.transactionId = [NSString stringWithFormat:@"%d", 1338838546];
        builder.referenceNumber = [NSString stringWithFormat:@"%d", 6];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");
                        XCTAssertNotNil(self.response);
                       XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
            }];
    
    }];
    XCTAssert(YES, @"Device Connected");
}

-(void)test_Credit_Tip_Adjust
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Credit_Tip_Adjust"];
        HpsC2xCreditAdjustBuilder *builder = [[HpsC2xCreditAdjustBuilder alloc]initWithDevice:self.device];
        builder.amount = [[NSDecimalNumber alloc]initWithDouble:11.00];
        builder.gratuity = [[NSDecimalNumber alloc]initWithDouble:1.00];
        builder.transactionId = [NSString stringWithFormat:@"%d", 1338847091];
        builder.referenceNumber = [NSString stringWithFormat:@"%d", 6];
        //builder.creditCard = [self getCC];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
            if(error) XCTFail(@"Request Timed out");
            XCTAssertNotNil(self.response);
            XCTAssertEqualObjects(@"Approved", self.response.deviceResponseCode);
        }];
        
    }];
    XCTAssert(YES, @"Device Connected");
}


-(void)test_Batch_close
{
    deviceConnectionExpectation = [self expectationWithDescription:@"test_C2X_DeviceConnected"];
    [self deviceSetUp];
    [self.device initialize];
    self.device.deviceDelegate = self;
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
               if(error) XCTFail(@"Request Timed out");
        transactionExpectation = [self expectationWithDescription:@"test_C2X_Batch_Close"];
        HpsC2xBatchCloseBuilder *builder = [[HpsC2xBatchCloseBuilder alloc]initWithDevice:self.device];
        self.device.transactionDelegate = self;
        [builder execute];
        [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
                      if(error) XCTFail(@"Request Timed out");
            
            
            }];
                  }];
    XCTAssert(YES, @"Device Connected");
    
}


#pragma mark - Device Delegate methods
- (void)onConnected:(HpsTerminalInfo *)terminalInfo
{
    NSLog(@"Device Connected");
    [deviceConnectionExpectation fulfill];
    
}
- (void)onDisconnected
{
    NSLog(@"Device Disconnected");
}
//- (void)onError:(NSString*)deviceError
//{
//    NSLog(@"%@",deviceError);
//}
- (void)onTerminalInfoReceived:(HpsTerminalInfo *)terminalInfo
{
    
}
- (void)onBluetoothDeviceList:(NSMutableArray *)peripherals
{
    for (int i =0; i<self.device.peripherals.count; i++) {
        CBPeripheral *peripheral = [self.device.peripherals objectAtIndex:i];
        if ([peripheral.name hasPrefix:@"CHB"]) {
            [self.device stopScan];
            [self.device connectDevice:peripheral];
        }
    }
}


#pragma mark - Transaction Delegate methods
- (void)onStatusUpdate:(HpsC2xTransactionStatus)transactionStatus
{
    NSLog(@"Status: %lu", (unsigned long)transactionStatus);
    
    switch (transactionStatus)
       {
           case WaitingForCard:
               NSLog(@"Waiting for card");
           case BadRead:
               NSLog(@"BadRead");
               break;
           case ICCSwiped:
               NSLog(@"ICCSwiped");
               break;
           case FallbackInitiated:
               NSLog(@"FallbackInitiated");
               break;
           case MultipleCardsDetected:
               NSLog(@"MultipleCardsDetected");
               break;
           case CardRead:
               NSLog(@"CardRead");
               break;
           case TechnicalFallbackInitiated:
               NSLog(@"TechnicalFallbackInitiated");
               break;
           case CardReadError:
               NSLog(@"CardReadError");
               break;
           case CardRemovedAfterTransactionComplete:
               NSLog(@"CardRemovedAfterTransactionComplete");
               break;
           case ContactlessCardStillInField:
               NSLog(@"ContactlessCardStillInField");
               break;
           case ContactlessInterfaceFailedTryContact:
               NSLog(@"ContactlessInterfaceFailedTryContact");
               break;
           case DoNotRemoveCard:
               NSLog(@"DoNotRemoveCard");
               break;
           case DeviceBusy:
               NSLog(@"DeviceBusy");
               break;
           case EnterPin:
               NSLog(@"EnterPin");
               break;
           case LastPinAttempt:
               NSLog(@"LastPinAttempt");
               break;
           case PinAccepted:
               NSLog(@"PinAccepted");
               break;
           case RetryPin:
               NSLog(@"RetryPin");
               break;
           case RemoveCard:
               NSLog(@"RemoveCard");
               break;
           case Configuring:
               NSLog(@"Configuring");
               break;
           case SeePhone:
               NSLog(@"SeePhone");
               break;
           case None:
               NSLog(@"None");
               break;
       }
}
- (void)onCardholderInteractionRequested:(HpsCardholderInteractionRequest *)request
{
     if (request.cardholderInteractionType == CardholderInteractionTypeFinalAmountConfirmation)
     {
         self.device.interactionResult.finalAmountConfirmed = YES;
         self.device.interactionResult.cardholderInteractionType = CardholderInteractionTypeFinalAmountConfirmation;
     }
    else if (request.cardholderInteractionType == CardholderInteractionTypeEMVApplicationSelection)
    {
       self.device.interactionResult.cardholderInteractionType = CardholderInteractionTypeEMVApplicationSelection;
        //have to provide selected Aid index
    }
    else if (request.cardholderInteractionType == CardholderInteractionTypeCommericalCardDataEntry)
       {
           self.device.interactionResult.cardholderInteractionType = CardholderInteractionTypeCommericalCardDataEntry;
           
       }
}
- (void)onTransactionComplete:(HpsTerminalResponse *)response
{
    NSLog(@"Transaction completed");
    NSLog(@"TransactionId %d", response.transactionId);
    self.response = response;
    [transactionExpectation fulfill];
    transactionExpectation = nil;
}
- (void)onError:(NSError *)emvError
{
    NSLog(@"%@",emvError);
    [transactionExpectation fulfill];
    transactionExpectation = nil;
}


@end
