; Typed native gameplay records; docs/actor-record-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1000
.macro weapon_attributes type_flags, wisdom_delta, intellect_delta, constitution_delta, agility_delta, strength_delta, stat_b_upper, graphics_kind, default_palette, enemy_type_mask, critical, accuracy, power, status_word, status_chance
    .byte type_flags, wisdom_delta | (intellect_delta << 2) | (constitution_delta << 4) | (agility_delta << 6)
    .byte strength_delta | (stat_b_upper << 2), graphics_kind, default_palette
    .byte enemy_type_mask, critical, accuracy, power
    .word status_word
    .byte status_chance
.endmacro
weapon_attribute_records_00:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 2, 0, 0, 75, 2, 0, 80
weapon_attribute_records_01:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 26, 4, 0, 75, 6, 0, 80
weapon_attribute_records_02:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 24, 0, 0, 75, 11, 16, 80
weapon_attribute_records_03:
    weapon_attributes 0, 1, 1, 0, 0, 0, 48, 0, 14, 0, 0, 75, 17, 0, 80
weapon_attribute_records_04:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 12, 4, 0, 75, 24, 0, 80
weapon_attribute_records_05:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 22, 16, 0, 75, 30, 0, 80
weapon_attribute_records_06:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 18, 0, 0, 75, 38, 8192, 80
weapon_attribute_records_07:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 4, 128, 0, 75, 47, 0, 80
weapon_attribute_records_08:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 6, 0, 0, 75, 53, 0, 80
weapon_attribute_records_09:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 24, 0, 0, 75, 3, 0, 80
weapon_attribute_records_0A:
    weapon_attributes 1, 0, 0, 0, 1, 0, 48, 0, 12, 0, 0, 75, 8, 0, 80
weapon_attribute_records_0B:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 2, 16, 0, 75, 14, 0, 80
weapon_attribute_records_0C:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 30, 4, 0, 75, 20, 0, 80
weapon_attribute_records_0D:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 22, 32, 0, 75, 27, 0, 80
weapon_attribute_records_0E:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 8, 0, 10, 75, 35, 0, 80
weapon_attribute_records_0F:
    weapon_attributes 1, 0, 0, 0, 0, 1, 48, 0, 16, 0, 0, 75, 43, 0, 80
weapon_attribute_records_10:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 26, 128, 0, 75, 52, 0, 80
weapon_attribute_records_11:
    weapon_attributes 1, 0, 0, 0, 2, 2, 48, 0, 4, 0, 0, 99, 127, 0, 99
weapon_attribute_records_12:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 75, 4, 0, 80
weapon_attribute_records_13:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 28, 2, 0, 75, 11, 0, 80
weapon_attribute_records_14:
    weapon_attributes 2, 0, 0, 1, 0, 0, 48, 0, 22, 0, 0, 75, 16, 0, 80
weapon_attribute_records_15:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 26, 2, 0, 75, 23, 0, 80
weapon_attribute_records_16:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 30, 4, 0, 75, 29, 0, 80
weapon_attribute_records_17:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 18, 8, 0, 75, 38, 0, 80
weapon_attribute_records_18:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 12, 2, 0, 75, 46, 0, 80
weapon_attribute_records_19:
    weapon_attributes 2, 0, 0, 0, 0, 2, 48, 0, 8, 0, 0, 75, 54, 0, 80
weapon_attribute_records_1A:
    weapon_attributes 2, 0, 0, 0, 0, 0, 48, 0, 20, 0, 0, 75, 56, 0, 80
weapon_attribute_records_1B:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 75, 4, 0, 80
weapon_attribute_records_1C:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 12, 0, 0, 75, 11, 0, 80
weapon_attribute_records_1D:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 14, 0, 0, 75, 16, 256, 80
weapon_attribute_records_1E:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 18, 16, 0, 75, 23, 0, 80
weapon_attribute_records_1F:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 26, 0, 0, 75, 29, 128, 80
weapon_attribute_records_20:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 24, 0, 0, 75, 38, 16, 80
weapon_attribute_records_21:
    weapon_attributes 3, 0, 0, 0, 0, 1, 48, 0, 4, 0, 0, 75, 46, 0, 80
weapon_attribute_records_22:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 28, 128, 0, 75, 54, 0, 80
weapon_attribute_records_23:
    weapon_attributes 3, 0, 0, 0, 0, 0, 48, 0, 8, 0, 0, 75, 56, 0, 80
weapon_attribute_records_24:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 28, 0, 0, 75, 2, 0, 80
weapon_attribute_records_25:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 16, 0, 0, 75, 6, 4, 80
weapon_attribute_records_26:
    weapon_attributes 4, 0, 0, 0, 1, 0, 48, 0, 4, 0, 0, 75, 12, 0, 80
weapon_attribute_records_27:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 2, 16, 0, 75, 17, 0, 80
weapon_attribute_records_28:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 12, 32, 0, 75, 24, 0, 80
weapon_attribute_records_29:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 22, 4, 0, 75, 30, 0, 80
weapon_attribute_records_2A:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 22, 0, 0, 75, 38, 4, 80
weapon_attribute_records_2B:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 8, 4, 10, 75, 47, 0, 80
weapon_attribute_records_2C:
    weapon_attributes 4, 0, 0, 0, 0, 0, 48, 0, 6, 0, 0, 75, 53, 0, 80
weapon_attribute_records_2D:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 28, 0, 0, 75, 3, 0, 80
weapon_attribute_records_2E:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 75, 8, 0, 80
weapon_attribute_records_2F:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 12, 8, 0, 75, 14, 0, 80
weapon_attribute_records_30:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 30, 0, 0, 75, 20, 128, 80
weapon_attribute_records_31:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 22, 32, 0, 75, 27, 0, 80
weapon_attribute_records_32:
    weapon_attributes 5, 1, 1, 0, 0, 0, 48, 1, 2, 0, 0, 75, 35, 0, 80
weapon_attribute_records_33:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 10, 0, 0, 75, 43, 128, 80
weapon_attribute_records_34:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 8, 0, 20, 75, 52, 0, 80
weapon_attribute_records_35:
    weapon_attributes 5, 0, 0, 0, 0, 0, 48, 1, 6, 0, 0, 75, 54, 0, 80
weapon_attribute_records_36:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 3, 0, 0, 0, 75, 2, 0, 80
weapon_attribute_records_37:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 5, 2, 16, 0, 75, 6, 0, 80
weapon_attribute_records_38:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 3, 4, 0, 0, 75, 12, 4, 80
weapon_attribute_records_39:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 5, 6, 0, 0, 75, 17, 0, 80
weapon_attribute_records_3A:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 3, 14, 4, 0, 75, 24, 0, 80
weapon_attribute_records_3B:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 3, 10, 0, 0, 75, 30, 8192, 80
weapon_attribute_records_3C:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 5, 16, 16, 0, 75, 38, 0, 80
weapon_attribute_records_3D:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 5, 12, 0, 10, 75, 47, 0, 80
weapon_attribute_records_3E:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 5, 8, 0, 10, 75, 53, 0, 80
weapon_attribute_records_3F:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 28, 0, 0, 75, 2, 0, 80
weapon_attribute_records_40:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 2, 0, 0, 75, 6, 0, 80
weapon_attribute_records_41:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 4, 8, 0, 75, 12, 0, 80
weapon_attribute_records_42:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 22, 0, 0, 75, 17, 256, 80
weapon_attribute_records_43:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 12, 32, 0, 75, 24, 0, 80
weapon_attribute_records_44:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 26, 0, 0, 75, 30, 256, 80
weapon_attribute_records_45:
    weapon_attributes 7, 1, 1, 0, 0, 0, 48, 2, 30, 0, 0, 75, 38, 0, 80
weapon_attribute_records_46:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 14, 128, 0, 75, 47, 0, 80
weapon_attribute_records_47:
    weapon_attributes 7, 0, 0, 0, 0, 0, 48, 2, 8, 0, 0, 75, 53, 0, 80
weapon_attribute_records_48:
    weapon_attributes 56, 0, 0, 0, 0, 0, 48, 0, 48, 0, 0, 99, 7, 0, 25
weapon_attribute_records_49:
    weapon_attributes 29, 0, 0, 0, 0, 0, 48, 0, 57, 0, 0, 99, 15, 8192, 25
weapon_attribute_records_4A:
    weapon_attributes 29, 0, 0, 0, 0, 0, 48, 0, 57, 0, 1, 99, 16, 8192, 25
weapon_attribute_records_4B:
    weapon_attributes 50, 0, 0, 0, 0, 0, 48, 0, 48, 0, 0, 99, 15, 0, 25
weapon_attribute_records_4C:
    weapon_attributes 50, 0, 0, 0, 0, 0, 48, 0, 48, 0, 0, 99, 14, 16, 99
weapon_attribute_records_4D:
    weapon_attributes 24, 0, 0, 0, 0, 0, 48, 1, 48, 0, 0, 99, 25, 0, 25
weapon_attribute_records_4E:
    weapon_attributes 25, 0, 0, 0, 0, 0, 48, 0, 48, 0, 0, 99, 16, 8192, 25
weapon_attribute_records_4F:
    weapon_attributes 40, 0, 0, 0, 0, 0, 48, 0, 55, 0, 0, 99, 36, 0, 25
weapon_attribute_records_50:
    weapon_attributes 40, 0, 0, 0, 0, 0, 48, 0, 55, 0, 0, 99, 37, 0, 25
weapon_attribute_records_51:
    weapon_attributes 42, 0, 0, 0, 0, 0, 48, 0, 64, 0, 0, 99, 17, 0, 25
weapon_attribute_records_52:
    weapon_attributes 70, 0, 0, 0, 0, 0, 48, 3, 76, 0, 0, 99, 16, 0, 25
weapon_attribute_records_53:
    weapon_attributes 37, 0, 0, 0, 0, 0, 48, 0, 49, 0, 0, 99, 34, 4096, 50
weapon_attribute_records_54:
    weapon_attributes 45, 0, 0, 0, 0, 0, 48, 0, 48, 0, 0, 99, 15, 8192, 80
weapon_attribute_records_55:
    weapon_attributes 41, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 66, 0, 25
weapon_attribute_records_56:
    weapon_attributes 28, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 24, 0, 0
weapon_attribute_records_57:
    weapon_attributes 42, 0, 0, 0, 0, 0, 0, 0, 64, 0, 1, 99, 31, 0, 25
weapon_attribute_records_58:
    weapon_attributes 70, 0, 0, 0, 0, 0, 0, 3, 76, 0, 0, 99, 26, 0, 25
weapon_attribute_records_59:
    weapon_attributes 57, 0, 0, 0, 0, 0, 0, 1, 60, 0, 0, 99, 44, 0, 25
weapon_attribute_records_5A:
    weapon_attributes 49, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 37, 0, 25
weapon_attribute_records_5B:
    weapon_attributes 42, 0, 0, 0, 0, 0, 0, 0, 64, 0, 1, 99, 33, 0, 25
weapon_attribute_records_5C:
    weapon_attributes 70, 0, 0, 0, 0, 0, 0, 3, 76, 0, 0, 99, 24, 0, 25
weapon_attribute_records_5D:
    weapon_attributes 39, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0, 99, 90, 16384, 0
weapon_attribute_records_5E:
    weapon_attributes 47, 0, 0, 0, 0, 0, 0, 0, 136, 0, 1, 99, 54, 8192, 25
weapon_attribute_records_5F:
    weapon_attributes 47, 0, 0, 0, 0, 0, 0, 0, 136, 0, 1, 99, 55, 0, 25
weapon_attribute_records_60:
    weapon_attributes 57, 0, 0, 0, 0, 0, 0, 1, 60, 0, 1, 99, 4, 0, 25
weapon_attribute_records_61:
    weapon_attributes 65, 0, 0, 0, 0, 0, 0, 0, 53, 0, 0, 99, 41, 8192, 25
weapon_attribute_records_62:
    weapon_attributes 65, 0, 0, 0, 0, 0, 0, 0, 53, 0, 0, 99, 42, 0, 25
weapon_attribute_records_63:
    weapon_attributes 38, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 47, 0, 25
weapon_attribute_records_64:
    weapon_attributes 56, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 44, 0, 25
weapon_attribute_records_65:
    weapon_attributes 54, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 28, 0, 25
weapon_attribute_records_66:
    weapon_attributes 52, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 39, 0, 25
weapon_attribute_records_67:
    weapon_attributes 52, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 38, 0, 25
weapon_attribute_records_68:
    weapon_attributes 55, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 42, 0, 25
weapon_attribute_records_69:
    weapon_attributes 33, 0, 0, 0, 0, 0, 0, 0, 54, 0, 1, 99, 56, 0, 25
weapon_attribute_records_6A:
    weapon_attributes 33, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 99, 55, 16, 99
weapon_attribute_records_6B:
    weapon_attributes 62, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 33, 0, 25
weapon_attribute_records_6C:
    weapon_attributes 37, 0, 0, 0, 0, 0, 0, 0, 49, 0, 0, 99, 63, 4096, 25
weapon_attribute_records_6D:
    weapon_attributes 64, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 82, 0, 25
weapon_attribute_records_6E:
    weapon_attributes 24, 0, 0, 0, 0, 0, 0, 1, 48, 0, 0, 99, 72, 0, 25
weapon_attribute_records_6F:
    weapon_attributes 39, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 99, 85, 32, 25
weapon_attribute_records_70:
    weapon_attributes 28, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 95, 0, 25
weapon_attribute_records_71:
    weapon_attributes 63, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0, 99, 28, 0, 25
weapon_attribute_records_72:
    weapon_attributes 43, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 32, 512, 25
weapon_attribute_records_73:
    weapon_attributes 36, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 31, 0, 25
weapon_attribute_records_74:
    weapon_attributes 35, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 2, 0, 25
weapon_attribute_records_75:
    weapon_attributes 48, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 73, 0, 25
weapon_attribute_records_76:
    weapon_attributes 58, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 56, 8192, 25
weapon_attribute_records_77:
    weapon_attributes 32, 0, 0, 0, 0, 0, 0, 0, 56, 0, 1, 99, 62, 0, 25
weapon_attribute_records_78:
    weapon_attributes 46, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 65, 16384, 25
weapon_attribute_records_79:
    weapon_attributes 46, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 65, 16384, 25
weapon_attribute_records_7A:
    weapon_attributes 45, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 83, 16384, 80
weapon_attribute_records_7B:
    weapon_attributes 45, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 83, 16384, 80
weapon_attribute_records_7C:
    weapon_attributes 30, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 70, 64, 25
weapon_attribute_records_7D:
    weapon_attributes 29, 0, 0, 0, 0, 0, 0, 0, 57, 0, 1, 99, 73, 8192, 25
weapon_attribute_records_7E:
    weapon_attributes 29, 0, 0, 0, 0, 0, 0, 0, 57, 0, 1, 99, 69, 16384, 25
weapon_attribute_records_7F:
    weapon_attributes 50, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 3, 0, 25
weapon_attribute_records_80:
    weapon_attributes 50, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 3, 16, 99
weapon_attribute_records_81:
    weapon_attributes 25, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 68, 0, 25
weapon_attribute_records_82:
    weapon_attributes 40, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 99, 95, 0, 25
weapon_attribute_records_83:
    weapon_attributes 68, 0, 0, 0, 0, 0, 0, 0, 58, 0, 1, 99, 90, 0, 50
weapon_attribute_records_84:
    weapon_attributes 51, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 102, 0, 25
weapon_attribute_records_85:
    weapon_attributes 1, 0, 0, 0, 0, 0, 48, 0, 30, 0, 0, 99, 57, 0, 80
weapon_attribute_records_86:
    weapon_attributes 0, 0, 0, 0, 0, 0, 48, 0, 12, 0, 0, 99, 66, 0, 80
weapon_attribute_records_87:
    weapon_attributes 38, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 54, 0, 25
weapon_attribute_records_88:
    weapon_attributes 41, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 53, 0, 25
weapon_attribute_records_89:
    weapon_attributes 47, 0, 0, 0, 0, 0, 0, 0, 136, 0, 1, 99, 77, 8192, 25
weapon_attribute_records_8A:
    weapon_attributes 47, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0, 99, 78, 16384, 33
weapon_attribute_records_8B:
    weapon_attributes 59, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 61, 0, 25
weapon_attribute_records_8C:
    weapon_attributes 26, 0, 0, 0, 0, 0, 0, 0, 49, 0, 0, 99, 72, 4096, 25
weapon_attribute_records_8D:
    weapon_attributes 61, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 99, 83, 0, 25
weapon_attribute_records_8E:
    weapon_attributes 61, 0, 0, 0, 0, 0, 0, 0, 72, 0, 1, 99, 84, 0, 25
weapon_attribute_records_8F:
    weapon_attributes 64, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 51, 0, 25
weapon_attribute_records_90:
    weapon_attributes 65, 0, 0, 0, 0, 0, 0, 0, 53, 0, 0, 99, 56, 8192, 25
weapon_attribute_records_91:
    weapon_attributes 65, 0, 0, 0, 0, 0, 0, 0, 53, 0, 1, 99, 51, 0, 25
weapon_attribute_records_92:
    weapon_attributes 60, 0, 0, 0, 0, 0, 0, 1, 61, 0, 1, 99, 56, 0, 25
weapon_attribute_records_93:
    weapon_attributes 66, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0, 99, 56, 16384, 50
weapon_attribute_records_94:
    weapon_attributes 45, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 80, 32, 80
weapon_attribute_records_95:
    weapon_attributes 45, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 84, 32, 80
weapon_attribute_records_96:
    weapon_attributes 43, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 80, 512, 25
weapon_attribute_records_97:
    weapon_attributes 34, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 58, 8192, 25
weapon_attribute_records_98:
    weapon_attributes 67, 0, 0, 0, 0, 0, 0, 0, 63, 0, 0, 99, 70, 512, 60
weapon_attribute_records_99:
    weapon_attributes 44, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 4, 0, 25
weapon_attribute_records_9A:
    weapon_attributes 44, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 5, 0, 25
weapon_attribute_records_9B:
    weapon_attributes 52, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 103, 0, 25
weapon_attribute_records_9C:
    weapon_attributes 52, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 102, 64, 25
weapon_attribute_records_9D:
    weapon_attributes 33, 0, 0, 0, 0, 0, 0, 0, 54, 0, 1, 99, 3, 0, 25
weapon_attribute_records_9E:
    weapon_attributes 33, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 99, 4, 16, 99
weapon_attribute_records_9F:
    weapon_attributes 69, 0, 0, 0, 0, 0, 0, 0, 66, 0, 1, 99, 62, 0, 25
weapon_attribute_records_A0:
    weapon_attributes 6, 0, 0, 0, 0, 0, 48, 3, 10, 0, 0, 99, 80, 0, 80
weapon_attribute_records_A1:
    weapon_attributes 31, 0, 0, 0, 0, 0, 0, 0, 136, 0, 1, 75, 79, 32, 25
weapon_attribute_records_A2:
    weapon_attributes 35, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 75, 82, 0, 25
weapon_attribute_records_A3:
    weapon_attributes 32, 0, 0, 0, 0, 0, 0, 0, 56, 0, 1, 99, 80, 0, 25
weapon_attribute_records_A4:
    weapon_attributes 32, 0, 0, 0, 0, 0, 0, 0, 56, 0, 1, 99, 80, 0, 25
weapon_attribute_records_A5:
    weapon_attributes 55, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 75, 77, 0, 25
weapon_attribute_records_A6:
    weapon_attributes 61, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 99, 37, 0, 25
weapon_attribute_records_A7:
    weapon_attributes 61, 0, 0, 0, 0, 0, 0, 0, 72, 0, 1, 99, 38, 0, 25
weapon_attribute_records_A8:
    weapon_attributes 46, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 104, 0, 25
weapon_attribute_records_A9:
    weapon_attributes 27, 0, 0, 0, 0, 0, 0, 0, 52, 0, 1, 99, 71, 0, 25
weapon_attribute_records_AA:
    weapon_attributes 27, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 99, 60, 64, 25
weapon_attribute_records_AB:
    weapon_attributes 60, 0, 0, 0, 0, 0, 0, 1, 62, 0, 1, 99, 55, 0, 25
weapon_attribute_records_AC:
    weapon_attributes 66, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 99, 56, 32, 25
weapon_attribute_records_AD:
    weapon_attributes 58, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 76, 8192, 25
weapon_attribute_records_AE:
    weapon_attributes 53, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 99, 64, 0, 25
weapon_attribute_records_AF:
    weapon_attributes 71, 0, 0, 0, 0, 0, 0, 5, 70, 0, 2, 99, 54, 0, 25
weapon_attribute_records_B0:
    weapon_attributes 26, 0, 0, 0, 0, 0, 0, 0, 49, 0, 0, 99, 106, 4096, 99
weapon_attribute_records_B1:
    weapon_attributes 64, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 46, 0, 25
weapon_attribute_records_B2:
    weapon_attributes 34, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 107, 8192, 99
weapon_attribute_records_B3:
    weapon_attributes 67, 0, 0, 0, 0, 0, 0, 0, 63, 0, 0, 99, 108, 512, 99
weapon_attribute_records_B4:
    weapon_attributes 48, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 99, 1, 0, 25
weapon_attribute_records_B5:
    weapon_attributes 53, 0, 0, 0, 0, 0, 0, 0, 68, 0, 2, 99, 29, 0, 33
weapon_attribute_records_B6:
    weapon_attributes 71, 0, 0, 0, 0, 0, 0, 5, 70, 0, 2, 99, 30, 0, 33
weapon_attribute_records_B7:
    weapon_attributes 69, 0, 0, 0, 0, 0, 0, 0, 66, 0, 1, 99, 62, 0, 25
weapon_attribute_records_B8:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 81, 0, 99
weapon_attribute_records_B9:
    weapon_attributes 63, 0, 0, 0, 0, 0, 0, 0, 74, 0, 1, 99, 106, 0, 25
weapon_attribute_records_BA:
    weapon_attributes 36, 0, 0, 0, 0, 0, 0, 0, 48, 0, 1, 99, 26, 0, 25
weapon_attribute_records_BB:
    weapon_attributes 69, 0, 0, 0, 0, 0, 0, 0, 66, 0, 1, 99, 114, 0, 50
weapon_attribute_records_BC:
    weapon_attributes 53, 0, 0, 0, 0, 0, 0, 0, 68, 0, 4, 99, 58, 0, 50
weapon_attribute_records_BD:
    weapon_attributes 71, 0, 0, 0, 0, 0, 0, 5, 70, 0, 4, 99, 58, 0, 0
weapon_attribute_records_BE:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_BF:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C0:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C1:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C2:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C3:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C4:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C5:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C6:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C7:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C8:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_C9:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CA:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CB:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CC:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CD:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CE:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_CF:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D0:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D1:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D2:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D3:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D4:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D5:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D6:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D7:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D8:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_D9:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DA:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DB:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DC:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DD:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DE:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_DF:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E0:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E1:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E2:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E3:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E4:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E5:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E6:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E7:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E8:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_E9:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_EA:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_EB:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_EC:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_ED:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_EE:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_EF:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F0:
    weapon_attributes 72, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F1:
    weapon_attributes 0, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F2:
    weapon_attributes 21, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F3:
    weapon_attributes 20, 0, 0, 0, 0, 0, 0, 0, 149, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F4:
    weapon_attributes 19, 0, 0, 0, 0, 0, 0, 0, 147, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F5:
    weapon_attributes 18, 0, 0, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F6:
    weapon_attributes 17, 0, 0, 0, 0, 0, 0, 0, 137, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F7:
    weapon_attributes 16, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F8:
    weapon_attributes 15, 0, 0, 0, 0, 0, 0, 0, 149, 0, 0, 0, 0, 0, 0
weapon_attribute_records_F9:
    weapon_attributes 14, 0, 0, 0, 0, 0, 0, 0, 147, 0, 0, 0, 0, 0, 0
weapon_attribute_records_FA:
    weapon_attributes 13, 0, 0, 0, 0, 0, 48, 0, 2, 0, 0, 36, 2, 0, 25
weapon_attribute_records_FB:
    weapon_attributes 12, 0, 0, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0
weapon_attribute_records_FC:
    weapon_attributes 11, 0, 0, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0
weapon_attribute_records_FD:
    weapon_attributes 10, 0, 0, 0, 0, 0, 0, 0, 137, 0, 0, 0, 0, 0, 0
weapon_attribute_records_FE:
    weapon_attributes 9, 0, 0, 0, 0, 0, 0, 0, 137, 0, 0, 0, 0, 0, 0
weapon_attribute_records_FF:
    weapon_attributes 8, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0, 0, 0, 0, 0
