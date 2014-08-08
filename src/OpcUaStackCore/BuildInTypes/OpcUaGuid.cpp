#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{
	
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaGuid
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaGuid::OpcUaGuid(void)
	: ObjectPool<OpcUaGuid>()
	, data1_(0)
	, data2_(0)
	, data3_(0)
	{
		memset((char*)data4_, 0x00, sizeof(data4_));
	}
		
	OpcUaGuid::~OpcUaGuid(void)
	{
	}

	void 
	OpcUaGuid::data1(OpcUaUInt32 value)
	{
		data1_ = value;
	}

	OpcUaUInt32 
	OpcUaGuid::data1(void)
	{
		return data1_;
	}

	void 
	OpcUaGuid::data2(OpcUaUInt16 value)
	{
		data2_ = value;
	}

	OpcUaUInt16 
	OpcUaGuid::data2(void)
	{
		return data2_;
	}

	void 
	OpcUaGuid::data3(OpcUaUInt16 value)
	{
		data3_ = value;
	}

	OpcUaUInt16 
	OpcUaGuid::data3(void)
	{
		return data3_;
	}

	void 
	OpcUaGuid::data4(OpcUaByte value[8])
	{
		memcpy((char*)data4_, value, 8);
	}

	OpcUaByte* 
	OpcUaGuid::data4(void)
	{
		return data4_;
	}

	OpcUaGuid& 
	OpcUaGuid::operator=(const std::string& string)
	{
		assert(string.length() == 36);
		hexStringToByteSequence(string.substr(0,8), (uint8_t*)&data1_);
		hexStringToByteSequence(string.substr(9,4), (uint8_t*)&data2_);
		hexStringToByteSequence(string.substr(14,4), (uint8_t*)&data3_);
		hexStringToByteSequence(string.substr(19,4), data4_);
		hexStringToByteSequence(string.substr(24,12), &data4_[2]);
		return *this;
	}

	OpcUaGuid::operator std::string const (void)
	{
		std::string str1, str2, str3, str4, str5;

		byteSequenceToHexString((uint8_t*)&data1_, 4, str1);
		byteSequenceToHexString((uint8_t*)&data2_, 2, str2);
		byteSequenceToHexString((uint8_t*)&data3_, 2, str3);
		byteSequenceToHexString(data4_, 2, str4);
		byteSequenceToHexString(&data4_[2], 6, str5);

		return str1.append("-").append(str2).append("-").append(str3)
				.append("-").append(str4).append("-").append(str5);
	}

	void 
	OpcUaGuid::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, data1_);
		OpcUaNumber::opcUaBinaryEncode(os, data2_);
		OpcUaNumber::opcUaBinaryEncode(os, data3_);
		os.write((char*)data4_, sizeof(data4_));
	}
		
	void 
	OpcUaGuid::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, data1_);
		OpcUaNumber::opcUaBinaryDecode(is, data2_);
		OpcUaNumber::opcUaBinaryDecode(is, data3_);
		is.read((char*)data4_, sizeof(data4_));
	}
}