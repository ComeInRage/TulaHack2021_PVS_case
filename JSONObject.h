#pragma once

#include "json.hpp"
#include <optional>
#include <iostream>

namespace rc {

	struct JSONObject {

	private:

		nlohmann::json m_json{};

	public:

		JSONObject() = default;
		JSONObject(const JSONObject&) = default;
		JSONObject(JSONObject&&) = default;
		JSONObject& operator=(const JSONObject&) = default;
		JSONObject& operator=(JSONObject&&) = default;
		~JSONObject() = default;

		JSONObject(const nlohmann::json& json);
		JSONObject(nlohmann::json&& json) noexcept;

		JSONObject& operator=(const nlohmann::json& json);
		JSONObject& operator=(nlohmann::json&& json);

		bool operator==(const JSONObject& obj) const noexcept;
		bool operator==(const nlohmann::json& json) const noexcept;

		const nlohmann::json& get_json() const noexcept;
		nlohmann::json& get_json() noexcept;
		void set_json(const nlohmann::json& json) noexcept;

		template<typename keyT = std::string>
		JSONObject at_key(const keyT& key) const noexcept {

			try {

				return this->m_json.at(key);

			}
			catch (const nlohmann::json::exception& ex) {

				std::cout << "[EXCEPTION] at_key(): " << ex.what() << std::endl;
				return {};

			}

		}

		template<typename T = std::string>
		std::optional<T> get() const {

			try {

				return this->m_json.get<T>();

			}
			catch (const nlohmann::json::exception& ex) {

				std::cout << "[EXCEPTION] at_key(): " << ex.what() << std::endl;
				return std::nullopt;

			}

		}

	};

}