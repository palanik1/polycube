/**
* ctxwriter API generated from ctxwriter.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* CtxwriterJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "PortsJsonObject.h"
#include <vector>
#include "polycube/services/cube.h"

namespace polycube {
namespace service {
namespace model {

enum class CtxwriterActionEnum {
  READ, WRITE
};

/// <summary>
///
/// </summary>
class  CtxwriterJsonObject : public JsonObjectBase {
public:
  CtxwriterJsonObject();
  CtxwriterJsonObject(const nlohmann::json &json);
  ~CtxwriterJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// Name of the ctxwriter service
  /// </summary>
  std::string getName() const;
  void setName(std::string value);
  bool nameIsSet() const;

  /// <summary>
  /// Action performed on the received packet (i.e.,READ, WRITE headers: READ)
  /// </summary>
  CtxwriterActionEnum getAction() const;
  void setAction(CtxwriterActionEnum value);
  bool actionIsSet() const;
  void unsetAction();
  static std::string CtxwriterActionEnum_to_string(const CtxwriterActionEnum &value);
  static CtxwriterActionEnum string_to_CtxwriterActionEnum(const std::string &str);

  /// <summary>
  /// Entry of the ports table
  /// </summary>
  const std::vector<PortsJsonObject>& getPorts() const;
  void addPorts(PortsJsonObject value);
  bool portsIsSet() const;
  void unsetPorts();

private:
  std::string m_name;
  bool m_nameIsSet;
  CtxwriterActionEnum m_action;
  bool m_actionIsSet;
  std::vector<PortsJsonObject> m_ports;
  bool m_portsIsSet;
};

}
}
}

