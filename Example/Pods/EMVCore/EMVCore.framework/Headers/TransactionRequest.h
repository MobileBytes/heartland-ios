//
//  TransactionRequest.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

@class CardData;

NS_ASSUME_NONNULL_BEGIN

@interface TransactionRequest : NSObject

// Properties
@property (nonatomic, assign) TenderType tenderType;
@property (nonatomic, assign) TransactionType transactionType;
@property (nonatomic, assign) TaxCategory taxCategory;
@property (nonatomic, copy, nullable) CardData *cardData;
@property (nonatomic, copy, nullable) NSDecimalNumber *total;
@property (nonatomic, copy, nullable) NSDecimalNumber *tax;
@property (nonatomic, copy, nullable) NSDecimalNumber *tip;
@property (nonatomic, copy, nullable) NSDecimalNumber *cashBack;
@property (nonatomic, copy, nullable) NSString *gatewayTransactionId;
@property (nonatomic, copy, nullable) NSString *posReferenceNumber;
@property (nonatomic, copy, nullable) NSString *forcedAuthCode;
@property (nonatomic, copy, nullable) NSString *invoiceNumber;
@property (nonatomic, copy, nullable) NSString *operatingUserId;

// Init Methods
- (nonnull instancetype)initWithTransactionAmount:(nonnull NSDecimalNumber*)total
                                        tipAmount:(nonnull NSDecimalNumber*)tip
                                        taxAmount:(nonnull NSDecimalNumber*)tax
                                         cardData:(nonnull CardData*)cardData;

@end

NS_ASSUME_NONNULL_END
