#include <cstdio>
#include <cstdlib>
#include <string>

#include <readline/readline.h>
#include <readline/history.h>

#include <grpcpp/grpcpp.h>

#include "flare.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using flare::FlareRequest;
using flare::FlareReply;
using flare::Flare;

class FlareClient {
public:
  explicit FlareClient(const std::shared_ptr<Channel> &channel)
      : stub_(Flare::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string Execute(const std::string &sql) {
    // Data we are sending to the server.
    FlareRequest request;
    request.set_sql(sql);

    // Container for the data we expect from the server.
    FlareReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->Execute(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.result();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

private:
  std::unique_ptr<Flare::Stub> stub_;
};

int main(int argc, char **argv) {
  FlareClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

  char *buf;
  while ((buf = readline("flare> ")) != nullptr) {
    if (strlen(buf) > 0) {
      add_history(buf);
    }

    std::string sql(buf);
    std::string result = client.Execute(sql);
    std::cout << result << std::endl;

    free(buf);
  }

  return 0;
}
