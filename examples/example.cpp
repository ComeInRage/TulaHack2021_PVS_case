#include <iostream>
#include <fstream>

#include <WarningCollection.h>

#include <json.hpp>

namespace js = nlohmann;

int main() {

	std::ifstream stream("report.json");
	std::ifstream stream2("report_new.json");
	rc::Warning_Collection standard( js::json::parse(stream)["warnings"] );
	rc::Warning_Collection warns( js::json::parse(stream2)["warnings"] );

	auto changes = warns.compare_changes(standard);

	std::cout << "Extra:" << std::endl;
	for (const auto& warning : changes.extra_warnings) {

		auto has_code = warning.at_key("code").get<std::string>();
		auto has_line_number = warning.at_key("positions").at_key(0).at_key("line").get<int>();
		auto has_file_path = warning.at_key("positions").at_key(0).at_key("file").get<std::string>();
		std::cout << "[" << (has_code ? *has_code : "null") << "] line "
				  << (has_line_number ? *has_line_number : -1) << ": "
				  << (has_file_path ? *has_file_path : "null_path") << std::endl;

	}

	std::cout << "Absent:" << std::endl;
	for (const auto& warning : changes.absent_warnings) {

		auto has_code = warning.at_key("code").get<std::string>();
		auto has_line_number = warning.at_key("positions").at_key(0).at_key("line").get<int>();
		auto has_file_path = warning.at_key("positions").at_key(0).at_key("file").get<std::string>();
		std::cout << "[" << (has_code ? *has_code : "null") << "] line "
			<< (has_line_number ? *has_line_number : -1) << ": "
			<< (has_file_path ? *has_file_path : "null_path") << std::endl;

	}

	std::cout << "Changed:" << std::endl;
	for (const auto& warning_pair : changes.changed_warnings) {

		auto extra_has_code = warning_pair.first.at_key("code").get<std::string>();
		auto absent_has_code = warning_pair.second.at_key("code").get<std::string>();

		auto extra_has_msg = warning_pair.first.at_key("message").get<std::string>();
		auto absent_has_msg = warning_pair.second.at_key("message").get<std::string>();

		auto extra_has_file_path = warning_pair.first.at_key("positions").at_key(0).at_key("file").get<std::string>();
		auto absent_has_file_path = warning_pair.second.at_key("positions").at_key(0).at_key("file").get<std::string>();

		auto extra_has_line_number = warning_pair.first.at_key("positions").at_key(0).at_key("line").get<int>();
		auto absent_has_line_number = warning_pair.second.at_key("positions").at_key(0).at_key("line").get<int>();

		std::cout << "Was: [" << (absent_has_code ? *absent_has_code : "null") << "] line " << (absent_has_line_number ? *absent_has_line_number : -1) 
				  << ": " << (absent_has_msg ? *absent_has_msg : "null") << "\n"
				  << "Path: " << (absent_has_file_path ? *absent_has_file_path : "null_path") << "\n"
				  << "Now: [" << (extra_has_code ? *extra_has_code : "null") << "] line " << (extra_has_line_number ? *extra_has_line_number : -1) 
				  << ": " << (extra_has_msg ? *extra_has_msg : "null") << "\n"
				  << "Path: " << (extra_has_file_path ? *extra_has_file_path : "null_path") << std::endl;

	}

	system("pause");
	return 0;

}