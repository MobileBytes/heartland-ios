//
//  NSDictionary+EnumStringValues.h
//  EMVCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (EnumStringValues)

+ (nullable NSString *)valueForAnEnumType:(NSUInteger)enumCaseType
                             forEnumValue:(NSUInteger)enumValueType;

@end

NS_ASSUME_NONNULL_END
