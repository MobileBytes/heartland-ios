#import "HpsC2xBatchCloseBuilder.h"

@implementation HpsC2xBatchCloseBuilder
- (id)initWithDevice: (HpsC2xDevice*)c2xdevice{
    //self = [super initWithDevice:c2xdevice];
    self = [super init];
    if (self != nil)
    {
        device = c2xdevice;
        //[self buildRequest];
    }
    return self;
}

-(void)execute
{
    if (device != nil) {
        [device processTransactionWithRequest:[self buildRequest]];
    }
}

-(TransactionRequest*)buildRequest
{
    TransactionRequest *request = [TransactionRequest new];
    
    request.transactionType = TransactionTypeBatchClose;
    
    return request;
        
           
}
@end
