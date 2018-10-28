/*
    EnumTypeClass: UserTokenType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UserTokenType_h__
#define __OpcUaStackCore_UserTokenType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class UserTokenType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<UserTokenType> SPtr;
    
        typedef enum {
            EnumAnonymous = 0,     //!< An anonymous user.
            EnumUserName = 1,     //!< A user identified by a user name and password.
            EnumCertificate = 2,     //!< A user identified by an X509 certificate.
            EnumIssuedToken = 3,     //!< A user identified by WS-Security XML token.
        } Enum;
    
        UserTokenType(void);
        UserTokenType(Enum enumeration);
        UserTokenType(UserTokenType& value);
        virtual ~UserTokenType(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(UserTokenType& value);
        bool operator==(const UserTokenType& value) const;
        bool operator!=(const UserTokenType& value) const;
        UserTokenType& operator=(const UserTokenType& value);
        UserTokenType& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };

}

#endif