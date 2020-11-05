//
//  CardholderInteractionResult.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardholderEnums.h"
#import "CommercialCardData.h"

NS_ASSUME_NONNULL_BEGIN

@interface CardholderInteractionResult : NSObject

@property (nonatomic, assign) CardholderInteractionType cardholderInteractionType;
@property (nonatomic, assign) int selectedAidIndex;
@property (nonatomic, assign) BOOL finalAmountConfirmed;
@property (nonatomic, strong, nullable) CommercialCardData *commercialCardData;

@end

NS_ASSUME_NONNULL_END
