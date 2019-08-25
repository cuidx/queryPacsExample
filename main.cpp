// testEcho.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "imebra.h"
#include <string>
#include <exception>
#include <stdio.h>
#include <thread>

const char* dcmLongSCUStorageSOPClassUIDs[] = {
	imebra::uidAmbulatoryECGWaveformStorage_1_2_840_10008_5_1_4_1_1_9_1_3,
	imebra::uidArterialPulseWaveformStorage_1_2_840_10008_5_1_4_1_1_9_5_1,
	imebra::uidAutorefractionMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_2,
	imebra::uidBasicStructuredDisplayStorage_1_2_840_10008_5_1_4_1_1_131,
	imebra::uidBasicTextSRStorage_1_2_840_10008_5_1_4_1_1_88_11,
	imebra::uidBasicVoiceAudioWaveformStorage_1_2_840_10008_5_1_4_1_1_9_4_1,
	imebra::uidBlendingSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_4,
	imebra::uidBreastTomosynthesisImageStorage_1_2_840_10008_5_1_4_1_1_13_1_3,
	imebra::uidCardiacElectrophysiologyWaveformStorage_1_2_840_10008_5_1_4_1_1_9_3_1,
	imebra::uidChestCADSRStorage_1_2_840_10008_5_1_4_1_1_88_65,
	imebra::uidColonCADSRStorage_1_2_840_10008_5_1_4_1_1_88_69,
	imebra::uidColorSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_2,
	imebra::uidComprehensive3DSRStorage_1_2_840_10008_5_1_4_1_1_88_34,
	imebra::uidComprehensiveSRStorage_1_2_840_10008_5_1_4_1_1_88_33,
	imebra::uidComputedRadiographyImageStorage_1_2_840_10008_5_1_4_1_1_1,
	imebra::uidCTImageStorage_1_2_840_10008_5_1_4_1_1_2,
	imebra::uidDeformableSpatialRegistrationStorage_1_2_840_10008_5_1_4_1_1_66_3,
	imebra::uidDigitalIntraOralXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_3,
	imebra::uidDigitalIntraOralXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_3_1,
	imebra::uidDigitalMammographyXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_2,
	imebra::uidDigitalMammographyXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_2_1,
	imebra::uidDigitalXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_1,
	imebra::uidDigitalXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_1_1,
	imebra::uidEncapsulatedCDAStorage_1_2_840_10008_5_1_4_1_1_104_2,
	imebra::uidEncapsulatedPDFStorage_1_2_840_10008_5_1_4_1_1_104_1,
	imebra::uidEnhancedCTImageStorage_1_2_840_10008_5_1_4_1_1_2_1,
	imebra::uidEnhancedMRColorImageStorage_1_2_840_10008_5_1_4_1_1_4_3,
	imebra::uidEnhancedMRImageStorage_1_2_840_10008_5_1_4_1_1_4_1,
	imebra::uidEnhancedPETImageStorage_1_2_840_10008_5_1_4_1_1_130,
	imebra::uidEnhancedSRStorage_1_2_840_10008_5_1_4_1_1_88_22,
	imebra::uidEnhancedUSVolumeStorage_1_2_840_10008_5_1_4_1_1_6_2,
	imebra::uidEnhancedXAImageStorage_1_2_840_10008_5_1_4_1_1_12_1_1,
	imebra::uidEnhancedXRFImageStorage_1_2_840_10008_5_1_4_1_1_12_2_1,
	imebra::uidGeneralAudioWaveformStorage_1_2_840_10008_5_1_4_1_1_9_4_2,
	imebra::uidGeneralECGWaveformStorage_1_2_840_10008_5_1_4_1_1_9_1_2,
	imebra::uidGrayscaleSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_1,
	imebra::uidHemodynamicWaveformStorage_1_2_840_10008_5_1_4_1_1_9_2_1,
//	UID_ImplantationPlanSRDocumentStorage,
	imebra::uidIntraocularLensCalculationsStorage_1_2_840_10008_5_1_4_1_1_78_8,
	imebra::uidIntravascularOpticalCoherenceTomographyImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_14_1,
	imebra::uidIntravascularOpticalCoherenceTomographyImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_14_2,
	imebra::uidKeratometryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_3,
	imebra::uidKeyObjectSelectionDocumentStorage_1_2_840_10008_5_1_4_1_1_88_59,
	imebra::uidLegacyConvertedEnhancedCTImageStorage_1_2_840_10008_5_1_4_1_1_2_2,
	imebra::uidLegacyConvertedEnhancedMRImageStorage_1_2_840_10008_5_1_4_1_1_4_4,
	imebra::uidLegacyConvertedEnhancedPETImageStorage_1_2_840_10008_5_1_4_1_1_128_1,
	imebra::uidLensometryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_1,
	imebra::uidMacularGridThicknessandVolumeReportStorage_1_2_840_10008_5_1_4_1_1_79_1,
	imebra::uidMammographyCADSRStorage_1_2_840_10008_5_1_4_1_1_88_50,
	imebra::uidMRImageStorage_1_2_840_10008_5_1_4_1_1_4,
	imebra::uidMRSpectroscopyStorage_1_2_840_10008_5_1_4_1_1_4_2,
	imebra::uidMultiframeGrayscaleByteSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_2,
	imebra::uidMultiframeGrayscaleWordSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_3,
	imebra::uidMultiframeSingleBitSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_1,
	imebra::uidMultiframeTrueColorSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_4,
	imebra::uidNuclearMedicineImageStorage_1_2_840_10008_5_1_4_1_1_20,
	imebra::uidOphthalmicAxialMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_7,
	imebra::uidOphthalmicPhotography16BitImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_2,
	imebra::uidOphthalmicPhotography8BitImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_1,
	imebra::uidOphthalmicThicknessMapStorage_1_2_840_10008_5_1_4_1_1_81_1,
	imebra::uidOphthalmicTomographyImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_4,
	imebra::uidOphthalmicVisualFieldStaticPerimetryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_80_1,
	imebra::uidPositronEmissionTomographyImageStorage_1_2_840_10008_5_1_4_1_1_128,
	imebra::uidProcedureLogStorage_1_2_840_10008_5_1_4_1_1_88_40,
	imebra::uidPseudoColorSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_3,
	imebra::uidRawDataStorage_1_2_840_10008_5_1_4_1_1_66,
	imebra::uidRealWorldValueMappingStorage_1_2_840_10008_5_1_4_1_1_67,
	imebra::uidRespiratoryWaveformStorage_1_2_840_10008_5_1_4_1_1_9_6_1,
	imebra::uidRTBeamsDeliveryInstructionStorageTrial_1_2_840_10008_5_1_4_34_1,
	imebra::uidRTBeamsTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_4,
	imebra::uidRTBrachyTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_6,
	imebra::uidRTDoseStorage_1_2_840_10008_5_1_4_1_1_481_2,
	imebra::uidRTImageStorage_1_2_840_10008_5_1_4_1_1_481_1,
	imebra::uidRTIonBeamsTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_9,
	imebra::uidRTIonPlanStorage_1_2_840_10008_5_1_4_1_1_481_8,
	imebra::uidRTPlanStorage_1_2_840_10008_5_1_4_1_1_481_5,
	imebra::uidRTStructureSetStorage_1_2_840_10008_5_1_4_1_1_481_3,
	imebra::uidRTTreatmentSummaryRecordStorage_1_2_840_10008_5_1_4_1_1_481_7,
	imebra::uidSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7,
	imebra::uidSegmentationStorage_1_2_840_10008_5_1_4_1_1_66_4,
	imebra::uidSpatialFiducialsStorage_1_2_840_10008_5_1_4_1_1_66_2,
	imebra::uidSpatialRegistrationStorage_1_2_840_10008_5_1_4_1_1_66_1,
	imebra::uidSpectaclePrescriptionReportStorage_1_2_840_10008_5_1_4_1_1_78_6,
	imebra::uidStereometricRelationshipStorage_1_2_840_10008_5_1_4_1_1_77_1_5_3,
	imebra::uidSubjectiveRefractionMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_4,
	imebra::uidSurfaceScanMeshStorage_1_2_840_10008_5_1_4_1_1_68_1,
	imebra::uidSurfaceScanPointCloudStorage_1_2_840_10008_5_1_4_1_1_68_2,
	imebra::uidSurfaceSegmentationStorage_1_2_840_10008_5_1_4_1_1_66_5,
	//UID_TwelveLeadECGWaveformStorage,
	imebra::uidUltrasoundImageStorage_1_2_840_10008_5_1_4_1_1_6_1,
	imebra::uidUltrasoundMultiframeImageStorage_1_2_840_10008_5_1_4_1_1_3_1,
	imebra::uidVideoEndoscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_1_1,
	imebra::uidVideoMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_2_1,
	imebra::uidVideoPhotographicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_4_1,
	imebra::uidVisualAcuityMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_5,
	imebra::uidVLEndoscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_1,
	imebra::uidVLMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_2,
	imebra::uidVLPhotographicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_4,
	imebra::uidVLSlideCoordinatesMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_3,
	imebra::uidVLWholeSlideMicroscopyImageStorage_1_2_840_10008_5_1_4_1_1_77_1_6,
	imebra::uidXAXRFGrayscaleSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_5,
	imebra::uidXRay3DAngiographicImageStorage_1_2_840_10008_5_1_4_1_1_13_1_1,
	imebra::uidXRay3DCraniofacialImageStorage_1_2_840_10008_5_1_4_1_1_13_1_2,
	imebra::uidXRayAngiographicImageStorage_1_2_840_10008_5_1_4_1_1_12_1,
	imebra::uidXRayRadiationDoseSRStorage_1_2_840_10008_5_1_4_1_1_88_67,
	imebra::uidXRayRadiofluoroscopicImageStorage_1_2_840_10008_5_1_4_1_1_12_2,
	// retired
	imebra::uidHardcopyColorImageStorageSOPClass_1_2_840_10008_5_1_1_30,
	imebra::uidHardcopyGrayscaleImageStorageSOPClass_1_2_840_10008_5_1_1_29,
	imebra::uidNuclearMedicineImageStorage_1_2_840_10008_5_1_4_1_1_5,
	imebra::uidStandaloneCurveStorage_1_2_840_10008_5_1_4_1_1_9,
	imebra::uidStandaloneModalityLUTStorage_1_2_840_10008_5_1_4_1_1_10,
	imebra::uidStandaloneOverlayStorage_1_2_840_10008_5_1_4_1_1_8,
	imebra::uidStandalonePETCurveStorage_1_2_840_10008_5_1_4_1_1_129,
	imebra::uidStandaloneVOILUTStorage_1_2_840_10008_5_1_4_1_1_11,
	imebra::uidStoredPrintStorageSOPClass_1_2_840_10008_5_1_1_27,
	imebra::uidUltrasoundImageStorage_1_2_840_10008_5_1_4_1_1_6,
	imebra::uidUltrasoundMultiframeImageStorage_1_2_840_10008_5_1_4_1_1_3,
	imebra::uidVLImageStorageTrial_1_2_840_10008_5_1_4_1_1_77_1,
	imebra::uidVLMultiframeImageStorageTrial_1_2_840_10008_5_1_4_1_1_77_2,
	imebra::uidXRayAngiographicBiPlaneImageStorage_1_2_840_10008_5_1_4_1_1_12_3,
	NULL
};

const int numberOfDcmLongSCUStorageSOPClassUIDs = sizeof(dcmLongSCUStorageSOPClassUIDs) / sizeof(const char*) - 1;


void echo()
{
	//std::string svrIp("10.160.92.65");
	std::string svrIp("192.168.0.3");
	std::string svrPort("11121");
	imebra::TCPActiveAddress svrAddr(svrIp, svrPort);
	imebra::TCPStream svrStream(svrAddr);

	imebra::StreamReader sReader(svrStream);
	imebra::StreamWriter sWriter(svrStream);

	imebra::PresentationContext context(imebra::uidVerificationSOPClass_1_2_840_10008_1_1);
	context.addTransferSyntax(imebra::uidImplicitVRLittleEndian_1_2_840_10008_1_2);
	imebra::PresentationContexts contexts;
	contexts.addPresentationContext(context);

	std::string myAET("ECHOSCU");
	std::string svrAET("SANTESRV1");
	try
	{
		imebra::AssociationSCU scu(myAET, svrAET, 1, 1, contexts, sReader, sWriter, 10);
		imebra::DimseService service(scu);
		imebra::CEchoCommand command(imebra::uidVerificationSOPClass_1_2_840_10008_1_1,
			service.getNextCommandID(),
			imebra::dimseCommandPriority_t::medium,
			imebra::uidVerificationSOPClass_1_2_840_10008_1_1);

		service.sendCommandOrResponse(command);

		imebra::CEchoResponse *rsp = service.getCEchoResponse(command);
		if (rsp->getStatus() == imebra::dimseStatus_t::success)
		{
			printf("echo response success\n");
		}
		else
		{
			printf("echo response fail, status= %d\n", rsp->getStatus());
		}
	}
	catch (std::exception &e)
	{
		printf("echo exception ; %s\n",e.what());
	}

	
}

void find(std::string patientId)
{
	//std::string svrIp("10.160.92.65");
	std::string svrIp("192.168.0.3");
	std::string svrPort("11121");
	imebra::TCPActiveAddress svrAddr(svrIp, svrPort);
	imebra::TCPStream svrStream(svrAddr);

	imebra::StreamReader sReader(svrStream);
	imebra::StreamWriter sWriter(svrStream);

	imebra::PresentationContext context(imebra::uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1);
	context.addTransferSyntax(imebra::uidImplicitVRLittleEndian_1_2_840_10008_1_2);
	imebra::PresentationContexts contexts;
	contexts.addPresentationContext(context);

	imebra::DataSet dataSet("1.2.840.10008.1.2");
	dataSet.setString(imebra::TagId(imebra::tagId_t::AccessionNumber_0008_0050), patientId, imebra::tagVR_t::SH);
	dataSet.setString(imebra::TagId(imebra::tagId_t::PatientID_0010_0020), "", imebra::tagVR_t::LO);
	dataSet.setString(imebra::TagId(imebra::tagId_t::QueryRetrieveLevel_0008_0052), "STUDY", imebra::tagVR_t::CS);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyDate_0008_0020), "", imebra::tagVR_t::DA);
	dataSet.setString(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), "", imebra::tagVR_t::PN);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyTime_0008_0030), "", imebra::tagVR_t::TM);
	dataSet.setString(imebra::TagId(imebra::tagId_t::AccessionNumber_0008_0050), "", imebra::tagVR_t::SH);
	dataSet.setString(imebra::TagId(imebra::tagId_t::ModalitiesInStudy_0008_0061), "", imebra::tagVR_t::CS);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyDescription_0008_1030), "", imebra::tagVR_t::CS);
	dataSet.setString(imebra::TagId(imebra::tagId_t::PatientBirthDate_0010_0030), "", imebra::tagVR_t::DA);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyInstanceUID_0020_000D), "", imebra::tagVR_t::UI);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyID_0020_0010), "", imebra::tagVR_t::SH);
	dataSet.setString(imebra::TagId(imebra::tagId_t::NumberOfStudyRelatedSeries_0020_1206), "", imebra::tagVR_t::IS);
	dataSet.setString(imebra::TagId(imebra::tagId_t::NumberOfStudyRelatedInstances_0020_1208), "", imebra::tagVR_t::IS);

	std::string myAET("FINDSCU");
	std::string svrAET("SANTESRV1");
	try
	{
		imebra::AssociationSCU scu(myAET, svrAET, 1, 1, contexts, sReader, sWriter, 10);
		imebra::DimseService service(scu);
		imebra::CFindCommand command(imebra::uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1,
			service.getNextCommandID(),
			imebra::dimseCommandPriority_t::medium,
			imebra::uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1, dataSet);

		service.sendCommandOrResponse(command);

		imebra::CFindResponse *rsp = service.getCFindResponse(command);
		while (rsp->getStatus() == imebra::dimseStatus_t::success ||
			imebra::dimseStatus_t::pending == rsp->getStatus())
		{
			if (rsp->getStatus() == imebra::dimseStatus_t::success)
			{
				printf("find response success\n");
				break;
			}
			else if (imebra::dimseStatus_t::pending == rsp->getStatus())
			{
				printf("find response one data:\n");
				imebra::DataSet* data = rsp->getPayloadDataSet();
				try
				{
					imebra::Date* studyDate = data->getDate(imebra::TagId(imebra::tagId_t::StudyDate_0008_0020),0);
					printf("study date:%04d-%02d-%02d\n", studyDate->year, studyDate->month, studyDate->day);

					std::string name = data->getString(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
					printf("patient name:%s\n",name.c_str());

					std::string studyInstanceUid = data->getString(imebra::TagId(imebra::tagId_t::StudyInstanceUID_0020_000D), 0);
					printf("study instance UID:%s\n", studyInstanceUid.c_str());

					int seriesNum = data->getSignedLong(imebra::TagId(imebra::tagId_t::NumberOfStudyRelatedInstances_0020_1208), 0);
					printf("study series num:%d\n", seriesNum);
				}
				catch (std::exception &e)
				{
					printf("parse rsp fail, exception= %s\n", e.what());
				}
				rsp = service.getCFindResponse(command);
			}
			else
			{
				printf("find response fail, status= %d\n", rsp->getStatus());
				break;
			}
		}
		
	}
	catch (std::exception &e)
	{
		printf("find exception ; %s\n", e.what());
	}
}

void StoreProc(imebra::DimseService *service, bool bActive)
{
	int id = 0;
	while (bActive)
	{
		try
		{
			imebra::DimseCommand *cmd = service->getCommand();
			if (imebra::dimseCommandType_t::cStore == cmd->getCommandType())
			{
				char lszImage[1024] = { 0 };
				sprintf_s(lszImage, "img_%03d.dcm", id++);
				const imebra::CStoreCommand *store = cmd->getAsCStoreCommand();
				imebra::DataSet* data = store->getPayloadDataSet();
				imebra::CodecFactory::save(*data, lszImage, imebra::codecType_t::dicom);
				printf("save image %s\n", lszImage);

				imebra::CStoreResponse rsp(*store, imebra::dimseStatusCode_t::success);
				try
				{
					service->sendCommandOrResponse(rsp);
				}
				catch (std::exception &e)
				{
					printf("send store response fail, exception:%s\n", e.what());
				}
			}
		}
		catch (std::exception e)
		{
			printf("store proc get exception:%s\n",e.what());
			break;
		}
	}
	
}

void get(std::string studyInstanceUid)
{
	bool bActive = true;
	//std::string svrIp("10.160.92.65");
	std::string svrIp("192.168.0.3");
	std::string svrPort("11121");
	imebra::TCPActiveAddress svrAddr(svrIp, svrPort);
	imebra::TCPStream svrStream(svrAddr);

	imebra::StreamReader sReader(svrStream);
	imebra::StreamWriter sWriter(svrStream);

	imebra::PresentationContext context(imebra::uidStudyRootQueryRetrieveInformationModelGET_1_2_840_10008_5_1_4_1_2_2_3,true,true);
	context.addTransferSyntax(imebra::uidImplicitVRLittleEndian_1_2_840_10008_1_2);
	context.addTransferSyntax(imebra::uidExplicitVRLittleEndian_1_2_840_10008_1_2_1);
	context.addTransferSyntax(imebra::uidDeflatedExplicitVRLittleEndian_1_2_840_10008_1_2_1_99);
	imebra::PresentationContexts contexts;
	contexts.addPresentationContext(context);
	for (int j = 0; j < numberOfDcmLongSCUStorageSOPClassUIDs; j++)
	{
		imebra::PresentationContext context1(dcmLongSCUStorageSOPClassUIDs[j],true,true);
		context1.addTransferSyntax(imebra::uidImplicitVRLittleEndian_1_2_840_10008_1_2);
		context1.addTransferSyntax(imebra::uidExplicitVRLittleEndian_1_2_840_10008_1_2_1);
		context1.addTransferSyntax(imebra::uidDeflatedExplicitVRLittleEndian_1_2_840_10008_1_2_1_99);
		contexts.addPresentationContext(context1);
	}

	imebra::DataSet dataSet("1.2.840.10008.1.2");
	dataSet.setString(imebra::TagId(imebra::tagId_t::QueryRetrieveLevel_0008_0052), "STUDY", imebra::tagVR_t::CS);
	dataSet.setString(imebra::TagId(imebra::tagId_t::StudyInstanceUID_0020_000D), studyInstanceUid, imebra::tagVR_t::UI);

	std::string myAET("GETSCU");
	std::string svrAET("SANTESRV1");
	try
	{
		imebra::AssociationSCU scu(myAET, svrAET, 1, 1, contexts, sReader, sWriter, 10);
		imebra::DimseService service(scu);
		imebra::CGetCommand command(imebra::uidStudyRootQueryRetrieveInformationModelGET_1_2_840_10008_5_1_4_1_2_2_3,
			service.getNextCommandID(),
			imebra::dimseCommandPriority_t::medium,
			imebra::uidStudyRootQueryRetrieveInformationModelGET_1_2_840_10008_5_1_4_1_2_2_3, dataSet);

		service.sendCommandOrResponse(command);

		std::thread storeProc(StoreProc, &service, bActive);

		try
		{
			imebra::CGetResponse *rsp = service.getCGetResponse(command);
			while (rsp->getStatus() == imebra::dimseStatus_t::success ||
				imebra::dimseStatus_t::pending == rsp->getStatus())
			{
				if (rsp->getStatus() == imebra::dimseStatus_t::success)
				{
					bActive = false;
					printf("get response success\n");
					break;
				}
				else if (imebra::dimseStatus_t::pending == rsp->getStatus())
				{
					int remainNum = 0;
					printf("get response one data:\n");
					imebra::DataSet* data = rsp->getPayloadDataSet();
					try
					{
						remainNum = data->getSignedLong(imebra::TagId(imebra::tagId_t::NumberofRemainingSuboperations_0000_1020), 0);
						printf("remain num:%d\n", remainNum);
					}
					catch (std::exception &e)
					{
						printf("parse rsp fail, exception= %s\n", e.what());
					}
					if (remainNum > 0)
					{
						rsp = service.getCGetResponse(command);
					}

				}
				else
				{
					printf("get response fail, status= %d\n", rsp->getStatus());
					break;
				}
			}
			printf("get response status: %d\n", rsp->getStatusCode());
		}
		catch (std::exception e)
		{
			printf("get exception ; %s\n", e.what());
		}
		storeProc.join();
	}
	catch (std::exception &e)
	{
		printf("get exception ; %s\n", e.what());
	}
}

int main()
{
	printf("echo start\n");
	echo();
	printf("echo end\n");
	printf("find start\n");
	find("20151015156102");
	printf("find end\n");
	printf("get start\n");
	get("1.2.840.113619.186.808615256187.20151016134906670.630");
	printf("get end\n");
	getchar();
    return 0;
}

