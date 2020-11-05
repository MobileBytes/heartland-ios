//
//  TransactionResponse.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@class TransactionReceipt;

@interface TransactionResponse : NSObject

// Properties
@property (nonatomic, assign) TransactionResultType transactionResultType;
@property (nonatomic, assign) CardType cardType;
@property (nonatomic, assign) TenderType tenderType;
@property (nonatomic, assign) TransactionType transactionType;
@property (nonatomic, assign) CardDataSourceType cardDataSourceType;
@property (nonatomic, copy, nullable) NSString *gatewayTransactionId;
@property (nonatomic, copy, nullable) NSString *posReferenceNumber;
@property (nonatomic, copy, nullable) NSString *gatewayAuthCode;
@property (nonatomic, copy, nullable) NSString *maskedPan;
@property (nonatomic, copy, nullable) NSString *hostTransactionId;
@property (nonatomic, copy, nullable) NSDecimalNumber *approvedAmount;
@property (nonatomic, copy, nullable) NSDecimalNumber *tipAmount;
@property (nonatomic, copy, nullable) TransactionReceipt *receipt;

// FIXME: Android maps like this Map<TransactionType, String> mResponseMessages; have to check and update if required
@property (nonatomic, copy, nullable) NSDictionary<NSString*, NSString*> *responseMessages;

@end

NS_ASSUME_NONNULL_END
