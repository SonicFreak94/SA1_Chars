#include "stdafx.h"
#include "Sonic.h"
#include "Tails.h"
#include "EV_TR1.h"
#include "OBJECT_SonicPointingFinger.h"
#include "EV_TR2BEFORE.h"
#include "EV_TR2CHANGE.h"
#include "SkyChase.h"
#include "EV_TailsIntro.h"


FunctionPointer(void, MorphPoints, (NJS_MODEL_SADX *a, NJS_MODEL_SADX *b, NJS_MODEL_SADX *destination, float factor), 0x00439F20);
HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");
NJS_OBJECT **___SONIC_OBJECTS = (NJS_OBJECT **)GetProcAddress(handle, "___SONIC_OBJECTS");
NJS_MODEL_SADX **___SONIC_MODELS = (NJS_MODEL_SADX **)GetProcAddress(handle, "___SONIC_MODELS");

//void __cdecl Sonic_MorphStretchyFeet_c(CharObj2* a1)
//{
//	float a4; // ST10_4@3
//	float v2; // ST10_4@5
//	NJS_MODEL_SADX *v3; // ecx@5
//	float v4; // ST10_4@10
//	float v5; // ST10_4@13
//
//	if (a1->AnimationThing.Index == 13)
//	{
//		if (a1->AnimationThing.Frame >= 16.0)
//		{
//			if (a1->AnimationThing.Frame <= 24.0)
//			{
//				a1->SomeFrameNumberThing = 0;
//				v3 = &attach_0057464C;
//			}
//			else
//			{
//				v2 = (a1->AnimationThing.Frame - 24.0) * 0.125;
//				a1->SomeFrameNumberThing = v2;
//				MorphPoints(&attach_0057464C, &attach_00573DFC, &attach_005735AC, v2);
//				v3 = &attach_005735AC;
//			}
//			object_0055F330.model = v3;
//		}
//		else
//		{
//			a4 = (16.0 - a1->AnimationThing.Frame) * 0.0625;
//			a1->SomeFrameNumberThing = a4;
//			MorphPoints(&attach_0057464C, &attach_00573DFC, &attach_005735AC, a4);
//			object_0055F330.model = &attach_005735AC;
//		}
//		if (a1->AnimationThing.Frame < 8.0 || a1->AnimationThing.Frame > 16.0)
//		{
//			if (a1->AnimationThing.Frame <= 16.0 || a1->AnimationThing.Frame > 32.0)
//			{
//				a1->TailsFlightTime = 0;
//				object_00560DD0.model = &attach_00575AB4;
//			}
//			else
//			{
//				v5 = (32.0 - a1->AnimationThing.Frame) * 0.0625;
//				a1->TailsFlightTime = v5;
//				MorphPoints(&attach_00575AB4, &attach_0057630C, &attach_0057525C, v5);
//				object_00560DD0.model = &attach_0057525C;
//			}
//		}
//		else
//		{
//			v4 = (a1->AnimationThing.Frame - 8.0) * 0.125;
//			a1->TailsFlightTime = v4;
//			MorphPoints(&attach_00575AB4, &attach_0057630C, &attach_0057525C, v4);
//			object_00560DD0.model = &attach_0057525C;
//		}
//	}
//	else
//	{
//		a1->SomeFrameNumberThing = 0;
//		a1->TailsFlightTime = 0;
//		object_0055F330.model = &attach_0055F304;
//		object_00560DD0.model = &attach_00560DA4;
//	}
//}

void __cdecl Sonic_MorphStretchyFeet_c(CharObj2* a1)
{
	float a4; // ST10_4@3
	float v2; // ST10_4@5
	NJS_MODEL_SADX *v3; // ecx@5
	float v4; // ST10_4@10
	float v5; // ST10_4@13

	if (a1->Upgrades & Upgrades_LightShoes)
	{
		if (a1->AnimationThing.Index == 13)
		{
			if (a1->AnimationThing.Frame >= 16.0)
			{
				if (a1->AnimationThing.Frame <= 24.0)
				{
					a1->SomeFrameNumberThing = 0;
					v3 = &LSDashMorph_Left3;
				}
				else
				{
					v2 = (a1->AnimationThing.Frame - 24.0) * 0.125;
					a1->SomeFrameNumberThing = v2;
					MorphPoints(&LSDashMorph_Left3, &LSDashMorph_Left2, &LSDashMorph_Left1, v2);
					v3 = &LSDashMorph_Left1;
				}
				object_005818AC.model = v3;
			}
			else
			{
				a4 = (16.0 - a1->AnimationThing.Frame) * 0.0625;
				a1->SomeFrameNumberThing = a4;
				MorphPoints(&LSDashMorph_Left3, &LSDashMorph_Left2, &LSDashMorph_Left1, a4);
				object_005818AC.model = &LSDashMorph_Left1;
			}
			if (a1->AnimationThing.Frame < 8.0 || a1->AnimationThing.Frame > 16.0)
			{
				if (a1->AnimationThing.Frame <= 16.0 || a1->AnimationThing.Frame > 32.0)
				{
					a1->TailsFlightTime = 0;
					object_005825A4.model = &LSDashMorph_Right2;
				}
				else
				{
					v5 = (32.0 - a1->AnimationThing.Frame) * 0.0625;
					a1->TailsFlightTime = v5;
					MorphPoints(&LSDashMorph_Right2, &LSDashMorph_Right3, &LSDashMorph_Right1, v5);
					object_005825A4.model = &LSDashMorph_Right1;
				}
			}
			else
			{
				v4 = (a1->AnimationThing.Frame - 8.0) * 0.125;
				a1->TailsFlightTime = v4;
				MorphPoints(&LSDashMorph_Right2, &LSDashMorph_Right3, &LSDashMorph_Right1, v4);
				object_005825A4.model = &LSDashMorph_Right1;
			}
		}
		else
		{
			a1->SomeFrameNumberThing = 0;
			a1->TailsFlightTime = 0;
			object_005818AC.model = &attach_00581880;
			object_005825A4.model = &attach_00582578;
		}
	}
	else
	{
		if (a1->AnimationThing.Index == 13)
		{
			if (a1->AnimationThing.Frame >= 16.0)
			{
				if (a1->AnimationThing.Frame <= 24.0)
				{
					a1->SomeFrameNumberThing = 0;
					v3 = &attach_0057464C;
				}
				else
				{
					v2 = (a1->AnimationThing.Frame - 24.0) * 0.125;
					a1->SomeFrameNumberThing = v2;
					MorphPoints(&attach_0057464C, &attach_00573DFC, &attach_005735AC, v2);
					v3 = &attach_005735AC;
				}
				object_0055F330.model = v3;
			}
			else
			{
				a4 = (16.0 - a1->AnimationThing.Frame) * 0.0625;
				a1->SomeFrameNumberThing = a4;
				MorphPoints(&attach_0057464C, &attach_00573DFC, &attach_005735AC, a4);
				object_0055F330.model = &attach_005735AC;
			}
			if (a1->AnimationThing.Frame < 8.0 || a1->AnimationThing.Frame > 16.0)
			{
				if (a1->AnimationThing.Frame <= 16.0 || a1->AnimationThing.Frame > 32.0)
				{
					a1->TailsFlightTime = 0;
					object_00560DD0.model = &attach_00575AB4;
				}
				else
				{
					v5 = (32.0 - a1->AnimationThing.Frame) * 0.0625;
					a1->TailsFlightTime = v5;
					MorphPoints(&attach_00575AB4, &attach_0057630C, &attach_0057525C, v5);
					object_00560DD0.model = &attach_0057525C;
				}
			}
			else
			{
				v4 = (a1->AnimationThing.Frame - 8.0) * 0.125;
				a1->TailsFlightTime = v4;
				MorphPoints(&attach_00575AB4, &attach_0057630C, &attach_0057525C, v4);
				object_00560DD0.model = &attach_0057525C;
			}
		}
		else
		{
			a1->SomeFrameNumberThing = 0;
			a1->TailsFlightTime = 0;
			object_0055F330.model = &attach_0055F304;
			object_00560DD0.model = &attach_00560DA4;
		}
	}
}
static void __declspec(naked) Sonic_MorphStretchyFeet_asm()
{
	__asm
	{
		push esi // a1
		call Sonic_MorphStretchyFeet_c
		pop esi // a1
		retn
	}
}

extern "C" __declspec(dllexport) void __cdecl Init(const char *path, const HelperFunctions &helperFunctions)
{
	HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");

	//Sonic Data for DLL Export
	ResizeTextureList((NJS_TEXLIST *)0x91CB58, 28);
	NJS_OBJECT **___SONIC_OBJECTS = (NJS_OBJECT **)GetProcAddress(handle, "___SONIC_OBJECTS");
	NJS_ACTION **___SONIC_ACTIONS = (NJS_ACTION **)GetProcAddress(handle, "___SONIC_ACTIONS");
	NJS_MODEL_SADX **___SONIC_MODELS = (NJS_MODEL_SADX **)GetProcAddress(handle, "___SONIC_MODELS");
	NJS_MOTION **___SONIC_MOTIONS = (NJS_MOTION **)GetProcAddress(handle, "___SONIC_MOTIONS");
	___SONIC_OBJECTS[0] = &object_0056AF50;
	___SONIC_OBJECTS[1] = &object_00563B7C;
	___SONIC_OBJECTS[2] = &object_00563D0C;
	___SONIC_OBJECTS[3] = &object_005654EC;
	___SONIC_OBJECTS[4] = &object_00564CD0;
	___SONIC_OBJECTS[5] = &object_005647B8;
	___SONIC_OBJECTS[6] = &object_00564A78;
	___SONIC_OBJECTS[7] = &object_00561F14;
	___SONIC_OBJECTS[8] = &object_005620A4;
	___SONIC_OBJECTS[9] = &object_005638CC;
	___SONIC_OBJECTS[10] = &object_005630B0;
	___SONIC_OBJECTS[11] = &object_00562B80;
	___SONIC_OBJECTS[12] = &object_0056044C;
	___SONIC_OBJECTS[13] = &object_005605DC;
	___SONIC_OBJECTS[14] = &object_00561C68;
	___SONIC_OBJECTS[15] = &object_005613F8;
	___SONIC_OBJECTS[16] = &object_00560DD0;
	___SONIC_OBJECTS[17] = &object_0055E99C;
	___SONIC_OBJECTS[18] = &object_0055EB2C;
	___SONIC_OBJECTS[19] = &object_005601B8;
	___SONIC_OBJECTS[20] = &object_0055F948;
	___SONIC_OBJECTS[21] = &object_0055F330;
	___SONIC_OBJECTS[22] = &object_0062DE88;
	___SONIC_OBJECTS[23] = &object_00626AB4;
	___SONIC_OBJECTS[24] = &object_00626C44;
	___SONIC_OBJECTS[25] = &object_0062840C;
	___SONIC_OBJECTS[26] = &object_00627BF0;
	___SONIC_OBJECTS[27] = &object_006276D8;
	___SONIC_OBJECTS[28] = &object_00624E3C;
	___SONIC_OBJECTS[29] = &object_00624FCC;
	___SONIC_OBJECTS[30] = &object_006267F4;
	___SONIC_OBJECTS[31] = &object_00625FD8;
	___SONIC_OBJECTS[32] = &object_00625AA8;
	___SONIC_OBJECTS[33] = &object_00623474;
	___SONIC_OBJECTS[34] = &object_00623604;
	___SONIC_OBJECTS[35] = &object_00624B78;
	___SONIC_OBJECTS[36] = &object_00624308;
	___SONIC_OBJECTS[37] = &object_00623C14;
	___SONIC_OBJECTS[38] = &object_00621AC4;
	___SONIC_OBJECTS[39] = &object_00621C54;
	___SONIC_OBJECTS[40] = &object_006231E0;
	___SONIC_OBJECTS[41] = &object_00622970;
	___SONIC_OBJECTS[42] = &object_00622254;
	___SONIC_OBJECTS[44] = &object_0057BC44;
	___SONIC_OBJECTS[45] = &object_0056998C;
	___SONIC_OBJECTS[46] = &object_00569594;
	___SONIC_OBJECTS[47] = &object_005812AC;
	___SONIC_OBJECTS[48] = &object_00569DEC;
	___SONIC_OBJECTS[49] = &object_00569594;
	___SONIC_OBJECTS[50] = &object_00569E20;
	___SONIC_OBJECTS[51] = &object_00569CE8;
	___SONIC_OBJECTS[52] = &object_005698F0;
	___SONIC_OBJECTS[58] = &object_00581FB8;
	___SONIC_OBJECTS[59] = &object_005818AC;
	___SONIC_OBJECTS[60] = &object_00582CC0;
	___SONIC_OBJECTS[61] = &object_005825A4;
	___SONIC_OBJECTS[62] = &object_00565520;
	___SONIC_OBJECTS[63] = &object_00583284;
	___SONIC_OBJECTS[64] = &object_00583904;
	___SONIC_OBJECTS[65] = &object_00585EB4;
	___SONIC_OBJECTS[66] = &object_005729CC;
	___SONIC_OBJECTS[67] = &object_0057BC44;
	___SONIC_ACTIONS[0]->object = &object_0056AF50;
	___SONIC_ACTIONS[1]->object = &object_0056AF50;
	___SONIC_ACTIONS[2]->object = &object_0056AF50;
	___SONIC_ACTIONS[3]->object = &object_0056AF50;
	___SONIC_ACTIONS[4]->object = &object_0056AF50;
	___SONIC_ACTIONS[5]->object = &object_0056AF50;
	___SONIC_ACTIONS[6]->object = &object_0056AF50;
	___SONIC_ACTIONS[7]->object = &object_0056AF50;
	___SONIC_ACTIONS[8]->object = &object_0056AF50;
	___SONIC_ACTIONS[9]->object = &object_0056AF50;
	___SONIC_ACTIONS[10]->object = &object_0056AF50;
	___SONIC_ACTIONS[11]->object = &object_0056AF50;
	___SONIC_ACTIONS[12]->object = &object_0056AF50;
	___SONIC_ACTIONS[13]->object = &object_0056AF50;
	___SONIC_ACTIONS[14]->object = &object_005729CC;
	___SONIC_ACTIONS[15]->object = &object_0056AF50;
	___SONIC_ACTIONS[16]->object = &object_0056AF50;
	___SONIC_ACTIONS[17]->object = &object_0056AF50;
	___SONIC_ACTIONS[18]->object = &object_0056AF50;
	___SONIC_ACTIONS[19]->object = &object_0056AF50;
	___SONIC_ACTIONS[20]->object = &object_0056AF50;
	___SONIC_ACTIONS[21]->object = &object_0057BC44;
	___SONIC_ACTIONS[22]->object = &object_0056AF50;
	___SONIC_ACTIONS[23]->object = &object_0056AF50;
	___SONIC_ACTIONS[27]->object = &object_0056AF50;
	___SONIC_ACTIONS[28]->object = &object_0056AF50;
	___SONIC_ACTIONS[29]->object = &object_0056AF50;
	___SONIC_ACTIONS[30]->object = &object_0056AF50;
	___SONIC_ACTIONS[31]->object = &object_0056AF50;
	___SONIC_ACTIONS[32]->object = &object_0056AF50;
	___SONIC_ACTIONS[33]->object = &object_0056AF50;
	___SONIC_ACTIONS[34]->object = &object_0056AF50;
	___SONIC_ACTIONS[35]->object = &object_0056AF50;
	___SONIC_ACTIONS[36]->object = &object_0056AF50;
	___SONIC_ACTIONS[37]->object = &object_0056AF50;
	___SONIC_ACTIONS[38]->object = &object_0056AF50;
	___SONIC_ACTIONS[39]->object = &object_0056AF50;
	___SONIC_ACTIONS[40]->object = &object_0056AF50;
	___SONIC_ACTIONS[41]->object = &object_0056AF50;
	___SONIC_ACTIONS[42]->object = &object_0056AF50;
	___SONIC_ACTIONS[43]->object = &object_0056AF50;
	___SONIC_ACTIONS[44]->object = &object_0056AF50;
	___SONIC_ACTIONS[45]->object = &object_0056AF50;
	___SONIC_ACTIONS[46]->object = &object_0056AF50;
	___SONIC_ACTIONS[47]->object = &object_0056AF50;
	___SONIC_ACTIONS[48]->object = &object_0056AF50;
	___SONIC_ACTIONS[49]->object = &object_0056AF50;
	___SONIC_ACTIONS[50]->object = &object_0056AF50;
	___SONIC_ACTIONS[51]->object = &object_0056AF50;
	___SONIC_ACTIONS[52]->object = &object_0056AF50;
	___SONIC_ACTIONS[53]->object = &object_0056AF50;
	___SONIC_ACTIONS[54]->object = &object_0056AF50;
	___SONIC_ACTIONS[55]->object = &object_0056AF50;
	___SONIC_ACTIONS[56]->object = &object_0056AF50;
	___SONIC_ACTIONS[57]->object = &object_0056AF50;
	___SONIC_ACTIONS[58]->object = &object_0056AF50;
	___SONIC_ACTIONS[59]->object = &object_0056AF50;
	___SONIC_ACTIONS[60]->object = &object_0056AF50;
	___SONIC_ACTIONS[61]->object = &object_0056AF50;
	___SONIC_ACTIONS[62]->object = &object_0056AF50;
	___SONIC_ACTIONS[63]->object = &object_0056AF50;
	___SONIC_ACTIONS[64]->object = &object_0056AF50;
	___SONIC_ACTIONS[65]->object = &object_0056AF50;
	___SONIC_ACTIONS[66]->object = &object_0056AF50;
	___SONIC_ACTIONS[67]->object = &object_0056AF50;
	___SONIC_ACTIONS[68]->object = &object_0056AF50;
	___SONIC_ACTIONS[69]->object = &object_0056AF50;
	___SONIC_ACTIONS[70]->object = &object_0056AF50;
	___SONIC_ACTIONS[71]->object = &object_0056AF50;
	___SONIC_ACTIONS[72]->object = &object_0056AF50;
	___SONIC_ACTIONS[87]->object = &object_0056AF50;
	___SONIC_ACTIONS[88]->object = &object_0056AF50;
	___SONIC_ACTIONS[89]->object = &object_0056AF50;
	___SONIC_ACTIONS[90]->object = &object_0056AF50;
	___SONIC_ACTIONS[91]->object = &object_0056AF50;
	___SONIC_ACTIONS[92]->object = &object_0056AF50;
	___SONIC_ACTIONS[93]->object = &object_0056AF50;
	___SONIC_ACTIONS[94]->object = &object_0056AF50;
	___SONIC_ACTIONS[95]->object = &object_0056AF50;
	___SONIC_ACTIONS[96]->object = &object_0056AF50;
	___SONIC_ACTIONS[97]->object = &object_0056AF50;
	___SONIC_ACTIONS[98]->object = &object_0056AF50;
	___SONIC_ACTIONS[99]->object = &object_0056AF50;
	___SONIC_ACTIONS[100]->object = &object_0056AF50;
	___SONIC_ACTIONS[101]->object = &object_0056AF50;
	___SONIC_ACTIONS[102]->object = &object_0056AF50;
	___SONIC_ACTIONS[103]->object = &object_0056AF50;
	___SONIC_ACTIONS[104]->object = &object_0056AF50;
	___SONIC_ACTIONS[105]->object = &object_0056AF50;
	___SONIC_ACTIONS[106]->object = &object_0056AF50;
	___SONIC_ACTIONS[107]->object = &object_0056AF50;
	___SONIC_ACTIONS[108]->object = &object_0056AF50;
	___SONIC_ACTIONS[109]->object = &object_0056AF50;
	___SONIC_ACTIONS[113]->object = &object_0056AF50;
	___SONIC_ACTIONS[114]->object = &object_0056AF50;
	___SONIC_ACTIONS[115]->object = &object_0056AF50;
	___SONIC_ACTIONS[116]->object = &object_0056AF50;
	___SONIC_ACTIONS[117]->object = &object_0056AF50;
	___SONIC_ACTIONS[118]->object = &object_0056AF50;
	___SONIC_ACTIONS[119]->object = &object_0056AF50;
	___SONIC_ACTIONS[120]->object = &object_0056AF50;
	___SONIC_ACTIONS[121]->object = &object_0056AF50;
	___SONIC_ACTIONS[122]->object = &object_0056AF50;
	___SONIC_ACTIONS[123]->object = &object_0056AF50;
	___SONIC_ACTIONS[124]->object = &object_0056AF50;
	___SONIC_ACTIONS[125]->object = &object_0056AF50;
	___SONIC_ACTIONS[126]->object = &object_0056AF50;
	___SONIC_ACTIONS[127]->object = &object_0056AF50;
	___SONIC_ACTIONS[128]->object = &object_0056AF50;
	___SONIC_ACTIONS[129]->object = &object_0056AF50;
	___SONIC_ACTIONS[130]->object = &object_0062DE88;
	___SONIC_ACTIONS[131]->object = &object_0062DE88;
	___SONIC_ACTIONS[132]->object = &object_0062DE88;
	___SONIC_ACTIONS[133]->object = &object_0062DE88;
	___SONIC_ACTIONS[134]->object = &object_0056AF50;
	___SONIC_ACTIONS[135]->object = &object_0056AF50;
	___SONIC_ACTIONS[136]->object = &object_0056AF50;
	___SONIC_ACTIONS[137]->object = &object_0056AF50;
	___SONIC_ACTIONS[138]->object = &object_0062DE88;
	___SONIC_ACTIONS[139]->object = &object_0062DE88;
	___SONIC_ACTIONS[140]->object = &object_0062DE88;
	___SONIC_ACTIONS[141]->object = &object_0062DE88;
	___SONIC_ACTIONS[143]->object = &object_0062DE88;
	___SONIC_ACTIONS[144]->object = &object_0062DE88;
	___SONIC_ACTIONS[145]->object = &object_0056AF50;
	___SONIC_ACTIONS[146]->object = &object_0056AF50;
	___SONIC_ACTIONS[147]->object = &object_0056AF50;
	___SONIC_ACTIONS[148]->object = &object_0056AF50;
	___SONIC_MODELS[0] = &attach_0055F304;
	___SONIC_MODELS[1] = &attach_00560DA4;
	___SONIC_MODELS[2] = &attach_005735AC;
	___SONIC_MODELS[3] = &attach_00573DFC;
	___SONIC_MODELS[4] = &attach_0057464C;
	___SONIC_MODELS[5] = &attach_0057525C;
	___SONIC_MODELS[6] = &attach_00575AB4;
	___SONIC_MODELS[7] = &attach_0057630C;
	___SONIC_MODELS[8] = &attach_00569568;
	___SONIC_MODELS[9] = &attach_00579C68;
	___SONIC_MOTIONS[0] = &CinematicHead;
	WriteData((WeldInfo**)0x49AB7E, SonicWeldInfo);
	WriteData((WeldInfo**)0x49ABAC, SonicWeldInfo);
	WriteData((WeldInfo**)0x49AC3C, SonicWeldInfo);
	WriteData((WeldInfo**)0x49ACB6, SonicWeldInfo);

	//Tails Model Data
	ResizeTextureList((NJS_TEXLIST *)0x91A9C8, 24);
	NJS_OBJECT **___MILES_OBJECTS = (NJS_OBJECT **)GetProcAddress(handle, "___MILES_OBJECTS");
	NJS_ACTION **___MILES_ACTIONS = (NJS_ACTION **)GetProcAddress(handle, "___MILES_ACTIONS");
	NJS_MODEL_SADX **___MILES_MODELS = (NJS_MODEL_SADX **)GetProcAddress(handle, "___MILES_MODELS");
	NJS_MOTION **___MILES_MOTIONS = (NJS_MOTION **)GetProcAddress(handle, "___MILES_MOTIONS");
	___MILES_OBJECTS[0] = &object_0042AD54;
	___MILES_OBJECTS[1] = &object_00437C44;
	___MILES_OBJECTS[2] = &object_0043F4B4;
	___MILES_OBJECTS[3] = &object_0044148C;
	___MILES_OBJECTS[4] = &object_0042ABE8;
	___MILES_OBJECTS[5] = &object_00437AD8;
	___MILES_OBJECTS[6] = &object_0042AC84;
	___MILES_OBJECTS[7] = &object_00437B74;
	___MILES_OBJECTS[8] = &object_00426ED0;
	___MILES_OBJECTS[9] = &object_00426B90;
	___MILES_OBJECTS[10] = &object_00433DC0;
	___MILES_OBJECTS[11] = &object_00433A80;
	___MILES_OBJECTS[12] = &object_0041E548;
	___MILES_OBJECTS[13] = &object_0041EC90;
	___MILES_OBJECTS[14] = &object_0041ED2C;
	___MILES_OBJECTS[15] = &object_0041E5E4;
	___MILES_OBJECTS[16] = &object_0042BC1C;
	___MILES_OBJECTS[17] = &object_0042B4D4;
	___MILES_OBJECTS[18] = &object_0042BBE8;
	___MILES_OBJECTS[19] = &object_0042B4A0;
	___MILES_OBJECTS[20] = &object_00424D00;
	___MILES_OBJECTS[21] = &object_00424E94;
	___MILES_OBJECTS[22] = &object_0042674C;
	___MILES_OBJECTS[23] = &object_00422FD8;
	___MILES_OBJECTS[24] = &object_0042316C;
	___MILES_OBJECTS[25] = &object_00424A14;
	___MILES_OBJECTS[26] = &object_0042182C;
	___MILES_OBJECTS[27] = &object_004219BC;
	___MILES_OBJECTS[28] = &object_00422CF0;
	___MILES_OBJECTS[29] = &object_004200CC;
	___MILES_OBJECTS[30] = &object_0042025C;
	___MILES_OBJECTS[31] = &object_00421598;
	___MILES_OBJECTS[32] = &object_004225C8;
	___MILES_OBJECTS[33] = &object_00421FE4;
	___MILES_OBJECTS[34] = &object_00420E70;
	___MILES_OBJECTS[35] = &object_00420884;
	___MILES_OBJECTS[36] = &object_00425E88;
	___MILES_OBJECTS[37] = &object_00425C40;
	___MILES_OBJECTS[38] = &object_00424158;
	___MILES_OBJECTS[39] = &object_00423F10;
	___MILES_OBJECTS[40] = &object_00431BF0;
	___MILES_OBJECTS[41] = &object_00431D84;
	___MILES_OBJECTS[42] = &object_0043363C;
	___MILES_OBJECTS[43] = &object_0042FEC8;
	___MILES_OBJECTS[44] = &object_0043005C;
	___MILES_OBJECTS[45] = &object_00431904;
	___MILES_OBJECTS[46] = &object_0042E71C;
	___MILES_OBJECTS[47] = &object_0042E8AC;
	___MILES_OBJECTS[48] = &object_0042FBE0;
	___MILES_OBJECTS[49] = &object_0042CFBC;
	___MILES_OBJECTS[50] = &object_0042D14C;
	___MILES_OBJECTS[51] = &object_0042E488;
	___MILES_OBJECTS[52] = &object_0042F4B8;
	___MILES_OBJECTS[53] = &object_0042EED4;
	___MILES_OBJECTS[54] = &object_0042DD60;
	___MILES_OBJECTS[55] = &object_0042D774;
	___MILES_OBJECTS[56] = &object_00432D78;
	___MILES_OBJECTS[57] = &object_00432B30;
	___MILES_OBJECTS[58] = &object_00431048;
	___MILES_OBJECTS[59] = &object_00430E00;
	___MILES_OBJECTS[60] = &object_0046E63C;
	___MILES_OBJECTS[61] = &object_0046F46C;
	___MILES_OBJECTS[62] = &object_0041FE04;
	___MILES_OBJECTS[63] = &object_0042CCF4;
	___MILES_OBJECTS[64] = &object_0046EE44;
	___MILES_OBJECTS[65] = &object_0046FC84;
	___MILES_OBJECTS[66] = &object_0042AC1C;
	___MILES_OBJECTS[67] = &object_0042ABE8;
	___MILES_OBJECTS[68] = &object_00437B0C;
	___MILES_OBJECTS[69] = &object_00437AD8;
	___MILES_OBJECTS[70] = &object_0044C724;
	___MILES_ACTIONS[0]->object = &object_00437C44;
	___MILES_ACTIONS[1]->object = &object_00437C44;
	___MILES_ACTIONS[2]->object = &object_00437C44;
	___MILES_ACTIONS[3]->object = &object_00437C44;
	___MILES_ACTIONS[4]->object = &object_00437C44;
	___MILES_ACTIONS[5]->object = &object_00437C44;
	___MILES_ACTIONS[6]->object = &object_00437C44;
	___MILES_ACTIONS[7]->object = &object_00437C44;
	___MILES_ACTIONS[8]->object = &object_00437C44;
	___MILES_ACTIONS[9]->object = &object_00437C44;
	___MILES_ACTIONS[10]->object = &object_00437C44;
	___MILES_ACTIONS[11]->object = &object_0042AD54;
	___MILES_ACTIONS[12]->object = &object_0042AD54;
	___MILES_ACTIONS[13]->object = &object_0042AD54;
	___MILES_ACTIONS[14]->object = &object_0042AD54;
	___MILES_ACTIONS[15]->object = &object_0042AD54;
	___MILES_ACTIONS[16]->object = &object_0042AD54;
	___MILES_ACTIONS[17]->object = &object_00437C44;
	___MILES_ACTIONS[18]->object = &object_00437C44;
	___MILES_ACTIONS[19]->object = &object_00437C44;
	___MILES_ACTIONS[20]->object = &object_00437C44;
	___MILES_ACTIONS[21]->object = &object_0042AD54;
	___MILES_ACTIONS[22]->object = &object_0042AD54;
	___MILES_ACTIONS[23]->object = &object_0042AD54;
	___MILES_ACTIONS[24]->object = &object_0042AD54;
	___MILES_ACTIONS[25]->object = &object_0042AD54;
	___MILES_ACTIONS[26]->object = &object_0042AD54;
	___MILES_ACTIONS[27]->object = &object_0042AD54;
	___MILES_ACTIONS[28]->object = &object_0042AD54;
	___MILES_ACTIONS[29]->object = &object_0042AD54;
	___MILES_ACTIONS[30]->object = &object_0042AD54;
	___MILES_ACTIONS[31]->object = &object_0042AD54;
	___MILES_ACTIONS[32]->object = &object_0042AD54;
	___MILES_ACTIONS[33]->object = &object_0042AD54;
	___MILES_ACTIONS[34]->object = &object_0042AD54;
	___MILES_ACTIONS[35]->object = &object_0042AD54;
	___MILES_ACTIONS[36]->object = &object_0042AD54;
	___MILES_ACTIONS[37]->object = &object_0042AD54;
	___MILES_ACTIONS[38]->object = &object_0042AD54;
	___MILES_ACTIONS[39]->object = &object_0042AD54;
	___MILES_ACTIONS[40]->object = &object_0042AD54;
	___MILES_ACTIONS[41]->object = &object_0042AD54;
	___MILES_ACTIONS[42]->object = &object_0042AD54;
	___MILES_ACTIONS[43]->object = &object_0042AD54;
	___MILES_ACTIONS[44]->object = &object_0042AD54;
	___MILES_ACTIONS[45]->object = &object_0042AD54;
	___MILES_ACTIONS[46]->object = &object_0042AD54;
	___MILES_ACTIONS[47]->object = &object_0042AD54;
	___MILES_ACTIONS[48]->object = &object_0042AD54;
	___MILES_ACTIONS[49]->object = &object_0042AD54;
	___MILES_ACTIONS[50]->object = &object_0042AD54;
	___MILES_ACTIONS[51]->object = &object_0042AD54;
	___MILES_ACTIONS[52]->object = &object_0042AD54;
	___MILES_ACTIONS[53]->object = &object_00437C44;
	___MILES_ACTIONS[54]->object = &object_00437C44;
	___MILES_ACTIONS[55]->object = &object_0042AD54;
	___MILES_ACTIONS[56]->object = &object_0042AD54;
	___MILES_ACTIONS[57]->object = &object_0042AD54;
	___MILES_ACTIONS[58]->object = &object_0042AD54;
	___MILES_ACTIONS[59]->object = &object_0042AD54;
	___MILES_ACTIONS[60]->object = &object_0042AD54;
	___MILES_ACTIONS[61]->object = &object_0042AD54;
	___MILES_ACTIONS[62]->object = &object_0042AD54;
	___MILES_ACTIONS[63]->object = &object_0042AD54;
	___MILES_ACTIONS[64]->object = &object_0043F4B4;
	___MILES_ACTIONS[65]->object = &object_0044148C;
	___MILES_ACTIONS[66]->object = &object_0042AD54;
	___MILES_ACTIONS[67]->object = &object_0042AD54;
	___MILES_ACTIONS[68]->object = &object_0042AD54;
	___MILES_ACTIONS[69]->object = &object_0042AD54;
	___MILES_ACTIONS[70]->object = &object_0042AD54;
	___MILES_ACTIONS[71]->object = &object_0042AD54;
	___MILES_ACTIONS[72]->object = &object_0042AD54;
	___MILES_ACTIONS[73]->object = &object_0042AD54;
	___MILES_ACTIONS[74]->object = &object_0042AD54;
	___MILES_ACTIONS[75]->object = &object_0042AD54;
	___MILES_ACTIONS[76]->object = &object_0042AD54;
	___MILES_ACTIONS[77]->object = &object_0042AD54;
	___MILES_ACTIONS[78]->object = &object_0042AD54;
	___MILES_ACTIONS[79]->object = &object_0042AD54;
	___MILES_ACTIONS[80]->object = &object_0042AD54;
	___MILES_ACTIONS[81]->object = &object_0042AD54;
	___MILES_ACTIONS[82]->object = &object_0042AD54;
	___MILES_ACTIONS[83]->object = &object_0042AD54;
	___MILES_ACTIONS[85]->object = &object_0042AD54;
	___MILES_ACTIONS[86]->object = &object_0042AD54;
	___MILES_ACTIONS[87]->object = &object_0042AD54;
	___MILES_ACTIONS[88]->object = &object_0042AD54;
	___MILES_ACTIONS[91]->object = &object_0042AD54;
	___MILES_ACTIONS[92]->object = &object_0042AD54;
	___MILES_ACTIONS[93]->object = &object_0042AD54;
	___MILES_ACTIONS[94]->object = &object_0042AD54;
	___MILES_ACTIONS[95]->object = &object_0042AD54;
	___MILES_ACTIONS[96]->object = &object_0042AD54;
	___MILES_ACTIONS[97]->object = &object_0042AD54;
	___MILES_ACTIONS[110]->object = &object_0042AD54;
	___MILES_ACTIONS[111]->object = &object_0042AD54;
	___MILES_ACTIONS[112]->object = &object_0042AD54;
	___MILES_ACTIONS[113]->object = &object_0042AD54;
	___MILES_MODELS[0] = &attach_0041FDD8;
	___MILES_MODELS[1] = &attach_0042CCC8;
	___MILES_MODELS[2] = &attach_0042ABBC;
	___MILES_MODELS[3] = &attach_00437AAC;
	___MILES_MODELS[4] = &attach_0044517C;
	___MILES_MODELS[5] = &attach_0041E51C;
	___MILES_MODELS[6] = &attach_0041EC64;
	___MILES_MODELS[7] = &attach_0042B40C;
	___MILES_MODELS[8] = &attach_0042BB54;
	___MILES_MODELS[9] = &attach_00445778;
	___MILES_MODELS[10] = &attach_00445DA8;
	___MILES_MODELS[11] = &attach_00446A08;
	___MILES_MODELS[12] = &attach_00447038;
	___MILES_MODELS[13] = &attach_004463D8;
	___MILES_MODELS[14] = &attach_0046DFE8;
	___MILES_MOTIONS[0] = &TailsCinematicHead;
	WriteData((WeldInfo**)0x00461896, TailsWeldInfo);
	//WriteData((void*)0x0045B821, 0x90u, 3);
	//WriteData((void*)0x0045B835, 0x90u, 3);
	//WriteData((void*)0x0045BB60, 0x90u, 3);
	//WriteData((void*)0x0045BB74, 0x90u, 3);

	//Sky Chase
	WriteData((NJS_OBJECT**)0x0028B7A0C, &Tornado1_Object);
	WriteData((NJS_OBJECT**)0x0028BA71C, &Tornado1_Object);
	WriteData((NJS_OBJECT**)0x0028BDDBC, &Tornado1_Object);
	WriteData((NJS_OBJECT**)0x0028C09FC, &Tornado1_Object);
	WriteData((NJS_OBJECT**)0x002935DFC, &TornadoDestroyed_Object);
	WriteData((NJS_OBJECT**)0x0027EFDDC, &Tornado2Before_Object);
	WriteData((NJS_OBJECT**)0x0027F2AA4, &Tornado2Before_Object);
	WriteData((NJS_OBJECT**)0x0027F612C, &Tornado2Before_Object);
	WriteData((NJS_OBJECT**)0x0027F8974, &Tornado2Before_Object);
	WriteData((NJS_OBJECT**)0x0028988FC, &Tornado2Transformation_Object);
	WriteData((NJS_OBJECT**)0x00280F23C, &Tornado2Change_Object);
	WriteData((NJS_OBJECT**)0x002811CE4, &Tornado2Change_Object);
	WriteData((NJS_OBJECT**)0x002814D9C, &Tornado2Change_Object);
	WriteData((NJS_OBJECT**)0x002817514, &Tornado2Change_Object);

	//Event Data
	WriteData((NJS_ACTION**)0x006BF039, &EV_TR1_Action);
	WriteData((NJS_ACTION**)0x006BF3AA, &EV_TR1_Action);
	WriteData((NJS_ACTION**)0x006BF6B7, &EV_TR1_Action);
	WriteData((NJS_ACTION**)0x006DF5F4, &EV_TR1_Action);
	WriteData((NJS_ACTION**)0x006DFE45, &EV_TR1_Action);
	WriteData((NJS_OBJECT***)0x006BEE81, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x006BEEA1, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x006BEEC1, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x006BEF11, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x006DF421, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x006DF441, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x007D7BE1, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x007D7C11, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT***)0x007D7D01, &EV_TR1_Object.child);
	WriteData((NJS_OBJECT**)0x00664C3E, &OBJECT_SonicPointingFinger);
	WriteData((NJS_OBJECT**)0x0069E24B, &OBJECT_SonicPointingFinger);
	WriteData((NJS_OBJECT**)0x006D010C, &OBJECT_SonicPointingFinger);
	WriteData((NJS_OBJECT**)0x006D711E, &OBJECT_SonicPointingFinger);
	WriteData((NJS_ACTION**)0x006B9527, &EV_TR2BEFORE_Action);
	WriteData((NJS_ACTION**)0x006BA8B6, &EV_TR2BEFORE_Action);
	WriteData((NJS_ACTION**)0x006BA9E1, &EV_TR2BEFORE_Action);
	WriteData((NJS_ACTION**)0x006BABEB, &EV_TR2BEFORE_Action);
	WriteData((NJS_ACTION**)0x006BACF8, &EV_TR2BEFORE_Action);
	WriteData((NJS_ACTION**)0x006DA505, &EV_TR2BEFORE_Action);
	WriteData((NJS_OBJECT***)0x006B9281, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x006B9291, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x006BA0A1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x006BA0B1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x006DA2B1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x006DA2C1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7B41, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7B71, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7B91, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7BC1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7CB1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_OBJECT***)0x007D7CE1, &EV_TR2BEFORE_Object.child);
	WriteData((NJS_ACTION**)0x006AF5FE, &EV_TR2CHANGE_Action);
	WriteData((NJS_ACTION**)0x006AF92D, &EV_TR2CHANGE_Action);
	WriteData((NJS_ACTION**)0x006CDE0E, &EV_TR2CHANGE_Action);
	WriteData((NJS_ACTION**)0x006CE10D, &EV_TR2CHANGE_Action);
	ResizeTextureList((NJS_TEXLIST *)0x033315E4, 33);
	WriteData((NJS_OBJECT**)0x03342074, &EV_TailsProtoPlane);
	WriteData((NJS_OBJECT**)0x03344EAC, &EV_TailsProtoPlane);
	WriteData((NJS_OBJECT**)0x03347734, &EV_TailsProtoPlane);
	WriteData((NJS_OBJECT**)0x0334A8FC, &EV_TailsProtoPlane);
	WriteData((NJS_OBJECT**)0x006F9483, &EV_TailsCineHead_DC);
	WriteData((NJS_OBJECT**)0x0334A910, &EV_TailsCineHead_DC);
	WriteData((NJS_OBJECT**)0x0334A924, &EV_TailsCineHead_DC);
	WriteData((NJS_OBJECT**)0x0334A938, &EV_TailsCineHead_DC);
	WriteData((NJS_MOTION**)0x03375D88, &EV_Tails02);
	WriteData((NJS_MOTION**)0x03375D98, &EV_Tails01);
	WriteData((NJS_MOTION**)0x03375DA8, &EV_Tails01);
	WriteData((NJS_MOTION**)0x03375DB8, &EV_Tails00);

	WriteJump((void*)0x00493500, Sonic_MorphStretchyFeet_asm);
}

extern "C" __declspec(dllexport) const ModInfo SADXModInfo = { ModLoaderVer };