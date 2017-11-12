/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include <OpcUaStackCore/Network/TCPAcceptor.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Base/ConditionProcess.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelMapOld.h"
#include "OpcUaStackServer/ServiceSet/SessionConfig.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSet/SessionMap.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryManagerIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManagerOld
	: public SecureChannelManagerIf
	, public SessionManagerIf
	, public DiscoveryManagerIf
	{
	  public:
		static SessionManagerOld* instance_;
		static SessionManagerOld* instance(void);

		typedef boost::shared_ptr<SessionManagerOld> SPtr;

		SessionManagerOld(void);
		virtual ~SessionManagerOld(void);

		void discoveryService(DiscoveryService::SPtr& discoveryService);
		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);
		void ioService(IOService* ioService);

		void openServerSocket(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
		);
		void closeServerSocket(void);

		//- SecureChannelManagerIf --------------------------------------------
		void connect(OpcUaUInt32 channelId);
		void disconnect(OpcUaUInt32 channelId);
		bool secureChannelMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		//- SecureChannelManagerIf --------------------------------------------

		//- SessionManagerIf---------------------------------------------------
		void sessionMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		void sessionDelete(uint32_t authenticationToken);
		//- SessionManagerIf --------------------------------------------------

		//- DiscoveryManagerIf ------------------------------------------------
		void discoveryMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		//- DiscoveryManagerIf ------------------------------------------------

	  private:
		bool readConfiguration(void);
		bool openListenerSocket(void);
		bool closeListenerSocket(void);

		SecureChannelServerOld::SPtr getSecureChannel(OpcUaUInt32 secureChannelId);

		SessionOld::SPtr getSession(OpcUaUInt32 authenticationToken, bool createIfNotExist = false);
		SessionOld::SPtr createSession(void);

		// function to handle secure channel
		void acceptNewChannel(void);
		void handleAccept(const boost::system::error_code& error, SecureChannelServerOld::SPtr secureChannel);

		IOService* ioService_;
		ConditionProcess shutdown_;

		Url url_;
		TCPAcceptor::SPtr tcpAcceptor_;
		DiscoveryService::SPtr discoveryService_;
		TransactionManager::SPtr transactionManagerSPtr_;

		// server configuration
		std::string prefixSessionConfig_;
		std::string prefixSecureChannelConfig_; 
		Config* sessionConfig_; 
		Config* secureChannelConfig_;

		SecureChannelMapOld secureChannelMap_;
		SessionMap sessionMap_;
	};

}

#endif
