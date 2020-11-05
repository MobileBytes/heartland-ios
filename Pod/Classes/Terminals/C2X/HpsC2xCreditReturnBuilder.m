#import "HpsC2xCreditReturnBuilder.h"

@implementation HpsC2xCreditReturnBuilder

- (id)initWithDevice: (HpsC2xDevice*)c2xdevice{
    self = [super initWithDevice:c2xdevice];
    self = [super init];
    if (self != nil)
    {
        device = c2xdevice;
    }
    return self;
}

-(TransactionRequest*)buildRequest
{
    TransactionRequest *request = [TransactionRequest new];
    request.tenderType = TenderTypeCredit;
    request.transactionType = TransactionTypeRefundWithCard;
    request.gatewayTransactionId = self.transactionId;
    
    if (self.amount!= nil) {
        request.total = self.amount;
    }
    request.posReferenceNumber = self.referenceNumber;
    return request;
           
}
@end
