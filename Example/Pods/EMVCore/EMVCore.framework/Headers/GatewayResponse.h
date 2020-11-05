//
//  GatewayResponse.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "GatewayEnums.h"
#import "CommonEnums.h"

@interface GatewayResponse : NSObject <NSCopying>

@property (nonatomic, copy) NSDecimalNumber * _Nullable approvedAmount;
@property (nonatomic, copy) NSDecimalNumber * _Nullable tipAmount;
@property (nonatomic, copy) NSString * _Nullable gatewayTransactionId;
@property (nonatomic, copy) NSString * _Nullable authCode;
@property (nonatomic, copy) NSString * _Nullable cvvResponseCode;
@property (nonatomic, copy) NSString * _Nullable avsResponseCode;
@property (nonatomic, copy) NSString * _Nullable gatewayResponseText;
@property (nonatomic, copy) NSString * _Nullable emvIssuerAuthCode;
@property (nonatomic, copy) NSString * _Nullable emvIssuerAuthenticationData;
@property (nonatomic, copy) NSString * _Nullable emvIssuerScripts;
@property (nonatomic, copy) NSString * _Nullable maskedPan;
@property (nonatomic, copy) NSString * _Nullable authResponse;
@property (nonatomic, copy) NSString * _Nullable stin;
@property (nonatomic, copy) NSString * _Nullable posReferenceId;
@property (nonatomic, copy) NSString * _Nullable cardholderName;
@property (nonatomic, copy) NSString * _Nullable cardExpirationDate;
@property (nonatomic, weak) NSError * _Nullable gatewayError;
@property (nonatomic, assign) BOOL isPartialApproval;
@property (nonatomic, assign) BOOL isApproved;
@property (nonatomic, assign) BOOL isGatewayTimeOut;
@property (nonatomic, assign) CardDataSourceType cardDataSourceType;
@property (nonatomic, assign) CardType cardType;
@property (nonatomic, assign) CommercialCard commercialCard;
@property (nonatomic, assign) GatewayAction gatewayAction;

@end
