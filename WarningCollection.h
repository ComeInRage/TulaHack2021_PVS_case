#pragma once

#include "Warning.h"
#include <utility>

namespace rc {

	struct Changes;

	class Warning_Collection : public std::vector<rc::Warning> {

	public:

		using base_type = std::vector<rc::Warning>;

	public:

		using base_type::vector;
		using base_type::operator=;

		Warning_Collection(const nlohmann::json& json);
		Warning_Collection(nlohmann::json&& json) noexcept;

		Changes compare_changes(const rc::Warning_Collection& standard) const;

	};

	struct Changes {

		using changed_type = std::vector<std::pair<rc::Warning, rc::Warning>>;

		rc::Warning_Collection extra_warnings;
		rc::Warning_Collection absent_warnings;
		changed_type changed_warnings;

	};
	
	rc::Changes compare_changes(const rc::Warning_Collection& collection, const rc::Warning_Collection& standard);

}