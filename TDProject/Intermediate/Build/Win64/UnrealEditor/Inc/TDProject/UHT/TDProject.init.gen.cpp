// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TDProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TDProject()
	{
		if (!Z_Registration_Info_UPackage__Script_TDProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TDProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xFEDEBB90,
				0x047FB13A,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TDProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TDProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TDProject(Z_Construct_UPackage__Script_TDProject, TEXT("/Script/TDProject"), Z_Registration_Info_UPackage__Script_TDProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xFEDEBB90, 0x047FB13A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
