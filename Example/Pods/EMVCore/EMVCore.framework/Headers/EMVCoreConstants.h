//
//  EMVCoreConstants.h
//  EMVCore
//

#import <Foundation/Foundation.h>

#ifndef EMVCoreConstants_h
#define EMVCoreConstants_h

// Gateway Config Keys
extern NSString * _Nonnull const TerminalIDKey;
extern NSString * _Nonnull const DeviceIDKey;
extern NSString * _Nonnull const TransactionKeyKey;
extern NSString * _Nonnull const BankIDKey;
extern NSString * _Nonnull const MerchantDBAKey;
extern NSString * _Nonnull const CompanyIDKey;
extern NSString * _Nonnull const AccountIDKey;
extern NSString * _Nonnull const PINKey;
extern NSString * _Nonnull const PINTokenKey;
extern NSString * _Nonnull const SessionTokenKey;
extern NSString * _Nonnull const UsernameKey;
extern NSString * _Nonnull const PasswordKey;
extern NSString * _Nonnull const MerchantProfileIDKey;
extern NSString * _Nonnull const DeveloperIDKey;

// Credit Card Related Keys
extern NSString * _Nonnull const CardNumberKey;
extern NSString * _Nonnull const CardGoodThruKey;
extern NSString * _Nonnull const CardGoodThruMonthKey;
extern NSString * _Nonnull const CardGoodThruYearKey;
extern NSString * _Nonnull const CardholderNameKey;
extern NSString * _Nonnull const CardTrack1Key;
extern NSString * _Nonnull const CardTrack2Key;
extern NSString * _Nonnull const CardTrack3Key;
extern NSString * _Nonnull const CardTypeKey;
extern NSString * _Nonnull const CardKSNKey;
extern NSString * _Nonnull const CardEmulatedKey;
extern NSString * _Nonnull const CardEncryptionTypeKey;
extern NSString * _Nonnull const CardInfoKey;
extern NSString * _Nonnull const CardZipKey;

// Transaction Related Keys
extern NSString * _Nonnull const TransactionAmountKey;
extern NSString * _Nonnull const TransactionTotalKey;
extern NSString * _Nonnull const PaymentTypeKey;
extern NSString * _Nonnull const TransactionSalesTaxKey;
extern NSString * _Nonnull const TransactionTipKey;
extern NSString * _Nonnull const TransactionEventKey;
extern NSString * _Nonnull const TransactionReceiptKey;
extern NSString * _Nonnull const TransactionChangeDueKey;
extern NSString * _Nonnull const TransactionTenderedKey;
extern NSString * _Nonnull const TransactionCustomerReceiptKey;

#endif /* EMVCoreConstants_h */
