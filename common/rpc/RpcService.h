/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * RpcService.h
 * Interface for the RpcService.
 * Copyright (C) 2013 Simon Newton
 *
 * All Services generated by ola_protoc inherit from this one.
 */

#ifndef COMMON_RPC_RPCSERVICE_H_
#define COMMON_RPC_RPCSERVICE_H_

#include <google/protobuf/service.h>
#include <string>
#include "ola/Callback.h"

namespace ola {
namespace rpc {

class RpcController;

class RpcService {
  public:
    typedef SingleUseCallback0<void> CompletionCallback;

    RpcService() {}
    virtual ~RpcService() {}

    // Return the descriptor for this service.
    virtual const google::protobuf::ServiceDescriptor* GetDescriptor() = 0;

    // Invoke a method.
    virtual void CallMethod(const google::protobuf::MethodDescriptor *method,
                            RpcController *controller,
                            const google::protobuf::Message *request,
                            google::protobuf::Message *response,
                            CompletionCallback *done) = 0;

    virtual const google::protobuf::Message& GetRequestPrototype(
        const google::protobuf::MethodDescriptor *method) const = 0;
    virtual const google::protobuf::Message& GetResponsePrototype(
        const google::protobuf::MethodDescriptor *method) const = 0;
};
}  // namespace rpc
}  // namespace ola
#endif  // COMMON_RPC_RPCSERVICE_H_
