//
//  HpsUpaGetParamResponse.swift
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 1/14/25.
//

import Foundation

public struct HpsUpaGetParamResponse: Codable {
    public let message: String
    public let data: HpsUpaGetParamResponseData

    public init(message: String, data: HpsUpaGetParamResponseData) {
        self.message = message
        self.data = data
    }
}

public typealias HpsUpaGetParamResponseData = HpsUpaResponsePayload<[HpsUpaGetParamRequestParam: String]>
