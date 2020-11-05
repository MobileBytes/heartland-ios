//
//  ReceiptHelper.h
//  EMVCore
//

#import <Foundation/Foundation.h>

@class TransactionReceipt;
@class TransactionRequest;
@class GatewayResponse;
@class CardData;

NS_ASSUME_NONNULL_BEGIN

@interface ReceiptHelper : NSObject

/**
 Returns information that must be presented to the customer on the receipt for an MSR
 transaction.

 @param transactionRequest TransactionRequest containing information about the Transaction.
 @param gatewayResponse GatewayResponse containing information about the approved
 amounts, transaction id,and authorization code.
 @param cardData CardData containing information about the payment method and
 cardholder information.
 @return TransactionReceipt object containing required MSR transaction data if present.
 */
+ (nullable TransactionReceipt *)buildMsrReceiptFor:(nonnull TransactionRequest *)transactionRequest
                                withGatewayResponse:(nullable GatewayResponse*)gatewayResponse
                                        andCardData:(nonnull CardData *)cardData;

/**
 Returns information that must be presented to the customer on the receipt for an EMV
 transaction.

 @param gatewayResponse GatewayResponse containing information about the approved
 amounts, transaction id, and authorization code.
 @param cardData CardData containing information about the payment method and
 cardholder information.
 @return TransactionReceipt object containing required EMV and transaction data if present.
 */
+ (nullable TransactionReceipt *)buildEmvReceiptWith:(nullable GatewayResponse*)gatewayResponse
                                         andCardData:(nonnull CardData *)cardData;

@end

NS_ASSUME_NONNULL_END
