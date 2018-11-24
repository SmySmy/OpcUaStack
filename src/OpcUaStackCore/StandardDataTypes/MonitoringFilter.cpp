/*
    DataTypeClass: MonitoringFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoringFilter.h"

namespace OpcUaStackCore
{
    
    MonitoringFilter::MonitoringFilter(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    MonitoringFilter::~MonitoringFilter(void)
    {
    }
    
    bool
    MonitoringFilter::operator==(const MonitoringFilter& value)
    {
        MonitoringFilter* dst = const_cast<MonitoringFilter*>(&value);
        return true;
    }
    
    bool
    MonitoringFilter::operator!=(const MonitoringFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoringFilter::copyTo(MonitoringFilter& value)
    {
    }
    
    MonitoringFilter&
    MonitoringFilter::operator=(const MonitoringFilter& value)
    {
        const_cast<MonitoringFilter*>(&value)->copyTo(*this);
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
    MonitoringFilter::factory(void)
    {
    	return constructSPtr<MonitoringFilter>();
    }
    
    std::string
    MonitoringFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoringFilter::typeName(void)
    {
    	return "MonitoringFilter";
    }
    
    OpcUaNodeId
    MonitoringFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)719,0);
    }
    
    OpcUaNodeId
    MonitoringFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)721, 0);
    }
    
    OpcUaNodeId
    MonitoringFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)720, 0);
    }
    
    OpcUaNodeId
    MonitoringFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15293, 0);
    }
    
    void
    MonitoringFilter::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    MonitoringFilter::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    MonitoringFilter::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    MonitoringFilter::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    MonitoringFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoringFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    MonitoringFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoringFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    MonitoringFilter::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    MonitoringFilter::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    MonitoringFilter::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    MonitoringFilter::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    MonitoringFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoringFilter* dst = dynamic_cast<MonitoringFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoringFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoringFilter* dst = dynamic_cast<MonitoringFilter*>(&extensionObjectBase);
    	return *const_cast<MonitoringFilter*>(this) == *dst;
    }
    
    void
    MonitoringFilter::out(std::ostream& os)
    {
    }

}