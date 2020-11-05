#import <Foundation/Foundation.h>
#import "HpsC2xDevice.h"
#import "HpsCreditCard.h"
#import "HpsAddress.h"
#import "HpsTransactionDetails.h"
#import "EMVCore/EMVCore.h"
#import "HpsC2xBaseBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xCreditAuthBuilder : HpsC2xBaseBuilder
{
    HpsC2xDevice *device;
}
@property (nonatomic, strong) NSDecimalNumber *amount;
@property (nonatomic, strong) NSString *referenceNumber;
@property (nonatomic, strong) HpsCreditCard *creditCard;
@property (nonatomic, strong) HpsAddress *address;
@property (nonatomic, strong) HpsTransactionDetails *details;
@property (nonatomic, strong) NSDecimalNumber *gratuity;
@property (nonatomic, strong) NSString *cardHolderName;
- (id)initWithDevice: (HpsC2xDevice*)c2xdevice;
@end

NS_ASSUME_NONNULL_END
