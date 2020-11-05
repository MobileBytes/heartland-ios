//
//  TerminalInfoDelegate.h
//  EMVCore
//

#ifndef TerminalInfoDelegate_h
#define TerminalInfoDelegate_h

#import "TerminalInfo.h"

@protocol TerminalInfoDelegate <NSObject>

- (void)onTerminalInfoReceived:(nullable TerminalInfo *)terminalInfo;
- (void)onError;

@end

#endif /* TerminalInfoDelegate_h */
