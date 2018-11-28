#include "unittest.h"

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(NodesetXml_)

BOOST_AUTO_TEST_CASE(NodesetXml_)
{
	std::cout << "NodesetXml_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodesetXml_clear)
{
	NodeSetNamespace nodeSetNamespace;

	nodeSetNamespace.clear();
	nodeSetNamespace.clearGlobal();
}

BOOST_AUTO_TEST_CASE(NodesetXml_decode_encode_decode)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;

	configXml.clear();
    success = configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml");
    BOOST_REQUIRE(success == true);

    NodeSetXmlParser nodeSetXmlParser;
    success = nodeSetXmlParser.decode(configXml.ptree());
    BOOST_REQUIRE(success == true);

	configXml.clear();
    success = configXml.parse("../tst/data/data_value.xml");
    BOOST_REQUIRE(success == true);

    success = nodeSetXmlParser.decode(configXml.ptree());
    BOOST_REQUIRE(success == true);

    NodeSetNamespace& nodeSetNamespace = nodeSetXmlParser.nodeSetNamespace();
    NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
    NamespaceVec::iterator it;

    for (it = namespaceVec.begin(); it != namespaceVec.end(); it++) {
        uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(*it);

        std::cout << "NamespaceUri: " << *it << std::endl;
        std::cout << "mapToGlobalNamespaceIndex: " << namespaceIndex << std::endl;
    }

	InformationModel::SPtr informationModel = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModel, nodeSetXmlParser);
	BOOST_REQUIRE(success == true);

	informationModel->checkForwardReferences();


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	BaseNodeClass::SPtr nodeClass;
	OpcUaDataValue dataValue;

	// check boolean variable
	nodeClass = informationModel->find(OpcUaNodeId("Boolean", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaBoolean>() == true);

	// check boolean array variable
	nodeClass = informationModel->find(OpcUaNodeId("BooleanArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaBoolean>(0) == false);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaBoolean>(1) == true);

	// check byte variable
	nodeClass = informationModel->find(OpcUaNodeId("Byte", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaByte>() == 1);

	// check byte array variable
	nodeClass = informationModel->find(OpcUaNodeId("ByteArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaByte>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaByte>(1) == 2);

	// check sbyte variable
	nodeClass = informationModel->find(OpcUaNodeId("SByte", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaSByte>() == 1);

	// check sbyte array variable
	nodeClass = informationModel->find(OpcUaNodeId("SByteArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaSByte>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaSByte>(1) == 2);

	// check int16 variable
	nodeClass = informationModel->find(OpcUaNodeId("Int16", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>() == 16);

	// check int16 array variable
	nodeClass = informationModel->find(OpcUaNodeId("Int16Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>(3) == 4);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt16>(4) == 5);

	// check uint16 variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt16", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt16>() == 3);

	// check uint16 array variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt16Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt16>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt16>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt16>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt16>(3) == 4);

	// check int32 variable
	nodeClass = informationModel->find(OpcUaNodeId("Int32", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt32>() == 32);

	// check int32 array variable
	nodeClass = informationModel->find(OpcUaNodeId("Int32Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt32>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt32>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt32>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt32>(3) == 4);

	// check uint32 variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt32", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt32>() == 1);

	// check uint32 array variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt32Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt32>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt32>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt32>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt32>(3) == 4);

	// check int64 variable
	nodeClass = informationModel->find(OpcUaNodeId("Int64", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>() == 123);

	// check int64 array variable
	nodeClass = informationModel->find(OpcUaNodeId("Int64Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(3) == 4);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(4) == 5);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(5) == 6);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(6) == 7);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(7) == 8);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaInt64>(8) == 9);

	// check uint64 variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt64", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>() == 1212);

	// check uint64 array variable
	nodeClass = informationModel->find(OpcUaNodeId("UInt64Array", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>(2) == 3);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>(3) == 4);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaUInt64>(4) == 5);

	// check double variable
	nodeClass = informationModel->find(OpcUaNodeId("Double", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaDouble>() == 1);

	// check double array variable
	nodeClass = informationModel->find(OpcUaNodeId("DoubleArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaDouble>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaDouble>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaDouble>(2) == 3);

	// check float variable
	nodeClass = informationModel->find(OpcUaNodeId("Float", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaFloat>() == 1);

	// check float array variable
	nodeClass = informationModel->find(OpcUaNodeId("FloatArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaFloat>(0) == 1);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaFloat>(1) == 2);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaFloat>(2) == 3);

	// check string variable
	nodeClass = informationModel->find(OpcUaNodeId("String", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(*dataValue.variant()->getSPtr<OpcUaString>() == OpcUaString("String1"));

	// check string array variable
	nodeClass = informationModel->find(OpcUaNodeId("StringArray", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(*dataValue.variant()->getSPtr<OpcUaString>(0) == OpcUaString("String1"));
	BOOST_REQUIRE(*dataValue.variant()->getSPtr<OpcUaString>(1) == OpcUaString("String2"));
	BOOST_REQUIRE(*dataValue.variant()->getSPtr<OpcUaString>(2) == OpcUaString("String3"));

	// check date time variable
	nodeClass = informationModel->find(OpcUaNodeId("DateTime", 1));
	BOOST_REQUIRE(nodeClass.get() != nullptr);
	BOOST_REQUIRE(nodeClass->getValue(dataValue) == true);
	BOOST_REQUIRE(dataValue.variant()->get<OpcUaDateTime>() == OpcUaDateTime("2000-01-02T00:00:09"));

}

BOOST_AUTO_TEST_SUITE_END()

