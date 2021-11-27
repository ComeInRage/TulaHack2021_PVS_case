#pragma once

#include "JSONObject.h"

namespace rc {

	class Warning : public rc::JSONObject {

	private:

		rc::JSONObject m_navigation{};

	public:

		using rc::JSONObject::JSONObject;

		Warning(const rc::JSONObject& obj);
		Warning(rc::JSONObject&& obj);
		Warning(const nlohmann::json& obj);
		Warning(nlohmann::json&& obj);

		Warning& operator=(const rc::JSONObject& obj);
		Warning& operator=(rc::JSONObject&& obj);
		Warning& operator=(const nlohmann::json& obj);
		Warning& operator=(nlohmann::json&& obj);

		bool is_same(const Warning& warning) const noexcept;
		bool same_position(const Warning& warning) const noexcept;

	};

}

bool operator==(const rc::Warning& warning1, const rc::Warning& warning2) noexcept;