; Typed native gameplay records; docs/actor-record-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0000
.macro actor_descriptor tile_unit, bank_selector, upper_flags, field_72, field_74, field_76, field_77, ai_pointer, field_7b, field_7d, appearance_class
    .word tile_unit | (bank_selector << 10) | (upper_flags << 13), field_72, field_74
    .byte field_76
    .word field_77, ai_pointer, field_7b, field_7d
    .byte appearance_class
.endmacro
actor_identity_descriptors_00:
    actor_descriptor 405, 4, 0, 1028, 43654, 76, 21516, 0, 18092, 18092, 53
actor_identity_descriptors_01:
    actor_descriptor 110, 3, 0, 106, 6282, 81, 22248, 185, 16368, 16368, 55
actor_identity_descriptors_02:
    actor_descriptor 20, 4, 0, 766, 13451, 74, 21564, 452, 17692, 17692, 53
actor_identity_descriptors_03:
    actor_descriptor 308, 4, 0, 970, 13451, 74, 21720, 609, 18008, 18008, 53
actor_identity_descriptors_04:
    actor_descriptor 21, 3, 0, 20, 45708, 74, 21924, 731, 16156, 16156, 53
actor_identity_descriptors_05:
    actor_descriptor 512, 3, 0, 422, 11399, 76, 22992, 914, 16978, 16978, 53
actor_identity_descriptors_06:
    actor_descriptor 623, 3, 0, 502, 13455, 74, 22782, 1210, 17226, 17226, 54
actor_identity_descriptors_07:
    actor_descriptor 345, 3, 0, 340, 39561, 80, 22962, 1468, 16792, 16792, 54
actor_identity_descriptors_08:
    actor_descriptor 591, 3, 0, 486, 45702, 74, 21612, 1623, 17162, 17162, 54
actor_identity_descriptors_09:
    actor_descriptor 556, 3, 0, 466, 38409, 81, 22530, 1789, 17134, 17134, 53
actor_identity_descriptors_0A:
    actor_descriptor 96, 3, 0, 94, 12422, 75, 22302, 1972, 16342, 16342, 53
actor_identity_descriptors_0B:
    actor_descriptor 623, 3, 0, 502, 13455, 74, 22782, 2224, 17226, 17226, 54
actor_identity_descriptors_0C:
    actor_descriptor 512, 4, 0, 1052, 13451, 74, 21750, 2538, 18128, 18128, 53
actor_identity_descriptors_0D:
    actor_descriptor 0, 4, 0, 748, 37517, 82, 23046, 2878, 17654, 17654, 53
actor_identity_descriptors_0E:
    actor_descriptor 623, 3, 0, 502, 13455, 74, 22782, 3100, 17226, 17226, 53
actor_identity_descriptors_0F:
    actor_descriptor 0, 5, 0, 402, 41479, 78, 22746, 3370, 16916, 16916, 53
actor_identity_descriptors_10:
    actor_descriptor 897, 3, 0, 676, 7302, 80, 21972, 3550, 17514, 17514, 55
actor_identity_descriptors_11:
    actor_descriptor 512, 4, 0, 1052, 13451, 74, 21750, 3823, 18128, 18128, 53
actor_identity_descriptors_12:
    actor_descriptor 918, 4, 0, 1356, 45710, 74, 22056, 4163, 18630, 18630, 53
actor_identity_descriptors_13:
    actor_descriptor 373, 3, 0, 374, 41613, 78, 22506, 4435, 16880, 16880, 53
actor_identity_descriptors_14:
    actor_descriptor 405, 4, 0, 1028, 43654, 76, 21516, 4629, 18092, 18092, 53
actor_identity_descriptors_15:
    actor_descriptor 0, 3, 0, 0, 12424, 75, 22278, 4922, 16128, 16128, 53
actor_identity_descriptors_16:
    actor_descriptor 119, 4, 0, 810, 36492, 83, 22596, 5257, 17804, 17804, 53
actor_identity_descriptors_17:
    actor_descriptor 383, 4, 0, 1006, 8327, 79, 22416, 5420, 18066, 18066, 53
actor_identity_descriptors_18:
    actor_descriptor 233, 3, 0, 198, 40587, 79, 22332, 5481, 16572, 16572, 53
actor_identity_descriptors_19:
    actor_descriptor 722, 4, 0, 1244, 11407, 76, 22104, 5712, 18444, 18444, 53
actor_identity_descriptors_1A:
    actor_descriptor 345, 3, 0, 340, 39561, 80, 22962, 6050, 16792, 16792, 54
actor_identity_descriptors_1B:
    actor_descriptor 847, 4, 0, 1322, 5259, 82, 22374, 6266, 18578, 18578, 53
actor_identity_descriptors_1C:
    actor_descriptor 308, 4, 0, 970, 13451, 74, 21720, 6471, 18008, 18008, 53
actor_identity_descriptors_1D:
    actor_descriptor 0, 5, 0, 402, 41479, 78, 22746, 6661, 16916, 16916, 53
actor_identity_descriptors_1E:
    actor_descriptor 96, 3, 0, 94, 12422, 75, 22302, 6798, 16342, 16342, 53
actor_identity_descriptors_1F:
    actor_descriptor 738, 4, 0, 1260, 13456, 74, 22908, 7034, 18484, 18484, 53
actor_identity_descriptors_20:
    actor_descriptor 0, 1, 0, 1024, 52366, 55, 13792, 22021, 11328, 11328, 56
actor_identity_descriptors_21:
    actor_descriptor 326, 3, 0, 320, 9345, 78, 21792, 7317, 16766, 16766, 53
actor_identity_descriptors_22:
    actor_descriptor 302, 3, 0, 298, 41615, 78, 22482, 7623, 16730, 16730, 53
actor_identity_descriptors_23:
    actor_descriptor 952, 3, 0, 710, 12418, 75, 22182, 7855, 17606, 17606, 53
actor_identity_descriptors_24:
    actor_descriptor 571, 4, 0, 1086, 10372, 77, 22830, 8165, 18204, 18204, 55
actor_identity_descriptors_25:
    actor_descriptor 184, 3, 0, 154, 13452, 74, 22698, 8365, 16454, 16454, 53
actor_identity_descriptors_26:
    actor_descriptor 747, 3, 0, 594, 42634, 77, 22128, 8609, 17382, 17382, 53
actor_identity_descriptors_27:
    actor_descriptor 591, 3, 0, 486, 45702, 74, 21612, 8798, 17162, 17162, 54
actor_identity_descriptors_28:
    actor_descriptor 149, 3, 0, 126, 10379, 77, 22656, 8961, 16420, 16420, 53
actor_identity_descriptors_29:
    actor_descriptor 110, 3, 0, 106, 6282, 81, 22248, 9208, 16368, 16368, 55
actor_identity_descriptors_2A:
    actor_descriptor 20, 4, 0, 766, 13451, 74, 21564, 9488, 17692, 17692, 53
actor_identity_descriptors_2B:
    actor_descriptor 21, 3, 0, 20, 45708, 74, 21924, 9706, 16156, 16156, 53
actor_identity_descriptors_2C:
    actor_descriptor 512, 3, 0, 422, 11399, 76, 22992, 10066, 16978, 16978, 53
actor_identity_descriptors_2D:
    actor_descriptor 93, 4, 0, 796, 37511, 82, 23070, 10367, 17766, 17766, 53
actor_identity_descriptors_2E:
    actor_descriptor 0, 0, 0, 0, 52366, 55, 12592, 22021, 8768, 8768, 56
actor_identity_descriptors_2F:
    actor_descriptor 373, 3, 0, 374, 41613, 78, 22506, 10537, 16880, 16880, 53
actor_identity_descriptors_30:
    actor_descriptor 556, 3, 0, 466, 38409, 81, 22530, 10728, 17134, 17134, 53
actor_identity_descriptors_31:
    actor_descriptor 897, 3, 0, 676, 7302, 80, 21972, 10987, 17514, 17514, 55
actor_identity_descriptors_32:
    actor_descriptor 620, 4, 0, 1154, 39424, 80, 23190, 11311, 18274, 18274, 55
actor_identity_descriptors_33:
    actor_descriptor 50, 3, 0, 36, 41607, 78, 23208, 11480, 16206, 16206, 53
actor_identity_descriptors_34:
    actor_descriptor 674, 4, 0, 1208, 13451, 74, 21870, 11748, 18368, 18368, 53
actor_identity_descriptors_35:
    actor_descriptor 847, 4, 0, 1322, 5259, 82, 22374, 12204, 18578, 18578, 53
actor_identity_descriptors_36:
    actor_descriptor 918, 4, 0, 1356, 45710, 74, 22056, 12396, 18630, 18630, 53
actor_identity_descriptors_37:
    actor_descriptor 634, 4, 0, 1176, 4234, 83, 22872, 12640, 18304, 18304, 53
actor_identity_descriptors_38:
    actor_descriptor 591, 3, 0, 486, 45702, 74, 21612, 13022, 17162, 17162, 54
actor_identity_descriptors_39:
    actor_descriptor 688, 3, 0, 546, 44674, 75, 22560, 13173, 17318, 17318, 53
actor_identity_descriptors_3A:
    actor_descriptor 268, 3, 0, 274, 8333, 79, 22452, 13453, 16660, 16660, 53
actor_identity_descriptors_3B:
    actor_descriptor 710, 3, 0, 580, 43651, 76, 21672, 13743, 17354, 17354, 53
actor_identity_descriptors_3C:
    actor_descriptor 119, 4, 0, 810, 36492, 83, 22596, 14152, 17804, 17804, 53
actor_identity_descriptors_3D:
    actor_descriptor 233, 3, 0, 198, 40587, 79, 22332, 14591, 16572, 16572, 53
actor_identity_descriptors_3E:
    actor_descriptor 795, 3, 0, 618, 45712, 74, 23238, 14824, 17428, 17428, 53
actor_identity_descriptors_3F:
    actor_descriptor 512, 0, 0, 512, 52366, 55, 12352, 22021, 8256, 8256, 56
actor_identity_descriptors_40:
    actor_descriptor 302, 3, 0, 298, 41615, 78, 22482, 15018, 16730, 16730, 53
actor_identity_descriptors_41:
    actor_descriptor 184, 3, 0, 154, 13452, 74, 22698, 15217, 16454, 16454, 53
actor_identity_descriptors_42:
    actor_descriptor 383, 4, 0, 1006, 8327, 79, 22416, 15499, 18066, 18066, 53
actor_identity_descriptors_43:
    actor_descriptor 674, 4, 0, 1208, 13451, 74, 21870, 15703, 18368, 18368, 53
actor_identity_descriptors_44:
    actor_descriptor 747, 3, 0, 594, 42634, 77, 22128, 16075, 17382, 17382, 53
actor_identity_descriptors_45:
    actor_descriptor 73, 3, 0, 82, 43659, 76, 22020, 16258, 16308, 16308, 53
actor_identity_descriptors_46:
    actor_descriptor 634, 4, 0, 1176, 4234, 83, 22872, 16625, 18304, 18304, 53
actor_identity_descriptors_47:
    actor_descriptor 571, 4, 0, 1086, 10372, 77, 22830, 16880, 18204, 18204, 55
actor_identity_descriptors_48:
    actor_descriptor 197, 4, 0, 916, 46734, 73, 23112, 17259, 17916, 17916, 53
actor_identity_descriptors_49:
    actor_descriptor 50, 3, 0, 36, 41607, 78, 23208, 17698, 16206, 16206, 53
actor_identity_descriptors_4A:
    actor_descriptor 847, 4, 0, 1322, 5259, 82, 22374, 18153, 18578, 18578, 53
actor_identity_descriptors_4B:
    actor_descriptor 268, 3, 0, 274, 8333, 79, 22452, 18472, 16660, 16660, 53
actor_identity_descriptors_4C:
    actor_descriptor 952, 3, 0, 710, 12418, 75, 22182, 18756, 17606, 17606, 53
actor_identity_descriptors_4D:
    actor_descriptor 197, 4, 0, 916, 46734, 73, 23112, 19173, 17916, 17916, 53
actor_identity_descriptors_4E:
    actor_descriptor 795, 3, 0, 618, 45712, 74, 23238, 19571, 17428, 17428, 53
actor_identity_descriptors_4F:
    actor_descriptor 591, 3, 0, 486, 45702, 74, 21612, 19751, 17162, 17162, 54
actor_identity_descriptors_50:
    actor_descriptor 738, 4, 0, 1260, 13456, 74, 22908, 20041, 18484, 18484, 53
actor_identity_descriptors_51:
    actor_descriptor 326, 3, 0, 320, 9345, 78, 21792, 20366, 16766, 16766, 53
actor_identity_descriptors_52:
    actor_descriptor 795, 3, 0, 618, 45712, 74, 23238, 20900, 17428, 17428, 53
actor_identity_descriptors_53:
    actor_descriptor 197, 4, 0, 916, 46734, 73, 23112, 21215, 17916, 17916, 53
actor_identity_descriptors_54:
    actor_descriptor 394, 7, 4, 1698, 47246, 58, 15032, 25742, 8256, 8256, 0
actor_identity_descriptors_55:
    actor_descriptor 986, 4, 3, 1408, 25736, 58, 14948, 21709, 18092, 18092, 0
actor_identity_descriptors_56:
    actor_descriptor 0, 1, 0, 1024, 52366, 55, 12352, 22021, 8256, 8256, 80
actor_identity_descriptors_57:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_58:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_59:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5A:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5B:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5C:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5D:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5E:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_5F:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_60:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_61:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_62:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_63:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_64:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_65:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_66:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_67:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_68:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_69:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6A:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6B:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6C:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6D:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6E:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_6F:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_70:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_71:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_72:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_73:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_74:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_75:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_76:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_77:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_78:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_79:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7A:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7B:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7C:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7D:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7E:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 21215, 65535, 65535, 148
actor_identity_descriptors_7F:
    actor_descriptor 1023, 7, 7, 65535, 65535, 255, 65535, 8365, 65535, 65535, 148
actor_identity_descriptors_80:
    actor_descriptor 0, 0, 0, 0, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_81:
    actor_descriptor 512, 0, 0, 512, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_82:
    actor_descriptor 0, 1, 0, 1024, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_83:
    actor_descriptor 394, 7, 4, 1698, 47246, 58, 15032, 25742, 8256, 8256, 0
actor_identity_descriptors_84:
    actor_descriptor 673, 2, 0, 2398, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_85:
    actor_descriptor 753, 2, 0, 2432, 21644, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_86:
    actor_descriptor 774, 2, 0, 2448, 21644, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_87:
    actor_descriptor 798, 2, 0, 2464, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_88:
    actor_descriptor 356, 7, 0, 2576, 10382, 60, 15400, 21709, 8256, 8256, 0
actor_identity_descriptors_89:
    actor_descriptor 482, 7, 2, 2662, 45198, 62, 16048, 21709, 8256, 8256, 0
actor_identity_descriptors_8A:
    actor_descriptor 0, 0, 0, 0, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_8B:
    actor_descriptor 512, 0, 0, 512, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_8C:
    actor_descriptor 0, 1, 0, 1024, 52366, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_8D:
    actor_descriptor 0, 0, 0, 0, 52366, 55, 12352, 21709, 8256, 8256, 80
actor_identity_descriptors_8E:
    actor_descriptor 512, 0, 0, 512, 52366, 55, 12352, 21709, 8256, 8256, 80
actor_identity_descriptors_8F:
    actor_descriptor 0, 1, 0, 1024, 52366, 55, 12352, 21709, 8256, 8256, 80
actor_identity_descriptors_90:
    actor_descriptor 512, 1, 1, 1536, 7822, 58, 14878, 21709, 8256, 8256, 80
actor_identity_descriptors_91:
    actor_descriptor 523, 1, 1, 1542, 9358, 58, 14884, 21709, 8256, 8256, 80
actor_identity_descriptors_92:
    actor_descriptor 540, 1, 1, 1550, 10894, 58, 14890, 21709, 8256, 8256, 80
actor_identity_descriptors_93:
    actor_descriptor 554, 1, 1, 1558, 12430, 58, 14896, 21709, 8256, 8256, 0
actor_identity_descriptors_94:
    actor_descriptor 560, 1, 1, 1562, 13966, 58, 14902, 21709, 8256, 8256, 0
actor_identity_descriptors_95:
    actor_descriptor 569, 1, 1, 1566, 15502, 58, 14908, 21709, 8256, 8256, 0
actor_identity_descriptors_96:
    actor_descriptor 577, 1, 1, 1570, 17038, 58, 14914, 21709, 8256, 8256, 0
actor_identity_descriptors_97:
    actor_descriptor 583, 1, 1, 1574, 18574, 58, 14920, 21709, 8256, 8256, 0
actor_identity_descriptors_98:
    actor_descriptor 356, 7, 0, 2562, 64655, 58, 15100, 21709, 8256, 8256, 0
actor_identity_descriptors_99:
    actor_descriptor 597, 1, 0, 1636, 49295, 61, 15808, 21709, 8256, 8256, 0
actor_identity_descriptors_9A:
    actor_descriptor 632, 1, 0, 1650, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_9B:
    actor_descriptor 678, 1, 0, 1666, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_9C:
    actor_descriptor 632, 1, 0, 1686, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_9D:
    actor_descriptor 713, 1, 2, 1702, 53896, 61, 15826, 21709, 8256, 8256, 0
actor_identity_descriptors_9E:
    actor_descriptor 20, 4, 0, 2648, 42123, 62, 16036, 21709, 8256, 8256, 0
actor_identity_descriptors_9F:
    actor_descriptor 725, 1, 0, 1708, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_A0:
    actor_descriptor 755, 1, 0, 1732, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_A1:
    actor_descriptor 803, 1, 0, 1754, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_A2:
    actor_descriptor 838, 1, 2, 1774, 58511, 61, 15844, 21709, 8256, 8256, 0
actor_identity_descriptors_A3:
    actor_descriptor 847, 1, 0, 1778, 63119, 61, 15862, 21709, 8256, 8256, 0
actor_identity_descriptors_A4:
    actor_descriptor 863, 1, 0, 1786, 32911, 62, 16000, 21709, 8256, 8256, 0
actor_identity_descriptors_A5:
    actor_descriptor 912, 1, 0, 1812, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_A6:
    actor_descriptor 940, 1, 0, 1832, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_A7:
    actor_descriptor 972, 1, 0, 1848, 40079, 61, 15772, 21709, 8256, 8256, 0
actor_identity_descriptors_A8:
    actor_descriptor 0, 2, 0, 1878, 30863, 61, 15736, 21709, 8256, 8256, 0
actor_identity_descriptors_A9:
    actor_descriptor 47, 2, 0, 1906, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_AA:
    actor_descriptor 79, 2, 0, 1926, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_AB:
    actor_descriptor 79, 2, 0, 1926, 26255, 61, 15718, 21718, 8256, 8256, 0
actor_identity_descriptors_AC:
    actor_descriptor 144, 2, 0, 1946, 30863, 61, 15736, 21709, 8256, 8256, 0
actor_identity_descriptors_AD:
    actor_descriptor 184, 2, 0, 1974, 11407, 62, 15916, 21709, 8256, 8256, 0
actor_identity_descriptors_AE:
    actor_descriptor 218, 2, 0, 1994, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_AF:
    actor_descriptor 20, 4, 0, 2634, 42123, 62, 16036, 21709, 8256, 8256, 0
actor_identity_descriptors_B0:
    actor_descriptor 261, 2, 0, 2014, 35471, 61, 15754, 21709, 8256, 8256, 0
actor_identity_descriptors_B1:
    actor_descriptor 306, 2, 0, 2032, 44687, 61, 15790, 21709, 8256, 8256, 0
actor_identity_descriptors_B2:
    actor_descriptor 362, 2, 0, 2056, 30863, 61, 15736, 21709, 8256, 8256, 0
actor_identity_descriptors_B3:
    actor_descriptor 423, 2, 0, 2084, 35471, 61, 15754, 21709, 8256, 8256, 0
actor_identity_descriptors_B4:
    actor_descriptor 214, 7, 0, 2104, 16015, 62, 15934, 21709, 8256, 8256, 0
actor_identity_descriptors_B5:
    actor_descriptor 906, 2, 0, 2130, 29696, 62, 15988, 21709, 8256, 8256, 0
actor_identity_descriptors_B6:
    actor_descriptor 929, 2, 0, 2134, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_B7:
    actor_descriptor 929, 2, 0, 2154, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_B8:
    actor_descriptor 466, 2, 0, 2174, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_B9:
    actor_descriptor 36, 7, 0, 2194, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_BA:
    actor_descriptor 74, 7, 0, 2214, 20623, 62, 15952, 21709, 8256, 8256, 0
actor_identity_descriptors_BB:
    actor_descriptor 798, 2, 0, 2244, 21645, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_BC:
    actor_descriptor 98, 7, 0, 2228, 21645, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_BD:
    actor_descriptor 136, 7, 0, 2260, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_BE:
    actor_descriptor 178, 7, 2, 2670, 54784, 58, 15062, 21709, 8256, 8256, 0
actor_identity_descriptors_BF:
    actor_descriptor 978, 2, 0, 2280, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_C0:
    actor_descriptor 512, 2, 0, 2300, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_C1:
    actor_descriptor 552, 2, 0, 2320, 26255, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_C2:
    actor_descriptor 581, 2, 0, 2340, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_C3:
    actor_descriptor 610, 2, 0, 2356, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_C4:
    actor_descriptor 638, 2, 0, 2372, 37519, 62, 16018, 21709, 8256, 8256, 0
actor_identity_descriptors_C5:
    actor_descriptor 673, 2, 0, 2398, 35469, 61, 15754, 21709, 8256, 8256, 0
actor_identity_descriptors_C6:
    actor_descriptor 709, 2, 0, 2416, 21645, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_C7:
    actor_descriptor 753, 2, 0, 2432, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_C8:
    actor_descriptor 774, 2, 0, 2448, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_C9:
    actor_descriptor 798, 2, 0, 2464, 21645, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_CA:
    actor_descriptor 831, 2, 0, 2480, 21645, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_CB:
    actor_descriptor 859, 2, 0, 2496, 30861, 61, 15736, 21709, 8256, 8256, 0
actor_identity_descriptors_CC:
    actor_descriptor 409, 7, 0, 2526, 25088, 62, 15970, 21709, 8256, 8256, 0
actor_identity_descriptors_CD:
    actor_descriptor 906, 2, 0, 2530, 29839, 62, 15988, 21709, 8256, 8256, 0
actor_identity_descriptors_CE:
    actor_descriptor 918, 2, 2, 2534, 2191, 62, 15880, 21709, 8256, 8256, 0
actor_identity_descriptors_CF:
    actor_descriptor 1000, 1, 0, 2542, 6799, 62, 15898, 21709, 8256, 8256, 0
actor_identity_descriptors_D0:
    actor_descriptor 482, 7, 7, 2666, 39567, 58, 15002, 21709, 8256, 8256, 0
actor_identity_descriptors_D1:
    actor_descriptor 709, 2, 0, 2416, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_D2:
    actor_descriptor 19, 7, 3, 2628, 25600, 58, 14948, 21709, 8256, 8256, 0
actor_identity_descriptors_D3:
    actor_descriptor 7, 7, 2, 2614, 61573, 58, 15088, 21709, 8256, 8256, 0
actor_identity_descriptors_D4:
    actor_descriptor 431, 7, 0, 1594, 57344, 58, 15072, 21709, 8256, 8256, 0
actor_identity_descriptors_D5:
    actor_descriptor 431, 7, 3, 1610, 60416, 58, 15084, 21709, 8256, 8256, 0
actor_identity_descriptors_D6:
    actor_descriptor 431, 7, 3, 1610, 60928, 58, 15086, 21709, 8256, 8256, 0
actor_identity_descriptors_D7:
    actor_descriptor 755, 1, 2, 1750, 26112, 61, 15718, 21709, 8256, 8256, 0
actor_identity_descriptors_D8:
    actor_descriptor 899, 2, 3, 1580, 19968, 58, 14926, 21709, 8256, 8256, 0
actor_identity_descriptors_D9:
    actor_descriptor 431, 7, 3, 1588, 56320, 58, 15068, 21709, 8256, 8256, 0
actor_identity_descriptors_DA:
    actor_descriptor 431, 7, 3, 1588, 56832, 58, 15070, 21709, 8256, 8256, 0
actor_identity_descriptors_DB:
    actor_descriptor 0, 7, 0, 2588, 20992, 58, 14930, 21709, 8256, 8256, 0
actor_identity_descriptors_DC:
    actor_descriptor 431, 7, 3, 1588, 57344, 58, 15072, 21709, 8256, 8256, 0
actor_identity_descriptors_DD:
    actor_descriptor 431, 7, 3, 1594, 56320, 58, 15068, 21709, 8256, 8256, 0
actor_identity_descriptors_DE:
    actor_descriptor 431, 7, 3, 1594, 56832, 58, 15070, 21709, 8256, 8256, 0
actor_identity_descriptors_DF:
    actor_descriptor 423, 7, 0, 2604, 22528, 58, 14936, 21709, 8256, 8256, 0
actor_identity_descriptors_E0:
    actor_descriptor 284, 7, 0, 462, 65166, 56, 14272, 23558, 8256, 8256, 80
actor_identity_descriptors_E1:
    actor_descriptor 303, 7, 0, 974, 65166, 56, 14272, 23558, 8256, 8256, 80
actor_identity_descriptors_E2:
    actor_descriptor 329, 7, 0, 1486, 65166, 56, 14272, 23558, 8256, 8256, 80
actor_identity_descriptors_E3:
    actor_descriptor 709, 2, 0, 2416, 21647, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_E4:
    actor_descriptor 0, 0, 0, 0, 52238, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_E5:
    actor_descriptor 512, 0, 0, 512, 52238, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_E6:
    actor_descriptor 0, 1, 0, 1024, 52238, 55, 12352, 22762, 8256, 8256, 80
actor_identity_descriptors_E7:
    actor_descriptor 709, 2, 0, 2416, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_E8:
    actor_descriptor 709, 2, 0, 2416, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_E9:
    actor_descriptor 709, 2, 0, 2416, 21646, 61, 15700, 21709, 8256, 8256, 0
actor_identity_descriptors_EA:
    actor_descriptor 405, 3, 6, 1410, 58501, 90, 23268, 21745, 18718, 18718, 0
actor_identity_descriptors_EB:
    actor_descriptor 405, 3, 6, 2630, 58504, 90, 23268, 21709, 18718, 18718, 0
actor_identity_descriptors_EC:
    actor_descriptor 388, 7, 6, 2560, 39566, 58, 15002, 22762, 8256, 8256, 0
actor_identity_descriptors_ED:
    actor_descriptor 388, 7, 6, 2558, 39566, 58, 15002, 22762, 8256, 8256, 0
actor_identity_descriptors_EE:
    actor_descriptor 394, 7, 4, 2550, 47246, 58, 15032, 22762, 8256, 8256, 0
actor_identity_descriptors_EF:
    actor_descriptor 394, 7, 4, 2554, 47246, 58, 15032, 22762, 8256, 8256, 0
actor_identity_descriptors_F0:
    actor_descriptor 356, 7, 0, 2562, 2190, 59, 15112, 22762, 8256, 8256, 0
actor_identity_descriptors_F1:
    actor_descriptor 356, 7, 0, 2562, 2190, 59, 15112, 22762, 8256, 8256, 0
actor_identity_descriptors_F2:
    actor_descriptor 356, 7, 0, 2562, 2190, 59, 15112, 22762, 8256, 8256, 0
actor_identity_descriptors_F3:
    actor_descriptor 356, 7, 0, 2576, 13454, 60, 15412, 22762, 8256, 8256, 0
actor_identity_descriptors_F4:
    actor_descriptor 356, 7, 0, 2576, 13454, 60, 15412, 22762, 8256, 8256, 0
actor_identity_descriptors_F5:
    actor_descriptor 356, 7, 0, 2576, 13454, 60, 15412, 22762, 8256, 8256, 0
actor_identity_descriptors_F6:
    actor_descriptor 284, 7, 0, 462, 65166, 56, 11152, 22762, 1600, 1600, 80
actor_identity_descriptors_F7:
    actor_descriptor 303, 7, 0, 974, 65166, 56, 11152, 22762, 1600, 1600, 80
actor_identity_descriptors_F8:
    actor_descriptor 329, 7, 0, 1486, 65166, 56, 11152, 22762, 1600, 1600, 80
actor_identity_descriptors_F9:
    actor_descriptor 988, 4, 2, 1520, 5120, 91, 23316, 22622, 18828, 18828, 158
actor_identity_descriptors_FA:
    actor_descriptor 24, 5, 2, 1544, 6656, 91, 23322, 22642, 18828, 18828, 0
actor_identity_descriptors_FB:
    actor_descriptor 36, 5, 2, 1586, 8192, 91, 23328, 22662, 18828, 18828, 0
actor_identity_descriptors_FC:
    actor_descriptor 996, 3, 2, 1606, 9728, 91, 23334, 22682, 18828, 18828, 0
actor_identity_descriptors_FD:
    actor_descriptor 447, 4, 2, 1622, 11264, 91, 23340, 22702, 18828, 18828, 0
actor_identity_descriptors_FE:
    actor_descriptor 464, 4, 2, 1658, 12800, 91, 23346, 22722, 18828, 18828, 0
actor_identity_descriptors_FF:
    actor_descriptor 481, 4, 2, 1684, 14336, 91, 23352, 22742, 18828, 18828, 0
