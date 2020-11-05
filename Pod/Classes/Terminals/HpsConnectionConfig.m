#import "HpsConnectionConfig.h"

@implementation HpsConnectionConfig

-(TerminalConfiguration *)terminalConfig:(TerminalType)terminalType
                         withTerminalName:(nonnull NSString *)terminalName
{
    TerminalConfiguration *config = [[TerminalConfiguration alloc] init];
    config.bluetoothName = terminalName;

    switch (terminalType)
    {
        case BBPOS_CHIPPER_2X:
        {
            config.terminalType = BBPOS_CHIPPER_2X;
            config.connectionType = BLUETOOTH;
            config.outputCapability = PRINT_AND_DISPLAY;
            config.inputCapability = MAGSTRIPE_ICC_ONLY;
            config.authenticationCapability = NO_CAPABILITY;
            config.operatingEnvironment = ON_MERCHANT_PREMISES_ATTENDED;
        }
            break;

        default:
            break;
    }

    return config;
}

-(GatewayConfiguration *)gatewayConfig:(GatewayType)gatewayType
{
    GatewayConfiguration *config = [[GatewayConfiguration alloc] init];

    switch (gatewayType)
    {
        case GatewayTypePortico:
        {
            config.gatewayType = GatewayTypePortico;
            config.credentials = [self porticoCredentials];
        }
            break;

        default:
            break;
    }

    return config;
}

-(TransactionConfiguration *)transactionConfiguration
{
    TransactionConfiguration *config = [[TransactionConfiguration alloc] init];

    config.isChipEnabled = YES;
    config.isMagStripeEnabled = YES;
    config.isManualEntryEnabled = YES;
    config.currencyCode = CurrencyCodeUSD;
    config.countryCode = CountryCodeUS;

    return config;
}

-(NSMutableDictionary*)porticoCredentials
{
    NSMutableDictionary *credentials = [NSMutableDictionary new];
    
    [credentials setValue:self.VersionNumber forKey:@"VersionNumberKey"];
    [credentials setValue:self.DeveloperID forKey:@"DeveloperIDKey"];
    [credentials setValue:self.LicenseID forKey:@"LicenseIDKey"];
    [credentials setValue:self.SiteID forKey:@"SiteIDKey"];
    [credentials setValue:self.Username forKey:@"UsernameKey"];
    [credentials setValue:self.Password forKey:@"PasswordKey"];
    [credentials setValue:self.DeviceID forKey:@"DeviceIDKey"];
    
    return credentials;
}

@end
