//
//  GatewayRequest.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GatewayEnums.h"
#import "CommonEnums.h"
#import "TerminalEnums.h"

@class Address;
@class CardData;
@class Customer;
@class TerminalInfo;
@class CommercialCardData;
@class TerminalCapabilities;

@interface GatewayRequest : NSObject

@property (nonatomic, copy, nullable) NSDecimalNumber *subTotalAmount;
@property (nonatomic, copy, nullable) NSDecimalNumber *taxAmount;
@property (nonatomic, copy, nullable) NSDecimalNumber *tipAmount;
@property (nonatomic, copy, nonnull) NSDecimalNumber *totalAmount;
@property (nonatomic, copy, nullable) NSString *posReferenceNumber;
@property (nonatomic, copy, nullable) NSString *operatingUserId;
@property (nonatomic, copy, nullable) NSString *gatewayTransactionId;
@property (nonatomic, copy, nullable) NSString *forceAuthCode;
@property (nonatomic, copy, nullable) NSString *invoiceNumber;
@property (nonatomic, copy, nullable) UIImage *signature;
@property (nonatomic, assign) ReversalReason reversalReason;
@property (nonatomic, assign) TenderType tenderType;
@property (nonatomic, assign) CvmResult cvmResult;
@property (nonatomic, assign) AvsType avsType;
@property (nonatomic, assign) GatewayAction gatewayAction;
@property (nonatomic, assign) TerminalOperatingEnvironment operatingEnvironment;
@property (nonatomic, assign) TerminalAuthenticationCapability authenticationCapability;
@property (nonatomic, assign) TerminalOutputCapability outputCapability;
@property (nonatomic, assign) TerminalInputCapability inputCapability;
@property (nonatomic, assign) TaxCategory taxCategory;
@property (nonatomic, copy, nullable) TerminalCapabilities *terminalCapabilities;
@property (nonatomic, copy, nullable) TerminalInfo *terminalInfo;
@property (nonatomic, copy, nullable) Customer *customer;
@property (nonatomic, copy, nullable) Address *cardholderAddress;
@property (nonatomic, copy, nullable) CardData *cardData;
@property (nonatomic, copy, nullable) NSString *hostTransactionId;
@property (nonatomic, nullable) CommercialCardData *commercialCardData;

// FIXME: UPDATE: NSDictionaty with CommercialCardDataFields.
//        It is Used for Level2 and Level3 transactions

@end
