//
//  AID.h
//  EMVCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Describes an application type provided by an Application Provider that is
 * stored on the chip in an Integrated Chip Card.
 */
@interface AID : NSObject <NSCoding>

// Properties
@property (nonatomic, copy, nullable) NSString *rid;
@property (nonatomic, copy, nullable) NSString *pix;
@property (nonatomic, copy, nullable) NSString *label;
@property (nonatomic, copy, nullable) NSString *preferredName;

@end

NS_ASSUME_NONNULL_END
