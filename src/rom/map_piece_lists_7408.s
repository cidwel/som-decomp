; Bounded native map piece lists; docs/map-piece-list-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7408
.macro map_piece flag_index, flag_min, flag_max, piece_id, tile_x, tile_y
    .byte flag_index, (flag_min << 4) | flag_max, piece_id & $FF
    .byte (tile_x << 1) | ((piece_id >> 8) & 1)
    .byte (tile_y << 1) | ((piece_id >> 9) & 1)
.endmacro
map_0F4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 840, 0, 0
    map_piece 0, 0, 15, 681, 16, 31
    map_piece 0, 0, 15, 681, 16, 48
    map_piece 0, 0, 15, 839, 62, 58
    map_piece 0, 0, 15, 839, 70, 58
    map_piece 0, 0, 15, 839, 62, 40
    map_piece 0, 0, 15, 839, 70, 40
    map_piece 0, 0, 15, 839, 70, 23
    map_piece 0, 0, 15, 839, 62, 23
    map_piece 0, 0, 15, 839, 72, 7
    map_piece 0, 0, 15, 839, 66, 5
    map_piece 0, 0, 15, 839, 60, 7
    map_piece 0, 0, 15, 839, 57, 7
    map_piece 0, 0, 15, 839, 51, 5
    map_piece 0, 0, 15, 839, 37, 5
    map_piece 0, 0, 15, 839, 28, 6
    map_piece 0, 0, 15, 839, 25, 6
    map_piece 0, 0, 15, 839, 21, 5
    map_piece 0, 0, 15, 839, 17, 6
    map_piece 0, 0, 15, 839, 43, 22
    map_piece 0, 0, 15, 839, 45, 22
    map_piece 0, 0, 15, 839, 47, 43
    map_piece 0, 0, 15, 839, 55, 43
    map_piece 0, 0, 15, 839, 47, 62
    map_piece 0, 0, 15, 839, 55, 62
    map_piece 0, 0, 15, 839, 39, 65
    map_piece 0, 0, 15, 839, 33, 65
    map_piece 0, 0, 15, 839, 27, 65
    map_piece 0, 0, 15, 839, 20, 83
    map_piece 0, 0, 15, 839, 16, 83
    map_piece 0, 0, 15, 839, 14, 83
    map_piece 0, 0, 15, 839, 8, 83
    map_piece 0, 0, 15, 839, 9, 29
    map_piece 0, 0, 15, 839, 12, 27
    map_piece 0, 0, 15, 839, 16, 25
    map_piece 0, 0, 15, 839, 20, 27
    map_piece 0, 0, 15, 839, 23, 29
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0F5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 879, 0, 0
    map_piece 78, 6, 6, 681, 17, 30
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0F6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 879, 0, 0
    map_piece 78, 6, 6, 681, 17, 30
map_0F8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 840, 0, 0
    map_piece 0, 0, 15, 839, 62, 58
    map_piece 0, 0, 15, 839, 70, 58
    map_piece 0, 0, 15, 839, 62, 40
    map_piece 0, 0, 15, 839, 70, 40
    map_piece 0, 0, 15, 839, 70, 23
    map_piece 0, 0, 15, 839, 62, 23
    map_piece 0, 0, 15, 839, 72, 7
    map_piece 0, 0, 15, 839, 66, 5
    map_piece 0, 0, 15, 839, 60, 7
    map_piece 0, 0, 15, 839, 57, 7
    map_piece 0, 0, 15, 839, 51, 5
    map_piece 0, 0, 15, 839, 37, 5
    map_piece 0, 0, 15, 839, 28, 6
    map_piece 0, 0, 15, 839, 25, 6
    map_piece 0, 0, 15, 839, 21, 5
    map_piece 0, 0, 15, 839, 17, 6
    map_piece 0, 0, 15, 839, 43, 22
    map_piece 0, 0, 15, 839, 45, 22
    map_piece 0, 0, 15, 839, 47, 43
    map_piece 0, 0, 15, 839, 55, 43
    map_piece 0, 0, 15, 839, 47, 62
    map_piece 0, 0, 15, 839, 55, 62
    map_piece 0, 0, 15, 839, 39, 65
    map_piece 0, 0, 15, 839, 33, 65
    map_piece 0, 0, 15, 839, 27, 65
    map_piece 0, 0, 15, 839, 20, 83
    map_piece 0, 0, 15, 839, 16, 83
    map_piece 0, 0, 15, 839, 14, 83
    map_piece 0, 0, 15, 839, 8, 83
    map_piece 0, 0, 15, 839, 9, 29
    map_piece 0, 0, 15, 839, 12, 27
    map_piece 0, 0, 15, 839, 16, 25
    map_piece 0, 0, 15, 839, 20, 27
    map_piece 0, 0, 15, 839, 23, 29
    map_piece 79, 1, 15, 681, 66, 69
    map_piece 79, 1, 15, 844, 66, 67
    map_piece 79, 2, 15, 844, 66, 65
    map_piece 79, 3, 15, 681, 66, 14
    map_piece 79, 3, 15, 845, 68, 14
    map_piece 79, 4, 15, 845, 70, 14
    map_piece 79, 5, 15, 681, 72, 17
    map_piece 79, 5, 15, 845, 64, 14
    map_piece 79, 6, 15, 681, 51, 68
    map_piece 79, 6, 15, 845, 49, 68
    map_piece 79, 6, 15, 845, 53, 68
    map_piece 79, 7, 15, 681, 55, 68
    map_piece 79, 7, 15, 844, 47, 70
    map_piece 79, 8, 15, 681, 39, 72
    map_piece 79, 8, 15, 845, 34, 72
    map_piece 79, 9, 15, 845, 32, 72
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0F9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 841, 0, 0
    map_piece 0, 0, 15, 839, 14, 76
    map_piece 0, 0, 15, 839, 16, 76
    map_piece 0, 0, 15, 839, 27, 60
    map_piece 0, 0, 15, 839, 29, 60
    map_piece 0, 0, 15, 839, 9, 44
    map_piece 0, 0, 15, 839, 17, 44
    map_piece 0, 0, 15, 839, 21, 44
    map_piece 0, 0, 15, 839, 7, 27
    map_piece 0, 0, 15, 839, 9, 27
    map_piece 0, 0, 15, 839, 17, 27
    map_piece 0, 0, 15, 839, 19, 27
    map_piece 0, 0, 15, 839, 38, 6
    map_piece 0, 0, 15, 839, 33, 5
    map_piece 0, 0, 15, 839, 28, 6
    map_piece 0, 0, 15, 839, 25, 8
    map_piece 0, 0, 15, 839, 21, 6
    map_piece 0, 0, 15, 839, 17, 5
    map_piece 0, 0, 15, 839, 13, 6
    map_piece 0, 0, 15, 839, 9, 5
    map_piece 0, 0, 15, 839, 38, 27
    map_piece 0, 0, 15, 839, 41, 28
    map_piece 0, 0, 15, 839, 44, 27
    map_piece 0, 0, 15, 839, 43, 6
    map_piece 0, 0, 15, 839, 45, 6
    map_piece 0, 0, 15, 839, 49, 5
    map_piece 0, 0, 15, 839, 53, 6
    map_piece 0, 0, 15, 839, 55, 6
    map_piece 0, 0, 15, 839, 57, 6
    map_piece 0, 0, 15, 839, 59, 6
    map_piece 0, 0, 15, 839, 63, 5
    map_piece 0, 0, 15, 839, 67, 6
    map_piece 0, 0, 15, 839, 58, 71
    map_piece 0, 0, 15, 839, 67, 71
    map_piece 0, 0, 15, 839, 47, 53
    map_piece 0, 0, 15, 839, 55, 56
    map_piece 0, 0, 15, 839, 63, 53
    map_piece 79, 10, 15, 681, 64, 30
    map_piece 79, 10, 15, 844, 64, 32
    map_piece 79, 11, 15, 844, 64, 34
    map_piece 79, 12, 15, 844, 64, 36
    map_piece 79, 13, 15, 844, 64, 38
    map_piece 79, 14, 15, 844, 64, 40
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0FA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 752, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0FB_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 835, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 836, 0, 0
map_0FD_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 753, 0, 0
map_0FF_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 843, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 881, 0, 0
    map_piece 0, 0, 15, 880, 72, 40
    map_piece 0, 0, 15, 880, 37, 48
    map_piece 0, 0, 15, 880, 55, 16
    map_piece 0, 0, 15, 880, 8, 9
    map_piece 0, 0, 15, 880, 0, 44
    map_piece 0, 0, 15, 880, 68, 4
map_100_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 2, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 2, 0, 0
    map_piece 0, 0, 15, 3, 3, 0
    map_piece 0, 0, 15, 3, 6, 0
    map_piece 0, 0, 15, 3, 8, 0
    map_piece 0, 0, 15, 3, 10, 0
    map_piece 0, 0, 15, 3, 12, 0
    map_piece 0, 0, 15, 3, 3, 4
    map_piece 0, 0, 15, 3, 6, 4
    map_piece 0, 0, 15, 3, 8, 4
    map_piece 0, 0, 15, 3, 10, 4
    map_piece 0, 0, 15, 3, 12, 4
    map_piece 0, 0, 15, 3, 3, 8
    map_piece 0, 0, 15, 3, 6, 8
    map_piece 0, 0, 15, 3, 8, 8
    map_piece 0, 0, 15, 3, 10, 8
    map_piece 0, 0, 15, 3, 12, 8
    map_piece 0, 0, 15, 3, 3, 12
    map_piece 0, 0, 15, 3, 6, 12
    map_piece 0, 0, 15, 3, 8, 12
    map_piece 0, 0, 15, 3, 10, 12
    map_piece 0, 0, 15, 3, 12, 12
    map_piece 0, 0, 15, 3, 3, 16
    map_piece 0, 0, 15, 3, 6, 16
    map_piece 0, 0, 15, 3, 8, 16
    map_piece 0, 0, 15, 3, 10, 16
    map_piece 0, 0, 15, 3, 12, 16
map_101_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 16, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 17, 0, 0
map_102_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 16, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 17, 0, 0
map_103_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_104_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 20, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 21, 0, 0
map_105_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 58, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 59, 0, 0
map_106_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_107_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 56, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 57, 0, 0
map_108_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 64, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 65, 0, 0
map_109_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 62, 0, 0
    map_piece 19, 2, 15, 72, 32, 12
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 63, 0, 0
map_10A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 68, 0, 0
    map_piece 0, 0, 15, 70, 2, 3
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 69, 0, 0
    map_piece 0, 0, 15, 71, 2, 3
map_10B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 66, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 67, 0, 0
map_10C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 251, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 252, 0, 0
map_10D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 253, 0, 0
    map_piece 0, 0, 15, 235, 15, 6
    map_piece 0, 0, 15, 234, 37, 7
    map_piece 0, 0, 15, 234, 43, 7
    map_piece 0, 0, 15, 234, 11, 12
    map_piece 0, 0, 15, 135, 40, 7
    map_piece 0, 0, 15, 135, 7, 7
    map_piece 0, 0, 15, 238, 40, 13
    map_piece 0, 0, 15, 238, 7, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 254, 0, 0
map_10E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 486, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 487, 0, 0
map_10F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 488, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 489, 0, 0
map_111_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_112_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 508, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 509, 0, 0
map_113_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 46, 0, 0
    map_piece 0, 0, 15, 44, 10, 7
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 47, 0, 0
    map_piece 0, 0, 15, 45, 10, 7
map_114_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_115_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 50, 0, 0
    map_piece 169, 1, 15, 48, 22, 5
    map_piece 169, 1, 15, 242, 14, 18
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 51, 0, 0
map_116_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 52, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 53, 0, 0
map_117_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_118_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 79, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 80, 0, 0
map_119_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_11A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 367, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 368, 0, 0
map_11B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 62, 0, 0
    map_piece 19, 2, 15, 72, 32, 12
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 63, 0, 0
map_11C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 82, 0, 0
    map_piece 20, 6, 15, 81, 42, 62
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 83, 0, 0
map_11D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 84, 0, 0
    map_piece 96, 1, 15, 89, 20, 44
    map_piece 96, 1, 15, 86, 13, 51
    map_piece 0, 0, 15, 88, 8, 64
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 85, 0, 0
    map_piece 96, 1, 15, 140, 14, 4
    map_piece 96, 1, 15, 90, 19, 39
    map_piece 96, 1, 15, 87, 13, 51
map_11E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 94, 0, 0
    map_piece 96, 2, 2, 91, 44, 32
    map_piece 96, 3, 3, 92, 44, 32
    map_piece 96, 4, 15, 93, 44, 32
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 95, 0, 0
    map_piece 96, 2, 15, 140, 45, 28
map_11F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 102, 0, 0
    map_piece 20, 0, 5, 88, 0, 21
    map_piece 20, 6, 15, 88, 23, 21
    map_piece 96, 4, 15, 96, 23, 62
    map_piece 27, 1, 5, 203, 21, 34
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 103, 0, 0
map_120_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 104, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_121_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 46, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 47, 0, 0
map_122_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 102, 0, 0
    map_piece 0, 0, 15, 106, 14, 32
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 103, 0, 0
map_123_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 124, 0, 0
    map_piece 24, 2, 15, 122, 6, 8
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 125, 0, 0
    map_piece 24, 2, 15, 123, 6, 8
map_124_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 108, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 109, 0, 0
map_125_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 110, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 111, 0, 0
map_126_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 112, 0, 0
    map_piece 20, 7, 15, 99, 19, 10
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 113, 0, 0
map_127_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 121, 0, 0
    map_piece 0, 0, 15, 88, 9, 7
    map_piece 0, 0, 15, 88, 24, 6
    map_piece 0, 0, 15, 242, 18, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 121, 0, 0
    map_piece 0, 0, 15, 88, 9, 7
    map_piece 0, 0, 15, 88, 24, 6
    map_piece 0, 0, 15, 242, 18, 31
map_128_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 116, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 117, 0, 0
map_129_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 119, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 120, 0, 0
map_12A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 431, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 432, 0, 0
map_12B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_12C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 167, 0, 0
    map_piece 23, 0, 0, 169, 8, 15
    map_piece 23, 0, 0, 169, 9, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 168, 0, 0
    map_piece 23, 0, 0, 170, 8, 15
    map_piece 23, 0, 0, 170, 9, 15
map_12D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 171, 0, 0
    map_piece 0, 0, 15, 243, 9, 13
    map_piece 0, 0, 15, 413, 12, 12
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 172, 0, 0
    map_piece 0, 0, 15, 414, 12, 12
map_12E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 177, 0, 0
    map_piece 164, 0, 0, 169, 7, 7
    map_piece 165, 0, 0, 169, 22, 7
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 178, 0, 0
    map_piece 164, 0, 0, 170, 7, 7
    map_piece 165, 0, 0, 170, 22, 7
map_12F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 181, 0, 0
    map_piece 83, 1, 15, 183, 6, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 182, 0, 0
map_130_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 186, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 187, 0, 0
map_131_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 188, 0, 0
    map_piece 83, 0, 1, 190, 15, 15
    map_piece 83, 2, 2, 191, 15, 15
    map_piece 83, 3, 3, 192, 15, 15
    map_piece 83, 4, 6, 193, 15, 15
    map_piece 83, 5, 5, 194, 15, 17
    map_piece 83, 6, 6, 195, 15, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 189, 0, 0
map_132_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 196, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 197, 0, 0
map_133_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 329, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 330, 0, 0
map_134_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 184, 0, 0
    map_piece 23, 0, 1, 169, 12, 20
    map_piece 23, 0, 1, 169, 14, 20
    map_piece 23, 0, 1, 169, 20, 20
    map_piece 23, 0, 1, 169, 22, 20
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 185, 0, 0
    map_piece 23, 0, 1, 170, 12, 20
    map_piece 23, 0, 1, 170, 14, 20
    map_piece 23, 0, 1, 170, 20, 20
    map_piece 23, 0, 1, 170, 22, 20
map_135_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 201, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 202, 0, 0
    map_piece 83, 8, 8, 198, 11, 8
    map_piece 83, 9, 9, 199, 11, 8
    map_piece 83, 10, 10, 200, 11, 8
map_136_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 201, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 202, 0, 0
    map_piece 0, 0, 15, 200, 11, 8
map_137_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 141, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 142, 0, 0
map_138_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 126, 0, 0
    map_piece 0, 0, 15, 235, 12, 35
    map_piece 0, 0, 15, 235, 16, 29
    map_piece 0, 0, 15, 235, 30, 29
    map_piece 0, 0, 15, 235, 34, 35
    map_piece 0, 0, 15, 235, 34, 21
    map_piece 0, 0, 15, 235, 40, 10
    map_piece 0, 0, 15, 235, 36, 8
    map_piece 0, 0, 15, 235, 32, 8
    map_piece 0, 0, 15, 235, 14, 8
    map_piece 0, 0, 15, 235, 10, 8
    map_piece 0, 0, 15, 235, 6, 10
    map_piece 0, 0, 15, 234, 14, 32
    map_piece 0, 0, 15, 234, 18, 26
    map_piece 0, 0, 15, 234, 20, 24
    map_piece 0, 0, 15, 234, 26, 24
    map_piece 0, 0, 15, 234, 28, 26
    map_piece 0, 0, 15, 234, 32, 32
    map_piece 0, 0, 15, 234, 34, 7
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 248, 8, 22
    map_piece 0, 0, 15, 248, 23, 24
    map_piece 0, 0, 15, 248, 39, 22
    map_piece 0, 0, 15, 238, 17, 37
    map_piece 0, 0, 15, 238, 20, 39
    map_piece 0, 0, 15, 238, 17, 33
    map_piece 0, 0, 15, 238, 29, 33
    map_piece 0, 0, 15, 238, 29, 37
    map_piece 0, 0, 15, 238, 26, 39
    map_piece 0, 0, 15, 133, 36, 22
    map_piece 0, 0, 15, 133, 38, 9
    map_piece 0, 0, 15, 133, 30, 9
    map_piece 0, 0, 15, 133, 16, 9
    map_piece 0, 0, 15, 133, 8, 9
    map_piece 0, 0, 15, 134, 22, 38
    map_piece 164, 1, 15, 132, 22, 24
    map_piece 165, 1, 15, 132, 7, 22
    map_piece 166, 1, 15, 132, 38, 22
    map_piece 28, 1, 15, 416, 7, 40
    map_piece 29, 1, 15, 416, 38, 40
    map_piece 28, 0, 1, 238, 23, 10
    map_piece 28, 0, 1, 416, 0, 0
    map_piece 28, 0, 1, 416, 2, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 127, 0, 0
map_139_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 128, 0, 0
    map_piece 0, 0, 15, 235, 24, 34
    map_piece 0, 0, 15, 234, 28, 6
    map_piece 0, 0, 15, 234, 35, 6
    map_piece 0, 0, 15, 248, 38, 26
    map_piece 0, 0, 15, 248, 28, 35
    map_piece 0, 0, 15, 238, 26, 21
    map_piece 0, 0, 15, 107, 40, 9
    map_piece 0, 0, 15, 107, 37, 6
    map_piece 0, 0, 15, 107, 26, 6
    map_piece 0, 0, 15, 107, 23, 9
    map_piece 0, 0, 15, 107, 20, 12
    map_piece 0, 0, 15, 107, 17, 15
    map_piece 0, 0, 15, 107, 29, 21
    map_piece 0, 0, 15, 107, 31, 24
    map_piece 0, 0, 15, 107, 8, 8
    map_piece 0, 0, 15, 107, 6, 13
    map_piece 0, 0, 15, 133, 31, 34
    map_piece 0, 0, 15, 133, 15, 28
    map_piece 0, 0, 15, 134, 37, 39
    map_piece 167, 0, 0, 136, 37, 32
    map_piece 165, 1, 15, 132, 37, 26
    map_piece 166, 1, 15, 132, 27, 35
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 129, 0, 0
map_13A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 130, 0, 0
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 17, 7
    map_piece 0, 0, 15, 234, 20, 9
    map_piece 0, 0, 15, 234, 9, 9
    map_piece 0, 0, 15, 248, 15, 31
    map_piece 0, 0, 15, 237, 8, 35
    map_piece 0, 0, 15, 237, 10, 33
    map_piece 0, 0, 15, 237, 12, 31
    map_piece 0, 0, 15, 237, 18, 31
    map_piece 0, 0, 15, 237, 20, 33
    map_piece 0, 0, 15, 237, 22, 35
    map_piece 0, 0, 15, 134, 14, 39
    map_piece 164, 1, 15, 132, 14, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 131, 0, 0
map_13B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 143, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 144, 0, 0
map_13C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 143, 0, 0
    map_piece 0, 0, 15, 150, 12, 18
    map_piece 0, 0, 15, 151, 17, 29
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 144, 0, 0
map_13D_piece_list:
    map_piece 0, 0, 15, 145, 0, 0
    map_piece 164, 1, 1, 147, 13, 11
    map_piece 164, 2, 2, 148, 13, 11
    map_piece 164, 3, 15, 149, 13, 11
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 146, 0, 0
map_13E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 490, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 491, 0, 0
map_13F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 492, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 493, 0, 0
map_140_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 317, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 318, 0, 0
map_141_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 319, 0, 0
    map_piece 36, 4, 15, 324, 19, 14
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 320, 0, 0
map_142_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 327, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 328, 0, 0
map_143_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 332, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 333, 0, 0
map_144_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 494, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 495, 0, 0
map_145_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 360, 0, 0
    map_piece 0, 0, 15, 360, 24, 0
    map_piece 0, 0, 15, 360, 0, 28
    map_piece 0, 0, 15, 360, 24, 28
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 357, 0, 0
map_146_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 375, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 376, 0, 0
map_147_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 377, 0, 0
    map_piece 43, 2, 15, 411, 24, 19
    map_piece 43, 2, 15, 552, 12, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 378, 0, 0
    map_piece 43, 2, 15, 412, 26, 24
map_148_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 379, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 380, 0, 0
map_149_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 381, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 382, 0, 0
map_14A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 383, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 384, 0, 0
map_14B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 385, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 386, 0, 0
map_14C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 433, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 434, 0, 0
map_14D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 435, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 436, 0, 0
map_14F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 58, 0, 0
    map_piece 0, 0, 15, 79, 32, 48
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 59, 0, 0
    map_piece 0, 0, 15, 80, 32, 48
map_150_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 361, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 362, 0, 0
map_151_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 363, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 364, 0, 0
map_152_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 365, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 366, 0, 0
map_153_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 496, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 497, 0, 0
map_154_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 498, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 499, 0, 0
map_155_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_156_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 16, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 17, 0, 0
map_157_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    map_piece 0, 0, 15, 244, 6, 8
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
    map_piece 0, 0, 15, 245, 6, 8
map_158_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
map_159_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 387, 0, 0
    map_piece 43, 1, 15, 407, 7, 14
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 388, 0, 0
map_15A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 389, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 390, 0, 0
map_15B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 391, 0, 0
    map_piece 44, 2, 2, 238, 15, 8
    map_piece 44, 2, 2, 238, 15, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 392, 0, 0
map_15C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 395, 0, 0
    map_piece 44, 1, 15, 393, 11, 11
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 125, 0, 0
    map_piece 44, 1, 15, 394, 11, 11
map_15D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_15E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 502, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 503, 0, 0
map_15F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_160_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 443, 0, 0
    map_piece 85, 1, 1, 447, 18, 17
    map_piece 85, 2, 15, 453, 22, 10
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 444, 0, 0
    map_piece 85, 1, 1, 448, 18, 17
    map_piece 85, 2, 15, 454, 22, 10
map_161_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 171, 0, 0
    map_piece 0, 0, 15, 479, 8, 4
    map_piece 0, 0, 15, 175, 8, 17
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 172, 0, 0
    map_piece 0, 0, 15, 480, 8, 4
    map_piece 0, 0, 15, 176, 8, 17
map_162_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 455, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 456, 0, 0
map_163_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 459, 0, 0
    map_piece 0, 0, 15, 457, 8, 7
    map_piece 0, 0, 15, 457, 16, 7
    map_piece 86, 1, 15, 183, 9, 19
    map_piece 85, 3, 15, 183, 17, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 460, 0, 0
    map_piece 0, 0, 15, 458, 9, 7
    map_piece 0, 0, 15, 458, 17, 7
map_164_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
map_165_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    map_piece 86, 0, 1, 481, 15, 0
    map_piece 86, 2, 15, 479, 5, 3
    map_piece 0, 0, 15, 481, 5, 13
    map_piece 0, 0, 15, 481, 9, 13
    map_piece 0, 0, 15, 481, 7, 18
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
    map_piece 86, 2, 15, 480, 5, 3
    map_piece 0, 0, 15, 482, 5, 13
    map_piece 0, 0, 15, 482, 9, 13
map_166_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 171, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 172, 0, 0
map_167_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 469, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 470, 0, 0
map_168_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 467, 0, 0
    map_piece 0, 0, 15, 462, 15, 12
    map_piece 86, 3, 4, 466, 13, 26
    map_piece 86, 4, 4, 461, 14, 12
    map_piece 86, 0, 4, 464, 30, 9
    map_piece 86, 5, 15, 464, 15, 9
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 468, 0, 0
    map_piece 86, 0, 3, 463, 15, 12
    map_piece 86, 5, 15, 463, 15, 12
    map_piece 86, 5, 15, 465, 15, 9
map_169_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 471, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 472, 0, 0
map_16A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 473, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 474, 0, 0
map_16B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 68, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 69, 0, 0
map_16C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 524, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 525, 0, 0
map_16D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    map_piece 0, 0, 15, 475, 7, 13
    map_piece 0, 0, 15, 479, 5, 3
    map_piece 0, 0, 15, 477, 6, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
    map_piece 0, 0, 15, 476, 7, 13
    map_piece 0, 0, 15, 480, 5, 3
map_16F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 507, 0, 0
    map_piece 0, 0, 15, 44, 8, 5
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 507, 0, 0
    map_piece 0, 0, 15, 44, 8, 5
map_170_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 536, 0, 0
    map_piece 57, 1, 15, 724, 19, 14
    map_piece 57, 1, 15, 552, 24, 10
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 537, 0, 0
    map_piece 57, 1, 15, 725, 19, 14
map_171_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 538, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 539, 0, 0
map_172_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 541, 0, 0
    map_piece 56, 0, 1, 44, 38, 0
    map_piece 56, 2, 15, 44, 21, 4
    map_piece 56, 1, 15, 540, 16, 11
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 542, 0, 0
map_173_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 543, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 544, 0, 0
map_174_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 543, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 544, 0, 0
map_175_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 545, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 546, 0, 0
map_176_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 550, 0, 0
    map_piece 56, 3, 15, 547, 8, 30
    map_piece 56, 3, 15, 416, 15, 31
    map_piece 56, 4, 15, 548, 22, 21
    map_piece 56, 4, 15, 416, 18, 27
    map_piece 56, 5, 15, 547, 18, 15
    map_piece 56, 5, 15, 416, 26, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 551, 0, 0
map_177_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_178_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 18, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 19, 0, 0
map_179_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 606, 0, 0
    map_piece 52, 4, 15, 604, 15, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 607, 0, 0
map_17A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 573, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 574, 0, 0
map_17B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 171, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 172, 0, 0
map_17C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 583, 0, 0
    map_piece 53, 1, 15, 585, 18, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 584, 0, 0
    map_piece 53, 1, 15, 586, 18, 16
map_17D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 173, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 174, 0, 0
map_17E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 167, 0, 0
    map_piece 221, 0, 1, 169, 8, 15
    map_piece 221, 0, 1, 169, 9, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 168, 0, 0
    map_piece 221, 0, 1, 170, 8, 15
    map_piece 221, 0, 1, 170, 9, 15
map_17F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 179, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 180, 0, 0
map_180_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 581, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 582, 0, 0
map_181_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 579, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 580, 0, 0
map_182_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 597, 0, 0
    map_piece 53, 0, 1, 483, 23, 7
    map_piece 53, 2, 15, 483, 14, 7
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 598, 0, 0
map_183_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 599, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 600, 0, 0
map_184_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 171, 0, 0
    map_piece 0, 0, 15, 175, 8, 17
    map_piece 0, 0, 15, 479, 8, 4
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 172, 0, 0
    map_piece 0, 0, 15, 176, 8, 17
    map_piece 0, 0, 15, 480, 8, 4
map_185_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 602, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 603, 0, 0
map_186_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 577, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 578, 0, 0
map_187_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 575, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 576, 0, 0
map_189_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 639, 0, 0
    map_piece 0, 0, 15, 637, 11, 21
    map_piece 0, 0, 15, 638, 11, 8
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 640, 0, 0
map_18A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 639, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 640, 0, 0
map_18B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 639, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 640, 0, 0
map_18C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 639, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 640, 0, 0
