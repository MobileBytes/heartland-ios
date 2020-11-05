#import "HpsC2xBaseBuilder.h"

@implementation HpsC2xBaseBuilder

- (id)initWithDevice: (id<IC2xDeviceInterface>)c2xdevice{
    self = [super init];
    if (self != nil)
    {
        self.device = c2xdevice;
    }
    return self;
}

-(void)execute
{
    if (self.device != nil) {
        [self.device processTransactionWithRequest:[self buildRequest]];
    }
}

-(TransactionRequest*)buildRequest
{
    TransactionRequest *request = [TransactionRequest new];
    request.tip = 0;
    request.total = 0;
    request.tax = 0;
    return request;
}

@end
