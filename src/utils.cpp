//
// Created by KorshunK on 03.05.2024.
//

#include "utils.h"

bool Utils::getModSettingsBoolValue(std::string path) {
    return geode::prelude::Mod::get()->getSettingValue<bool>(path);
}