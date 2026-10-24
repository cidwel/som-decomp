; Cumulative XP thresholds for internal levels0..98; legacy JSON key exp_to_next.
.setcpu "65816"
.segment "CODE"
.org $4B58
.macro cumulative_xp threshold
    .byte (threshold & $FF), ((threshold >> 8) & $FF), ((threshold >> 16) & $FF)
.endmacro
hero_cumulative_experience_thresholds:
hero_level_01_xp_threshold:
    cumulative_xp 16
hero_level_02_xp_threshold:
    cumulative_xp 47
hero_level_03_xp_threshold:
    cumulative_xp 105
hero_level_04_xp_threshold:
    cumulative_xp 204
hero_level_05_xp_threshold:
    cumulative_xp 363
hero_level_06_xp_threshold:
    cumulative_xp 602
hero_level_07_xp_threshold:
    cumulative_xp 945
hero_level_08_xp_threshold:
    cumulative_xp 1418
hero_level_09_xp_threshold:
    cumulative_xp 2049
hero_level_10_xp_threshold:
    cumulative_xp 2870
hero_level_11_xp_threshold:
    cumulative_xp 3914
hero_level_12_xp_threshold:
    cumulative_xp 5218
hero_level_13_xp_threshold:
    cumulative_xp 6819
hero_level_14_xp_threshold:
    cumulative_xp 8759
hero_level_15_xp_threshold:
    cumulative_xp 11080
hero_level_16_xp_threshold:
    cumulative_xp 13827
hero_level_17_xp_threshold:
    cumulative_xp 17049
hero_level_18_xp_threshold:
    cumulative_xp 20794
hero_level_19_xp_threshold:
    cumulative_xp 25115
hero_level_20_xp_threshold:
    cumulative_xp 30065
hero_level_21_xp_threshold:
    cumulative_xp 35701
hero_level_22_xp_threshold:
    cumulative_xp 42081
hero_level_23_xp_threshold:
    cumulative_xp 49265
hero_level_24_xp_threshold:
    cumulative_xp 57316
hero_level_25_xp_threshold:
    cumulative_xp 66298
hero_level_26_xp_threshold:
    cumulative_xp 76278
hero_level_27_xp_threshold:
    cumulative_xp 87324
hero_level_28_xp_threshold:
    cumulative_xp 99507
hero_level_29_xp_threshold:
    cumulative_xp 112899
hero_level_30_xp_threshold:
    cumulative_xp 127575
hero_level_31_xp_threshold:
    cumulative_xp 143611
hero_level_32_xp_threshold:
    cumulative_xp 161086
hero_level_33_xp_threshold:
    cumulative_xp 180080
hero_level_34_xp_threshold:
    cumulative_xp 200675
hero_level_35_xp_threshold:
    cumulative_xp 222956
hero_level_36_xp_threshold:
    cumulative_xp 247009
hero_level_37_xp_threshold:
    cumulative_xp 272921
hero_level_38_xp_threshold:
    cumulative_xp 300783
hero_level_39_xp_threshold:
    cumulative_xp 330686
hero_level_40_xp_threshold:
    cumulative_xp 362724
hero_level_41_xp_threshold:
    cumulative_xp 396992
hero_level_42_xp_threshold:
    cumulative_xp 433588
hero_level_43_xp_threshold:
    cumulative_xp 472611
hero_level_44_xp_threshold:
    cumulative_xp 514162
hero_level_45_xp_threshold:
    cumulative_xp 558343
hero_level_46_xp_threshold:
    cumulative_xp 605260
hero_level_47_xp_threshold:
    cumulative_xp 655018
hero_level_48_xp_threshold:
    cumulative_xp 707726
hero_level_49_xp_threshold:
    cumulative_xp 763494
hero_level_50_xp_threshold:
    cumulative_xp 822433
hero_level_51_xp_threshold:
    cumulative_xp 884658
hero_level_52_xp_threshold:
    cumulative_xp 950283
hero_level_53_xp_threshold:
    cumulative_xp 1019425
hero_level_54_xp_threshold:
    cumulative_xp 1092204
hero_level_55_xp_threshold:
    cumulative_xp 1168739
hero_level_56_xp_threshold:
    cumulative_xp 1249153
hero_level_57_xp_threshold:
    cumulative_xp 1333570
hero_level_58_xp_threshold:
    cumulative_xp 1422116
hero_level_59_xp_threshold:
    cumulative_xp 1514918
hero_level_60_xp_threshold:
    cumulative_xp 1612106
hero_level_61_xp_threshold:
    cumulative_xp 1713810
hero_level_62_xp_threshold:
    cumulative_xp 1820163
hero_level_63_xp_threshold:
    cumulative_xp 1931299
hero_level_64_xp_threshold:
    cumulative_xp 2047354
hero_level_65_xp_threshold:
    cumulative_xp 2168465
hero_level_66_xp_threshold:
    cumulative_xp 2294772
hero_level_67_xp_threshold:
    cumulative_xp 2426416
hero_level_68_xp_threshold:
    cumulative_xp 2563540
hero_level_69_xp_threshold:
    cumulative_xp 2706287
hero_level_70_xp_threshold:
    cumulative_xp 2854804
hero_level_71_xp_threshold:
    cumulative_xp 3009239
hero_level_72_xp_threshold:
    cumulative_xp 3169740
hero_level_73_xp_threshold:
    cumulative_xp 3336459
hero_level_74_xp_threshold:
    cumulative_xp 3509548
hero_level_75_xp_threshold:
    cumulative_xp 3689162
hero_level_76_xp_threshold:
    cumulative_xp 3875456
hero_level_77_xp_threshold:
    cumulative_xp 4068587
hero_level_78_xp_threshold:
    cumulative_xp 4268715
hero_level_79_xp_threshold:
    cumulative_xp 4476000
hero_level_80_xp_threshold:
    cumulative_xp 4690605
hero_level_81_xp_threshold:
    cumulative_xp 4912693
hero_level_82_xp_threshold:
    cumulative_xp 5142430
hero_level_83_xp_threshold:
    cumulative_xp 5379983
hero_level_84_xp_threshold:
    cumulative_xp 5625521
hero_level_85_xp_threshold:
    cumulative_xp 5879214
hero_level_86_xp_threshold:
    cumulative_xp 6141234
hero_level_87_xp_threshold:
    cumulative_xp 6411754
hero_level_88_xp_threshold:
    cumulative_xp 6690950
hero_level_89_xp_threshold:
    cumulative_xp 6978998
hero_level_90_xp_threshold:
    cumulative_xp 7276076
hero_level_91_xp_threshold:
    cumulative_xp 7582364
hero_level_92_xp_threshold:
    cumulative_xp 7898043
hero_level_93_xp_threshold:
    cumulative_xp 8223296
hero_level_94_xp_threshold:
    cumulative_xp 8558308
hero_level_95_xp_threshold:
    cumulative_xp 8903264
hero_level_96_xp_threshold:
    cumulative_xp 9258352
hero_level_97_xp_threshold:
    cumulative_xp 9623761
hero_level_98_xp_threshold:
    cumulative_xp 9999682
hero_level_99_xp_threshold:
    cumulative_xp 9999999
