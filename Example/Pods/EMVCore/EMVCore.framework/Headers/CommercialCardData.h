//
//  CommercialCardData.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardDataEnums.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents Level 2 and Level 3 card data required by the host when processing commercial cards.
 */
@interface CommercialCardData : NSObject

@property (nonatomic, copy, nullable) NSDictionary <NSString *, NSString *> *commercialCardDataValuesDictionary;

@end

NS_ASSUME_NONNULL_END
