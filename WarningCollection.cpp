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

rc::Changes rc::Warning_Collection::compare_changes(const rc::Warning_Collection& standard) const {

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

	rc::Changes::changed_type changed_warnings;

	for (auto extra_warning_it = extra_warnings.begin(); extra_warning_it != extra_warnings.end();) {

		const rc::Warning& extra_warning = *extra_warning_it;

		auto coincidence = std::find_if(absent_warnings.begin(), absent_warnings.end(), [&](const rc::Warning& absent_warning) {
			return extra_warning.same_position(absent_warning);
		});

		if (coincidence != absent_warnings.end()) {

			changed_warnings.push_back({ extra_warning, *coincidence });
			absent_warnings.erase(coincidence);
			extra_warning_it = extra_warnings.erase(extra_warning_it);

		}
		else {
			++extra_warning_it;
		}

	}

	return { extra_warnings, absent_warnings, changed_warnings };

}

rc::Changes rc::compare_changes(const rc::Warning_Collection& collection, const rc::Warning_Collection& standard) {

	return collection.compare_changes(standard);

}