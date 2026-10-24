; Native audio metadata; docs/audio-table-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3DF9
sample_01_payload_pointer:
    .faraddr $C34782
sample_02_payload_pointer:
    .faraddr $C34E68
sample_03_payload_pointer:
    .faraddr $C35344
sample_04_payload_pointer:
    .faraddr $C356B8
sample_05_payload_pointer:
    .faraddr $C3618E
sample_06_payload_pointer:
    .faraddr $C36EDA
sample_07_payload_pointer:
    .faraddr $C37C0B
sample_08_payload_pointer:
    .faraddr $C37DC6
sample_09_payload_pointer:
    .faraddr $C381D3
sample_0A_payload_pointer:
    .faraddr $C39195
sample_0B_payload_pointer:
    .faraddr $C3A0E2
sample_0C_payload_pointer:
    .faraddr $C3BA8E
sample_0D_payload_pointer:
    .faraddr $C3CA3E
sample_0E_payload_pointer:
    .faraddr $C3CC9B
sample_0F_payload_pointer:
    .faraddr $C3CF88
sample_10_payload_pointer:
    .faraddr $C3E38B
sample_11_payload_pointer:
    .faraddr $C3F33B
sample_12_payload_pointer:
    .faraddr $C3F4B7
sample_13_payload_pointer:
    .faraddr $C3FBCA
sample_14_payload_pointer:
    .faraddr $C41606
sample_15_payload_pointer:
    .faraddr $C41EA5
sample_16_payload_pointer:
    .faraddr $C4230C
sample_17_payload_pointer:
    .faraddr $C43907
sample_18_payload_pointer:
    .faraddr $C43F9C
sample_19_payload_pointer:
    .faraddr $C447F3
sample_1A_payload_pointer:
    .faraddr $C45989
sample_1B_payload_pointer:
    .faraddr $C46255
sample_1C_payload_pointer:
    .faraddr $C46CE3
sample_1D_payload_pointer:
    .faraddr $C48E15
sample_1E_payload_pointer:
    .faraddr $C4954C
sample_1F_payload_pointer:
    .faraddr $C49FDA
sample_20_payload_pointer:
    .faraddr $C4B059
sample_21_payload_pointer:
    .faraddr $C4BB89
sample_01_loop_offset:
    .word 1602
sample_02_loop_offset:
    .word 1026
sample_03_loop_offset:
    .word 846
sample_04_loop_offset:
    .word 2727
sample_05_loop_offset:
    .word 27
sample_06_loop_offset:
    .word 3375
sample_07_loop_offset:
    .word 315
sample_08_loop_offset:
    .word 927
sample_09_loop_offset:
    .word 864
sample_0A_loop_offset:
    .word 1998
sample_0B_loop_offset:
    .word 6570
sample_0C_loop_offset:
    .word 2628
sample_0D_loop_offset:
    .word 423
sample_0E_loop_offset:
    .word 729
sample_0F_loop_offset:
    .word 2556
sample_10_loop_offset:
    .word 2934
sample_11_loop_offset:
    .word 360
sample_12_loop_offset:
    .word 1323
sample_13_loop_offset:
    .word 828
sample_14_loop_offset:
    .word 2043
sample_15_loop_offset:
    .word 1125
sample_16_loop_offset:
    .word 5625
sample_17_loop_offset:
    .word 1683
sample_18_loop_offset:
    .word 2133
sample_19_loop_offset:
    .word 4500
sample_1A_loop_offset:
    .word 2250
sample_1B_loop_offset:
    .word 2700
sample_1C_loop_offset:
    .word 810
sample_1D_loop_offset:
    .word 1764
sample_1E_loop_offset:
    .word 2700
sample_1F_loop_offset:
    .word 16875
sample_20_loop_offset:
    .word 2862
sample_21_loop_offset:
    .word 3744
sample_01_tuning_word:
    .word 24828
sample_02_tuning_word:
    .word 24744
sample_03_tuning_word:
    .word 16608
sample_04_tuning_word:
    .word 8332
sample_05_tuning_word:
    .word 226
sample_06_tuning_word:
    .word 208
sample_07_tuning_word:
    .word 242
sample_08_tuning_word:
    .word 24744
sample_09_tuning_word:
    .word 28863
sample_0A_tuning_word:
    .word 49365
sample_0B_tuning_word:
    .word 0
sample_0C_tuning_word:
    .word 57597
sample_0D_tuning_word:
    .word 24800
sample_0E_tuning_word:
    .word 28896
sample_0F_tuning_word:
    .word 49366
sample_10_tuning_word:
    .word 57513
sample_11_tuning_word:
    .word 24800
sample_12_tuning_word:
    .word 24828
sample_13_tuning_word:
    .word 41149
sample_14_tuning_word:
    .word 28924
sample_15_tuning_word:
    .word 65535
sample_16_tuning_word:
    .word 0
sample_17_tuning_word:
    .word 65407
sample_18_tuning_word:
    .word 37
sample_19_tuning_word:
    .word 160
sample_1A_tuning_word:
    .word 12440
sample_1B_tuning_word:
    .word 0
sample_1C_tuning_word:
    .word 65407
sample_1D_tuning_word:
    .word 24828
sample_1E_tuning_word:
    .word 12440
sample_1F_tuning_word:
    .word 0
sample_20_tuning_word:
    .word 192
sample_21_tuning_word:
    .word 0
.macro sample_adsr attack, decay, enabled, sustain_rate, sustain_level
    .byte attack | (decay << 4) | (enabled << 7)
    .byte sustain_rate | (sustain_level << 5)
.endmacro
sample_01_adsr:
    sample_adsr 15, 7, 1, 15, 7
sample_02_adsr:
    sample_adsr 15, 7, 1, 12, 7
sample_03_adsr:
    sample_adsr 15, 7, 1, 14, 7
sample_04_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_05_adsr:
    sample_adsr 14, 7, 1, 0, 7
sample_06_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_07_adsr:
    sample_adsr 15, 7, 1, 13, 4
sample_08_adsr:
    sample_adsr 15, 7, 1, 14, 7
sample_09_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_0A_adsr:
    sample_adsr 15, 7, 1, 16, 7
sample_0B_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_0C_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_0D_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_0E_adsr:
    sample_adsr 15, 7, 1, 12, 7
sample_0F_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_10_adsr:
    sample_adsr 15, 7, 1, 12, 7
sample_11_adsr:
    sample_adsr 15, 4, 1, 12, 3
sample_12_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_13_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_14_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_15_adsr:
    sample_adsr 15, 4, 1, 0, 0
sample_16_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_17_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_18_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_19_adsr:
    sample_adsr 15, 6, 1, 16, 6
sample_1A_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_1B_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_1C_adsr:
    sample_adsr 15, 7, 1, 14, 7
sample_1D_adsr:
    sample_adsr 15, 7, 1, 20, 7
sample_1E_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_1F_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_20_adsr:
    sample_adsr 15, 7, 1, 0, 7
sample_21_adsr:
    sample_adsr 15, 7, 1, 12, 7
song_00_sample_requirements:
    .word 19, 29, 9, 12, 24, 25, 27, 8, 18, 28, 0, 0, 0, 0, 0, 0
song_01_sample_requirements:
    .word 24, 25, 21, 22, 19, 16, 12, 2, 18, 9, 29, 0, 0, 0, 0, 0
song_02_sample_requirements:
    .word 19, 9, 12, 16, 6, 28, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_03_sample_requirements:
    .word 16, 5, 29, 12, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_04_sample_requirements:
    .word 19, 4, 9, 11, 24, 25, 3, 2, 10, 13, 20, 0, 0, 0, 0, 0
song_05_sample_requirements:
    .word 16, 29, 20, 12, 24, 25, 27, 8, 18, 21, 22, 15, 30, 0, 0, 0
song_06_sample_requirements:
    .word 19, 16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_07_sample_requirements:
    .word 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_08_sample_requirements:
    .word 19, 16, 8, 12, 3, 17, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_09_sample_requirements:
    .word 19, 29, 26, 12, 24, 23, 27, 13, 18, 15, 21, 22, 0, 0, 0, 0
song_0A_sample_requirements:
    .word 19, 18, 9, 12, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_0B_sample_requirements:
    .word 19, 16, 9, 12, 7, 14, 18, 31, 0, 0, 0, 0, 0, 0, 0, 0
song_0C_sample_requirements:
    .word 25, 28, 30, 23, 5, 33, 4, 7, 32, 19, 0, 0, 0, 0, 0, 0
song_0D_sample_requirements:
    .word 24, 21, 19, 12, 3, 14, 8, 18, 1, 5, 0, 0, 0, 0, 0, 0
song_0E_sample_requirements:
    .word 1, 12, 5, 19, 3, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_0F_sample_requirements:
    .word 19, 3, 9, 12, 14, 5, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_10_sample_requirements:
    .word 24, 25, 22, 1, 5, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_11_sample_requirements:
    .word 24, 25, 9, 12, 19, 16, 3, 29, 18, 0, 0, 0, 0, 0, 0, 0
song_12_sample_requirements:
    .word 16, 12, 9, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_13_sample_requirements:
    .word 24, 25, 8, 2, 12, 19, 29, 16, 14, 0, 0, 0, 0, 0, 0, 0
song_14_sample_requirements:
    .word 19, 5, 9, 12, 24, 30, 27, 8, 2, 28, 7, 13, 14, 0, 0, 0
song_15_sample_requirements:
    .word 19, 5, 9, 12, 24, 25, 14, 8, 3, 0, 0, 0, 0, 0, 0, 0
song_16_sample_requirements:
    .word 24, 25, 27, 26, 20, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_17_sample_requirements:
    .word 24, 6, 28, 12, 4, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_18_sample_requirements:
    .word 28, 12, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_19_sample_requirements:
    .word 11, 27, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_1A_sample_requirements:
    .word 5, 12, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_1B_sample_requirements:
    .word 5, 33, 12, 7, 5, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_1C_sample_requirements:
    .word 24, 25, 27, 8, 3, 29, 18, 12, 0, 0, 0, 0, 0, 0, 0, 0
song_1D_sample_requirements:
    .word 16, 5, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_1E_sample_requirements:
    .word 28, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_1F_sample_requirements:
    .word 26, 27, 18, 13, 29, 12, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_20_sample_requirements:
    .word 24, 25, 21, 22, 29, 9, 18, 16, 15, 0, 0, 0, 0, 0, 0, 0
song_21_sample_requirements:
    .word 4, 19, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_22_sample_requirements:
    .word 12, 13, 29, 6, 27, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_23_sample_requirements:
    .word 4, 19, 9, 6, 28, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_24_sample_requirements:
    .word 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_25_sample_requirements:
    .word 19, 4, 9, 12, 6, 7, 28, 5, 0, 0, 0, 0, 0, 0, 0, 0
song_26_sample_requirements:
    .word 24, 25, 21, 22, 2, 8, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_27_sample_requirements:
    .word 14, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_28_sample_requirements:
    .word 28, 14, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_29_sample_requirements:
    .word 18, 17, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2A_sample_requirements:
    .word 24, 25, 21, 22, 19, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2B_sample_requirements:
    .word 10, 3, 19, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2C_sample_requirements:
    .word 19, 5, 9, 12, 16, 28, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2D_sample_requirements:
    .word 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2E_sample_requirements:
    .word 5, 19, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_2F_sample_requirements:
    .word 5, 19, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_30_sample_requirements:
    .word 5, 19, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_31_sample_requirements:
    .word 24, 25, 21, 22, 8, 19, 5, 16, 29, 13, 12, 0, 0, 0, 0, 0
song_32_sample_requirements:
    .word 19, 4, 9, 12, 24, 25, 14, 8, 2, 22, 21, 3, 0, 0, 0, 0
song_33_sample_requirements:
    .word 32, 33, 31, 27, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_34_sample_requirements:
    .word 3, 19, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_35_sample_requirements:
    .word 3, 5, 12, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_36_sample_requirements:
    .word 19, 29, 9, 12, 6, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_37_sample_requirements:
    .word 19, 5, 2, 12, 10, 7, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_38_sample_requirements:
    .word 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
song_39_sample_requirements:
    .word 24, 25, 21, 28, 2, 8, 5, 4, 19, 12, 0, 0, 0, 0, 0, 0
song_3A_sample_requirements:
    .word 19, 17, 12, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
