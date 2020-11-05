//
//  TransactionConfiguration.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface TransactionConfiguration : NSObject

@property (nonatomic, assign) BOOL isMagStripeEnabled;
@property (nonatomic, assign) BOOL isChipEnabled;
@property (nonatomic, assign) BOOL isManualEntryEnabled;
@property (nonatomic, assign) BOOL isContaclessEnabled;
@property (nonatomic, assign) CurrencyCode currencyCode;
@property (nonatomic, assign) CountryCode countryCode;
@property (nonatomic, assign) NSUInteger defualtCurrencyExponent;

@end

NS_ASSUME_NONNULL_END
