; Hero growth records; docs/hero-progression-numeric-source.md.
.setcpu "65816"
.segment "CODE"
.org $4210
.macro hero_growth hp, mp, strength, agility, constitution, intelligence, wisdom
    .word hp
    .byte mp, strength, agility, constitution, intelligence, wisdom
.endmacro
boy_level_growth_records:
boy_level_01:
    hero_growth 50, 0, 15, 15, 13, 5, 5
boy_level_02:
    hero_growth 59, 0, 16, 16, 14, 6, 6
boy_level_03:
    hero_growth 69, 0, 17, 17, 15, 6, 7
boy_level_04:
    hero_growth 79, 0, 17, 17, 16, 7, 8
boy_level_05:
    hero_growth 88, 0, 18, 18, 17, 7, 9
boy_level_06:
    hero_growth 98, 0, 19, 19, 18, 8, 9
boy_level_07:
    hero_growth 108, 0, 20, 20, 19, 8, 10
boy_level_08:
    hero_growth 117, 0, 21, 21, 20, 9, 11
boy_level_09:
    hero_growth 127, 0, 22, 22, 21, 9, 11
boy_level_10:
    hero_growth 137, 0, 22, 22, 22, 10, 12
boy_level_11:
    hero_growth 146, 0, 23, 23, 23, 10, 13
boy_level_12:
    hero_growth 156, 0, 24, 24, 24, 10, 13
boy_level_13:
    hero_growth 166, 0, 25, 25, 25, 11, 14
boy_level_14:
    hero_growth 175, 0, 26, 26, 26, 11, 15
boy_level_15:
    hero_growth 185, 0, 27, 27, 27, 12, 16
boy_level_16:
    hero_growth 195, 0, 28, 28, 28, 12, 16
boy_level_17:
    hero_growth 205, 0, 28, 28, 28, 13, 17
boy_level_18:
    hero_growth 214, 0, 29, 29, 29, 13, 18
boy_level_19:
    hero_growth 224, 0, 30, 30, 30, 14, 18
boy_level_20:
    hero_growth 234, 0, 31, 31, 31, 14, 19
boy_level_21:
    hero_growth 243, 0, 32, 32, 32, 15, 20
boy_level_22:
    hero_growth 253, 0, 33, 33, 33, 15, 21
boy_level_23:
    hero_growth 263, 0, 34, 34, 34, 15, 21
boy_level_24:
    hero_growth 272, 0, 34, 34, 34, 16, 22
boy_level_25:
    hero_growth 282, 0, 35, 35, 35, 16, 23
boy_level_26:
    hero_growth 292, 0, 36, 36, 36, 17, 23
boy_level_27:
    hero_growth 301, 0, 37, 37, 37, 17, 24
boy_level_28:
    hero_growth 311, 0, 38, 38, 38, 18, 25
boy_level_29:
    hero_growth 321, 0, 39, 39, 39, 18, 26
boy_level_30:
    hero_growth 331, 0, 39, 39, 39, 19, 26
boy_level_31:
    hero_growth 340, 0, 40, 40, 40, 19, 27
boy_level_32:
    hero_growth 350, 0, 41, 41, 41, 20, 28
boy_level_33:
    hero_growth 360, 0, 42, 42, 42, 20, 28
boy_level_34:
    hero_growth 369, 0, 43, 43, 43, 20, 29
boy_level_35:
    hero_growth 379, 0, 44, 44, 44, 21, 30
boy_level_36:
    hero_growth 389, 0, 45, 45, 45, 21, 30
boy_level_37:
    hero_growth 398, 0, 45, 45, 45, 22, 31
boy_level_38:
    hero_growth 408, 0, 46, 46, 46, 22, 32
boy_level_39:
    hero_growth 418, 0, 47, 47, 47, 23, 33
boy_level_40:
    hero_growth 427, 0, 48, 48, 48, 23, 33
boy_level_41:
    hero_growth 437, 0, 49, 49, 49, 24, 34
boy_level_42:
    hero_growth 447, 0, 50, 50, 50, 24, 35
boy_level_43:
    hero_growth 457, 0, 50, 50, 50, 25, 35
boy_level_44:
    hero_growth 466, 0, 51, 51, 51, 25, 36
boy_level_45:
    hero_growth 476, 0, 52, 52, 52, 25, 37
boy_level_46:
    hero_growth 486, 0, 53, 53, 53, 26, 38
boy_level_47:
    hero_growth 495, 0, 54, 54, 54, 26, 38
boy_level_48:
    hero_growth 505, 0, 55, 55, 55, 27, 39
boy_level_49:
    hero_growth 515, 0, 56, 56, 56, 27, 40
boy_level_50:
    hero_growth 524, 0, 56, 56, 56, 28, 40
boy_level_51:
    hero_growth 534, 0, 57, 57, 57, 28, 41
boy_level_52:
    hero_growth 544, 0, 58, 58, 58, 29, 42
boy_level_53:
    hero_growth 553, 0, 59, 59, 59, 29, 42
boy_level_54:
    hero_growth 563, 0, 60, 60, 60, 30, 43
boy_level_55:
    hero_growth 573, 0, 61, 61, 61, 30, 44
boy_level_56:
    hero_growth 582, 0, 62, 62, 62, 30, 45
boy_level_57:
    hero_growth 592, 0, 62, 62, 62, 31, 45
boy_level_58:
    hero_growth 602, 0, 63, 63, 63, 31, 46
boy_level_59:
    hero_growth 612, 0, 64, 64, 64, 32, 47
boy_level_60:
    hero_growth 621, 0, 65, 65, 65, 32, 47
boy_level_61:
    hero_growth 631, 0, 66, 66, 66, 33, 48
boy_level_62:
    hero_growth 641, 0, 67, 67, 67, 33, 49
boy_level_63:
    hero_growth 650, 0, 67, 67, 67, 34, 50
boy_level_64:
    hero_growth 660, 0, 68, 68, 68, 34, 50
boy_level_65:
    hero_growth 670, 0, 69, 69, 69, 35, 51
boy_level_66:
    hero_growth 679, 0, 70, 70, 70, 35, 52
boy_level_67:
    hero_growth 689, 0, 71, 71, 71, 35, 52
boy_level_68:
    hero_growth 699, 0, 72, 72, 72, 36, 53
boy_level_69:
    hero_growth 708, 0, 73, 73, 73, 36, 54
boy_level_70:
    hero_growth 718, 0, 73, 73, 73, 37, 54
boy_level_71:
    hero_growth 728, 0, 74, 74, 74, 37, 55
boy_level_72:
    hero_growth 738, 0, 75, 75, 75, 38, 56
boy_level_73:
    hero_growth 747, 0, 76, 76, 76, 38, 57
boy_level_74:
    hero_growth 757, 0, 77, 77, 77, 39, 57
boy_level_75:
    hero_growth 767, 0, 78, 78, 78, 39, 58
boy_level_76:
    hero_growth 776, 0, 78, 78, 78, 40, 59
boy_level_77:
    hero_growth 786, 0, 79, 79, 79, 40, 59
boy_level_78:
    hero_growth 796, 0, 80, 80, 80, 40, 60
boy_level_79:
    hero_growth 805, 0, 81, 81, 81, 41, 61
boy_level_80:
    hero_growth 815, 0, 82, 82, 82, 41, 62
boy_level_81:
    hero_growth 825, 0, 83, 83, 83, 42, 62
boy_level_82:
    hero_growth 834, 0, 84, 84, 84, 42, 63
boy_level_83:
    hero_growth 844, 0, 84, 84, 84, 43, 64
boy_level_84:
    hero_growth 854, 0, 85, 85, 85, 43, 64
boy_level_85:
    hero_growth 864, 0, 86, 86, 86, 44, 65
boy_level_86:
    hero_growth 873, 0, 87, 87, 87, 44, 66
boy_level_87:
    hero_growth 883, 0, 88, 88, 88, 45, 67
boy_level_88:
    hero_growth 893, 0, 89, 89, 89, 45, 67
boy_level_89:
    hero_growth 902, 0, 90, 90, 90, 45, 68
boy_level_90:
    hero_growth 912, 0, 90, 90, 90, 46, 69
boy_level_91:
    hero_growth 922, 0, 91, 91, 91, 46, 69
boy_level_92:
    hero_growth 931, 0, 92, 92, 92, 47, 70
boy_level_93:
    hero_growth 941, 0, 93, 93, 93, 47, 71
boy_level_94:
    hero_growth 951, 0, 94, 94, 94, 48, 71
boy_level_95:
    hero_growth 960, 0, 95, 95, 95, 48, 72
boy_level_96:
    hero_growth 970, 0, 96, 96, 96, 49, 73
boy_level_97:
    hero_growth 980, 0, 97, 97, 97, 49, 74
boy_level_98:
    hero_growth 990, 0, 98, 98, 98, 50, 74
boy_level_99:
    hero_growth 999, 0, 99, 99, 99, 50, 75
