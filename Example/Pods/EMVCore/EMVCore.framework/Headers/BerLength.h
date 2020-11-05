//
//  BerLength.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardDataEnums.h"

@interface BerLength : NSObject

@property (nonatomic, copy, nullable) NSData *value;
@property (nonatomic) BerLengthType type;

+ (BerLengthType)getTagLengthType:(unsigned char)byte;
+ (BOOL)isTagLengthLastByte:(unsigned char)byte;
+ (nullable NSData*)getEncodedLength:(NSUInteger)length;
+ (nullable NSString*)getEncodedLengthHexString:(NSUInteger)length;

+ (BOOL)isValid:(int)byte;
+ (int)getLength:(int)byte;
+ (BOOL)isMultiByte:(int)byte;

@end
