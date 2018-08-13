/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_MQTTClientServerBase_h__
#define __OpcUaStackPubSub_MQTTClientServerBase_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT MQTTClientServerBase
	{
	  public:
		MQTTClientServerBase(void);
		virtual ~MQTTClientServerBase(void);

		//
		// virtual functions
		//
		virtual bool init(void);
		virtual bool cleanup(void);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool mqttClientIfEnabled(void);
	};

}

#endif

