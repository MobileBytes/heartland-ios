//
//  TerminalActionCodes.h
//  EMVCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TerminalActionCodes : NSObject

@property (nonatomic, copy, nullable) NSString *defaultTac;
@property (nonatomic, copy, nullable) NSString *denialTac;
@property (nonatomic, copy, nullable) NSString *onlineTac;

@end

NS_ASSUME_NONNULL_END
