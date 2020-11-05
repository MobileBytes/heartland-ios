//
//  GatewayEnums.h
//  EMVCore
//

#ifndef GatewayEnums_h
#define GatewayEnums_h

// TODO: IMPORTANT: Any changes done to any of these enums' values should also be updated in
//                  EnumStringValues.h.

/**
 Enum representing Gateway types

 - GatewayTypeDemoMode: Demo Mode is used to complete any Transaction without interacting with Gateway
 - GatewayTypeTransIT: Used to configure TransIT Gateway only
 - GatewayTypeProPay: Used to Configure ProPay Gateway only
 - GatewayTypePortico: Used to Configure Portico Gateway only
 */
typedef NS_ENUM(NSUInteger, GatewayType)
{
    GatewayTypeDemoMode,
    GatewayTypeTransIT,
    GatewayTypeProPay,
    GatewayTypePortico
};

typedef NS_ENUM(NSUInteger, GatewayMode)
{
    GatewayModeDebug,
    GatewayModeProduction,
    GatewayModeCertification
};

/**
    Enum representing the Gateway Actions
    Common operations that may be supported by host implementations.

     - GatewayActionAuthenticate: Used to get session key or transaction key by sending username, password etc
     - GatewayActionSale: This is used to perform Sale Transaction. Auto captured by TransIT
     - GatewayActionAuth: This is used to perform the Auth transactions, then followed by Transaction Capture.
        Ex: Restaurant format
     - GatewayActionCapture: This is performed on a previosusly Authed Transaction
        (performs void if not captured) Ex: Restaurant format
     - GatewayActionTipAdjust: This action is used to Adjust Tip
     - GatewayActionRefundWithReference: This action is performed when a Transaction was
        settled on Gateway, with Reference(TransactionId)
     - GatewayActionRefundWithCardData: Refund with Card Data (Open Refunds)
     - GatewayActionVoid: This action is performed when a Transaction was not settled on
        Gateway and requires a funds return to customer
     - GatewayActionForcedAuth: ForcedAuth is typically used for capturing a phone or voice
        authorization. When entering a Force you will be required to enter the authorization code
     - GatewayActionBalanceInquiry: This is used for Balance Inquiry
     - GatewayActionTokenizeCard: This is to get token for a Transaction
     - GatewayActionTransactionAdjustment: This is used to Adjust Transaction. Ex: Adjusting with CVM(Signature)
     - GatewayActionBatchClose: This action is used to settle all transactions that have been entered in a batch
 */
typedef NS_ENUM (NSUInteger, GatewayAction)
{
    GatewayActionAuthenticate,
    GatewayActionSale,
    GatewayActionAuth,
    GatewayActionCapture,
    GatewayActionTipAdjust,
    GatewayActionRefundWithReference,
    GatewayActionRefundWithCardData,
    GatewayActionVoid,
    GatewayActionForcedAuth,
    GatewayActionBalanceInquiry,
    GatewayActionTokenizeCard,
    GatewayActionTransactionAdjustment,
    GatewayActionBatchClose,
    // The None type tells that no other action was taken.
    GatewayActionNone
};

#endif /* GatewayEnums_h */
