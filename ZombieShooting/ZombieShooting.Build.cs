// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ZombieShooting : ModuleRules
{
	public ZombieShooting(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Json", "JsonUtilities", "UMG", "NavigationSystem", "AIModule", "GameplayTasks" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
