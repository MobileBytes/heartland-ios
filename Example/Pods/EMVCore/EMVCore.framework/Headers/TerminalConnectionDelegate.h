//
//  TerminalConnectionDelegate.h
//  EMVCore
//

#import "TerminalInfo.h"
#import "NSError+CustomError.h"

#ifndef TerminalConnectionDelegate_h
#define TerminalConnectionDelegate_h

@protocol TerminalConnectionDelegate <NSObject>

- (void)onConnected:(TerminalInfo *)terminalInfo;
- (void)onDisconnected;
- (void)onError:(NSError *)error;

@end

#endif /* TerminalConnectionDelegate_h */
