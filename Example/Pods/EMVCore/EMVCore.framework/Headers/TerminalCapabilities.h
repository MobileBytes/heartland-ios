//
//  TerminalCapabilities.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface TerminalCapabilities : NSObject <NSCopying>

@property (nonatomic, assign) TerminalOperatingEnvironment terminalOperatingEnvironemt;
@property (nonatomic, assign) TerminalAuthenticationCapability terminalAuthenticationCapability;
@property (nonatomic, assign) TerminalOutputCapability terminalOutputCapability;
@property (nonatomic, assign) TerminalInputCapability terminalInputCapability;

@end

NS_ASSUME_NONNULL_END
