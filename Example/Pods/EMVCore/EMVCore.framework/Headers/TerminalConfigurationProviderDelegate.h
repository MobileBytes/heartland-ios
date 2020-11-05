//
//  TerminalConfigurationProviderDelegate.h
//  EMVCore
//

#ifndef TerminalConfigurationProviderDelegate_h
#define TerminalConfigurationProviderDelegate_h

@protocol TerminalConfigurationProviderDelegate <NSObject>

/**
 * Invoked when terminal configuration is successfully loaded. Upon successful load, the following methods will
 * provide data if it was available in the configuration:
 * TerminalConfigurationProvider#getTacMap
 * TerminalConfigurationProvider#getContactlessAids
 * TerminalConfigurationProvider#getContactAids
 */
- (void)onConfigurationLoaded;

/**
 * Invoked when an error occurs during the loading process.
 */
- (void)onError:(NSString *)errorMessage;

@end


#endif /* TerminalConfigurationProviderDelegate_h */
