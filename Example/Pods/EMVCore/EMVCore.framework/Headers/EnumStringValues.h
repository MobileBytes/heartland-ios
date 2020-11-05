//
//  EnumStringValues.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface EnumStringValues : NSObject

+ (NSDictionary *)dictionaryForEnumType:(NSUInteger)enumType;

@end

NS_ASSUME_NONNULL_END
