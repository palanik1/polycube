/**
* mapwriter API generated from mapwriter.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "PortsBase.h"
#include "../Mapwriter.h"

PortsBase::PortsBase(polycube::service::Cube<Ports> &parent,
    std::shared_ptr<polycube::service::PortIface> port)
    : Port(port), parent_(dynamic_cast<Mapwriter &>(parent)) {}


PortsBase::~PortsBase() {}

void PortsBase::update(const PortsJsonObject &conf) {
  set_conf(conf.getBase());

}

PortsJsonObject PortsBase::toJsonObject() {
  PortsJsonObject conf;
  conf.setBase(to_json());

  conf.setName(getName());

  return conf;
}

std::shared_ptr<spdlog::logger> PortsBase::logger() {
  return parent_.logger();
}

