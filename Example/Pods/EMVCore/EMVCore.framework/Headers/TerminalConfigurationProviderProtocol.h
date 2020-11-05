//
//  TerminalConfigurationProviderProtocol.h
//  EMVCore
//

#ifndef TerminalConfigurationProvider_h
#define TerminalConfigurationProvider_h

#import "TerminalEnums.h"
#import "GatewayEnums.h"

@class AIDConfiguration;
@class TerminalActionCodes;
@class EMVCAPK;

@protocol TerminalConfigurationProviderDelegate;

@protocol TerminalConfigurationProviderProtocol <NSObject>

- (void)createConfigWith:(TerminalType)terminalType
             gatewayType:(GatewayType)gatewayType
terminalConfigurationProviderDelegate:(nullable id<TerminalConfigurationProviderDelegate>)delegate;

@optional

/**
 * Returns a list of contactless AID's for a given terminal configuration.
 */
- (nullable NSArray<AIDConfiguration *> *)contactAIDs;

/**
 * Returns a list of contact AID's for a given terminal configuration.
 */
- (nullable NSArray<AIDConfiguration *> *)contactlessAIDs;

/**
 * Returns a mapping of AIDConfiguration reference id's to a given TerminalActionCode
 * returns dictionary containing the contactless AIDs'.
 */
- (nullable NSDictionary<NSString *, TerminalActionCodes *> *)terminalActionDictionary;

/**
 * Returns the list of Certificate Authority Public Keys(CAPK's) for a given terminal configuration.
 */
- (nullable NSArray<EMVCAPK *> *) publicKeys;

@end

#endif /* TerminalConfigurationProvider_h */
