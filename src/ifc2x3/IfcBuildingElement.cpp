// IFC SDK : IFC2X3 C++ Early Classes  
// Copyright (C) 2009 CSTB
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full license is in Licence.txt file included with this 
// distribution or is available at :
//     http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

#ifdef ENABLE_MSVC_PRECOMPILED_HEADER
#include "../precompiled.h"
#else

#include "ifc2x3/IfcBuildingElement.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcElement.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>

#endif
#include <string>

using namespace ifc2x3;

IfcBuildingElement::IfcBuildingElement(Step::Id id, Step::SPFData *args) : IfcElement(id, args) {
}

IfcBuildingElement::~IfcBuildingElement() {
}

bool IfcBuildingElement::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcBuildingElement(this);
}

const std::string &IfcBuildingElement::type() const {
    return IfcBuildingElement::s_type.getName();
}

const Step::ClassType &IfcBuildingElement::getClassType() {
    return IfcBuildingElement::s_type;
}

const Step::ClassType &IfcBuildingElement::getType() const {
    return IfcBuildingElement::s_type;
}

bool IfcBuildingElement::isOfType(const Step::ClassType &t) const {
    return IfcBuildingElement::s_type == t ? true : IfcElement::isOfType(t);
}

bool IfcBuildingElement::init() {
    bool status = IfcElement::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcBuildingElement::copy(const IfcBuildingElement &obj, const CopyOp &copyop) {
    IfcElement::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcBuildingElement::s_type("IfcBuildingElement");
