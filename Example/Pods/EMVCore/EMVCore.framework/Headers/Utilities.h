//
//  Utilities.h
//  BBPOS
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"
#import "EMVTagDescriptor.h"
#import "TerminalEnums.h"

@interface Utilities : NSObject

// Currency Code Enum String Value
+ (nonnull NSString *)stringCurrencyCode:(CurrencyCode)code;

// Get hex String From Enum
+ (nonnull NSString *)hexStringFromEMVTagEnum:(EMVTagDescriptor)hexNumber;

// Get Terminal Status String from Enum
+ (nonnull NSString *)stringTerminalStatus:(TerminalStatus)terminalStatus;

@end
