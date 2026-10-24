; Hero growth records; docs/hero-progression-numeric-source.md.
.setcpu "65816"
.segment "CODE"
.org $4840
.macro hero_growth hp, mp, strength, agility, constitution, intelligence, wisdom
    .word hp
    .byte mp, strength, agility, constitution, intelligence, wisdom
.endmacro
sprite_level_growth_records:
sprite_level_01:
    hero_growth 40, 8, 7, 12, 10, 15, 5
sprite_level_02:
    hero_growth 47, 8, 8, 12, 11, 16, 6
sprite_level_03:
    hero_growth 54, 8, 8, 13, 11, 17, 6
sprite_level_04:
    hero_growth 62, 8, 9, 13, 12, 17, 7
sprite_level_05:
    hero_growth 69, 9, 9, 14, 12, 18, 7
sprite_level_06:
    hero_growth 77, 9, 10, 14, 12, 19, 8
sprite_level_07:
    hero_growth 84, 9, 10, 15, 13, 20, 8
sprite_level_08:
    hero_growth 92, 10, 10, 15, 13, 21, 9
sprite_level_09:
    hero_growth 99, 10, 11, 16, 14, 22, 9
sprite_level_10:
    hero_growth 107, 11, 11, 17, 14, 22, 10
sprite_level_11:
    hero_growth 114, 11, 12, 17, 14, 23, 10
sprite_level_12:
    hero_growth 122, 11, 12, 18, 15, 24, 10
sprite_level_13:
    hero_growth 129, 12, 13, 19, 15, 25, 11
sprite_level_14:
    hero_growth 137, 12, 13, 19, 16, 26, 11
sprite_level_15:
    hero_growth 144, 13, 14, 20, 16, 27, 12
sprite_level_16:
    hero_growth 152, 13, 14, 21, 16, 28, 12
sprite_level_17:
    hero_growth 159, 14, 14, 21, 17, 28, 13
sprite_level_18:
    hero_growth 167, 14, 15, 22, 17, 29, 13
sprite_level_19:
    hero_growth 175, 15, 15, 22, 18, 30, 14
sprite_level_20:
    hero_growth 182, 16, 16, 23, 18, 31, 14
sprite_level_21:
    hero_growth 190, 16, 16, 24, 18, 32, 15
sprite_level_22:
    hero_growth 197, 17, 17, 24, 19, 33, 15
sprite_level_23:
    hero_growth 205, 17, 17, 25, 19, 34, 15
sprite_level_24:
    hero_growth 212, 18, 17, 26, 20, 34, 16
sprite_level_25:
    hero_growth 220, 19, 18, 26, 20, 35, 16
sprite_level_26:
    hero_growth 228, 19, 18, 27, 21, 36, 17
sprite_level_27:
    hero_growth 235, 20, 19, 28, 21, 37, 17
sprite_level_28:
    hero_growth 243, 21, 19, 28, 21, 38, 18
sprite_level_29:
    hero_growth 251, 22, 20, 29, 22, 39, 18
sprite_level_30:
    hero_growth 258, 23, 20, 30, 22, 39, 19
sprite_level_31:
    hero_growth 266, 23, 20, 30, 23, 40, 19
sprite_level_32:
    hero_growth 273, 24, 21, 31, 23, 41, 20
sprite_level_33:
    hero_growth 281, 25, 21, 32, 23, 42, 20
sprite_level_34:
    hero_growth 289, 26, 22, 32, 24, 43, 20
sprite_level_35:
    hero_growth 297, 27, 22, 33, 24, 44, 21
sprite_level_36:
    hero_growth 304, 28, 23, 34, 25, 45, 21
sprite_level_37:
    hero_growth 312, 29, 23, 34, 25, 45, 22
sprite_level_38:
    hero_growth 320, 30, 24, 35, 25, 46, 22
sprite_level_39:
    hero_growth 327, 32, 24, 36, 26, 47, 23
sprite_level_40:
    hero_growth 335, 33, 24, 36, 26, 48, 23
sprite_level_41:
    hero_growth 343, 34, 25, 37, 27, 49, 24
sprite_level_42:
    hero_growth 350, 35, 25, 38, 27, 50, 24
sprite_level_43:
    hero_growth 358, 37, 26, 38, 27, 50, 25
sprite_level_44:
    hero_growth 366, 38, 26, 39, 28, 51, 25
sprite_level_45:
    hero_growth 374, 39, 27, 40, 28, 52, 25
sprite_level_46:
    hero_growth 381, 41, 27, 40, 29, 53, 26
sprite_level_47:
    hero_growth 389, 42, 27, 41, 29, 54, 26
sprite_level_48:
    hero_growth 397, 44, 28, 42, 29, 55, 27
sprite_level_49:
    hero_growth 405, 46, 28, 42, 30, 56, 27
sprite_level_50:
    hero_growth 412, 47, 29, 43, 30, 56, 28
sprite_level_51:
    hero_growth 420, 49, 29, 43, 31, 57, 28
sprite_level_52:
    hero_growth 428, 51, 30, 44, 31, 58, 29
sprite_level_53:
    hero_growth 436, 53, 30, 45, 31, 59, 29
sprite_level_54:
    hero_growth 444, 55, 30, 45, 32, 60, 30
sprite_level_55:
    hero_growth 452, 57, 31, 46, 32, 61, 30
sprite_level_56:
    hero_growth 459, 59, 31, 47, 33, 62, 30
sprite_level_57:
    hero_growth 467, 61, 32, 47, 33, 62, 31
sprite_level_58:
    hero_growth 475, 64, 32, 48, 33, 63, 31
sprite_level_59:
    hero_growth 483, 66, 33, 49, 34, 64, 32
sprite_level_60:
    hero_growth 491, 68, 33, 49, 34, 65, 32
sprite_level_61:
    hero_growth 499, 71, 33, 50, 35, 66, 33
sprite_level_62:
    hero_growth 506, 74, 34, 51, 35, 67, 33
sprite_level_63:
    hero_growth 514, 76, 34, 51, 35, 67, 34
sprite_level_64:
    hero_growth 522, 79, 35, 52, 36, 68, 34
sprite_level_65:
    hero_growth 530, 82, 35, 53, 36, 69, 35
sprite_level_66:
    hero_growth 538, 85, 36, 53, 37, 70, 35
sprite_level_67:
    hero_growth 546, 88, 36, 54, 37, 71, 35
sprite_level_68:
    hero_growth 554, 92, 37, 55, 37, 72, 36
sprite_level_69:
    hero_growth 562, 95, 37, 55, 38, 73, 36
sprite_level_70:
    hero_growth 570, 99, 37, 56, 38, 73, 37
sprite_level_71:
    hero_growth 578, 99, 38, 57, 39, 74, 37
sprite_level_72:
    hero_growth 586, 99, 38, 57, 39, 75, 38
sprite_level_73:
    hero_growth 594, 99, 39, 58, 39, 76, 38
sprite_level_74:
    hero_growth 601, 99, 39, 59, 40, 77, 39
sprite_level_75:
    hero_growth 609, 99, 40, 59, 40, 78, 39
sprite_level_76:
    hero_growth 617, 99, 40, 60, 41, 78, 40
sprite_level_77:
    hero_growth 625, 99, 40, 61, 41, 79, 40
sprite_level_78:
    hero_growth 633, 99, 41, 61, 42, 80, 40
sprite_level_79:
    hero_growth 641, 99, 41, 62, 42, 81, 41
sprite_level_80:
    hero_growth 649, 99, 42, 63, 42, 82, 41
sprite_level_81:
    hero_growth 657, 99, 42, 63, 43, 83, 42
sprite_level_82:
    hero_growth 665, 99, 43, 64, 43, 84, 42
sprite_level_83:
    hero_growth 673, 99, 43, 64, 44, 84, 43
sprite_level_84:
    hero_growth 681, 99, 43, 65, 44, 85, 43
sprite_level_85:
    hero_growth 689, 99, 44, 66, 44, 86, 44
sprite_level_86:
    hero_growth 697, 99, 44, 66, 45, 87, 44
sprite_level_87:
    hero_growth 705, 99, 45, 67, 45, 88, 45
sprite_level_88:
    hero_growth 713, 99, 45, 68, 46, 89, 45
sprite_level_89:
    hero_growth 721, 99, 46, 68, 46, 90, 45
sprite_level_90:
    hero_growth 729, 99, 46, 69, 46, 90, 46
sprite_level_91:
    hero_growth 737, 99, 47, 70, 47, 91, 46
sprite_level_92:
    hero_growth 745, 99, 47, 70, 47, 92, 47
sprite_level_93:
    hero_growth 753, 99, 47, 71, 48, 93, 47
sprite_level_94:
    hero_growth 761, 99, 48, 72, 48, 94, 48
sprite_level_95:
    hero_growth 769, 99, 48, 72, 48, 95, 48
sprite_level_96:
    hero_growth 777, 99, 49, 73, 49, 96, 49
sprite_level_97:
    hero_growth 785, 99, 49, 74, 49, 97, 49
sprite_level_98:
    hero_growth 793, 99, 50, 74, 50, 98, 50
sprite_level_99:
    hero_growth 800, 99, 50, 75, 50, 99, 50
