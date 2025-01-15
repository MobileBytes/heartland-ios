//
//  HpsUpaGetParamRequest.swift
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 1/14/25.
//

import Foundation

public struct HpsUpaGetParamRequest: Codable {
    public let message: String
    public let data: HpsUpaCommandPayload<HpsUpaGetParamRequestBody>

    public init(
        message: String = "MSG",
        data: HpsUpaCommandPayload<HpsUpaGetParamRequestBody>
    ) {
        self.message = message
        self.data = data
    }
}

public struct HpsUpaGetParamRequestBody: Codable {
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

public enum HpsUpaGetParamRequestParam: String, RawRepresentable, Codable {
    case automaticEODProcessingSupported = "AutomaticEODProcessingSupported"
    case automaticEODProcessingTime = "AutomaticEODProcessingTime"
    case automaticEODWindow = "AutomaticEODWindow"
    case managerPassword = "ManagerPassword"
    case safAmountMax = "SAFAmountMAX"
    case safEndOfDay = "SAFEndOfDay"
    case safIntervalTimer = "SAFIntervalTimer"
    case safMode = "SAFMode"
}
