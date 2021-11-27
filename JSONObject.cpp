#include "JSONObject.h"

rc::JSONObject::JSONObject(const nlohmann::json& json)
	: m_json(json) {}

rc::JSONObject::JSONObject(nlohmann::json&& json) noexcept
	: m_json(std::move(json)) {}

rc::JSONObject& rc::JSONObject::operator=(const nlohmann::json& json) {

	this->m_json = json;
	return *this;

}

rc::JSONObject& rc::JSONObject::operator=(nlohmann::json&& json) {

	this->m_json = std::move(json);
	return *this;

}

bool rc::JSONObject::operator==(const JSONObject& obj) const noexcept {

	return (this->m_json == obj.m_json);

}

bool rc::JSONObject::operator==(const nlohmann::json& json) const noexcept {

	return (this->m_json == json);

}

const nlohmann::json& rc::JSONObject::get_json() const noexcept {

	return this->m_json;

}

nlohmann::json& rc::JSONObject::get_json() noexcept {

	return this->m_json;

}

void rc::JSONObject::set_json(const nlohmann::json& json) noexcept {

	this->m_json = json;

}