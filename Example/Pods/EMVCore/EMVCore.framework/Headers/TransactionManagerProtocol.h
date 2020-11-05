//
//  TransactionManagerProtocol.h
//  EMVCore
//

#import "GatewayEnums.h"
#import "TerminalEnums.h"
#import "TerminalInfoDelegate.h"
#import "TransactionDelegate.h"
#import "CardholderInteractionResult.h"

#ifndef TransactionManagerDelegate_h
#define TransactionManagerDelegate_h

@protocol TransactionManagerProtocol <NSObject>

- (nullable NSArray *)supportedTerminalTypes:(GatewayType)gatewayType;
- (nullable NSArray *)supportedTerminalConnectionTypes:(TerminalType)terminalType;
- (void)initializeWithTerminalConfiguration:(nullable TerminalConfiguration *)terminalConfig
                   transactionConfiguration:(nullable TransactionConfiguration *)transactionConfig
                       gatewayConfiguration:(nullable GatewayConfiguration *)gatewayConfig;
- (void)connect:(nullable id<TerminalConnectionDelegate>)terminalConnectionDelegate;
- (void)deviceInfo:(nullable id<TerminalInfoDelegate>)terminalInfoDelegate;
- (void)updateTransactionDelegate:(nullable id <TransactionDelegate>)delegate;
- (void)startTransaction:(nullable TransactionRequest *)request
 withTransactionDelegate:(nullable id <TransactionDelegate>)delegate;
- (void)sendCardholderInteractionResult:(nullable CardholderInteractionResult *)result;
/**
 * Invoke when the consumer wants to cancel a transaction. If a transaction is in progress and
 * is in a cancellable state, the current processing will be stopped and {@link
 * TransactionListener#onTransactionComplete(TransactionResponse)}
 * will be triggered with a result indicating that the transaction was cancelled. If the
 * transaction cannot be cancelled, {@link TransactionListener#onStatusUpdate(TransactionStatus)}
 * will be broadcast with a status indicating that the terminal is busy.
 */
- (void)cancel;
- (void)disconnect;
- (BOOL)isInitialized;
/**
 * Check to see if the card reader is connected.
 * @return true if connected, false otherwise.
 */
- (BOOL)isConnected;

@end

#endif /* TransactionManagerProtocol_h */
