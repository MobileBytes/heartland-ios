#import "HpsTerminalResponse.h"
#import "HpsHpaSharedParams.h"
#import "C2XEnums.h"

@implementation HpsTerminalResponse

- (void) mapResponse:(id <HpaResposeInterface>) response
{
	self.version = response.Version;
	self.status = response.MultipleMessage;
	self.responseText = response.Response;
	NSMutableDictionary *paramDictionary = [HpsHpaSharedParams getInstance].params;
	self.terminalSerialNumber = paramDictionary[@"TERMINAL INFORMATION"][@"SERIAL NUMBER"];
	if (response.ResponseId) {
		self.transactionId =  response.ResponseId.intValue;
	}
	else{
		self.transactionId =  response.TransactionId.intValue;

	}
    self.lastResponseTransactionId = [HpsHpaSharedParams getInstance].lastResponse.ResponseId.intValue;
    
}

+(HpsTerminalResponse*)terminalResponseFromVitalSDK:(TransactionResponse*)transactionResponse
{
    HpsTerminalResponse *terminalResponse = [[HpsTerminalResponse alloc]init];
    if (terminalResponse != nil) {
        terminalResponse.approvedAmount = transactionResponse.approvedAmount;
        terminalResponse.entryMethod = [C2XEnums cardDataSourceTypeToString:transactionResponse.cardDataSourceType];
        terminalResponse.approvalCode = transactionResponse.gatewayAuthCode;
        terminalResponse.transactionId = [transactionResponse.gatewayTransactionId intValue];
        terminalResponse.maskedCardNumber = transactionResponse.maskedPan;
        terminalResponse.responseText = [NSDictionary valueForAnEnumType:TransactionResultTypeEnum forEnumValue:transactionResponse.transactionResultType];
        terminalResponse.deviceResponseCode = [C2XEnums transactionResultTypeToString:transactionResponse.transactionResultType];
        terminalResponse.tipAmount = transactionResponse.tipAmount;
        terminalResponse.terminalRefNumber = transactionResponse.posReferenceNumber;
        terminalResponse.transactionType =[C2XEnums transactionTypeToString:transactionResponse.transactionType];
        if (transactionResponse.receipt != nil) {
            terminalResponse.applicationId = transactionResponse.receipt.aid;
            terminalResponse.applicationName = transactionResponse.receipt.applicationLabel;
            terminalResponse.approvalCode = transactionResponse.receipt.authorizationCode;
            terminalResponse.cardholderName = transactionResponse.receipt.cardholderName;
            terminalResponse.cashBackAmount = [NSNumber numberWithInteger:[transactionResponse.receipt.cashBackAmount integerValue]];//transactionResponse.receipt.cashBackAmount;
            terminalResponse.applicationCrytptogram = transactionResponse.receipt.cryptogram;
            terminalResponse.maskedCardNumber = transactionResponse.receipt.maskedPan;
            terminalResponse.entryMethod = [C2XEnums cardDataSourceTypeToString:transactionResponse.receipt.posEntryMode];
            terminalResponse.terminalVerficationResult = transactionResponse.receipt.terminalVerificationResult;
            terminalResponse.transactionAmount = [NSNumber numberWithInteger:[transactionResponse.receipt.transactionAmount integerValue]];//transactionResponse.receipt.transactionAmount;
            terminalResponse.transactionId = [transactionResponse.receipt.transactionId intValue];
            terminalResponse.transactionType = [C2XEnums transactionTypeToString:transactionResponse.receipt.transactionType];
        }
        
    }
    
    return terminalResponse;
}



@end
