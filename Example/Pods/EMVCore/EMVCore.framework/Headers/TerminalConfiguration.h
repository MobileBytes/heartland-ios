//
//  TerminalConfiguration.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"

NS_ASSUME_NONNULL_BEGIN

@class AIDConfiguration;
@class TerminalActionCodes;
@class EMVCAPK;

@interface TerminalConfiguration : NSObject <NSCopying>

@property (nonatomic, copy, nullable) NSString *host;
@property (nonatomic, assign) NSUInteger port;
@property (nonatomic, assign) NSUInteger timeout;
@property (nonatomic, assign) NSInteger minPinLength;
@property (nonatomic, assign) NSInteger maxPinLength;
@property (nonatomic, assign) NSNumber *energySaverModeDelay;
@property (nonatomic, nullable) NSNumber *shutDownDelay;
@property (nonatomic, nullable) NSNumber *screenTurnOffDelay;
@property (nonatomic, assign) TerminalOperatingEnvironment operatingEnvironment;
@property (nonatomic, assign) TerminalAuthenticationCapability authenticationCapability;
@property (nonatomic, assign) TerminalOutputCapability outputCapability;
@property (nonatomic, assign) TerminalInputCapability inputCapability;
@property (nonatomic, assign) TerminalType terminalType;
@property (nonatomic, assign) ConnectionType connectionType;
@property (nonatomic, copy, nullable) NSArray<AIDConfiguration *> *contactAIDs;
@property (nonatomic, copy, nullable) NSArray<AIDConfiguration *> *contactLessAIDs;
@property (nonatomic, copy, nullable) NSDictionary<NSString *, TerminalActionCodes *> *terminalActionCodesDictionary;
@property (nonatomic, copy, nullable) NSArray<EMVCAPK *> *capks;
@property (nonatomic, copy, nullable) NSString *bluetoothName;

@end

NS_ASSUME_NONNULL_END
