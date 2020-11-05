#import <Foundation/Foundation.h>
#import "HpsTerminalInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol HpsC2xDeviceDelegate <NSObject>


- (void)onConnected:(HpsTerminalInfo *)terminalInfo;
- (void)onDisconnected;
- (void)onError:(NSString*)deviceError;
- (void)onTerminalInfoReceived:(HpsTerminalInfo *)terminalInfo;
- (void)onBluetoothDeviceList:(NSMutableArray *)peripherals;


@end

NS_ASSUME_NONNULL_END
