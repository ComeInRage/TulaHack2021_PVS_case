#pragma once

#include "JSONObject.h"

namespace rc {

	class Warning : public rc::JSONObject {

	private:

		rc::JSONObject m_navigation{};

	public:

		Warning() = default;
		Warning(const Warning&) = default;
		Warning(Warning&&) = default;
		Warning& operator=(const Warning&) = default;
		Warning& operator=(Warning&&) = default;
		~Warning() = default;

		Warning(const rc::JSONObject& obj);
		Warning(rc::JSONObject&& obj);
		Warning(const nlohmann::json& obj);
		Warning(nlohmann::json&& obj);

		Warning& operator=(const rc::JSONObject& obj);
		Warning& operator=(rc::JSONObject&& obj);
		Warning& operator=(const nlohmann::json& obj);
		Warning& operator=(nlohmann::json&& obj);

		bool operator==(const rc::Warning& warning) const noexcept;

	};

}