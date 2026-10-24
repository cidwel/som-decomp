; Hero growth records; docs/hero-progression-numeric-source.md.
.setcpu "65816"
.segment "CODE"
.org $4528
.macro hero_growth hp, mp, strength, agility, constitution, intelligence, wisdom
    .word hp
    .byte mp, strength, agility, constitution, intelligence, wisdom
.endmacro
girl_level_growth_records:
girl_level_01:
    hero_growth 45, 8, 10, 10, 12, 7, 15
girl_level_02:
    hero_growth 52, 8, 11, 11, 12, 8, 16
girl_level_03:
    hero_growth 59, 8, 12, 11, 13, 9, 17
girl_level_04:
    hero_growth 67, 8, 13, 12, 13, 10, 17
girl_level_05:
    hero_growth 74, 9, 14, 13, 14, 10, 18
girl_level_06:
    hero_growth 82, 9, 14, 14, 14, 11, 19
girl_level_07:
    hero_growth 89, 9, 15, 14, 15, 11, 20
girl_level_08:
    hero_growth 97, 10, 16, 15, 15, 12, 21
girl_level_09:
    hero_growth 104, 10, 16, 16, 16, 13, 22
girl_level_10:
    hero_growth 112, 11, 17, 17, 17, 13, 22
girl_level_11:
    hero_growth 119, 11, 18, 17, 17, 14, 23
girl_level_12:
    hero_growth 127, 11, 18, 18, 18, 15, 24
girl_level_13:
    hero_growth 134, 12, 19, 19, 19, 15, 25
girl_level_14:
    hero_growth 142, 12, 20, 20, 19, 16, 26
girl_level_15:
    hero_growth 149, 13, 21, 20, 20, 17, 27
girl_level_16:
    hero_growth 157, 13, 21, 21, 21, 17, 28
girl_level_17:
    hero_growth 164, 14, 22, 22, 21, 18, 28
girl_level_18:
    hero_growth 172, 14, 23, 23, 22, 18, 29
girl_level_19:
    hero_growth 180, 15, 23, 23, 22, 19, 30
girl_level_20:
    hero_growth 187, 16, 24, 24, 23, 20, 31
girl_level_21:
    hero_growth 195, 16, 25, 25, 24, 20, 32
girl_level_22:
    hero_growth 202, 17, 26, 26, 24, 21, 33
girl_level_23:
    hero_growth 210, 17, 26, 26, 25, 22, 34
girl_level_24:
    hero_growth 217, 18, 27, 27, 26, 22, 34
girl_level_25:
    hero_growth 225, 19, 28, 28, 26, 23, 35
girl_level_26:
    hero_growth 233, 19, 28, 29, 27, 24, 36
girl_level_27:
    hero_growth 240, 20, 29, 29, 28, 24, 37
girl_level_28:
    hero_growth 248, 21, 30, 30, 28, 25, 38
girl_level_29:
    hero_growth 256, 22, 31, 31, 29, 25, 39
girl_level_30:
    hero_growth 263, 23, 31, 32, 30, 26, 39
girl_level_31:
    hero_growth 271, 23, 32, 32, 30, 27, 40
girl_level_32:
    hero_growth 278, 24, 33, 33, 31, 27, 41
girl_level_33:
    hero_growth 286, 25, 33, 34, 32, 28, 42
girl_level_34:
    hero_growth 294, 26, 34, 35, 32, 29, 43
girl_level_35:
    hero_growth 302, 27, 35, 36, 33, 29, 44
girl_level_36:
    hero_growth 309, 28, 35, 36, 34, 30, 45
girl_level_37:
    hero_growth 317, 29, 36, 37, 34, 31, 45
girl_level_38:
    hero_growth 325, 30, 37, 38, 35, 31, 46
girl_level_39:
    hero_growth 332, 32, 38, 39, 36, 32, 47
girl_level_40:
    hero_growth 340, 33, 38, 39, 36, 32, 48
girl_level_41:
    hero_growth 348, 34, 39, 40, 37, 33, 49
girl_level_42:
    hero_growth 355, 35, 40, 41, 38, 34, 50
girl_level_43:
    hero_growth 363, 37, 40, 42, 38, 34, 50
girl_level_44:
    hero_growth 371, 38, 41, 42, 39, 35, 51
girl_level_45:
    hero_growth 379, 39, 42, 43, 40, 36, 52
girl_level_46:
    hero_growth 386, 41, 43, 44, 40, 36, 53
girl_level_47:
    hero_growth 394, 42, 43, 45, 41, 37, 54
girl_level_48:
    hero_growth 402, 44, 44, 45, 42, 38, 55
girl_level_49:
    hero_growth 410, 46, 45, 46, 42, 38, 56
girl_level_50:
    hero_growth 417, 47, 45, 47, 43, 39, 56
girl_level_51:
    hero_growth 425, 49, 46, 48, 43, 39, 57
girl_level_52:
    hero_growth 433, 51, 47, 48, 44, 40, 58
girl_level_53:
    hero_growth 441, 53, 47, 49, 45, 41, 59
girl_level_54:
    hero_growth 449, 55, 48, 50, 45, 41, 60
girl_level_55:
    hero_growth 457, 57, 49, 51, 46, 42, 61
girl_level_56:
    hero_growth 464, 59, 50, 51, 47, 43, 62
girl_level_57:
    hero_growth 472, 61, 50, 52, 47, 43, 62
girl_level_58:
    hero_growth 480, 64, 51, 53, 48, 44, 63
girl_level_59:
    hero_growth 488, 66, 52, 54, 49, 45, 64
girl_level_60:
    hero_growth 496, 68, 52, 54, 49, 45, 65
girl_level_61:
    hero_growth 504, 71, 53, 55, 50, 46, 66
girl_level_62:
    hero_growth 511, 74, 54, 56, 51, 46, 67
girl_level_63:
    hero_growth 519, 76, 55, 57, 51, 47, 67
girl_level_64:
    hero_growth 527, 79, 55, 57, 52, 48, 68
girl_level_65:
    hero_growth 535, 82, 56, 58, 53, 48, 69
girl_level_66:
    hero_growth 543, 85, 57, 59, 53, 49, 70
girl_level_67:
    hero_growth 551, 88, 57, 60, 54, 50, 71
girl_level_68:
    hero_growth 559, 92, 58, 61, 55, 50, 72
girl_level_69:
    hero_growth 567, 95, 59, 61, 55, 51, 73
girl_level_70:
    hero_growth 575, 99, 59, 62, 56, 52, 73
girl_level_71:
    hero_growth 583, 99, 60, 63, 57, 52, 74
girl_level_72:
    hero_growth 591, 99, 61, 64, 57, 53, 75
girl_level_73:
    hero_growth 599, 99, 62, 64, 58, 53, 76
girl_level_74:
    hero_growth 606, 99, 62, 65, 59, 54, 77
girl_level_75:
    hero_growth 614, 99, 63, 66, 59, 55, 78
girl_level_76:
    hero_growth 622, 99, 64, 67, 60, 55, 78
girl_level_77:
    hero_growth 630, 99, 64, 67, 61, 56, 79
girl_level_78:
    hero_growth 638, 99, 65, 68, 61, 57, 80
girl_level_79:
    hero_growth 646, 99, 66, 69, 62, 57, 81
girl_level_80:
    hero_growth 654, 99, 67, 70, 63, 58, 82
girl_level_81:
    hero_growth 662, 99, 67, 70, 63, 59, 83
girl_level_82:
    hero_growth 670, 99, 68, 71, 64, 59, 84
girl_level_83:
    hero_growth 678, 99, 69, 72, 64, 60, 84
girl_level_84:
    hero_growth 686, 99, 69, 73, 65, 60, 85
girl_level_85:
    hero_growth 694, 99, 70, 73, 66, 61, 86
girl_level_86:
    hero_growth 702, 99, 71, 74, 66, 62, 87
girl_level_87:
    hero_growth 710, 99, 72, 75, 67, 62, 88
girl_level_88:
    hero_growth 718, 99, 72, 76, 68, 63, 89
girl_level_89:
    hero_growth 726, 99, 73, 76, 68, 64, 90
girl_level_90:
    hero_growth 734, 99, 74, 77, 69, 64, 90
girl_level_91:
    hero_growth 742, 99, 74, 78, 70, 65, 91
girl_level_92:
    hero_growth 750, 99, 75, 79, 70, 66, 92
girl_level_93:
    hero_growth 758, 99, 76, 79, 71, 66, 93
girl_level_94:
    hero_growth 766, 99, 76, 80, 72, 67, 94
girl_level_95:
    hero_growth 774, 99, 77, 81, 72, 67, 95
girl_level_96:
    hero_growth 782, 99, 78, 82, 73, 68, 96
girl_level_97:
    hero_growth 790, 99, 79, 83, 74, 69, 97
girl_level_98:
    hero_growth 795, 99, 79, 84, 74, 69, 98
girl_level_99:
    hero_growth 800, 99, 80, 85, 75, 70, 99
