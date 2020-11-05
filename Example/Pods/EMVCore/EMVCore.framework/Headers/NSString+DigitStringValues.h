//
//  NSString+DigitStringValues.h
//  EMVCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (DigitStringValues)

+ (instancetype)stringForDigit:(NSUInteger)number;

@end

NS_ASSUME_NONNULL_END
