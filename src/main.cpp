#include "spdlog/spdlog.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include <memory>

void setupLogging(std::string logFile) {
    auto console_sink = std::make_shared<spdlog::sinks::ansicolor_stderr_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logFile, 5000000, 5, true);

#ifdef NDEBUG
    console_sink->set_level(spdlog::level::warn);
    file_sink->set_level(spdlog::level::info);
#else
    console_sink->set_level(spdlog::level::debug);
    file_sink->set_level(spdlog::level::trace);
#endif

    std::vector<spdlog::sink_ptr> sinks(2);
    sinks[0] = console_sink;
    sinks[1] = file_sink;

    auto logger = std::make_shared<spdlog::logger>("", begin(sinks), end(sinks));
    spdlog::set_default_logger(logger);
}

int main(int argc, char** argv) {
    setupLogging("logs/main");

    spdlog::info("Hello, World!");

    return 0;
}
