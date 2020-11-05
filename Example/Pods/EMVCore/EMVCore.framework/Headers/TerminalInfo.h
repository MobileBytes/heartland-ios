//
//  TerminalInfo.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface TerminalInfo : NSObject <NSCopying>

@property (nonatomic, copy, nullable) NSString *serialNumber;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *appVersion;
@property (nonatomic, copy, nullable) NSString *terminalName;
@property (nonatomic, assign) NSInteger batteryLevel;
@property (nonatomic, assign) NSInteger batteryPercentage;
@property (nonatomic, assign) ConnectionType connectionType;
@property (nonatomic, assign) TerminalType terminalType;

@end

NS_ASSUME_NONNULL_END
