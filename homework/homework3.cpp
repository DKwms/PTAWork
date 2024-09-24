//
// Created by ROG on 2024/9/24.
//

#include "homework3.h"

void homework3::manaTest()
{
    MultilineLidar multiline_lidar;
    auto chassis = std::make_shared<Chassis>();
    multiline_lidar.subscribe("toChassis",chassis);
    multiline_lidar.publish("toChassis",1);
    multiline_lidar.publish("toChassis",2);
}