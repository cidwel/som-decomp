; Typed event references; docs/event-index-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A00
.macro map_event_reference command_id, upper_bits
    .word command_id | (upper_bits << 12)
.endmacro
map_12B_event_references:
    map_event_reference $61D, 0
    map_event_reference $99A, 0
map_12C_event_references:
    map_event_reference $618, 0
    map_event_reference $90E, 0
    map_event_reference $1DB, 0
    map_event_reference $8AF, 0
map_12D_event_references:
    map_event_reference $910, 0
    map_event_reference $910, 0
    map_event_reference $910, 0
    map_event_reference $90F, 0
map_12E_event_references:
    map_event_reference $912, 0
    map_event_reference $912, 0
    map_event_reference $90D, 0
    map_event_reference $90D, 0
    map_event_reference $6F0, 0
    map_event_reference $6F1, 0
    map_event_reference $911, 0
map_12F_event_references:
    map_event_reference $914, 0
    map_event_reference $1E9, 0
    map_event_reference $93C, 0
    map_event_reference $93C, 0
    map_event_reference $93C, 0
    map_event_reference $913, 0
    map_event_reference $913, 0
map_130_event_references:
    map_event_reference $919, 0
    map_event_reference $916, 0
    map_event_reference $918, 0
    map_event_reference $915, 0
map_131_event_references:
    map_event_reference $929, 0
    map_event_reference $1E8, 0
    map_event_reference $917, 0
map_132_event_references:
    map_event_reference $1E0, 0
    map_event_reference $92F, 0
    map_event_reference $930, 0
    map_event_reference $92B, 0
    map_event_reference $92B, 0
map_134_event_references:
    map_event_reference $618, 0
    map_event_reference $93D, 0
    map_event_reference $93D, 0
map_135_event_references:
    map_event_reference $1E7, 0
    map_event_reference $92E, 0
    map_event_reference $92E, 0
map_136_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
map_137_event_references:
    map_event_reference $99B, 0
    map_event_reference $99B, 0
map_138_event_references:
    map_event_reference $6F5, 0
    map_event_reference $931, 0
    map_event_reference $931, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $9AC, 0
    map_event_reference $9AC, 0
    map_event_reference $22C, 0
    map_event_reference $22D, 0
map_139_event_references:
    map_event_reference $6F5, 0
    map_event_reference $8E6, 0
    map_event_reference $8E6, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F1, 0
    map_event_reference $6F3, 0
    map_event_reference $6F3, 0
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6D8, 0
    map_event_reference $6F2, 0
    map_event_reference $6F2, 0
    map_event_reference $6F3, 0
    map_event_reference $6F3, 0
    map_event_reference $6D8, 0
    map_event_reference $933, 0
    map_event_reference $933, 0
map_13A_event_references:
    map_event_reference $23B, 0
    map_event_reference $936, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $6F0, 0
    map_event_reference $934, 0
    map_event_reference $934, 0
map_13B_event_references:
    map_event_reference $99D, 0
    map_event_reference $99E, 0
    map_event_reference $99C, 0
    map_event_reference $99C, 0
map_13C_event_references:
    map_event_reference $369, 0
    map_event_reference $36B, 0
    map_event_reference $36C, 0
    map_event_reference $9A1, 0
    map_event_reference $9A1, 0
map_13D_event_references:
    map_event_reference $36E, 0
    map_event_reference $36E, 0
map_13E_event_references:
    map_event_reference $9A8, 0
    map_event_reference $9A8, 0
    map_event_reference $9B1, 0
map_13F_event_references:
    map_event_reference $295, 0
    map_event_reference $9B3, 0
map_140_event_references:
    map_event_reference $280, 0
    map_event_reference $96B, 0
    map_event_reference $96B, 0
    map_event_reference $96D, 0
    map_event_reference $96D, 0
    map_event_reference $8FB, 0
    map_event_reference $8FB, 0
    map_event_reference $969, 0
    map_event_reference $969, 0
    map_event_reference $94C, 0
    map_event_reference $94C, 0
    map_event_reference $9D6, 0
    map_event_reference $9D6, 0
    map_event_reference $955, 0
    map_event_reference $955, 0
map_141_event_references:
    map_event_reference $96A, 0
    map_event_reference $958, 0
    map_event_reference $958, 0
    map_event_reference $967, 0
    map_event_reference $967, 0
    map_event_reference $96C, 0
    map_event_reference $96C, 0
    map_event_reference $964, 0
    map_event_reference $964, 0
    map_event_reference $968, 0
    map_event_reference $968, 0
    map_event_reference $963, 0
    map_event_reference $963, 0
map_142_event_references:
    map_event_reference $287, 0
    map_event_reference $966, 0
    map_event_reference $966, 0
    map_event_reference $965, 0
    map_event_reference $965, 0
    map_event_reference $961, 0
    map_event_reference $961, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $962, 0
    map_event_reference $962, 0
    map_event_reference $95A, 0
    map_event_reference $95A, 0
    map_event_reference $990, 0
    map_event_reference $990, 0
map_143_event_references:
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $960, 0
    map_event_reference $960, 0
    map_event_reference $95B, 0
    map_event_reference $95B, 0
map_144_event_references:
    map_event_reference $9B4, 0
    map_event_reference $9B5, 0
    map_event_reference $9AE, 0
    map_event_reference $9AE, 0
    map_event_reference $9B0, 0
    map_event_reference $9B0, 0
map_145_event_references:
    map_event_reference $281, 0
    map_event_reference $285, 0
    map_event_reference $286, 0
    map_event_reference $286, 0
map_146_event_references:
    map_event_reference $A49, 0
    map_event_reference $A49, 0
    map_event_reference $A47, 0
    map_event_reference $A47, 0
    map_event_reference $A45, 0
    map_event_reference $A45, 0
    map_event_reference $A43, 0
    map_event_reference $A43, 0
map_147_event_references:
    map_event_reference $6CC, 0
    map_event_reference $A4D, 0
    map_event_reference $A4D, 0
    map_event_reference $9FE, 0
    map_event_reference $9FE, 0
    map_event_reference $A46, 0
    map_event_reference $A46, 0
map_148_event_references:
    map_event_reference $A8C, 0
    map_event_reference $A8C, 0
    map_event_reference $A4B, 0
    map_event_reference $A4B, 0
    map_event_reference $A4F, 0
    map_event_reference $A4F, 0
    map_event_reference $A48, 0
    map_event_reference $A48, 0
map_149_event_references:
    map_event_reference $A57, 0
    map_event_reference $A57, 0
    map_event_reference $A56, 0
    map_event_reference $A56, 0
    map_event_reference $A4C, 0
    map_event_reference $A4C, 0
    map_event_reference $A4A, 0
    map_event_reference $A4A, 0
map_14A_event_references:
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $A5B, 0
    map_event_reference $A5B, 0
    map_event_reference $A34, 0
    map_event_reference $A34, 0
    map_event_reference $A4E, 0
    map_event_reference $A4E, 0
    map_event_reference $9FD, 0
    map_event_reference $9FD, 0
map_14B_event_references:
    map_event_reference $A5D, 0
    map_event_reference $A5D, 0
map_14C_event_references:
    map_event_reference $633, 0
    map_event_reference $A12, 0
    map_event_reference $A0B, 0
    map_event_reference $A13, 0
    map_event_reference $A13, 0
    map_event_reference $A13, 0
    map_event_reference $A13, 0
map_150_event_references:
    map_event_reference $25C, 0
    map_event_reference $9CE, 0
    map_event_reference $A52, 0
    map_event_reference $9CD, 0
    map_event_reference $9D4, 0
map_151_event_references:
    map_event_reference $260, 0
    map_event_reference $9D0, 0
    map_event_reference $9CF, 0
map_152_event_references:
    map_event_reference $9DC, 0
map_153_event_references:
    map_event_reference $29C, 0
    map_event_reference $9B6, 0
    map_event_reference $9B6, 0
map_155_event_references:
    map_event_reference $624, 0
    map_event_reference $8A4, 0
map_159_event_references:
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $A58, 0
    map_event_reference $A58, 0
    map_event_reference $A59, 0
    map_event_reference $A59, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
map_15A_event_references:
    map_event_reference $A5A, 0
    map_event_reference $A5A, 0
    map_event_reference $A5E, 0
    map_event_reference $A5E, 0
    map_event_reference $92A, 0
    map_event_reference $92A, 0
    map_event_reference $A5C, 0
    map_event_reference $A5C, 0
    map_event_reference $A31, 0
    map_event_reference $A31, 0
map_15B_event_references:
    map_event_reference $63E, 0
    map_event_reference $A60, 0
    map_event_reference $A61, 0
    map_event_reference $A5F, 0
    map_event_reference $A5F, 0
map_15C_event_references:
    map_event_reference $63D, 0
    map_event_reference $A51, 0
    map_event_reference $A51, 0
    map_event_reference $A50, 0
    map_event_reference $A50, 0
map_15D_event_references:
    map_event_reference $63F, 0
    map_event_reference $A62, 0
map_15E_event_references:
    map_event_reference $A68, 0
    map_event_reference $A68, 0
    map_event_reference $A38, 0
    map_event_reference $A38, 0
map_15F_event_references:
    map_event_reference $63B, 0
    map_event_reference $A35, 0
map_160_event_references:
    map_event_reference $AB3, 0
    map_event_reference $AB3, 0
    map_event_reference $662, 0
    map_event_reference $663, 0
    map_event_reference $661, 0
    map_event_reference $661, 0
    map_event_reference $660, 0
    map_event_reference $A00, 0
    map_event_reference $A00, 0
map_161_event_references:
    map_event_reference $AB5, 0
    map_event_reference $AB4, 0
    map_event_reference $AB4, 0
    map_event_reference $AB4, 0
map_162_event_references:
    map_event_reference $AB7, 0
    map_event_reference $AB8, 0
    map_event_reference $AB6, 0
    map_event_reference $AB6, 0
map_163_event_references:
    map_event_reference $ABA, 0
    map_event_reference $AB9, 0
    map_event_reference $665, 0
    map_event_reference $664, 0
    map_event_reference $ACC, 0
    map_event_reference $ACD, 0
map_165_event_references:
    map_event_reference $ABC, 0
    map_event_reference $666, 0
    map_event_reference $667, 0
    map_event_reference $ABB, 0
map_166_event_references:
    map_event_reference $ABE, 0
    map_event_reference $ABE, 0
    map_event_reference $ABE, 0
    map_event_reference $ABD, 0
map_167_event_references:
    map_event_reference $AC0, 0
    map_event_reference $ABF, 0
    map_event_reference $ABF, 0
map_168_event_references:
    map_event_reference $668, 0
    map_event_reference $AC4, 0
    map_event_reference $AC4, 0
    map_event_reference $669, 0
    map_event_reference $669, 0
    map_event_reference $AC1, 0
    map_event_reference $AC1, 0
map_16A_event_references:
    map_event_reference $6D8, 0
    map_event_reference $AC6, 0
    map_event_reference $AC5, 0
map_16B_event_references:
    map_event_reference $66B, 0
    map_event_reference $AC9, 0
    map_event_reference $AC9, 0
map_16D_event_references:
    map_event_reference $AC8, 0
    map_event_reference $AC7, 0
map_16F_event_references:
    map_event_reference $541, 0
    map_event_reference $A63, 0
    map_event_reference $A63, 0
    map_event_reference $91B, 0
    map_event_reference $91B, 0
map_170_event_references:
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $A65, 0
    map_event_reference $A65, 0
    map_event_reference $A67, 0
    map_event_reference $A67, 0
    map_event_reference $6B1, 0
    map_event_reference $A7D, 0
    map_event_reference $A7D, 0
    map_event_reference $780, 0
    map_event_reference $A69, 0
    map_event_reference $A69, 0
    map_event_reference $A66, 0
    map_event_reference $A66, 0
    map_event_reference $A6B, 0
    map_event_reference $A6B, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $A64, 0
    map_event_reference $A64, 0
map_171_event_references:
    map_event_reference $A71, 0
    map_event_reference $A71, 0
    map_event_reference $A73, 0
    map_event_reference $A73, 0
    map_event_reference $A75, 0
    map_event_reference $A75, 0
    map_event_reference $A77, 0
    map_event_reference $A77, 0
    map_event_reference $A6D, 0
    map_event_reference $A6D, 0
    map_event_reference $A70, 0
    map_event_reference $A70, 0
    map_event_reference $A6E, 0
    map_event_reference $A6E, 0
map_172_event_references:
    map_event_reference $A81, 0
    map_event_reference $A81, 0
    map_event_reference $A7F, 0
    map_event_reference $A7F, 0
    map_event_reference $A7F, 0
    map_event_reference $A7F, 0
    map_event_reference $6B2, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6B0, 0
    map_event_reference $A7B, 0
    map_event_reference $A7B, 0
    map_event_reference $A7A, 0
    map_event_reference $A7A, 0
    map_event_reference $A7C, 0
    map_event_reference $A7C, 0
map_175_event_references:
    map_event_reference $A83, 0
    map_event_reference $A83, 0
    map_event_reference $A82, 0
    map_event_reference $A82, 0
map_176_event_references:
    map_event_reference $547, 0
    map_event_reference $547, 0
    map_event_reference $6B5, 0
    map_event_reference $6B4, 0
    map_event_reference $6B3, 0
    map_event_reference $A85, 0
    map_event_reference $A85, 0
    map_event_reference $A85, 0
map_177_event_references:
    map_event_reference $542, 0
    map_event_reference $A87, 0
map_178_event_references:
    map_event_reference $61F, 0
    map_event_reference $98B, 0
map_179_event_references:
    map_event_reference $B46, 0
map_17A_event_references:
    map_event_reference $B47, 0
    map_event_reference $B47, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $000, 0
map_17B_event_references:
    map_event_reference $B4A, 0
    map_event_reference $B4A, 0
    map_event_reference $B4A, 0
    map_event_reference $B49, 0
map_17C_event_references:
    map_event_reference $B4C, 0
    map_event_reference $B4C, 0
    map_event_reference $51E, 0
    map_event_reference $B4B, 0
    map_event_reference $B4B, 0
map_17D_event_references:
    map_event_reference $B4E, 0
    map_event_reference $B4D, 0
    map_event_reference $B4D, 0
    map_event_reference $B4D, 0
map_17E_event_references:
    map_event_reference $B43, 0
    map_event_reference $51F, 0
    map_event_reference $B42, 0
map_180_event_references:
    map_event_reference $B36, 0
    map_event_reference $B36, 0
    map_event_reference $B34, 0
    map_event_reference $B34, 0
    map_event_reference $B33, 0
    map_event_reference $B33, 0
map_181_event_references:
    map_event_reference $B37, 0
    map_event_reference $B37, 0
    map_event_reference $B35, 0
    map_event_reference $B35, 0
    map_event_reference $B52, 0
    map_event_reference $B52, 0
    map_event_reference $B38, 0
    map_event_reference $B38, 0
    map_event_reference $B3C, 0
    map_event_reference $B51, 0
map_182_event_references:
    map_event_reference $B50, 0
    map_event_reference $528, 0
    map_event_reference $B40, 0
map_183_event_references:
    map_event_reference $520, 0
    map_event_reference $B3B, 0
    map_event_reference $B3B, 0
map_184_event_references:
    map_event_reference $B3A, 0
    map_event_reference $B39, 0
    map_event_reference $B39, 0
    map_event_reference $B39, 0
map_185_event_references:
    map_event_reference $B54, 0
    map_event_reference $B54, 0
    map_event_reference $B53, 0
    map_event_reference $B53, 0
map_186_event_references:
    map_event_reference $B5A, 0
    map_event_reference $B5B, 0
    map_event_reference $529, 0
    map_event_reference $52A, 0
    map_event_reference $52B, 0
    map_event_reference $52B, 0
    map_event_reference $52C, 0
    map_event_reference $B55, 0
    map_event_reference $B55, 0
map_187_event_references:
    map_event_reference $52E, 0
    map_event_reference $B5C, 0
    map_event_reference $B5C, 0
map_189_event_references:
    map_event_reference $A1E, 0
    map_event_reference $A1E, 0
    map_event_reference $A1D, 0
    map_event_reference $A1D, 0
map_18A_event_references:
    map_event_reference $A1F, 0
    map_event_reference $A1F, 0
    map_event_reference $A20, 0
    map_event_reference $A20, 0
map_18B_event_references:
    map_event_reference $A21, 0
    map_event_reference $A21, 0
    map_event_reference $A22, 0
    map_event_reference $A22, 0
map_18C_event_references:
    map_event_reference $A23, 0
    map_event_reference $A23, 0
    map_event_reference $A24, 0
    map_event_reference $A24, 0
map_190_event_references:
    map_event_reference $AD1, 0
    map_event_reference $AD2, 0
    map_event_reference $AD3, 0
    map_event_reference $AD4, 0
    map_event_reference $AD5, 0
    map_event_reference $AD6, 0
    map_event_reference $AD0, 0
    map_event_reference $AD0, 0
    map_event_reference $AD0, 0
    map_event_reference $AD0, 0
    map_event_reference $AD8, 0
    map_event_reference $AD9, 0
    map_event_reference $ADA, 0
    map_event_reference $ADA, 0
    map_event_reference $AD7, 0
map_191_event_references:
    map_event_reference $ADB, 0
    map_event_reference $AE6, 0
    map_event_reference $AE7, 0
    map_event_reference $AE7, 0
    map_event_reference $ADC, 0
    map_event_reference $AE5, 0
    map_event_reference $AE2, 0
    map_event_reference $ADD, 0
    map_event_reference $ADE, 0
    map_event_reference $AE4, 0
    map_event_reference $AE1, 0
    map_event_reference $AE3, 0
    map_event_reference $AE0, 0
    map_event_reference $ADF, 0
map_192_event_references:
    map_event_reference $554, 0
    map_event_reference $54D, 0
    map_event_reference $54E, 0
    map_event_reference $55A, 0
    map_event_reference $55B, 0
    map_event_reference $B1F, 0
    map_event_reference $B11, 0
    map_event_reference $B16, 0
    map_event_reference $B16, 0
map_193_event_references:
    map_event_reference $B02, 0
    map_event_reference $AF8, 0
    map_event_reference $AFC, 0
    map_event_reference $AFA, 0
    map_event_reference $B03, 0
    map_event_reference $AF7, 0
    map_event_reference $AF6, 0
    map_event_reference $AFB, 0
    map_event_reference $AF9, 0
    map_event_reference $550, 0
    map_event_reference $AFD, 0
    map_event_reference $B01, 0
    map_event_reference $54F, 0
    map_event_reference $B08, 0
    map_event_reference $AFE, 0
    map_event_reference $B07, 0
    map_event_reference $B06, 0
    map_event_reference $AFF, 0
    map_event_reference $AFF, 0
map_194_event_references:
    map_event_reference $B0D, 0
    map_event_reference $B10, 0
    map_event_reference $B10, 0
    map_event_reference $B00, 0
    map_event_reference $B0E, 0
    map_event_reference $B0F, 0
    map_event_reference $551, 0
map_195_event_references:
    map_event_reference $647, 0
    map_event_reference $54D, 0
    map_event_reference $54E, 0
    map_event_reference $55A, 0
    map_event_reference $55B, 0
    map_event_reference $B1F, 0
    map_event_reference $B11, 0
    map_event_reference $B16, 0
    map_event_reference $B16, 0
map_196_event_references:
    map_event_reference $B26, 0
    map_event_reference $B23, 0
    map_event_reference $B2C, 0
    map_event_reference $B2D, 0
    map_event_reference $B27, 0
    map_event_reference $B22, 0
    map_event_reference $B2B, 0
    map_event_reference $B2E, 0
    map_event_reference $B28, 0
    map_event_reference $B24, 0
    map_event_reference $B25, 0
    map_event_reference $B2F, 0
map_197_event_references:
    map_event_reference $B14, 0
    map_event_reference $B15, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_199_event_references:
    map_event_reference $B1B, 0
    map_event_reference $B1C, 0
    map_event_reference $B19, 0
    map_event_reference $B19, 0
    map_event_reference $B1E, 0
    map_event_reference $B1E, 0
map_19A_event_references:
    map_event_reference $B14, 0
    map_event_reference $B15, 0
    map_event_reference $B17, 0
    map_event_reference $B17, 0
map_19C_event_references:
    map_event_reference $62D, 0
    map_event_reference $BD0, 0
    map_event_reference $BD0, 0
    map_event_reference $BCA, 0
    map_event_reference $BCA, 0
    map_event_reference $BAF, 0
    map_event_reference $BAF, 0
map_19D_event_references:
    map_event_reference $BCC, 0
    map_event_reference $BCD, 0
    map_event_reference $BCE, 0
    map_event_reference $BCF, 0
    map_event_reference $BCB, 0
    map_event_reference $BCB, 0
map_19E_event_references:
    map_event_reference $BD1, 0
    map_event_reference $BD1, 0
    map_event_reference $BD2, 0
    map_event_reference $BD3, 0
    map_event_reference $BD4, 0
    map_event_reference $BD5, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $BDA, 0
    map_event_reference $BDA, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
map_19F_event_references:
    map_event_reference $BE5, 0
    map_event_reference $BE5, 0
    map_event_reference $BEB, 0
    map_event_reference $BEB, 0
    map_event_reference $BED, 0
    map_event_reference $BED, 0
    map_event_reference $BDC, 0
    map_event_reference $BDC, 0
    map_event_reference $BDC, 0
    map_event_reference $BDC, 0
    map_event_reference $BDB, 0
    map_event_reference $BDB, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $781, 0
    map_event_reference $BDC, 0
    map_event_reference $BDC, 0
    map_event_reference $BE1, 0
    map_event_reference $BE2, 0
    map_event_reference $BE3, 0
    map_event_reference $BE4, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
    map_event_reference $780, 0
map_1A0_event_references:
    map_event_reference $BF4, 0
    map_event_reference $BF4, 0
    map_event_reference $BD9, 0
    map_event_reference $BD9, 0
    map_event_reference $BEA, 0
    map_event_reference $BEA, 0
    map_event_reference $BEC, 0
    map_event_reference $BEC, 0
map_1A1_event_references:
    map_event_reference $4C1, 0
    map_event_reference $4C3, 0
    map_event_reference $BF5, 0
    map_event_reference $BF5, 0
    map_event_reference $4C2, 0
    map_event_reference $4C4, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $6D8, 0
    map_event_reference $BF8, 0
    map_event_reference $BF9, 0
    map_event_reference $BFA, 0
    map_event_reference $BFA, 0
map_1A2_event_references:
    map_event_reference $4A1, 0
    map_event_reference $BDD, 0
    map_event_reference $BDE, 0
    map_event_reference $BDE, 0
    map_event_reference $BDE, 0
map_1A3_event_references:
    map_event_reference $4A3, 0
    map_event_reference $BF7, 0
    map_event_reference $BF7, 0
map_1AE_event_references:
    map_event_reference $4B0, 0
    map_event_reference $BFB, 0
    map_event_reference $BFB, 0
    map_event_reference $BFC, 0
    map_event_reference $BFC, 0
    map_event_reference $4C5, 0
    map_event_reference $BD8, 0
    map_event_reference $BD8, 0
map_1AF_event_references:
    map_event_reference $4A0, 0
    map_event_reference $BDF, 0
    map_event_reference $BFD, 0
map_1B0_event_references:
    map_event_reference $629, 0
    map_event_reference $B0B, 0
    map_event_reference $B0B, 0
    map_event_reference $B0A, 0
    map_event_reference $B0A, 0
    map_event_reference $B1E, 0
    map_event_reference $B1E, 0
    map_event_reference $BB0, 0
    map_event_reference $BB0, 0
map_1B1_event_references:
    map_event_reference $629, 0
    map_event_reference $598, 0
    map_event_reference $598, 0
    map_event_reference $6F0, 0
    map_event_reference $B0C, 0
    map_event_reference $B0C, 0
map_1B2_event_references:
    map_event_reference $629, 0
    map_event_reference $B1D, 0
    map_event_reference $B20, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
map_1B3_event_references:
    map_event_reference $629, 0
    map_event_reference $B1D, 0
    map_event_reference $B20, 0
    map_event_reference $B1C, 0
    map_event_reference $B1C, 0
map_1B4_event_references:
    map_event_reference $629, 0
    map_event_reference $B0B, 0
    map_event_reference $B0B, 0
    map_event_reference $B0A, 0
    map_event_reference $B0A, 0
    map_event_reference $B1E, 0
    map_event_reference $B1E, 0
    map_event_reference $BB0, 0
    map_event_reference $BB0, 0
map_1BC_event_references:
    map_event_reference $5EE, 0
    map_event_reference $5E1, 0
    map_event_reference $5E1, 0
map_1BD_event_references:
    map_event_reference $5F2, 0
    map_event_reference $5E5, 0
    map_event_reference $5E5, 0
    map_event_reference $5E5, 0
map_1BE_event_references:
    map_event_reference $5F6, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
    map_event_reference $5E8, 0
map_1EF_event_references:
    map_event_reference $000, 0
    map_event_reference $000, 0
    map_event_reference $000, 0
