#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	AttributeService::AttributeService(void)
	{
	}

	AttributeService::~AttributeService(void)
	{
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_ReadRequest_Encoding_DefaultBinary:
				receiveReadRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_WriteRequest_Encoding_DefaultBinary:
				receiveWriteRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_HistoryReadRequest_Encoding_DefaultBinary:
				receiveHistoryReadRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary:
				receiveHistoryUpdateRequest(typeId, serviceTransaction);
				break;
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	AttributeService::receiveReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRead::SPtr trx = boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction);
		ReadRequest::SPtr readRequest = trx->request();
		ReadResponse::SPtr readResponse = trx->response();

		Log(Debug, "attribute service read request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", readRequest->readValueIdArray()->size());

		// check attribute maxAge
		// FIXME: todo 

		// check attribute timestampToReturn
		// FIXME: todo

		// check node id array
		if (readRequest->readValueIdArray()->size() == 0) {
			trx->responseHeader()->serviceResult(BadNothingToDo);
			trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
			return;
		}
		if (readRequest->readValueIdArray()->size() > 1000) { // FIXME: todo
			trx->responseHeader()->serviceResult(BadTooManyOperations);
			trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
			return;
		}

		// read values
		readResponse->dataValueArray()->resize(readRequest->readValueIdArray()->size());
		for (uint32_t idx = 0; idx < readRequest->readValueIdArray()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = OpcUaDataValue::construct();
			readResponse->dataValueArray()->set(idx, dataValue);

			ReadValueId::SPtr readValueId;
			if (!readRequest->readValueIdArray()->get(idx, readValueId)) {
				dataValue->statusCode(BadNodeIdInvalid);
				Log(Debug, "read value error, because node request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readValueId->nodeId());
			if (baseNodeClass.get() == nullptr) {
				dataValue->statusCode(BadNodeIdUnknown);
				Log(Debug, "read value error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId());
				continue;
			}

			Attribute* attribute = baseNodeClass->attribute((AttributeId)readValueId->attributeId());
			if (attribute == nullptr) {
				dataValue->statusCode(BadAttributeIdInvalid);
				Log(Debug, "read value error, because node attribute not exist in node")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				continue;
			}

			if (attribute->exist() == false) {
				Log(Debug, "read value error, because node attribute is empty")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				dataValue->statusCode(BadNotReadable);
				continue;
			}

			if (!AttributeAccess::copy(*attribute, *dataValue)) {
				Log(Debug, "read value error, because value error")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				dataValue->reset();
				dataValue->statusCode(BadAttributeIdInvalid);
				continue;
			}

			Log(Debug, "read value")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *readValueId->nodeId())
				.parameter("Attr", readValueId->attributeId())
				.parameter("Class", baseNodeClass->nodeClass().data())
				.parameter("Data", *dataValue);
		}

		trx->responseHeader()->serviceResult(Success);
		trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	AttributeService::receiveWriteRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	AttributeService::receiveHistoryReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	AttributeService::receiveHistoryUpdateRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

}