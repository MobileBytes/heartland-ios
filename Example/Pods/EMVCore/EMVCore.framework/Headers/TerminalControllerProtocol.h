//
//  TerminalControllerProtocol.h
//  EMVCore
//

#ifndef TerminalControllerProtocol_h
#define TerminalControllerProtocol_h

#import "TerminalRequest.h"
#import "TerminalEnums.h"
#import "TerminalInteractionResult.h"

@protocol TerminalControllerProtocol <NSObject>

/**
 * Attempts to connect to the configured terminal.
 */
- (void)connect;

/**
 * TerminalRequest contains details of the transaction being processed.
 */
- (void)sendRequest:(nullable TerminalRequest *)terminalRequest;

/**
 *  TerminalInteractionResult with details of the cardholders selection.
 */
- (void)sendTerminalInteractionResult:(nullable TerminalInteractionResult *)terminalInteractionResult;

/**
 *  Attempts to cancel the current transaction. If the terminal is busy processing another
 *  command, TerminalDelegate will broadcast to the onTerminalStatusUpdate:(TerminalStatus) status
 *  update. If the terminal is not busy, a command will be issued to stop the current transaction.
 *  An appropriate response will be broadcasted to onTerminalResponseReceived:(TerminalResponse *)response indicating
 *  that the transaction was cancelled.
 */
- (void)cancel;

/**
 * Attempts to disconnect from the configured terminal.
 */
- (void)disconnect;

@end

#endif /* TerminalControllerProtocol_h */
