/*
    DataTypeClass: MonitoringFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoringFilterResult.h"

namespace OpcUaStackCore
{
    
    MonitoringFilterResult::MonitoringFilterResult(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    MonitoringFilterResult::~MonitoringFilterResult(void)
    {
    }
    
    bool
    MonitoringFilterResult::operator==(const MonitoringFilterResult& value)
    {
        MonitoringFilterResult* dst = const_cast<MonitoringFilterResult*>(&value);
        return true;
    }
    
    bool
    MonitoringFilterResult::operator!=(const MonitoringFilterResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoringFilterResult::copyTo(MonitoringFilterResult& value)
    {
    }
    
    MonitoringFilterResult&
    MonitoringFilterResult::operator=(const MonitoringFilterResult& value)
    {
        const_cast<MonitoringFilterResult*>(&value)->copyTo(*this);
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
    MonitoringFilterResult::factory(void)
    {
    	return constructSPtr<MonitoringFilterResult>();
    }
    
    std::string
    MonitoringFilterResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoringFilterResult::typeName(void)
    {
    	return "MonitoringFilterResult";
    }
    
    OpcUaNodeId
    MonitoringFilterResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)731,0);
    }
    
    OpcUaNodeId
    MonitoringFilterResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)733, 0);
    }
    
    OpcUaNodeId
    MonitoringFilterResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)732, 0);
    }
    
    OpcUaNodeId
    MonitoringFilterResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15313, 0);
    }
    
    void
    MonitoringFilterResult::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    MonitoringFilterResult::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    MonitoringFilterResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    MonitoringFilterResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    MonitoringFilterResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoringFilterResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    MonitoringFilterResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoringFilterResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    MonitoringFilterResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    MonitoringFilterResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    MonitoringFilterResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    MonitoringFilterResult::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    MonitoringFilterResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoringFilterResult* dst = dynamic_cast<MonitoringFilterResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoringFilterResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoringFilterResult* dst = dynamic_cast<MonitoringFilterResult*>(&extensionObjectBase);
    	return *const_cast<MonitoringFilterResult*>(this) == *dst;
    }
    
    void
    MonitoringFilterResult::out(std::ostream& os)
    {
    }

}