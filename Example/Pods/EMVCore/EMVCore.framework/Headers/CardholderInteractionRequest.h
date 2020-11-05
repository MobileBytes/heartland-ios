//
//  CardholderInteractionRequest.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardholderEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface CardholderInteractionRequest : NSObject

@property (nonatomic, assign) CardholderInteractionType cardholderInteractionType;
@property (nonatomic, strong, nullable) NSArray <NSString *> *supportedApplication;
@property (nonatomic, copy, nullable) NSDecimalNumber *finalTransactionAmount;
@property (nonatomic, copy, nullable) NSArray <NSString *> *commercialCardDataFields;

@end

NS_ASSUME_NONNULL_END
