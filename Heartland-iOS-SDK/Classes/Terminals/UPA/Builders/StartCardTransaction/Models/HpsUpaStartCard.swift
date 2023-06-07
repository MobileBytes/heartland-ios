//
//  HpsUpaStartCard.swift
//  Heartland-iOS-SDK
//

import Foundation

struct HpsUpaStartCardConstants {
    static let command = "StartCardTransaction"
}

public struct HpsUpaStartCard: Codable {
    public var message: String
    public let data: HpsUpaCommandPayload<HpsUpaStartCardDataDetails>

    public init(message: String = "MSG", data: HpsUpaCommandPayload<HpsUpaStartCardDataDetails>) {
        self.message = message
        self.data = data
    }
}

public struct HpsUpaStartCardDataDetails: Codable {
    public let params: HpsUpaStartCardParams
    public let processingIndicators: HpsUpaStartCardProcessingIndicators
    public let transaction: HpsUpaStartCardTransaction

    public init(params: HpsUpaStartCardParams, processingIndicators: HpsUpaStartCardProcessingIndicators, transaction: HpsUpaStartCardTransaction) {
        self.params = params
        self.processingIndicators = processingIndicators
        self.transaction = transaction
    }
}

public struct HpsUpaStartCardParams: Codable {
    public let acquisitionTypes: String
    public let timeout: Int?
    public let header: String?
    public let displayTotalAmount: String?
    public let promptForManualEntryPassword: String?
    public let brandIcon1: Int?
    public let brandIcon2: Int?

    public init(acquisitionTypes: String, timeout: Int?, header: String?, displayTotalAmount: String?, promptForManualEntryPassword: String?, brandIcon1: Int?, brandIcon2: Int?) {
        self.acquisitionTypes = acquisitionTypes
        self.timeout = timeout
        self.header = header
        self.displayTotalAmount = displayTotalAmount
        self.promptForManualEntryPassword = promptForManualEntryPassword
        self.brandIcon1 = brandIcon1
        self.brandIcon2 = brandIcon2
    }

    public init(acquisitionTypes: [HpsUpaStartCardParamsAcquisitionType], timeout: Int? = nil, header: String? = nil, displayTotalAmount: String? = nil, promptForManualEntryPassword: String? = nil, brandIcon1: Int? = nil, brandIcon2: Int? = nil) {
        self.init(acquisitionTypes: acquisitionTypes.rawValue, timeout: timeout, header: header, displayTotalAmount: displayTotalAmount, promptForManualEntryPassword: promptForManualEntryPassword, brandIcon1: brandIcon1, brandIcon2: brandIcon2)
    }
}

public struct HpsUpaStartCardProcessingIndicators: Codable {
    public let quickChip: String
    public let checkLuhn: String?
    public let securityCode: String?
    public let cardFilterType: String?

    public init(quickChip: String, checkLuhn: String?, securityCode: String?, cardFilterType: String?) {
        self.quickChip = quickChip
        self.checkLuhn = checkLuhn
        self.securityCode = securityCode
        self.cardFilterType = cardFilterType
    }
}

public struct HpsUpaStartCardTransaction: Codable {
    public let totalAmount: String
    public let cashBackAmount: String?
    public let tranDate: String?
    public let tranTime: String?
    public let transactionType: String

    public init(totalAmount: String, cashBackAmount: String?, tranDate: String?, tranTime: String?, transactionType: String) {
        self.totalAmount = totalAmount
        self.cashBackAmount = cashBackAmount
        self.tranDate = tranDate
        self.tranTime = tranTime
        self.transactionType = transactionType
    }
}

public enum HpsUpaStartCardParamsAcquisitionType: String {
    case contact = "Contact"
    case contactless = "Contactless"
    case manual = "Manual"
    case scan = "Scan"
    case swipe = "Swipe"
}

extension Array: RawRepresentable where Element == HpsUpaStartCardParamsAcquisitionType {
    public var rawValue: String {
        map(\.rawValue).joined(separator: "|")
    }

    public init?(rawValue: String) {
        let rawValues = rawValue.components(separatedBy: "|")
        let values = rawValues.compactMap(HpsUpaStartCardParamsAcquisitionType.init(rawValue:))
        guard rawValue == "" || !values.isEmpty else { return nil }
        self = values
    }
}
