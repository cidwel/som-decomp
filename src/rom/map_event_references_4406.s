; Typed event references; docs/event-index-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4406
.macro map_event_reference command_id, upper_bits
    .word command_id | (upper_bits << 12)
.endmacro
map_008_event_references:
    map_event_reference $100, 0
map_00F_event_references:
    map_event_reference $64F, 0
map_010_event_references:
    map_event_reference $70E, 0
    map_event_reference $83F, 0
    map_event_reference $83F, 0
    map_event_reference $803, 0
    map_event_reference $803, 0
    map_event_reference $606, 0
    map_event_reference $805, 0
    map_event_reference $607, 0
    map_event_reference $905, 0
    map_event_reference $11F, 0
    map_event_reference $608, 0
    map_event_reference $600, 0
    map_event_reference $601, 0
    map_event_reference $806, 0
    map_event_reference $806, 0
map_011_event_references:
    map_event_reference $6D8, 0
    map_event_reference $B04, 0
    map_event_reference $B04, 0
    map_event_reference $B04, 0
    map_event_reference $B04, 0
    map_event_reference $838, 0
    map_event_reference $838, 0
    map_event_reference $838, 0
map_012_event_references:
    map_event_reference $626, 0
    map_event_reference $835, 0
    map_event_reference $835, 0
    map_event_reference $923, 0
    map_event_reference $923, 0
map_013_event_references:
    map_event_reference $70E, 0
    map_event_reference $807, 0
    map_event_reference $807, 0
    map_event_reference $604, 0
    map_event_reference $45A, 0
    map_event_reference $83E, 0
    map_event_reference $83E, 0
map_014_event_references:
    map_event_reference $3A8, 0
    map_event_reference $AA8, 0
    map_event_reference $AA8, 0
    map_event_reference $AAB, 0
    map_event_reference $AAB, 0
    map_event_reference $AA7, 0
    map_event_reference $AA7, 0
    map_event_reference $AA9, 0
    map_event_reference $AA9, 0
    map_event_reference $98A, 0
    map_event_reference $98A, 0
    map_event_reference $AAA, 0
    map_event_reference $AAA, 0
    map_event_reference $AAF, 0
    map_event_reference $AAF, 0
    map_event_reference $AAD, 0
    map_event_reference $AAD, 0
    map_event_reference $AB0, 0
    map_event_reference $AB0, 0
    map_event_reference $AAC, 0
    map_event_reference $AAC, 0
    map_event_reference $AAE, 0
    map_event_reference $AAE, 0
    map_event_reference $AB1, 0
    map_event_reference $AB1, 0
map_015_event_references:
    map_event_reference $647, 0
    map_event_reference $B29, 0
    map_event_reference $B2A, 0
    map_event_reference $B30, 0
    map_event_reference $B31, 0
    map_event_reference $ACE, 0
    map_event_reference $ACF, 0
    map_event_reference $9B2, 0
    map_event_reference $9B2, 0
    map_event_reference $9B2, 0
    map_event_reference $9B2, 0
map_016_event_references:
    map_event_reference $2FA, 0
    map_event_reference $A7E, 0
    map_event_reference $A72, 0
    map_event_reference $2FB, 0
    map_event_reference $B21, 0
    map_event_reference $A80, 0
map_017_event_references:
    map_event_reference $705, 0
    map_event_reference $85D, 0
    map_event_reference $85D, 0
    map_event_reference $602, 0
    map_event_reference $818, 0
    map_event_reference $818, 0
    map_event_reference $819, 0
    map_event_reference $819, 0
map_018_event_references:
    map_event_reference $627, 0
    map_event_reference $AE8, 0
    map_event_reference $AE9, 0
map_019_event_references:
    map_event_reference $705, 0
    map_event_reference $816, 0
    map_event_reference $816, 0
    map_event_reference $609, 0
    map_event_reference $836, 0
    map_event_reference $836, 0
    map_event_reference $817, 0
    map_event_reference $817, 0
    map_event_reference $820, 0
    map_event_reference $820, 0
map_01A_event_references:
    map_event_reference $AED, 0
    map_event_reference $AED, 0
    map_event_reference $AEC, 0
    map_event_reference $AEC, 0
map_01B_event_references:
    map_event_reference $705, 0
    map_event_reference $45B, 0
    map_event_reference $45B, 0
    map_event_reference $609, 0
    map_event_reference $890, 0
    map_event_reference $890, 0
    map_event_reference $890, 0
    map_event_reference $81C, 0
    map_event_reference $81C, 0
    map_event_reference $81C, 0
    map_event_reference $81C, 0
    map_event_reference $81C, 0
map_01C_event_references:
    map_event_reference $616, 0
    map_event_reference $1D8, 0
    map_event_reference $450, 0
map_01D_event_references:
    map_event_reference $451, 0
    map_event_reference $452, 0
    map_event_reference $453, 0
map_01E_event_references:
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $454, 0
    map_event_reference $455, 0
    map_event_reference $456, 0
    map_event_reference $6DA, 0
    map_event_reference $457, 0
map_01F_event_references:
    map_event_reference $616, 0
    map_event_reference $458, 0
    map_event_reference $459, 0
map_020_event_references:
    map_event_reference $A3C, 0
    map_event_reference $A3E, 0
    map_event_reference $2C2, 0
    map_event_reference $2C2, 0
    map_event_reference $2C1, 0
    map_event_reference $2C1, 0
map_023_event_references:
    map_event_reference $A38, 0
    map_event_reference $A38, 0
map_024_event_references:
    map_event_reference $B63, 0
    map_event_reference $B63, 0
    map_event_reference $B61, 0
    map_event_reference $B62, 0
    map_event_reference $B62, 0
    map_event_reference $AEB, 0
    map_event_reference $AEA, 0
    map_event_reference $AEA, 0
map_025_event_references:
    map_event_reference $AF3, 0
    map_event_reference $AF2, 0
    map_event_reference $AF2, 0
    map_event_reference $B64, 0
    map_event_reference $B65, 0
    map_event_reference $AF5, 0
    map_event_reference $AF1, 0
    map_event_reference $AF1, 0
    map_event_reference $AF4, 0
    map_event_reference $AF4, 0
    map_event_reference $AF0, 0
    map_event_reference $AF0, 0
    map_event_reference $B5E, 0
    map_event_reference $B5F, 0
    map_event_reference $AEF, 0
    map_event_reference $B60, 0
    map_event_reference $AEE, 0
    map_event_reference $AEE, 0
map_027_event_references:
    map_event_reference $619, 0
    map_event_reference $937, 0
    map_event_reference $937, 0
    map_event_reference $8B3, 0
    map_event_reference $8B3, 0
    map_event_reference $845, 0
    map_event_reference $845, 0
map_028_event_references:
    map_event_reference $619, 0
    map_event_reference $876, 0
    map_event_reference $876, 0
    map_event_reference $876, 0
    map_event_reference $883, 0
    map_event_reference $883, 0
    map_event_reference $883, 0
map_029_event_references:
    map_event_reference $619, 0
    map_event_reference $884, 0
    map_event_reference $884, 0
    map_event_reference $885, 0
    map_event_reference $885, 0
map_02A_event_references:
    map_event_reference $BB1, 0
    map_event_reference $BB1, 0
    map_event_reference $BBC, 0
    map_event_reference $BBC, 0
    map_event_reference $561, 0
    map_event_reference $563, 0
    map_event_reference $BB2, 0
    map_event_reference $BB2, 0
    map_event_reference $BB3, 0
    map_event_reference $BB3, 0
    map_event_reference $BB9, 0
    map_event_reference $BB9, 0
    map_event_reference $562, 0
    map_event_reference $560, 0
    map_event_reference $BB5, 0
    map_event_reference $BB5, 0
    map_event_reference $BB8, 0
    map_event_reference $BB8, 0
    map_event_reference $BB4, 0
    map_event_reference $BB4, 0
    map_event_reference $BBF, 0
    map_event_reference $BBF, 0
    map_event_reference $BBD, 0
    map_event_reference $BBD, 0
map_02B_event_references:
    map_event_reference $BC1, 0
    map_event_reference $BC3, 0
    map_event_reference $BC0, 0
    map_event_reference $BC0, 0
    map_event_reference $BBE, 0
    map_event_reference $BBE, 0
    map_event_reference $BBA, 0
    map_event_reference $BBA, 0
    map_event_reference $BBB, 0
    map_event_reference $BBB, 0
    map_event_reference $BC6, 0
    map_event_reference $BC6, 0
    map_event_reference $564, 0
    map_event_reference $4C9, 0
    map_event_reference $4C9, 0
    map_event_reference $BB7, 0
    map_event_reference $BB7, 0
    map_event_reference $BB6, 0
    map_event_reference $BB6, 0
    map_event_reference $BC5, 0
    map_event_reference $BC5, 0
map_02C_event_references:
    map_event_reference $BC4, 0
    map_event_reference $BC2, 0
map_02D_event_references:
    map_event_reference $BC4, 0
    map_event_reference $BC2, 0
map_02E_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
map_02F_event_references:
    map_event_reference $95C, 0
    map_event_reference $95D, 0
    map_event_reference $A27, 0
    map_event_reference $A27, 0
    map_event_reference $A27, 0
map_030_event_references:
    map_event_reference $2C6, 0
    map_event_reference $2C7, 0
    map_event_reference $A3B, 0
    map_event_reference $A3B, 0
map_031_event_references:
    map_event_reference $619, 0
    map_event_reference $244, 0
    map_event_reference $244, 0
    map_event_reference $244, 0
    map_event_reference $247, 0
    map_event_reference $247, 0
map_033_event_references:
    map_event_reference $B56, 0
    map_event_reference $B56, 0
map_034_event_references:
    map_event_reference $619, 0
    map_event_reference $9E4, 0
    map_event_reference $9E4, 0
    map_event_reference $9E4, 0
    map_event_reference $9E4, 0
    map_event_reference $246, 0
    map_event_reference $246, 0
    map_event_reference $246, 0
    map_event_reference $886, 0
    map_event_reference $241, 0
    map_event_reference $886, 0
    map_event_reference $241, 0
map_035_event_references:
    map_event_reference $619, 0
    map_event_reference $243, 0
    map_event_reference $243, 0
    map_event_reference $243, 0
    map_event_reference $243, 0
    map_event_reference $248, 0
    map_event_reference $248, 0
    map_event_reference $248, 0
    map_event_reference $240, 0
    map_event_reference $9EE, 0
    map_event_reference $240, 0
    map_event_reference $9EE, 0
map_036_event_references:
    map_event_reference $619, 0
    map_event_reference $245, 0
    map_event_reference $245, 0
    map_event_reference $242, 0
    map_event_reference $242, 0
    map_event_reference $242, 0
map_037_event_references:
    map_event_reference $619, 0
    map_event_reference $244, 0
    map_event_reference $244, 0
    map_event_reference $244, 0
    map_event_reference $247, 0
    map_event_reference $247, 0
map_038_event_references:
    map_event_reference $61A, 0
    map_event_reference $9E3, 0
    map_event_reference $9E3, 0
    map_event_reference $9E3, 0
    map_event_reference $9E3, 0
    map_event_reference $9E5, 0
    map_event_reference $9E5, 0
    map_event_reference $9E5, 0
    map_event_reference $9E5, 0
    map_event_reference $9E5, 0
    map_event_reference $9E5, 0
map_039_event_references:
    map_event_reference $619, 0
    map_event_reference $606, 0
    map_event_reference $9EF, 0
    map_event_reference $9EF, 0
map_03A_event_references:
    map_event_reference $24C, 0
    map_event_reference $24C, 0
    map_event_reference $24C, 0
    map_event_reference $24C, 0
map_03B_event_references:
    map_event_reference $619, 0
    map_event_reference $9F2, 0
    map_event_reference $9F2, 0
    map_event_reference $9F2, 0
    map_event_reference $9F2, 0
map_03C_event_references:
    map_event_reference $A26, 0
    map_event_reference $A26, 0
    map_event_reference $A26, 0
    map_event_reference $A26, 0
    map_event_reference $A26, 0
    map_event_reference $9E2, 0
    map_event_reference $9E2, 0
    map_event_reference $9E2, 0
    map_event_reference $9E2, 0
    map_event_reference $9E2, 0
map_03D_event_references:
    map_event_reference $625, 0
    map_event_reference $91C, 0
    map_event_reference $91C, 0
    map_event_reference $920, 0
    map_event_reference $920, 0
    map_event_reference $91A, 0
    map_event_reference $91A, 0
map_03E_event_references:
    map_event_reference $625, 0
    map_event_reference $6D8, 0
    map_event_reference $922, 0
    map_event_reference $922, 0
    map_event_reference $921, 0
map_03F_event_references:
    map_event_reference $624, 0
    map_event_reference $91E, 0
    map_event_reference $91E, 0
    map_event_reference $91E, 0
    map_event_reference $91E, 0
    map_event_reference $8A3, 0
    map_event_reference $8A5, 0
    map_event_reference $8A6, 0
    map_event_reference $91D, 0
    map_event_reference $91D, 0
map_040_event_references:
    map_event_reference $3E0, 0
    map_event_reference $987, 0
    map_event_reference $988, 0
    map_event_reference $97D, 0
    map_event_reference $97E, 0
    map_event_reference $91F, 0
    map_event_reference $91F, 0
    map_event_reference $91F, 0
    map_event_reference $91F, 0
map_041_event_references:
    map_event_reference $3E1, 0
    map_event_reference $980, 0
    map_event_reference $97F, 0
    map_event_reference $97F, 0
map_042_event_references:
    map_event_reference $982, 0
    map_event_reference $982, 0
    map_event_reference $981, 0
    map_event_reference $981, 0
    map_event_reference $983, 0
    map_event_reference $983, 0
    map_event_reference $984, 0
    map_event_reference $984, 0
map_043_event_references:
    map_event_reference $28A, 0
    map_event_reference $9DA, 0
    map_event_reference $9DA, 0
    map_event_reference $9DA, 0
    map_event_reference $9D1, 0
    map_event_reference $9D1, 0
    map_event_reference $9D1, 0
    map_event_reference $9D3, 0
    map_event_reference $9D3, 0
    map_event_reference $9D3, 0
map_044_event_references:
    map_event_reference $646, 0
    map_event_reference $9C8, 0
    map_event_reference $9C8, 0
    map_event_reference $9C8, 0
    map_event_reference $9D2, 0
    map_event_reference $9D2, 0
    map_event_reference $9D2, 0
    map_event_reference $9CA, 0
    map_event_reference $9CA, 0
    map_event_reference $9CA, 0
    map_event_reference $9C0, 0
    map_event_reference $9C0, 0
    map_event_reference $9C0, 0
map_045_event_references:
    map_event_reference $646, 0
    map_event_reference $A28, 0
    map_event_reference $A28, 0
    map_event_reference $A28, 0
    map_event_reference $9E8, 0
    map_event_reference $9E8, 0
    map_event_reference $9E8, 0
    map_event_reference $9EA, 0
    map_event_reference $9EA, 0
    map_event_reference $9EA, 0
map_046_event_references:
    map_event_reference $646, 0
    map_event_reference $A30, 0
    map_event_reference $A30, 0
    map_event_reference $A30, 0
    map_event_reference $A2C, 0
    map_event_reference $A2C, 0
    map_event_reference $A2C, 0
map_048_event_references:
    map_event_reference $3DB, 0
    map_event_reference $3DF, 0
    map_event_reference $3DF, 0
    map_event_reference $3DF, 0
    map_event_reference $3DF, 0
map_049_event_references:
    map_event_reference $62E, 0
    map_event_reference $848, 0
    map_event_reference $848, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $8EE, 0
    map_event_reference $8EE, 0
    map_event_reference $81A, 0
    map_event_reference $81A, 0
    map_event_reference $837, 0
    map_event_reference $837, 0
map_04B_event_references:
    map_event_reference $636, 0
    map_event_reference $A0A, 0
    map_event_reference $A0C, 0
    map_event_reference $A08, 0
    map_event_reference $A08, 0
map_04C_event_references:
    map_event_reference $633, 0
    map_event_reference $A03, 0
    map_event_reference $A03, 0
    map_event_reference $A05, 0
    map_event_reference $A05, 0
    map_event_reference $382, 0
    map_event_reference $382, 0
map_04D_event_references:
    map_event_reference $633, 0
    map_event_reference $380, 0
    map_event_reference $380, 0
    map_event_reference $A10, 0
    map_event_reference $A10, 0
map_04E_event_references:
    map_event_reference $633, 0
    map_event_reference $A04, 0
    map_event_reference $A04, 0
map_050_event_references:
    map_event_reference $633, 0
    map_event_reference $991, 0
    map_event_reference $A09, 0
    map_event_reference $A09, 0
map_051_event_references:
    map_event_reference $633, 0
    map_event_reference $A0D, 0
    map_event_reference $A0D, 0
    map_event_reference $606, 0
    map_event_reference $985, 0
    map_event_reference $985, 0
    map_event_reference $A0F, 0
    map_event_reference $A0F, 0
    map_event_reference $A0F, 0
map_052_event_references:
    map_event_reference $62C, 0
    map_event_reference $B3D, 0
    map_event_reference $B4F, 0
    map_event_reference $B41, 0
    map_event_reference $B3E, 0
    map_event_reference $B3F, 0
    map_event_reference $B32, 0
    map_event_reference $B32, 0
    map_event_reference $89C, 0
    map_event_reference $89C, 0
    map_event_reference $89C, 0
    map_event_reference $89C, 0
map_053_event_references:
    map_event_reference $633, 0
    map_event_reference $A07, 0
    map_event_reference $A07, 0
    map_event_reference $A06, 0
    map_event_reference $A06, 0
map_054_event_references:
    map_event_reference $288, 0
    map_event_reference $9B7, 0
    map_event_reference $9B7, 0
    map_event_reference $9B7, 0
map_055_event_references:
    map_event_reference $646, 0
    map_event_reference $9BD, 0
    map_event_reference $9BD, 0
    map_event_reference $9BD, 0
    map_event_reference $9BB, 0
    map_event_reference $9BB, 0
    map_event_reference $9BB, 0
    map_event_reference $9BA, 0
    map_event_reference $9BA, 0
    map_event_reference $9BA, 0
    map_event_reference $9C5, 0
    map_event_reference $9C5, 0
    map_event_reference $9C5, 0
map_056_event_references:
    map_event_reference $646, 0
    map_event_reference $9B9, 0
    map_event_reference $9B9, 0
    map_event_reference $9B9, 0
    map_event_reference $9C1, 0
    map_event_reference $9C1, 0
    map_event_reference $9C1, 0
    map_event_reference $9B8, 0
    map_event_reference $9B8, 0
    map_event_reference $9B8, 0
map_057_event_references:
    map_event_reference $646, 0
    map_event_reference $9BF, 0
    map_event_reference $9BF, 0
    map_event_reference $9BF, 0
    map_event_reference $9C4, 0
    map_event_reference $9C4, 0
    map_event_reference $9C4, 0
    map_event_reference $9BC, 0
    map_event_reference $9BC, 0
    map_event_reference $9BC, 0
    map_event_reference $9C7, 0
    map_event_reference $9C7, 0
    map_event_reference $9C7, 0
map_058_event_references:
    map_event_reference $646, 0
    map_event_reference $9C6, 0
    map_event_reference $9C6, 0
    map_event_reference $9C6, 0
    map_event_reference $9C9, 0
    map_event_reference $9C9, 0
    map_event_reference $9C9, 0
    map_event_reference $9CB, 0
    map_event_reference $9CB, 0
    map_event_reference $9CB, 0
    map_event_reference $9BE, 0
    map_event_reference $9BE, 0
    map_event_reference $9BE, 0
map_059_event_references:
    map_event_reference $61F, 0
    map_event_reference $98C, 0
    map_event_reference $9ED, 0
    map_event_reference $9ED, 0
    map_event_reference $9ED, 0
    map_event_reference $9ED, 0
    map_event_reference $A3F, 0
    map_event_reference $A3F, 0
    map_event_reference $A3F, 0
map_05A_event_references:
    map_event_reference $643, 0
    map_event_reference $A42, 0
    map_event_reference $A44, 0
    map_event_reference $A33, 0
    map_event_reference $A33, 0
map_05C_event_references:
    map_event_reference $646, 0
    map_event_reference $9EB, 0
    map_event_reference $9EB, 0
    map_event_reference $9EB, 0
    map_event_reference $9F3, 0
    map_event_reference $9F3, 0
    map_event_reference $9F3, 0
    map_event_reference $9F5, 0
    map_event_reference $9F5, 0
    map_event_reference $9F5, 0
map_05D_event_references:
    map_event_reference $646, 0
    map_event_reference $A32, 0
    map_event_reference $A32, 0
    map_event_reference $A32, 0
    map_event_reference $9F4, 0
    map_event_reference $9F4, 0
    map_event_reference $9F4, 0
map_05E_event_references:
    map_event_reference $646, 0
    map_event_reference $9E9, 0
    map_event_reference $9E9, 0
    map_event_reference $9E9, 0
    map_event_reference $A29, 0
    map_event_reference $A29, 0
    map_event_reference $A29, 0
    map_event_reference $9F7, 0
    map_event_reference $9F7, 0
    map_event_reference $9F7, 0
map_05F_event_references:
    map_event_reference $646, 0
    map_event_reference $9F8, 0
    map_event_reference $9F8, 0
    map_event_reference $9F8, 0
    map_event_reference $9F6, 0
    map_event_reference $9F6, 0
    map_event_reference $9F6, 0
    map_event_reference $A2B, 0
    map_event_reference $A2B, 0
    map_event_reference $A2B, 0
map_060_event_references:
    map_event_reference $646, 0
    map_event_reference $A3D, 0
    map_event_reference $A3D, 0
    map_event_reference $A3D, 0
    map_event_reference $A3D, 0
    map_event_reference $A2D, 0
    map_event_reference $A2D, 0
    map_event_reference $A2D, 0
map_061_event_references:
    map_event_reference $646, 0
    map_event_reference $A2E, 0
    map_event_reference $A2E, 0
    map_event_reference $A2E, 0
    map_event_reference $A2A, 0
    map_event_reference $A2A, 0
    map_event_reference $A2A, 0
    map_event_reference $A2F, 0
    map_event_reference $A2F, 0
    map_event_reference $A2F, 0
map_062_event_references:
    map_event_reference $28C, 0
    map_event_reference $9A9, 0
    map_event_reference $9A9, 0
    map_event_reference $9A7, 0
    map_event_reference $9A7, 0
    map_event_reference $9AD, 0
    map_event_reference $9AD, 0
    map_event_reference $9A6, 0
    map_event_reference $9A6, 0
    map_event_reference $9AF, 0
    map_event_reference $9A3, 0
    map_event_reference $9A3, 0
map_063_event_references:
    map_event_reference $28C, 0
    map_event_reference $9A9, 0
    map_event_reference $9A9, 0
    map_event_reference $9A7, 0
    map_event_reference $9A7, 0
    map_event_reference $9AD, 0
    map_event_reference $9AD, 0
    map_event_reference $9A6, 0
    map_event_reference $9A6, 0
    map_event_reference $9AF, 0
    map_event_reference $9A3, 0
    map_event_reference $9A3, 0
map_06D_event_references:
    map_event_reference $230, 0
    map_event_reference $231, 0
    map_event_reference $231, 0
    map_event_reference $93F, 0
    map_event_reference $93F, 0
    map_event_reference $93F, 0
map_06E_event_references:
    map_event_reference $A25, 0
    map_event_reference $A25, 0
map_06F_event_references:
    map_event_reference $5A0, 0
    map_event_reference $5A1, 0
    map_event_reference $AA1, 0
    map_event_reference $AA1, 0
map_070_event_references:
    map_event_reference $0AB, 0
    map_event_reference $A1B, 0
    map_event_reference $A1C, 0
map_071_event_references:
    map_event_reference $622, 0
    map_event_reference $A88, 0
    map_event_reference $A88, 0
    map_event_reference $A8A, 0
    map_event_reference $A8B, 0
    map_event_reference $A8D, 0
    map_event_reference $A8E, 0
    map_event_reference $A96, 0
    map_event_reference $A97, 0
    map_event_reference $A99, 0
    map_event_reference $A9A, 0
map_072_event_references:
    map_event_reference $620, 0
    map_event_reference $860, 0
    map_event_reference $860, 0
    map_event_reference $AB2, 0
    map_event_reference $8BA, 0
    map_event_reference $8BB, 0
    map_event_reference $8B5, 0
    map_event_reference $8B6, 0
map_073_event_references:
    map_event_reference $621, 0
    map_event_reference $97B, 0
    map_event_reference $97B, 0
    map_event_reference $8BD, 0
    map_event_reference $8BE, 0
    map_event_reference $97C, 0
    map_event_reference $97C, 0
    map_event_reference $8C3, 0
    map_event_reference $8C4, 0
    map_event_reference $8C8, 0
    map_event_reference $8C9, 0
    map_event_reference $902, 0
    map_event_reference $903, 0
    map_event_reference $92C, 0
    map_event_reference $92D, 0
    map_event_reference $938, 0
    map_event_reference $939, 0
    map_event_reference $83B, 0
map_074_event_references:
    map_event_reference $59E, 0
    map_event_reference $59F, 0
    map_event_reference $A89, 0
    map_event_reference $A89, 0
    map_event_reference $A89, 0
    map_event_reference $A89, 0
    map_event_reference $A89, 0
    map_event_reference $A89, 0
map_075_event_references:
    map_event_reference $AA0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $A84, 0
    map_event_reference $A84, 0
map_076_event_references:
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6F3, 0
    map_event_reference $6F3, 0
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6F3, 0
    map_event_reference $6F3, 0
    map_event_reference $AA3, 0
    map_event_reference $AA3, 0
    map_event_reference $AA2, 0
    map_event_reference $AA2, 0
map_077_event_references:
    map_event_reference $5A3, 0
    map_event_reference $5A4, 0
    map_event_reference $AA5, 0
    map_event_reference $AA5, 0
map_078_event_references:
    map_event_reference $642, 0
    map_event_reference $AA6, 0
map_079_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
map_07A_event_references:
    map_event_reference $3A9, 0
    map_event_reference $973, 0
    map_event_reference $973, 0
    map_event_reference $8C6, 0
    map_event_reference $8C6, 0
    map_event_reference $8C7, 0
    map_event_reference $8C5, 0
    map_event_reference $974, 0
    map_event_reference $974, 0
    map_event_reference $975, 0
    map_event_reference $976, 0
    map_event_reference $989, 0
map_07B_event_references:
    map_event_reference $510, 0
    map_event_reference $8B7, 0
    map_event_reference $8B7, 0
    map_event_reference $979, 0
    map_event_reference $979, 0
    map_event_reference $97A, 0
    map_event_reference $97A, 0
    map_event_reference $8B9, 0
    map_event_reference $977, 0
    map_event_reference $977, 0
    map_event_reference $970, 0
    map_event_reference $970, 0
    map_event_reference $978, 0
    map_event_reference $978, 0
    map_event_reference $8C2, 0
    map_event_reference $935, 0
    map_event_reference $972, 0
    map_event_reference $972, 0
    map_event_reference $971, 0
    map_event_reference $971, 0
    map_event_reference $8B8, 0
map_07C_event_references:
    map_event_reference $8B7, 0
    map_event_reference $8B7, 0
    map_event_reference $979, 0
    map_event_reference $979, 0
    map_event_reference $97A, 0
    map_event_reference $97A, 0
    map_event_reference $8B9, 0
    map_event_reference $977, 0
    map_event_reference $977, 0
    map_event_reference $970, 0
    map_event_reference $970, 0
    map_event_reference $978, 0
    map_event_reference $978, 0
    map_event_reference $8C2, 0
    map_event_reference $935, 0
    map_event_reference $972, 0
    map_event_reference $972, 0
    map_event_reference $971, 0
    map_event_reference $971, 0
    map_event_reference $8B8, 0
map_07D_event_references:
    map_event_reference $622, 0
    map_event_reference $A94, 0
    map_event_reference $A94, 0
    map_event_reference $A92, 0
    map_event_reference $A92, 0
    map_event_reference $A93, 0
    map_event_reference $A93, 0
    map_event_reference $A95, 0
    map_event_reference $A95, 0
    map_event_reference $A9C, 0
    map_event_reference $A9C, 0
    map_event_reference $A90, 0
    map_event_reference $A90, 0
    map_event_reference $A91, 0
    map_event_reference $A91, 0
    map_event_reference $A9D, 0
    map_event_reference $A9D, 0
    map_event_reference $A8F, 0
    map_event_reference $A9B, 0
map_07E_event_references:
    map_event_reference $621, 0
    map_event_reference $973, 0
    map_event_reference $973, 0
    map_event_reference $8C6, 0
    map_event_reference $8C6, 0
    map_event_reference $8C7, 0
    map_event_reference $8C5, 0
    map_event_reference $974, 0
    map_event_reference $974, 0
    map_event_reference $975, 0
    map_event_reference $976, 0
    map_event_reference $989, 0
map_07F_event_references:
    map_event_reference $620, 0
    map_event_reference $8B7, 0
    map_event_reference $8B7, 0
    map_event_reference $979, 0
    map_event_reference $979, 0
    map_event_reference $97A, 0
    map_event_reference $97A, 0
    map_event_reference $8B9, 0
    map_event_reference $977, 0
    map_event_reference $977, 0
    map_event_reference $970, 0
    map_event_reference $970, 0
    map_event_reference $978, 0
    map_event_reference $978, 0
    map_event_reference $8C2, 0
    map_event_reference $935, 0
    map_event_reference $972, 0
    map_event_reference $972, 0
    map_event_reference $971, 0
    map_event_reference $971, 0
    map_event_reference $8B8, 0
map_080_event_references:
    map_event_reference $847, 0
    map_event_reference $847, 0
    map_event_reference $104, 0
    map_event_reference $102, 0
map_081_event_references:
    map_event_reference $105, 0
    map_event_reference $846, 0
    map_event_reference $846, 0
    map_event_reference $810, 0
    map_event_reference $84A, 0
map_082_event_references:
    map_event_reference $70E, 0
    map_event_reference $605, 0
    map_event_reference $801, 0
    map_event_reference $808, 0
map_083_event_references:
    map_event_reference $610, 0
    map_event_reference $85A, 0
    map_event_reference $858, 0
    map_event_reference $84B, 0
    map_event_reference $84B, 0
    map_event_reference $85B, 0
    map_event_reference $859, 0
    map_event_reference $85C, 0
    map_event_reference $802, 0
    map_event_reference $802, 0
map_084_event_references:
    map_event_reference $611, 0
    map_event_reference $907, 0
    map_event_reference $906, 0
map_086_event_references:
    map_event_reference $280, 0
map_087_event_references:
    map_event_reference $896, 0
    map_event_reference $896, 0
    map_event_reference $6F3, 0
    map_event_reference $6F3, 0
map_088_event_references:
    map_event_reference $6DC, 0
    map_event_reference $93E, 0
    map_event_reference $6E7, 0
    map_event_reference $6E8, 0
    map_event_reference $93E, 0
    map_event_reference $80D, 0
    map_event_reference $80D, 0
map_089_event_references:
    map_event_reference $897, 0
    map_event_reference $897, 0
    map_event_reference $80B, 0
    map_event_reference $80B, 0
map_08A_event_references:
    map_event_reference $621, 0
    map_event_reference $8B7, 0
    map_event_reference $8B7, 0
    map_event_reference $979, 0
    map_event_reference $979, 0
    map_event_reference $97A, 0
    map_event_reference $97A, 0
    map_event_reference $8B9, 0
    map_event_reference $977, 0
    map_event_reference $977, 0
    map_event_reference $970, 0
    map_event_reference $970, 0
    map_event_reference $978, 0
    map_event_reference $978, 0
    map_event_reference $8C2, 0
    map_event_reference $935, 0
    map_event_reference $972, 0
    map_event_reference $972, 0
    map_event_reference $971, 0
    map_event_reference $971, 0
    map_event_reference $8B8, 0
map_08B_event_references:
    map_event_reference $128, 0
    map_event_reference $895, 0
    map_event_reference $895, 0
    map_event_reference $6E9, 0
    map_event_reference $6EA, 0
    map_event_reference $6F0, 0
    map_event_reference $894, 0
    map_event_reference $894, 0
map_08C_event_references:
    map_event_reference $6E6, 0
    map_event_reference $6E6, 0
    map_event_reference $80B, 0
    map_event_reference $80B, 0
map_08E_event_references:
    map_event_reference $128, 0
    map_event_reference $895, 0
    map_event_reference $895, 0
    map_event_reference $6E9, 0
    map_event_reference $6EA, 0
    map_event_reference $6F0, 0
    map_event_reference $89D, 0
    map_event_reference $89D, 0
map_08F_event_references:
    map_event_reference $125, 0
    map_event_reference $895, 0
    map_event_reference $895, 0
    map_event_reference $6E9, 0
    map_event_reference $6EA, 0
    map_event_reference $6F0, 0
    map_event_reference $89D, 0
    map_event_reference $89D, 0
map_090_event_references:
    map_event_reference $613, 0
    map_event_reference $84C, 0
    map_event_reference $84C, 0
    map_event_reference $839, 0
    map_event_reference $839, 0
    map_event_reference $839, 0
    map_event_reference $86C, 0
    map_event_reference $870, 0
    map_event_reference $86D, 0
    map_event_reference $86F, 0
    map_event_reference $86B, 0
    map_event_reference $812, 0
    map_event_reference $812, 0
    map_event_reference $874, 0
    map_event_reference $86E, 0
    map_event_reference $81E, 0
    map_event_reference $81E, 0
map_091_event_references:
    map_event_reference $8D2, 0
    map_event_reference $8D3, 0
    map_event_reference $8DF, 0
    map_event_reference $84D, 0
    map_event_reference $84D, 0
map_09B_event_references:
    map_event_reference $606, 0
    map_event_reference $85F, 0
    map_event_reference $85F, 0
map_09C_event_references:
    map_event_reference $606, 0
    map_event_reference $986, 0
    map_event_reference $986, 0
map_09D_event_references:
    map_event_reference $606, 0
    map_event_reference $9EC, 0
    map_event_reference $9EC, 0
map_09E_event_references:
    map_event_reference $619, 0
    map_event_reference $27F, 0
    map_event_reference $8B2, 0
    map_event_reference $8B2, 0
map_09F_event_references:
    map_event_reference $606, 0
    map_event_reference $868, 0
    map_event_reference $868, 0
map_0A0_event_references:
    map_event_reference $813, 0
    map_event_reference $814, 0
    map_event_reference $81F, 0
    map_event_reference $81F, 0
    map_event_reference $81F, 0
    map_event_reference $81F, 0
map_0A1_event_references:
    map_event_reference $15F, 0
    map_event_reference $821, 0
    map_event_reference $822, 0
    map_event_reference $823, 0
    map_event_reference $824, 0
    map_event_reference $825, 0
    map_event_reference $825, 0
    map_event_reference $825, 0
    map_event_reference $825, 0
    map_event_reference $83D, 0
    map_event_reference $83D, 0
    map_event_reference $83C, 0
    map_event_reference $83C, 0
    map_event_reference $83C, 0
map_0A2_event_references:
    map_event_reference $826, 0
    map_event_reference $827, 0
    map_event_reference $828, 0
    map_event_reference $82A, 0
    map_event_reference $82A, 0
map_0A3_event_references:
    map_event_reference $82C, 0
    map_event_reference $82D, 0
    map_event_reference $82D, 0
map_0A4_event_references:
    map_event_reference $16C, 0
    map_event_reference $16B, 0
    map_event_reference $16A, 0
map_0A6_event_references:
    map_event_reference $834, 0
    map_event_reference $834, 0
map_0A7_event_references:
    map_event_reference $16C, 0
    map_event_reference $16B, 0
    map_event_reference $16A, 0
map_0A8_event_references:
    map_event_reference $614, 0
    map_event_reference $861, 0
    map_event_reference $862, 0
    map_event_reference $864, 0
    map_event_reference $863, 0
    map_event_reference $81B, 0
map_0AA_event_references:
    map_event_reference $815, 0
    map_event_reference $815, 0
    map_event_reference $815, 0
    map_event_reference $811, 0
    map_event_reference $811, 0
    map_event_reference $811, 0
map_0AB_event_references:
    map_event_reference $606, 0
    map_event_reference $892, 0
    map_event_reference $892, 0
map_0C2_event_references:
    map_event_reference $635, 0
    map_event_reference $A0E, 0
    map_event_reference $A0E, 0
    map_event_reference $A18, 0
    map_event_reference $A19, 0
    map_event_reference $A1A, 0
    map_event_reference $A15, 0
    map_event_reference $A15, 0
map_0C3_event_references:
    map_event_reference $628, 0
    map_event_reference $BD6, 0
    map_event_reference $BD7, 0
    map_event_reference $B09, 0
    map_event_reference $B09, 0
    map_event_reference $BE0, 0
    map_event_reference $BE0, 0
    map_event_reference $BC8, 0
    map_event_reference $BC9, 0
map_0C4_event_references:
    map_event_reference $617, 0
    map_event_reference $8B0, 0
    map_event_reference $8B1, 0
    map_event_reference $87F, 0
    map_event_reference $87F, 0
map_0C5_event_references:
    map_event_reference $635, 0
    map_event_reference $A0E, 0
    map_event_reference $A0E, 0
    map_event_reference $A18, 0
    map_event_reference $A19, 0
    map_event_reference $A1A, 0
    map_event_reference $A15, 0
    map_event_reference $A15, 0
map_0C6_event_references:
    map_event_reference $62A, 0
    map_event_reference $B69, 0
    map_event_reference $B69, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_0C7_event_references:
    map_event_reference $B73, 0
    map_event_reference $B73, 0
    map_event_reference $B6B, 0
    map_event_reference $B6B, 0
    map_event_reference $B6A, 0
    map_event_reference $B6A, 0
map_0C8_event_references:
    map_event_reference $B6D, 0
    map_event_reference $B6D, 0
    map_event_reference $B6C, 0
    map_event_reference $B6C, 0
map_0C9_event_references:
    map_event_reference $B6F, 0
    map_event_reference $B6F, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $B6E, 0
    map_event_reference $B6E, 0
map_0CA_event_references:
    map_event_reference $B71, 0
    map_event_reference $B71, 0
    map_event_reference $B70, 0
    map_event_reference $B70, 0
map_0CB_event_references:
    map_event_reference $B75, 0
    map_event_reference $B75, 0
    map_event_reference $B72, 0
    map_event_reference $B72, 0
    map_event_reference $B74, 0
    map_event_reference $B74, 0
map_0CC_event_references:
    map_event_reference $5EC, 0
    map_event_reference $5DF, 0
    map_event_reference $5DF, 0
    map_event_reference $5DE, 0
    map_event_reference $5DE, 0
map_0CD_event_references:
    map_event_reference $B7B, 0
    map_event_reference $B7B, 0
    map_event_reference $B79, 0
    map_event_reference $B79, 0
    map_event_reference $B78, 0
    map_event_reference $B78, 0
map_0CE_event_references:
    map_event_reference $B7A, 0
    map_event_reference $B7A, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_0CF_event_references:
    map_event_reference $5E9, 0
    map_event_reference $5E9, 0
    map_event_reference $B7E, 0
    map_event_reference $B7E, 0
map_0D0_event_references:
    map_event_reference $B83, 0
    map_event_reference $B83, 0
    map_event_reference $B82, 0
    map_event_reference $B82, 0
map_0D1_event_references:
    map_event_reference $B85, 0
    map_event_reference $B85, 0
    map_event_reference $B87, 0
    map_event_reference $B87, 0
    map_event_reference $B84, 0
    map_event_reference $B84, 0
map_0D2_event_references:
    map_event_reference $B86, 0
    map_event_reference $B86, 0
map_0D3_event_references:
    map_event_reference $B88, 0
    map_event_reference $B88, 0
    map_event_reference $B89, 0
    map_event_reference $B89, 0
map_0D4_event_references:
    map_event_reference $B8B, 0
    map_event_reference $B8B, 0
    map_event_reference $B8A, 0
    map_event_reference $B8A, 0
map_0D5_event_references:
    map_event_reference $5F0, 0
    map_event_reference $5E3, 0
    map_event_reference $5E3, 0
    map_event_reference $5E2, 0
    map_event_reference $5E2, 0
map_0D6_event_references:
    map_event_reference $B8F, 0
    map_event_reference $B8F, 0
    map_event_reference $B8E, 0
    map_event_reference $B8E, 0
map_0D7_event_references:
    map_event_reference $B91, 0
    map_event_reference $B91, 0
    map_event_reference $B90, 0
    map_event_reference $B90, 0
map_0D8_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $5EA, 0
    map_event_reference $5EA, 0
    map_event_reference $B94, 0
    map_event_reference $B94, 0
map_0D9_event_references:
    map_event_reference $B99, 0
    map_event_reference $B99, 0
    map_event_reference $B98, 0
    map_event_reference $B98, 0
map_0DA_event_references:
    map_event_reference $B9B, 0
    map_event_reference $B9B, 0
    map_event_reference $B9A, 0
    map_event_reference $B9A, 0
map_0DB_event_references:
    map_event_reference $BA1, 0
    map_event_reference $BA1, 0
    map_event_reference $B9D, 0
    map_event_reference $B9D, 0
    map_event_reference $B9C, 0
    map_event_reference $B9C, 0
map_0DC_event_references:
    map_event_reference $B9F, 0
    map_event_reference $B9F, 0
    map_event_reference $B9E, 0
    map_event_reference $B9E, 0
map_0DD_event_references:
    map_event_reference $BA3, 0
    map_event_reference $BA3, 0
    map_event_reference $BA2, 0
    map_event_reference $BA2, 0
map_0DE_event_references:
    map_event_reference $26C, 0
    map_event_reference $98F, 0
    map_event_reference $98E, 0
    map_event_reference $98E, 0
map_0DF_event_references:
    map_event_reference $26C, 0
    map_event_reference $9D7, 0
    map_event_reference $9D8, 0
    map_event_reference $9D8, 0
map_0E0_event_references:
    map_event_reference $26C, 0
    map_event_reference $98D, 0
    map_event_reference $A54, 0
    map_event_reference $9D5, 0
    map_event_reference $9CC, 0
    map_event_reference $9D9, 0
    map_event_reference $9D9, 0
    map_event_reference $9D9, 0
    map_event_reference $9D9, 0
map_0E1_event_references:
    map_event_reference $BA5, 0
    map_event_reference $BA5, 0
    map_event_reference $BA0, 0
    map_event_reference $BA4, 0
    map_event_reference $BA0, 0
    map_event_reference $BA4, 0
map_0E2_event_references:
    map_event_reference $5F4, 0
    map_event_reference $5E7, 0
    map_event_reference $5E7, 0
    map_event_reference $5E6, 0
    map_event_reference $5E6, 0
map_0E3_event_references:
    map_event_reference $BA9, 0
    map_event_reference $BA9, 0
    map_event_reference $BA8, 0
    map_event_reference $BA8, 0
map_0E4_event_references:
    map_event_reference $61D, 0
    map_event_reference $995, 0
    map_event_reference $998, 0
    map_event_reference $992, 0
    map_event_reference $992, 0
    map_event_reference $992, 0
    map_event_reference $997, 0
    map_event_reference $996, 0
    map_event_reference $999, 0
map_0E5_event_references:
    map_event_reference $5EB, 0
    map_event_reference $5EB, 0
    map_event_reference $BAC, 0
    map_event_reference $BAC, 0
map_0E6_event_references:
    map_event_reference $5E1, 0
    map_event_reference $5E1, 0
map_0E7_event_references:
    map_event_reference $5E5, 0
    map_event_reference $5E5, 0
    map_event_reference $5E5, 0
map_0E8_event_references:
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
map_0E9_event_references:
    map_event_reference $62A, 0
    map_event_reference $5E0, 0
    map_event_reference $5E0, 0
    map_event_reference $B7D, 0
    map_event_reference $B7D, 0
    map_event_reference $B7C, 0
    map_event_reference $B7C, 0
map_0EA_event_references:
    map_event_reference $62A, 0
    map_event_reference $5E4, 0
    map_event_reference $5E4, 0
    map_event_reference $B93, 0
    map_event_reference $B93, 0
    map_event_reference $B92, 0
    map_event_reference $B92, 0
map_0EB_event_references:
    map_event_reference $62A, 0
    map_event_reference $5F8, 0
    map_event_reference $5F8, 0
    map_event_reference $BAB, 0
    map_event_reference $BAB, 0
    map_event_reference $BAA, 0
    map_event_reference $BAA, 0
map_0ED_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
map_0F0_event_references:
    map_event_reference $951, 0
    map_event_reference $951, 0
    map_event_reference $6CD, 0
    map_event_reference $6CF, 0
    map_event_reference $6CF, 0
    map_event_reference $928, 0
    map_event_reference $928, 0
map_0F4_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_0F5_event_references:
    map_event_reference $428, 0
    map_event_reference $429, 0
map_0F6_event_references:
    map_event_reference $428, 0
    map_event_reference $429, 0
map_0F8_event_references:
    map_event_reference $42A, 0
    map_event_reference $6D8, 0
    map_event_reference $431, 0
    map_event_reference $432, 0
    map_event_reference $89B, 0
    map_event_reference $89B, 0
    map_event_reference $88B, 0
    map_event_reference $887, 0
    map_event_reference $888, 0
    map_event_reference $898, 0
    map_event_reference $420, 0
    map_event_reference $86A, 0
    map_event_reference $86A, 0
    map_event_reference $433, 0
    map_event_reference $434, 0
    map_event_reference $430, 0
    map_event_reference $435, 0
    map_event_reference $889, 0
    map_event_reference $88A, 0
    map_event_reference $6F0, 0
    map_event_reference $87E, 0
    map_event_reference $87E, 0
map_0F9_event_references:
    map_event_reference $42B, 0
    map_event_reference $6D8, 0
    map_event_reference $436, 0
    map_event_reference $423, 0
    map_event_reference $88C, 0
map_0FA_event_references:
    map_event_reference $6D8, 0
    map_event_reference $8C1, 0
    map_event_reference $8CA, 0
map_0FB_event_references:
    map_event_reference $891, 0
    map_event_reference $954, 0
map_0FF_event_references:
    map_event_reference $62B, 0
    map_event_reference $880, 0
    map_event_reference $881, 0
map_100_event_references:
    map_event_reference $100, 0
map_102_event_references:
    map_event_reference $113, 0
    map_event_reference $865, 0
    map_event_reference $866, 0
    map_event_reference $867, 0
map_103_event_references:
    map_event_reference $610, 0
    map_event_reference $80E, 0
map_105_event_references:
    map_event_reference $879, 0
    map_event_reference $877, 0
    map_event_reference $877, 0
    map_event_reference $878, 0
    map_event_reference $878, 0
map_106_event_references:
    map_event_reference $613, 0
    map_event_reference $80F, 0
map_107_event_references:
    map_event_reference $873, 0
    map_event_reference $871, 0
    map_event_reference $872, 0
map_108_event_references:
    map_event_reference $8D5, 0
    map_event_reference $8D6, 0
    map_event_reference $8D7, 0
    map_event_reference $8D4, 0
    map_event_reference $8D4, 0
map_109_event_references:
    map_event_reference $188, 0
    map_event_reference $8E0, 0
    map_event_reference $8DB, 0
    map_event_reference $8DC, 0
    map_event_reference $8E1, 0
    map_event_reference $8D8, 0
    map_event_reference $8D9, 0
    map_event_reference $8DA, 0
    map_event_reference $8E3, 0
    map_event_reference $8E5, 0
map_10A_event_references:
    map_event_reference $17E, 0
    map_event_reference $8E2, 0
    map_event_reference $8DD, 0
    map_event_reference $8DD, 0
map_10B_event_references:
    map_event_reference $19E, 0
    map_event_reference $8E8, 0
map_10C_event_references:
    map_event_reference $8E4, 0
map_10D_event_references:
    map_event_reference $8EB, 0
    map_event_reference $8D0, 0
    map_event_reference $8E9, 0
    map_event_reference $8D1, 0
    map_event_reference $8ED, 0
    map_event_reference $8ED, 0
    map_event_reference $8EC, 0
    map_event_reference $8EC, 0
    map_event_reference $8E7, 0
    map_event_reference $8E7, 0
    map_event_reference $8EA, 0
    map_event_reference $8EA, 0
map_10E_event_references:
    map_event_reference $9A5, 0
    map_event_reference $9A5, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_10F_event_references:
    map_event_reference $9AB, 0
    map_event_reference $9AB, 0
map_111_event_references:
    map_event_reference $61B, 0
    map_event_reference $95E, 0
map_112_event_references:
    map_event_reference $26C, 0
    map_event_reference $A55, 0
map_113_event_references:
    map_event_reference $230, 0
    map_event_reference $944, 0
    map_event_reference $944, 0
    map_event_reference $941, 0
    map_event_reference $941, 0
map_114_event_references:
    map_event_reference $71D, 0
    map_event_reference $932, 0
map_115_event_references:
    map_event_reference $232, 0
    map_event_reference $946, 0
    map_event_reference $946, 0
    map_event_reference $943, 0
    map_event_reference $943, 0
map_116_event_references:
    map_event_reference $947, 0
    map_event_reference $947, 0
map_117_event_references:
    map_event_reference $611, 0
    map_event_reference $908, 0
map_118_event_references:
    map_event_reference $87C, 0
    map_event_reference $87A, 0
    map_event_reference $87B, 0
map_119_event_references:
    map_event_reference $614, 0
    map_event_reference $88F, 0
map_11A_event_references:
    map_event_reference $A53, 0
    map_event_reference $A53, 0
    map_event_reference $A53, 0
map_11B_event_references:
    map_event_reference $188, 0
    map_event_reference $8E0, 0
    map_event_reference $8DB, 0
    map_event_reference $8DC, 0
    map_event_reference $8E1, 0
    map_event_reference $8D8, 0
    map_event_reference $8D9, 0
    map_event_reference $8DA, 0
    map_event_reference $8E3, 0
    map_event_reference $8E5, 0
map_11C_event_references:
    map_event_reference $1BA, 0
    map_event_reference $848, 0
    map_event_reference $848, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $8EE, 0
    map_event_reference $8EE, 0
    map_event_reference $81A, 0
    map_event_reference $81A, 0
    map_event_reference $837, 0
    map_event_reference $837, 0
map_11D_event_references:
    map_event_reference $1BB, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $849, 0
    map_event_reference $849, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $8F0, 0
    map_event_reference $8F0, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $84E, 0
    map_event_reference $84E, 0
map_11E_event_references:
    map_event_reference $1BC, 0
    map_event_reference $84F, 0
    map_event_reference $84F, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $8F2, 0
    map_event_reference $8F2, 0
    map_event_reference $8F4, 0
    map_event_reference $8F4, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
map_11F_event_references:
    map_event_reference $1B8, 0
    map_event_reference $368, 0
    map_event_reference $8FC, 0
    map_event_reference $8FE, 0
    map_event_reference $8FA, 0
    map_event_reference $8F8, 0
    map_event_reference $948, 0
    map_event_reference $948, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $8F3, 0
    map_event_reference $8F3, 0
    map_event_reference $8F5, 0
    map_event_reference $8F5, 0
map_120_event_references:
    map_event_reference $8EF, 0
    map_event_reference $8EF, 0
    map_event_reference $8F7, 0
    map_event_reference $8F7, 0
map_121_event_references:
    map_event_reference $8F1, 0
    map_event_reference $8F1, 0
map_123_event_references:
    map_event_reference $238, 0
    map_event_reference $94A, 0
    map_event_reference $94A, 0
    map_event_reference $949, 0
    map_event_reference $949, 0
map_124_event_references:
    map_event_reference $1B8, 0
    map_event_reference $8F9, 0
    map_event_reference $8F9, 0
map_125_event_references:
    map_event_reference $8FB, 0
    map_event_reference $8FB, 0
map_126_event_references:
    map_event_reference $8F6, 0
    map_event_reference $8F6, 0
    map_event_reference $8FD, 0
    map_event_reference $8FD, 0
map_127_event_references:
    map_event_reference $853, 0
    map_event_reference $853, 0
    map_event_reference $855, 0
    map_event_reference $855, 0
    map_event_reference $8FF, 0
    map_event_reference $8FF, 0
map_128_event_references:
    map_event_reference $1C8, 0
    map_event_reference $857, 0
    map_event_reference $857, 0
    map_event_reference $854, 0
    map_event_reference $854, 0
map_129_event_references:
    map_event_reference $1CC, 0
    map_event_reference $904, 0
    map_event_reference $904, 0
    map_event_reference $856, 0
    map_event_reference $856, 0
