//
//  Tag.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CardDataEnums.h"

@interface Tag : NSObject

@property (nonatomic, assign) TagClass tagClass;
@property (nonatomic, assign) TagType tagType;
@property (nonatomic, assign) TagIdentfier tagIdentifier;
@property (nonatomic, copy, nullable) NSData *value;

+ (TagClass)tagClassFromChar:(unsigned char)byte;
+ (BOOL)tagIsPrimitive:(unsigned char)byte;
+ (unsigned char)tagIdentifier:(unsigned char)byte firstByte:(BOOL)isFirstByte;
+ (BOOL)tagIdentifierIsLastByte:(unsigned char)byte;

+ (BOOL)isValid:(int)byte;
+ (BOOL)isConstructed:(int)byte;
+ (BOOL)isMultiByte:(int)byte;
+ (BOOL)isLast:(int)byte;
+ (nonnull NSString *)tagName:(nonnull NSString *)tag;

@end
