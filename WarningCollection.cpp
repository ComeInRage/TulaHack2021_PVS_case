#include "WarningCollection.h"

rc::Warning_Collection::Warning_Collection(const nlohmann::json& json) : base_type() {

	if (json.is_array()) {
		this->reserve(json.size());
		this->assign(json.begin(), json.end());
	}

}

rc::Warning_Collection::Warning_Collection(nlohmann::json&& json) noexcept : base_type() {

	if (json.is_array()) {
		(*this) = std::move(json.get<base_type>());
	}

}

rc::Warning_Collection::report_type rc::Warning_Collection::extra_and_absent(const rc::Warning_Collection& standard) const {

	rc::Warning_Collection extra_warnings{};
	rc::Warning_Collection absent_warnings = standard;

	for (const rc::Warning& warning : *this) {

		auto coincidence = std::find(absent_warnings.begin(), absent_warnings.end(), warning);

		if (coincidence != absent_warnings.end()) {

			absent_warnings.erase(coincidence);

		}
		else {

			extra_warnings.push_back(warning);
		}

	}

	return { extra_warnings, absent_warnings };

}