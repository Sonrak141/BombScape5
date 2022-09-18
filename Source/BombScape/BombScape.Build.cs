// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BombScape : ModuleRules
{
	public BombScape(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
