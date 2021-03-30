import Foundation
import GlobalMobileSDK

@objc
public class HpsC2xEnums: NSObject {
    public static func transactionTypeToString(_ transactionType: GlobalMobileSDK.TransactionType?) -> String {
        switch (transactionType) {
        case .Auth:
            return "Auth"
        case .BatchClose:
            return "BatchClose"
        case .Capture:
            return "Capture"
        case .ListSaf:
            return "ListSaf"
        case .Return:
            return "Return"
        case .Reversal:
            return "Reversal"
        case .Sale:
            return "Sale"
        case .TipAdjust:
            return "TipAdjust"
        case .Tokenize:
            return "Tokenize"
        case .Verify:
            return "Verify"
        default:
            return "unknown"
        }
    }
    public static func cardDataSourceTypeToString(_ cardDataSourceType: GlobalMobileSDK.EntryMode?) -> String {
        switch (cardDataSourceType) {
        case .chipFallback:
            return "chipFallback"
        case .contact:
            return "contact"
        case .contactless:
            return "contactless"
        case .manual:
            return "manual"
        case .msr:
            return "msr"
        case .quickChip:
            return "quickChip"
        default:
            return "unknown"
        }
    }
}
