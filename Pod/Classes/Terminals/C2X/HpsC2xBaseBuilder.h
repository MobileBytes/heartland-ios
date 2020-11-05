#import <Foundation/Foundation.h>
#import "HpsDeviceProtocols.h"
#import "HpsC2xDevice.h"
#import "EMVCore/EMVCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface HpsC2xBaseBuilder : NSObject


@property (nonatomic, strong) id<IC2xDeviceInterface> device;
- (id)initWithDevice: (id<IC2xDeviceInterface>)c2xdevice;
-(TransactionRequest*)buildRequest;
-(void)execute;
@end

NS_ASSUME_NONNULL_END
