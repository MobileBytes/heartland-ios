
#import <Foundation/Foundation.h>
#import "HpsC2xDevice.h"
#import "EMVCore/EMVCore.h"
#import "HpsC2xBaseBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xBatchCloseBuilder : HpsC2xBaseBuilder
{
    HpsC2xDevice *device;
}
- (id)initWithDevice: (HpsC2xDevice*)c2xdevice;

@end

NS_ASSUME_NONNULL_END
