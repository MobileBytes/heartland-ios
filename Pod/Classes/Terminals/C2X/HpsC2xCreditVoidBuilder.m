#import "HpsC2xCreditVoidBuilder.h"

@implementation HpsC2xCreditVoidBuilder

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
    request.tenderType = TenderTypeCredit;
    request.transactionType = TransactionTypeVoid;
    request.gatewayTransactionId = self.transactionId;
    request.posReferenceNumber = self.referenceNumber;
    return request;
           
}
@end
