#import "HpsC2xCreditCaptureBuilder.h"

@implementation HpsC2xCreditCaptureBuilder

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
    request.transactionType = TransactionTypeCapture;
    request.gatewayTransactionId = self.transactionId;
    
    if (self.amount!= nil) {
        request.total = self.amount;
    }
    if (self.gratuity != nil) {
        request.tip = self.gratuity;
    }
    request.posReferenceNumber = self.referenceNumber;
    return request;
           
}
@end
