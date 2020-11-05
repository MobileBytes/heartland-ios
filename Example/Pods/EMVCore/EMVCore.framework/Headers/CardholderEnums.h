//
//  CardholderEnums.h
//  EMVCore
//

#ifndef CardholderEnums_h
#define CardholderEnums_h

// TODO: IMPORTANT: Any changes done to any of these enums' values should also be updated in
//                  EnumStringValues.h.

typedef NS_ENUM(NSUInteger, CardholderAuthenticationMethod)
{
    CardholderAuthenticationMethodNotAuthenticated,
    CardholderAuthenticationMethodPIN,
    CardholderAuthenticationMethodOfflinePin,
    CardholderAuthenticationMethodElectronicSignatureAnalysis,
    CardholderAuthenticationMethodManualSignature,
    CardholderAuthenticationMethodManualOther,
    CardholderAuthenticationMethodUnknown,
    CardholderAuthenticationMethodSystematicOther,
    CardholderAuthenticationMethodETicketEnvAmex,
    CardholderAuthenticationMethodNotSet
};

/**
 CardholderInteraction types :

 -  CardholderInteractionTypeEMVApplicationSelection: Multiple supported Applications (AIDs) are
    present on the inserted card and the cardholder must select which Application to process the payment

 -  CardholderInteractionTypeFinalAmountConfirmation: Cardholder must confirm the amount
    to be authorized prior to host processing takes place

 -  CardholderInteractionTypeCommercialCardDataEntry: Additional data was requested
    by the host because the processed card is a commercial card
 */
typedef NS_ENUM(NSUInteger, CardholderInteractionType)
{
    CardholderInteractionTypeEMVApplicationSelection,
    CardholderInteractionTypeFinalAmountConfirmation,
    CardholderInteractionTypeCommericalCardDataEntry
};

#endif /* CardholderEnums_h */
