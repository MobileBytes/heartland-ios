//
//  TerminalDelegate.h
//  EMVCore
//

#ifndef TerminalDelegate_h
#define TerminalDelegate_h

#import "TerminalInfo.h"
#import "CommonEnums.h"
#import "TerminalResponse.h"
#import "TerminalInteractionRequest.h"

@protocol TerminalDelegate <NSObject>

- (void)onConnected:(nullable TerminalInfo *)terminalInfo;
- (void)onTerminalInfo:(nullable TerminalInfo *)terminalInfo;
- (void)onTerminalStatusUpdate:(TerminalStatus)status;
- (void)onTerminalResponseReceived:(nullable TerminalResponse *)response;
- (void)onDisconnected;
- (void)onTerminalInteractionRequested:(nullable TerminalInteractionRequest *)request;
- (void)onError:(ErrorType)terminalError
        message:(nullable NSString *)stringMeesage;

@optional
#if DEBUG
- (void)onReceivingTerminalLogs:(nullable NSString *)logs;
#endif

@end

#endif /* TerminalDelegate_h */
