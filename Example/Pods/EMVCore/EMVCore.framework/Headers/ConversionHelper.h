//
//  ConversionHelper.h
//  EMVCore
//

#import <Foundation/Foundation.h>

#import "CommonEnums.h"
#import "TerminalEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface ConversionHelper : NSObject

+ (ReversalReason)toReversalReason:(TerminalDecisionType)terminalDecisionType;

@end

NS_ASSUME_NONNULL_END
