//
//  HpsUpaGetParamRequest.swift
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 1/14/25.
//

import Foundation

public struct HpsUpaGetParamRequest: Codable {
    public let message: String
    public let data: HpsUpaGetParamRequestData

    public init(
        message: String = "MSG",
        data: HpsUpaGetParamRequestData
    ) {
        self.message = message
        self.data = data
    }
}

public struct HpsUpaGetParamRequestData: Codable {
    public let command: String
    public let ecrId: String
    public let requestId: String
    public let data: HpsUpaGetParamRequestDataData

    public enum CodingKeys: String, CodingKey {
        case command
        case ecrId = "EcrId"
        case requestId, data
    }

    public init(
        command: String,
        ecrId: String,
        requestId: String,
        data: HpsUpaGetParamRequestDataData = .init()
    ) {
        self.command = command
        self.ecrId = ecrId
        self.requestId = requestId
        self.data = data
    }
}

public struct HpsUpaGetParamRequestDataData: Codable {
    public let password: String?
    public let params: HpsUpaGetParamRequestParams

    public init(
        password: String? = nil,
        params: HpsUpaGetParamRequestParams = .init()
    ) {
        self.password = password
        self.params = params
    }
}

public struct HpsUpaGetParamRequestParams: Codable {
    public let configuration: [HpsUpaGetParamRequestParam]

    public init(configuration: [HpsUpaGetParamRequestParam] = []) {
        self.configuration = configuration
    }
}

public enum HpsUpaGetParamRequestParam: String, Codable {
    case managerPassword = "ManagerPassword"
}
