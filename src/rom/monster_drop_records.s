; Typed native gameplay records; docs/actor-record-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A50
.macro monster_drop chance_64, guaranteed, flag_bit7, trap_agility_units8, field_1_low, field_2_low, content_threshold, content_mode, reward_a, reward_b
    .byte chance_64 | (guaranteed << 6) | (flag_bit7 << 7)
    .byte (trap_agility_units8 << 4) | field_1_low
    .byte field_2_low | (content_threshold << 3) | (content_mode << 6)
    .byte reward_a, reward_b
.endmacro
monster_drop_records_00:
    monster_drop 8, 0, 0, 1, 0, 0, 7, 3, 64, 4
monster_drop_records_01:
    monster_drop 4, 0, 0, 3, 0, 0, 7, 3, 64, 22
monster_drop_records_02:
    monster_drop 4, 0, 0, 2, 0, 0, 7, 2, 14, 64
monster_drop_records_03:
    monster_drop 4, 0, 0, 3, 0, 0, 7, 2, 34, 64
monster_drop_records_04:
    monster_drop 4, 0, 0, 2, 0, 0, 7, 3, 68, 16
monster_drop_records_05:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_06:
    monster_drop 4, 0, 0, 3, 3, 0, 7, 2, 28, 4
monster_drop_records_07:
    monster_drop 4, 0, 0, 3, 0, 0, 7, 1, 65, 68
monster_drop_records_08:
    monster_drop 4, 0, 1, 3, 0, 0, 7, 3, 68, 24
monster_drop_records_09:
    monster_drop 4, 0, 0, 3, 0, 0, 7, 1, 67, 69
monster_drop_records_0A:
    monster_drop 4, 0, 0, 3, 0, 2, 7, 3, 64, 20
monster_drop_records_0B:
    monster_drop 4, 0, 0, 3, 0, 0, 7, 1, 64, 67
monster_drop_records_0C:
    monster_drop 4, 0, 0, 4, 3, 3, 7, 1, 64, 46
monster_drop_records_0D:
    monster_drop 4, 0, 0, 3, 0, 2, 7, 2, 44, 74
monster_drop_records_0E:
    monster_drop 4, 0, 1, 4, 3, 2, 7, 2, 60, 45
monster_drop_records_0F:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 64, 67
monster_drop_records_10:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 1, 64, 68
monster_drop_records_11:
    monster_drop 4, 0, 1, 8, 3, 0, 7, 1, 66, 58
monster_drop_records_12:
    monster_drop 4, 0, 0, 4, 0, 3, 7, 3, 68, 96
monster_drop_records_13:
    monster_drop 4, 0, 1, 4, 3, 4, 7, 1, 65, 28
monster_drop_records_14:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 2, 158, 65
monster_drop_records_15:
    monster_drop 4, 0, 1, 4, 3, 2, 7, 1, 68, 5
monster_drop_records_16:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 1, 65, 67
monster_drop_records_17:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 2, 24, 68
monster_drop_records_18:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 1, 67, 64
monster_drop_records_19:
    monster_drop 4, 0, 0, 3, 0, 4, 7, 1, 68, 69
monster_drop_records_1A:
    monster_drop 4, 0, 1, 5, 0, 4, 7, 1, 65, 67
monster_drop_records_1B:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 1, 64, 68
monster_drop_records_1C:
    monster_drop 4, 0, 1, 5, 3, 2, 7, 1, 65, 9
monster_drop_records_1D:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 67, 69
monster_drop_records_1E:
    monster_drop 4, 0, 0, 5, 0, 4, 7, 1, 64, 65
monster_drop_records_1F:
    monster_drop 4, 0, 1, 2, 3, 3, 7, 1, 69, 27
monster_drop_records_20:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_21:
    monster_drop 4, 0, 0, 4, 0, 4, 7, 3, 64, 120
monster_drop_records_22:
    monster_drop 4, 0, 1, 4, 0, 2, 7, 1, 67, 69
monster_drop_records_23:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 65, 67
monster_drop_records_24:
    monster_drop 4, 0, 0, 4, 0, 5, 7, 1, 64, 68
monster_drop_records_25:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 64, 68
monster_drop_records_26:
    monster_drop 4, 0, 0, 4, 0, 0, 7, 1, 67, 65
monster_drop_records_27:
    monster_drop 4, 0, 1, 4, 3, 4, 7, 1, 65, 48
monster_drop_records_28:
    monster_drop 4, 0, 0, 7, 0, 3, 7, 1, 68, 65
monster_drop_records_29:
    monster_drop 4, 0, 0, 5, 0, 4, 7, 1, 68, 66
monster_drop_records_2A:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 65, 74
monster_drop_records_2B:
    monster_drop 4, 0, 0, 6, 0, 4, 7, 1, 68, 64
monster_drop_records_2C:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_2D:
    monster_drop 4, 0, 0, 2, 0, 5, 7, 1, 67, 66
monster_drop_records_2E:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_2F:
    monster_drop 4, 0, 0, 6, 0, 2, 7, 1, 67, 66
monster_drop_records_30:
    monster_drop 4, 0, 1, 5, 3, 2, 7, 1, 66, 60
monster_drop_records_31:
    monster_drop 4, 0, 0, 6, 3, 2, 7, 1, 65, 56
monster_drop_records_32:
    monster_drop 4, 0, 0, 2, 0, 5, 7, 1, 65, 64
monster_drop_records_33:
    monster_drop 4, 0, 1, 4, 3, 2, 7, 1, 68, 29
monster_drop_records_34:
    monster_drop 4, 0, 0, 4, 0, 2, 7, 1, 65, 69
monster_drop_records_35:
    monster_drop 4, 0, 0, 6, 0, 2, 7, 1, 65, 68
monster_drop_records_36:
    monster_drop 4, 0, 0, 6, 0, 2, 7, 1, 64, 68
monster_drop_records_37:
    monster_drop 4, 0, 0, 5, 0, 2, 7, 1, 64, 69
monster_drop_records_38:
    monster_drop 4, 0, 1, 4, 3, 2, 7, 1, 65, 7
monster_drop_records_39:
    monster_drop 4, 0, 1, 7, 0, 2, 7, 1, 67, 69
monster_drop_records_3A:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 67, 13
monster_drop_records_3B:
    monster_drop 4, 0, 1, 8, 3, 5, 7, 1, 65, 19
monster_drop_records_3C:
    monster_drop 4, 0, 1, 7, 3, 5, 7, 1, 66, 16
monster_drop_records_3D:
    monster_drop 4, 0, 0, 6, 3, 2, 7, 1, 38, 133
monster_drop_records_3E:
    monster_drop 4, 0, 0, 4, 0, 5, 7, 1, 64, 69
monster_drop_records_3F:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_40:
    monster_drop 4, 0, 1, 6, 3, 2, 7, 1, 69, 59
monster_drop_records_41:
    monster_drop 4, 0, 0, 7, 3, 2, 7, 1, 66, 15
monster_drop_records_42:
    monster_drop 4, 0, 0, 7, 0, 4, 7, 1, 69, 65
monster_drop_records_43:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 65, 35
monster_drop_records_44:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 61, 131
monster_drop_records_45:
    monster_drop 4, 0, 1, 8, 3, 2, 7, 1, 67, 17
monster_drop_records_46:
    monster_drop 4, 0, 1, 8, 0, 2, 7, 1, 64, 66
monster_drop_records_47:
    monster_drop 4, 0, 0, 7, 0, 2, 7, 1, 68, 66
monster_drop_records_48:
    monster_drop 4, 0, 0, 6, 0, 2, 7, 1, 64, 65
monster_drop_records_49:
    monster_drop 4, 0, 1, 8, 8, 2, 7, 1, 40, 135
monster_drop_records_4A:
    monster_drop 4, 0, 1, 8, 0, 2, 7, 1, 66, 67
monster_drop_records_4B:
    monster_drop 4, 0, 1, 8, 3, 2, 7, 1, 39, 130
monster_drop_records_4C:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 67, 18
monster_drop_records_4D:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 65, 57
monster_drop_records_4E:
    monster_drop 4, 0, 1, 7, 3, 2, 7, 1, 34, 56
monster_drop_records_4F:
    monster_drop 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
monster_drop_records_50:
    monster_drop 4, 0, 1, 9, 8, 2, 7, 1, 43, 128
monster_drop_records_51:
    monster_drop 4, 0, 1, 6, 3, 2, 7, 1, 69, 55
monster_drop_records_52:
    monster_drop 4, 0, 1, 9, 8, 2, 7, 1, 20, 132
monster_drop_records_53:
    monster_drop 4, 0, 1, 9, 8, 2, 7, 1, 41, 134
monster_drop_records_54:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_55:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_56:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_57:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_58:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_59:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5A:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5B:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5C:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5D:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5E:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_5F:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_60:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_61:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_62:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_63:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_64:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_65:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_66:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_67:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_68:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_69:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6A:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6B:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6C:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6D:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6E:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_6F:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_70:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_71:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_72:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_73:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_74:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_75:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_76:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_77:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_78:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_79:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7A:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7B:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7C:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7D:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7E:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
monster_drop_records_7F:
    monster_drop 63, 1, 1, 15, 15, 7, 7, 3, 255, 255
