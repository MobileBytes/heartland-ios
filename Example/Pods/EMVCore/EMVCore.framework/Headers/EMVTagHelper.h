//
//  EMVTagHelper.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardholderEnums.h"

@class Tag;

@interface EMVTagHelper : NSObject

+ (nonnull Tag *)applicationIdentifier;
+ (nonnull Tag *)applicationLabel;
+ (nonnull Tag *)applicationPrefName;
+ (nonnull Tag *)bankIdentifier;
+ (nonnull Tag *)cryptogram;
+ (nonnull Tag *)emvChipIndicator;
+ (nonnull Tag *)merchantIdentifier;
+ (nonnull Tag *)cardholderVerificationMethod;
+ (nonnull Tag *)terminalIdentifier;
+ (nonnull Tag *)terminalVerificationResults;
+ (nonnull Tag *)transactionStatusInformation;
+ (CardholderAuthenticationMethod)cardholderAuthenticationMethodfromTlv:(nullable NSString *)tlv;

@end
