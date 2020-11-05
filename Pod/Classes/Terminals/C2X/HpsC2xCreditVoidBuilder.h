#import <Foundation/Foundation.h>
#import "HpsC2xDevice.h"
#import "EMVCore/EMVCore.h"
#import "HpsC2xBaseBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xCreditVoidBuilder : HpsC2xBaseBuilder
{
    HpsC2xDevice *device;
}
@property (nonatomic, strong) NSString *referenceNumber;
@property (nonatomic, strong) NSString *transactionId;
- (id)initWithDevice: (HpsC2xDevice*)c2xdevice;

@end

NS_ASSUME_NONNULL_END
