//
//  AIDConfiguration.h
//  EMVCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AID;
@class TerminalActionCodes;

@interface AIDConfiguration : NSObject

@property (nonatomic, strong, nullable) AID *aid;
@property (nonatomic, strong, nullable) TerminalActionCodes *terminalActionCodes;
@property (nonatomic, copy, nullable) NSString *terminalAppVersion;
@property (nonatomic, copy, nullable) NSString *lowestSupportedICCAppVersion;
@property (nonatomic, copy, nullable) NSString *applicationSelectionFlags;
@property (nonatomic, copy, nullable) NSString *temrinalCapabilities;
@property (nonatomic, copy, nullable) NSString *tlvData;
@property (nonatomic, assign) NSInteger floorLimit;
@property (nonatomic, assign) NSInteger cvmLimit;
@property (nonatomic, assign) NSInteger transactionLimit;
@property (nonatomic, assign) NSInteger priorityIndex;

@end

NS_ASSUME_NONNULL_END
