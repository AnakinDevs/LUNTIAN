#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

namespace {
void require(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}
}

int main() {
    std::ifstream schemaFile("shared/protocol/schema.json");
    if (!schemaFile) {
        schemaFile.open("../shared/protocol/schema.json");
    }
    require(static_cast<bool>(schemaFile), "could not open shared/protocol/schema.json");

    const std::string schema{
        std::istreambuf_iterator<char>(schemaFile),
        std::istreambuf_iterator<char>()
    };

    require(schema.find(R"("schema_version")") != std::string::npos,
            "schema_version property exists");
    require(schema.find(R"("const": 1)") != std::string::npos,
            "schema version is one");

    const std::string requiredFields[] = {
        R"("event_id")", R"("device_id")", R"("event_type")",
        R"("timestamp")", R"("payload")"
    };
    for (const auto& field : requiredFields) {
        require(schema.find(field) != std::string::npos,
                "required event field exists: " + field);
    }

    const std::string workflowEvents[] = {
        R"("bin.telemetry")", R"("leanbot.mission")",
        R"("vision.detection")", R"("process.status")"
    };
    for (const auto& event : workflowEvents) {
        require(schema.find(event) != std::string::npos,
                "workflow event exists: " + event);
    }

    std::cout << "All LUNTIAN C++ protocol contract checks passed.\n";
    return EXIT_SUCCESS;
}
