/**
* ctxwriter API generated from ctxwriter.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


// TODO: Modify these methods with your own implementation


#include "Ctxwriter.h"
#include "Ctxwriter_dp.h"
#include<cstddef>


Ctxwriter::Ctxwriter(const std::string name, const CtxwriterJsonObject &conf)
  : Cube(conf.getBase(), { ctxwriter_code }, {}),
    CtxwriterBase(name) {
  logger()->info("Creating Ctxwriter instance");
  setAction(conf.getAction());
  addPortsList(conf.getPorts());
}


Ctxwriter::~Ctxwriter() {
  logger()->info("Destroying Ctxwriter instance");
}

void Ctxwriter::packet_in(Ports &port,
    polycube::service::PacketInMetadata &md,
    const std::vector<uint8_t> &packet) {
  logger()->debug("Packet received from port {0}", port.name());
}

CtxwriterActionEnum Ctxwriter::getAction() {
  uint8_t value = get_array_table<uint8_t>("action_map").get(0x0);
  return static_cast<CtxwriterActionEnum>(value);
  //throw std::runtime_error("getAction Not Impelemented");
}

void Ctxwriter::setAction(const CtxwriterActionEnum &value) {
  uint8_t action = static_cast<uint8_t>(value);
  get_array_table<uint8_t>("action_map").set(0x0, action);
  //throw std::runtime_error("setAction Not Impelemented");
  
}

// Basic default implementation, place your extension here (if needed)
std::shared_ptr<Ports> Ctxwriter::getPorts(const std::string &name) {
  // call default implementation in base class
  return CtxwriterBase::getPorts(name);
}

// Basic default implementation, place your extension here (if needed)
std::vector<std::shared_ptr<Ports>> Ctxwriter::getPortsList() {
  // call default implementation in base class
  return CtxwriterBase::getPortsList();
}

// Basic default implementation, place your extension here (if needed)
void Ctxwriter::addPorts(const std::string &name, const PortsJsonObject &conf) {
  //CtxwriterBase::addPorts(name, conf);
  if (get_ports().size() == 2) {
    throw std::runtime_error("maximum number of ports reached");
  }

  add_port<PortsJsonObject>(name, conf);
  logger()->info("port {0} was connected", name);
  update_ports_map();

}

// Basic default implementation, place your extension here (if needed)
void Ctxwriter::addPortsList(const std::vector<PortsJsonObject> &conf) {
  // call default implementation in base class
  CtxwriterBase::addPortsList(conf);
}

// Basic default implementation, place your extension here (if needed)
void Ctxwriter::replacePorts(const std::string &name, const PortsJsonObject &conf) {
  // call default implementation in base class
  CtxwriterBase::replacePorts(name, conf);
}

// Basic default implementation, place your extension here (if needed)
void Ctxwriter::delPorts(const std::string &name) {
  // call default implementation in base class
  //CtxwriterBase::delPorts(name);
  remove_port(name);
  logger()->info("port {0} was removed", name);
  update_ports_map();
}

// Basic default implementation, place your extension here (if needed)
void Ctxwriter::delPortsList() {
  // call default implementation in base class
  CtxwriterBase::delPortsList();
}


void Ctxwriter::update_ports_map() {
  auto ports_table = get_array_table<uint16_t>("ports_map");
  auto ports = get_ports();
  uint32_t i = 0;

  for (auto &port: ports) {
    ports_table.set(i, port->index());
    i++;
  }

  // mark other ports as empty (UINT16_MAX means empty)
  while (i < 2) {
    ports_table.set(i, UINT16_MAX);
    i++;
  }
}
