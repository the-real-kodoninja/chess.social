#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>

class ChessApp : public cppcms::application {
public:
    ChessApp(cppcms::service &srv) : cppcms::application(srv) {}

    virtual void main(std::string url) {
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
        cppcms::service srv(argc, argv);
        srv.applications_pool().mount(
            cppcms::create_pool<ChessApp>()
        );
        srv.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
