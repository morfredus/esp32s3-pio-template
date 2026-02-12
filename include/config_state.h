#pragma once
#include <string>

class ConfigState {
public:
    static ConfigState& instance() {
        static ConfigState inst;
        return inst;
    }

    const std::string& ip() const { return ipAddress; }
    void setIp(const std::string& ip) { ipAddress = ip; }

    const std::string& ssid() const { return connectedSsid; }
    void setSsid(const std::string& s) { connectedSsid = s; }

private:
    ConfigState() = default;

    std::string ipAddress;
    std::string connectedSsid;
};
