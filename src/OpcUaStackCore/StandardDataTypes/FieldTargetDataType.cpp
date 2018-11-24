/*
    DataTypeClass: FieldTargetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/FieldTargetDataType.h"

namespace OpcUaStackCore
{
    
    FieldTargetDataType::FieldTargetDataType(void)
    : Object()
    , ExtensionObjectBase()
    , dataSetFieldId_()
    , receiverIndexRange_()
    , targetNodeId_()
    , attributeId_()
    , writeIndexRange_()
    , overrideValueHandling_()
    , overrideValue_()
    {
    }
    
    FieldTargetDataType::~FieldTargetDataType(void)
    {
    }
    
    OpcUaGuid&
    FieldTargetDataType::dataSetFieldId(void)
    {
        return dataSetFieldId_;
    }
    
    OpcUaNumericRange&
    FieldTargetDataType::receiverIndexRange(void)
    {
        return receiverIndexRange_;
    }
    
    OpcUaNodeId&
    FieldTargetDataType::targetNodeId(void)
    {
        return targetNodeId_;
    }
    
    OpcUaIntegerId&
    FieldTargetDataType::attributeId(void)
    {
        return attributeId_;
    }
    
    OpcUaNumericRange&
    FieldTargetDataType::writeIndexRange(void)
    {
        return writeIndexRange_;
    }
    
    OverrideValueHandling&
    FieldTargetDataType::overrideValueHandling(void)
    {
        return overrideValueHandling_;
    }
    
    OpcUaVariant&
    FieldTargetDataType::overrideValue(void)
    {
        return overrideValue_;
    }
    
    bool
    FieldTargetDataType::operator==(const FieldTargetDataType& value)
    {
        FieldTargetDataType* dst = const_cast<FieldTargetDataType*>(&value);
        if (dataSetFieldId_ != dst->dataSetFieldId()) return false;
        if (receiverIndexRange_ != dst->receiverIndexRange()) return false;
        if (targetNodeId_ != dst->targetNodeId()) return false;
        if (attributeId_ != dst->attributeId()) return false;
        if (writeIndexRange_ != dst->writeIndexRange()) return false;
        if (overrideValueHandling_ != dst->overrideValueHandling()) return false;
        if (overrideValue_ != dst->overrideValue()) return false;
        return true;
    }
    
    bool
    FieldTargetDataType::operator!=(const FieldTargetDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    FieldTargetDataType::copyTo(FieldTargetDataType& value)
    {
        dataSetFieldId_.copyTo(value.dataSetFieldId());
        receiverIndexRange_.copyTo(value.receiverIndexRange());
        targetNodeId_.copyTo(value.targetNodeId());
        value.attributeId_ = attributeId_;
        writeIndexRange_.copyTo(value.writeIndexRange());
        overrideValueHandling_.copyTo(value.overrideValueHandling());
        overrideValue_.copyTo(value.overrideValue());
    }
    
    FieldTargetDataType&
    FieldTargetDataType::operator=(const FieldTargetDataType& value)
    {
        const_cast<FieldTargetDataType*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    FieldTargetDataType::factory(void)
    {
    	return constructSPtr<FieldTargetDataType>();
    }
    
    std::string
    FieldTargetDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    FieldTargetDataType::typeName(void)
    {
    	return "FieldTargetDataType";
    }
    
    OpcUaNodeId
    FieldTargetDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14744,0);
    }
    
    OpcUaNodeId
    FieldTargetDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14848, 0);
    }
    
    OpcUaNodeId
    FieldTargetDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14804, 0);
    }
    
    OpcUaNodeId
    FieldTargetDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15061, 0);
    }
    
    void
    FieldTargetDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        dataSetFieldId_.opcUaBinaryEncode(os);
        receiverIndexRange_.opcUaBinaryEncode(os);
        targetNodeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,attributeId_);
        writeIndexRange_.opcUaBinaryEncode(os);
        overrideValueHandling_.opcUaBinaryEncode(os);
        overrideValue_.opcUaBinaryEncode(os);
    }
    
    void
    FieldTargetDataType::opcUaBinaryDecode(std::istream& is)
    {
        dataSetFieldId_.opcUaBinaryDecode(is);
        receiverIndexRange_.opcUaBinaryDecode(is);
        targetNodeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,attributeId_);
        writeIndexRange_.opcUaBinaryDecode(is);
        overrideValueHandling_.opcUaBinaryDecode(is);
        overrideValue_.opcUaBinaryDecode(is);
    }
    
    bool
    FieldTargetDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    FieldTargetDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    FieldTargetDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    FieldTargetDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!dataSetFieldId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataSetFieldId", elementTree));
    
        elementTree.clear();
        if (!receiverIndexRange_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ReceiverIndexRange", elementTree));
    
        elementTree.clear();
        if (!targetNodeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_)) return false;
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!writeIndexRange_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("WriteIndexRange", elementTree));
    
        elementTree.clear();
        if (!overrideValueHandling_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("OverrideValueHandling", elementTree));
    
        elementTree.clear();
        if (!overrideValue_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("OverrideValue", elementTree));
    
        return true;
    }
    
    bool
    FieldTargetDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FieldTargetDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("DataSetFieldId");
        if (!tree) return false;
        if (!dataSetFieldId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ReceiverIndexRange");
        if (!tree) return false;
        if (!receiverIndexRange_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TargetNodeId");
        if (!tree) return false;
        if (!targetNodeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AttributeId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) return false;
    
        tree = pt.get_child_optional("WriteIndexRange");
        if (!tree) return false;
        if (!writeIndexRange_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("OverrideValueHandling");
        if (!tree) return false;
        if (!overrideValueHandling_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("OverrideValue");
        if (!tree) return false;
        if (!overrideValue_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    FieldTargetDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    FieldTargetDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    FieldTargetDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    FieldTargetDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    FieldTargetDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	FieldTargetDataType* dst = dynamic_cast<FieldTargetDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    FieldTargetDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	FieldTargetDataType* dst = dynamic_cast<FieldTargetDataType*>(&extensionObjectBase);
    	return *const_cast<FieldTargetDataType*>(this) == *dst;
    }
    
    void
    FieldTargetDataType::out(std::ostream& os)
    {
        os << "DataSetFieldId="; dataSetFieldId_.out(os);
        os << ", ReceiverIndexRange="; receiverIndexRange_.out(os);
        os << ", TargetNodeId="; targetNodeId_.out(os);
        os << ", AttributeId=" << attributeId_;
        os << ", WriteIndexRange="; writeIndexRange_.out(os);
        os << ", OverrideValueHandling="; overrideValueHandling_.out(os);
        os << ", OverrideValue="; overrideValue_.out(os);
    }

}