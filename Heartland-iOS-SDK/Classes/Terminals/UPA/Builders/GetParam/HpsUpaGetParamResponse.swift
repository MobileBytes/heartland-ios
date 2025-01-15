//
//  HpsUpaGetParamResponse.swift
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 1/14/25.
//

import Foundation

public struct HpsUpaGetParamResponse: Codable {
    public let message: String
    public let data: HpsUpaResponsePayload<HpsUpaGetParamResponseBody>

    public init(message: String, data: HpsUpaResponsePayload<HpsUpaGetParamResponseBody>) {
        self.message = message
        self.data = data
    }
}

public struct HpsUpaGetParamResponseBody: Codable {
    struct DynamicKey: CodingKey {
        var stringValue: String
        init?(stringValue: String) {
            self.stringValue = stringValue
        }
        var intValue: Int? { return nil }
        init?(intValue: Int) { return nil }
    }

    public let params: [HpsUpaGetParamRequestParam: String]

    public init(params: [HpsUpaGetParamRequestParam: String]) {
        self.params = params
    }

    public init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: DynamicKey.self)
        var tempParams: [HpsUpaGetParamRequestParam: String] = [:]
        for key in container.allKeys {
            if let param = HpsUpaGetParamRequestParam(rawValue: key.stringValue) {
                let value = try container.decode(String.self, forKey: key)
                tempParams[param] = value
            }
        }
        self.params = tempParams
    }

    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: DynamicKey.self)
        for (param, value) in params {
            let key = DynamicKey(stringValue: param.rawValue)
            try container.encode(value, forKey: key!)
        }
    }
}
