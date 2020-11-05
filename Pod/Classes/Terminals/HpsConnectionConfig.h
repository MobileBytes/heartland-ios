#import <Foundation/Foundation.h>
#import <EMVCore/EMVCore.h>

@interface HpsConnectionConfig : NSObject

@property (nonatomic) NSInteger connectionMode;
@property (nonatomic, strong) NSString *ipAddress;
@property (nonatomic, strong) NSString *port;
@property (nonatomic) NSInteger baudeRate;
@property (nonatomic) NSInteger parity;
@property (nonatomic) NSInteger stopBits;
@property (nonatomic) NSInteger dataBits;
@property (nonatomic) NSInteger *timeout;


@property (nonatomic, strong) NSString *VersionNumber;
@property (nonatomic, strong) NSString *DeveloperID;
@property (nonatomic, strong) NSString *LicenseID;
@property (nonatomic, strong) NSString *SiteID;
@property (nonatomic, strong) NSString *Username;
@property (nonatomic, strong) NSString *Password;
@property (nonatomic, strong) NSString *DeviceID;


-(TerminalConfiguration *)terminalConfig:(TerminalType)terminalType
                         withTerminalName:(NSString *)terminalName;
-(GatewayConfiguration *)gatewayConfig:(GatewayType)gatewayType;
-(TransactionConfiguration *)transactionConfiguration;
@end
