#import "C2XEnums.h"
#import <EMVCore/EMVCore.h>

@implementation C2XEnums

+(HpsC2xTransactionStatus)transactionStatusFromVitalSDK:(TransactionStatus)transactionStatus
{
    switch (transactionStatus)
       {
           case TransactionStatusWaitingForCard:
               return WaitingForCard;
           case TransactionStatusBadRead:
               return BadRead;
           case TransactionStatusICCSwiped:
               return ICCSwiped;
           case TransactionStatusFallbackInitiated:
               return FallbackInitiated;
           case TransactionStatusMultipleCardsDetected:
               return MultipleCardsDetected;
           case TransactionStatusCardRead:
               return CardRead;
           case TransactionStatusTechnicalFallbackInitiated:
               return TechnicalFallbackInitiated;
           case TransactionStatusCardReadError:
               return CardReadError;
           case TransactionStatusCardRemovedAfterTransactionComplete:
               return CardRemovedAfterTransactionComplete;
           case TransactionStatusContactlessCardStillInField:
               return ContactlessCardStillInField;
           case TransactionStatusContactlessInterfaceFailedTryContact:
               return ContactlessInterfaceFailedTryContact;
           case TransactionStatusDoNotRemoveCard:
               return DoNotRemoveCard;
           case TransactionStatusDeviceBusy:
               return DeviceBusy;
           case TransactionStatusEnterPin:
               return EnterPin;
           case TransactionStatusLastPinAttempt:
               return LastPinAttempt;
           case TransactionStatusPinAccepted:
               return PinAccepted;
           case TransactionStatusRetryPin:
               return RetryPin;
           case TransactionStatusRemoveCard:
               return RemoveCard;
           case TransactionStatusConfiguring:
                   return Configuring;
           case TransactionStatusSeePhone:
                   return SeePhone;
           case TransactionStatusNone:
               return None;
       }
}

+ (NSString*)transactionTypeToString:(TransactionType)transacationType
{
    switch(transacationType) {
           case TransactionTypeSale:
              return @"Sale";
           case TransactionTypeAuth:
               return @"Auth";
           case TransactionTypeCapture:
               return @"Capture";
           case TransactionTypeForcedAuth:
               return @"ForcedAuth";
           case TransactionTypeVoid:
               return @"Void";
           case TransactionTypeRefundWithCard:
               return @"RefundWithCard";
           case TransactionTypeRefundWithReference:
               return @"RefundWithReference";
           case TransactionTypeTipAdjust:
               return @"TipAdjust";
           case TransactionTypeBatchClose:
               return @"BatchClose";
           case TransactionTypeNone:
               return @"None";

           default:
               return @"unknown";
       }
}

+ (NSString*)cardDataSourceTypeToString:(CardDataSourceType)cardDataSourceType
{
    switch(cardDataSourceType) {
           case CardDataSourceTypeMSR:
              return @"MSR";
           case CardDataSourceTypeEMV:
               return @"SCR";
           case CardDataSourceTypeContactlessMSR:
               return @"CONTACTLESS_MSR";
           case CardDataSourceTypeContactlessEMV:
               return @"CONTACTLESS_EMV";
           case CardDataSourceTypeKeyed:
               return @"KEYED";
           case CardDataSourceTypePhone:
               return @"PHONE";
           case CardDataSourceTypeMail:
               return @"MAIL";
           case CardDataSourceTypeInternet:
               return @"INTERNET";
           case CardDataSourceTypeFallback:
               return @"FALLBACK";
           case CardDataSourceTypeNone:
               return @"None";

           default:
               return @"unknown";
       }
}

+ (NSString*)transactionResultTypeToString:(TransactionResultType)transactionResultType
{
    switch(transactionResultType) {
        case TransactionResultTypeApproved:
           return @"Approved";
        case TransactionResultTypeDeclinedOffline:
            return @"Declined Offline";
        case TransactionResultTypeDeclinedOnline:
            return @"Declined Online";
        case TransactionResultTypePartiallyApproved:
            return @"Partially Approved";
        case TransactionResultTypePostAuthReversal:
            return @"Post Auth Reversal";
        case TransactionResultTypeCallIssuer:
            return @"Call Issuer";
        case TransactionResultTypeCancelled:
            return @"Cancelled";
        default:
            return @"unknown";
    }
    
}
@end
