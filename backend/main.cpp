#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

class ChessApp : public cppcms::application {
public:
    ChessApp(cppcms::service &srv) : cppcms::application(srv) {
        std::cout << "ChessApp constructor called" << std::endl;
    }
    virtual void main(std::string url) {
        std::cout << "Handling request for URL: " << url << std::endl;
        if (url == "/register") {
            response().out() << "User registered (placeholder)";
        } else if (url == "/bet") {
            response().out() << "Bet placed (placeholder)";
        } else {
            response().out() << "Welcome to chess.social backend!";
        }
    }
};

int main(int argc, char **argv) {
    try {
        std::cout << "Starting service with " << argc << " args" << std::endl;
        // Initialize service with command line arguments
        cppcms::service srv(argc, argv);
        std::cout << "Service initialized, mounting app..." << std::endl;
        srv.applications_pool().mount(cppcms::create_pool<ChessApp>());
        std::cout << "Starting server on port 8080..." << std::endl;
        srv.run();
        std::cout << "Server stopped." << std::endl;
    } catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}