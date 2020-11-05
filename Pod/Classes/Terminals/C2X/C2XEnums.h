
#import <Foundation/Foundation.h>
#import "EMVCore/EMVCore.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, HpsC2xTransactionStatus) {    
       WaitingForCard,
       BadRead,
       ICCSwiped,
       FallbackInitiated,
       MultipleCardsDetected,
       CardRead,
       TechnicalFallbackInitiated,
       CardReadError,
       CardRemovedAfterTransactionComplete,
       ContactlessCardStillInField,
       ContactlessInterfaceFailedTryContact,
       DoNotRemoveCard,
       DeviceBusy,
       EnterPin,
       LastPinAttempt,
       PinAccepted,
       RetryPin,
       RemoveCard,
       Configuring,
       SeePhone,
       None
    
};
@interface C2XEnums : NSObject

+(HpsC2xTransactionStatus)transactionStatusFromVitalSDK:(TransactionStatus)transactionStatus;
+ (NSString*)transactionTypeToString:(TransactionType)transacationType;
+ (NSString*)cardDataSourceTypeToString:(CardDataSourceType)cardDataSourceType;
+ (NSString*)transactionResultTypeToString:(TransactionResultType)transactionResultType;
@end

NS_ASSUME_NONNULL_END
