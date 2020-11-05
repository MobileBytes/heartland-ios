
#import "HpsC2xCreditAuthBuilder.h"
#import "EMVCore/EMVCore.h"

@implementation HpsC2xCreditAuthBuilder

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
    request.transactionType = TransactionTypeSale;
    if (self.amount!= nil) {
        request.total = self.amount;
    }
    if (self.gratuity != nil) {
        request.tip = self.gratuity;
    }
    request.posReferenceNumber = self.referenceNumber;
    
    if (_details != nil) {
        request.invoiceNumber = self.details.invoiceNumber;
    }
    
    if (self.creditCard != nil) {
        
        CardData *card = [[CardData alloc]init];
        card.pan = self.creditCard.cardNumber;
        card.expirationDate = [NSString stringWithFormat:@"%d%d", self.creditCard.expMonth, self.creditCard.expYear];
        card.cvv2 = self.creditCard.cvv;
        card.cardDataSourceType = CardDataSourceTypeKeyed;
        
        if (self.address != nil) {
            AvsType avsType = AvsTypeNone;
            
            if(self.address.zip != nil && self.address.address != nil)
            {
                avsType = AvsTypeZipAddress;
            }
            else if (self.address.zip != nil)
            {
                avsType = AvsTypeZip;
            }
            
            Address *add = [[Address alloc]init];
            add.addressLine1 = self.address.address;
            add.city = self.address.city;
            add.state = self.address.state;
            add.postalCode = self.address.zip;
            card.postalCode = self.address.zip;
            card.avsType = avsType;
            card.cardholderAddress = add;
            card.cardholderName = self.cardHolderName;
            
        }
        
        request.cardData = card;
    }
    
    return request;
        
           
}
@end
