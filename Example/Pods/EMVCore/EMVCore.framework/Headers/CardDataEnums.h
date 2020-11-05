//
//  CardDataEnums.h
//  EMVCore
//

#ifndef CardDataEnums_h
#define CardDataEnums_h

// TODO: IMPORTANT: Any changes done to any of these enums' values should also be updated in
//                  EnumStringValues.h.

// TLV Related Enums
typedef NS_ENUM(NSUInteger, TagClass)
{
    TagClassUniversal = 0x00,
    TagClassApplication = 0x40,
    TagClassContextSpecific = 0x80,
    TagClassContextPrivate = 0xC0,
};

typedef NS_ENUM(NSUInteger, TagType)
{
    TagTypePrimitive = 0x00,
    TagTypeConstructed = 0x20
};

typedef NS_ENUM(NSUInteger, TagIdentfier)
{
    TagLeadingOctectLongIdentfier = 0x1F,
    TagTrailingIdentfierOctectHasNext = 0x80,
    TagTrailingIdentfierOctectIsLast = 0x00
};

typedef NS_ENUM(NSUInteger, BerLengthType)
{
    BerLengthTypeDefiniteShort,
    BerLengthTypeDefiniteLong,
    BerLengthTypeIndefinite
};

typedef NS_ENUM(NSUInteger, ParserPosition)
{
    ParserPositionTag,
    ParserPositionLength,
    ParserPositionValue
};

// Commercial Card Data Enum
typedef NS_ENUM(NSUInteger, CommercialCardDataField)
{
    /**
     * Value used by the customer to identify an order.
     * Issued by the buyer to the seller.
     */
    CommercialCardDataFieldPurchaseOrderNumber,
    /**
     * Used by AMEX to obtain supportive information on a change from
     * a merchant.
     */
    CommercialCardDataFieldSupplierRefNumber,
    /**
     * Reference identifier supplied by the Commercial Card cardholder.
     */
    CommercialCardDataFieldCustomerRefID,
    /**
     * The postal code for the address to which the goods are being shipped.
     */
    CommercialCardDataFieldShipToZip,
    /**
     * Displays descriptive information about a transaction on a customer's
     * card statement.
     */
    CommercialCardDataFieldChargeDescriptor,
};

#endif /* CardDataEnums_h */
