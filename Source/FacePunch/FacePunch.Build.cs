// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FacePunch : ModuleRules
{
	public FacePunch(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
