#import <Foundation/Foundation.h>
#import "HpsC2xDevice.h"
#import "EMVCore/EMVCore.h"
#import "HpsC2xBaseBuilder.h"
#import "HpsCreditCard.h"


NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xCreditReturnBuilder : HpsC2xBaseBuilder
{
    HpsC2xDevice *device;
}
@property (nonatomic, strong) NSDecimalNumber *amount;
@property (nonatomic, strong) NSString *referenceNumber;
@property (nonatomic, strong) NSString *transactionId;
@property (nonatomic, strong) HpsCreditCard *creditCard;
- (id)initWithDevice: (HpsC2xDevice*)c2xdevice;
@end

NS_ASSUME_NONNULL_END
