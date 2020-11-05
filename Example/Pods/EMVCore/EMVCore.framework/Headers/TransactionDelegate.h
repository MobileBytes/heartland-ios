//
//  TransactionDelegate.h
//  EMVCore
//

#import "CommonEnums.h"
#import "CardholderInteractionRequest.h"
#import "TransactionResponse.h"
#import "NSError+CustomError.h"

#ifndef TransactionDelegate_h
#define TransactionDelegate_h

@protocol TransactionDelegate <NSObject>

/**
 * Invoked when the transaction state has updated.
 * TransactionStatus representing the new state of the transaction process.
 */
- (void)onStatusUpdate:(TransactionStatus)transactionStatus;

/**
 * Invoked when cardholder interaction is required to continue normal transaction processing.
 * CardholderInteractionRequest contains details about the type of
 * interaction and any accompanying data that should be presented to the cardholder.
 */
- (void)onCardholderInteractionRequested:(CardholderInteractionRequest *)request;

/**
 * Invoked when a transaction has processed to completion.
 * TransactionResponse contains details regarding the final result of
 * the transaction.
 */
- (void)onTransactionComplete:(TransactionResponse *)response;

/**
 * Invoked when an unrecoverable error is encountered during transaction processing.
 * CustomError Object contains details regarding the error encountered.
 */
- (void)onError:(NSError *)emvError;

@end

#endif /* TransactionDelegate_h */
