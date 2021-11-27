#include "Warning.h"

rc::Warning::Warning(const rc::JSONObject& obj) 
	: JSONObject(obj), m_navigation(this->at_key("positions").at_key(0).at_key("navigation")) {}

rc::Warning::Warning(rc::JSONObject&& obj)
	: JSONObject(std::move(obj)), m_navigation(this->at_key("positions").at_key(0).at_key("navigation")) {}

rc::Warning::Warning(const nlohmann::json& json)
	: JSONObject(json), m_navigation(this->at_key("positions").at_key(0).at_key("navigation")) {}

rc::Warning::Warning(nlohmann::json&& json)
	: JSONObject(std::move(json)), m_navigation(this->at_key("positions").at_key(0).at_key("navigation")) {}

rc::Warning& rc::Warning::operator=(const rc::JSONObject& obj) {

	this->set_json(obj.get_json());
	this->m_navigation = this->at_key("positions").at_key(0).at_key("navigation");
	return *this;

}
rc::Warning& rc::Warning::operator=(rc::JSONObject&& obj) {

	this->set_json(obj.get_json());
	this->m_navigation = this->at_key("positions").at_key(0).at_key("navigation");
	return *this;

}

rc::Warning& rc::Warning::operator=(const nlohmann::json& json) {

	this->set_json(json);
	this->m_navigation = this->at_key("positions").at_key(0).at_key("navigation");
	return *this;

}
rc::Warning& rc::Warning::operator=(nlohmann::json&& json) {

	this->set_json(json);
	this->m_navigation = this->at_key("positions").at_key(0).at_key("navigation");
	return *this;

}

bool rc::Warning::is_same (const rc::Warning& warning) const noexcept {

	return (this->get_json() == warning.get_json());

}

bool rc::Warning::same_position(const rc::Warning& warning) const noexcept {

	return (this->m_navigation == warning.m_navigation);

}

bool operator==(const rc::Warning& warning1, const rc::Warning& warning2) noexcept {

	return (warning1.is_same(warning2));

}