//
//  TransactionReceipt.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

@class TransactionRequest;

NS_ASSUME_NONNULL_BEGIN

@interface TransactionReceipt : NSObject <NSCopying>

// Properties
@property (nonatomic, assign) TransactionType transactionType;
@property (nonatomic, assign) CurrencyCode currencyCode;
@property (nonatomic, assign) CardType cardType;
@property (nonatomic, assign) CvmResult cvmResult;
@property (nonatomic, assign) CardDataSourceType posEntryMode;
@property (nonatomic, assign) CountryCode terminalCountryCode;
@property (nonatomic, assign) PinStatementType pinStatementType;
@property (nonatomic, copy, nullable) NSDate *transactionDateTime;
@property (nonatomic, copy, nullable) NSString *invoiceNumber;
@property (nonatomic, copy, nullable) NSString *transactionAmount;
@property (nonatomic, copy, nullable) NSString *authorizationCode;
@property (nonatomic, copy, nullable) NSString *maskedPan;
@property (nonatomic, copy, nullable) NSString *transactionId;
@property (nonatomic, copy, nullable) NSString *cardholderName;
@property (nonatomic, copy, nullable) NSString *aid;
@property (nonatomic, copy, nullable) NSString *applicationLabel;
@property (nonatomic, copy, nullable) NSString *applicationExpiryDate;
@property (nonatomic, copy, nullable) NSString *applicationEffectiveDate;
@property (nonatomic, copy, nullable) NSString *applicationInterchangeProfile;
@property (nonatomic, copy, nullable) NSString *applicationVersionNumber;
@property (nonatomic, copy, nullable) NSString *applicationTransactionCounter;
@property (nonatomic, copy, nullable) NSString *panSequenceNumber;
@property (nonatomic, copy, nullable) NSString *cryptogram;
@property (nonatomic, copy, nullable) NSString *issuerApplicationData;
@property (nonatomic, copy, nullable) NSString *terminalVerificationResult;
@property (nonatomic, copy, nullable) NSString *unpredictableNumber;
@property (nonatomic, copy, nullable) NSString *cashBackAmount;
@property (nonatomic, copy, nullable) NSString *terminalType;
@property (nonatomic, copy, nullable) NSString *ifdSerialNumber;
@property (nonatomic, copy, nullable) NSString *cryptogramInformationData;

@end

NS_ASSUME_NONNULL_END
