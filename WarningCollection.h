#pragma once

#include "Warning.h"
#include <utility>

namespace rc {

	class Warning_Collection : public std::vector<rc::Warning> {

	public:

		using base_type = std::vector<rc::Warning>;
		using report_type = std::pair<rc::Warning_Collection, rc::Warning_Collection>;

	public:

		using base_type::vector;
		using base_type::operator=;

		Warning_Collection(const nlohmann::json& json);
		Warning_Collection(nlohmann::json&& json) noexcept;

		report_type extra_and_absent(const rc::Warning_Collection& standard) const;

	};

	rc::Warning_Collection::report_type extra_and_absent(const rc::Warning_Collection& collection, const rc::Warning_Collection& standard);

}