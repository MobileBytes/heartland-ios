//
//  HpsUpaGetParamBuilder.swift
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 1/14/25.
//

import Foundation

public protocol HpsUpaGetParamBuilderProtocol {
    typealias Response = HpsUpaGetParamResponse
    typealias Handler = (Result<Response, Error>) -> Void
    func configure(device: HpsUpaDevice)
    func configure(ecrId: String)
    func configure(requestId: String)
    func configure(params: [HpsUpaGetParamRequestParam])
    func configure(password: String?)
    func execute(completion: @escaping Handler)
}

public enum HpsUpaGetParamBuilderError: Error {
    case invalidRequest
    case invalidResponse(String?)
}

public class HpsUpaGetParamBuilder: HpsUpaGetParamBuilderProtocol {
    private var device: HpsUpaDevice?
    private var ecrId: String = .init()
    private var requestId: String = .init()
    private var params: [HpsUpaGetParamRequestParam] = .init()
    private var password: String?

    public init() {
    }

    public func configure(device: HpsUpaDevice) {
        self.device = device
    }

    public func configure(ecrId: String) {
        self.ecrId = ecrId
    }

    public func configure(requestId: String) {
        self.requestId = requestId
    }

    public func configure(params: [HpsUpaGetParamRequestParam]) {
        self.params = params
    }

    public func configure(password: String?) {
        self.password = password
    }

    public func execute(completion: @escaping Handler) {
        guard let (device, request) = buildRequest(),
              let data = try? JSONEncoder().encode(request),
              let packet = String(data: data, encoding: .utf8) else {
            completion(.failure(HpsUpaGetParamBuilderError.invalidRequest))
            return
        }
        device.processTransaction(withJSONString: packet) { response, responseJSON, error in
            if let error = error {
                completion(.failure(error))
            } else if let data = responseJSON?.data(using: .utf8),
                      let response = try? JSONDecoder().decode(HpsUpaGetParamResponse.self, from: data) {
                completion(.success(response))
            } else {
                completion(.failure(HpsUpaGetParamBuilderError.invalidResponse(responseJSON)))
            }
        }
    }

    private func buildRequest() -> (HpsUpaDevice, HpsUpaGetParamRequest)? {
        guard let device = device else {
            return nil
        }
        let request = HpsUpaGetParamRequest(
            data: .init(
                command: "GetParam",
                ecrId: ecrId,
                requestId: requestId,
                data: .init(
                    password: password,
                    params: .init(
                        configuration: params
                    )
                )
            )
        )
        reset()
        return (device, request)
    }

    private func reset() {
        device = nil
        ecrId = .init()
        requestId = .init()
        params = .init()
        password = nil
    }
}
