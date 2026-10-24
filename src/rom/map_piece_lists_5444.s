; Bounded native map piece lists; docs/map-piece-list-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5444
.macro map_piece flag_index, flag_min, flag_max, piece_id, tile_x, tile_y
    .byte flag_index, (flag_min << 4) | flag_max, piece_id & $FF
    .byte (tile_x << 1) | ((piece_id >> 8) & 1)
    .byte (tile_y << 1) | ((piece_id >> 9) & 1)
.endmacro
map_008_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 1, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 1, 0, 0
map_00E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 355, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 355, 0, 0
map_00F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_010_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 22, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 23, 0, 0
map_011_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 532, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 533, 0, 0
map_012_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 530, 0, 0
    map_piece 63, 2, 2, 97, 14, 12
    map_piece 63, 3, 3, 98, 14, 12
    map_piece 63, 4, 15, 99, 14, 12
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 531, 0, 0
map_013_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 24, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 25, 0, 0
map_014_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 569, 0, 0
    map_piece 0, 0, 15, 134, 14, 14
    map_piece 0, 0, 15, 134, 60, 49
    map_piece 0, 0, 15, 133, 6, 19
    map_piece 0, 0, 15, 133, 10, 19
    map_piece 0, 0, 15, 133, 15, 21
    map_piece 0, 0, 15, 133, 19, 21
    map_piece 0, 0, 15, 133, 12, 40
    map_piece 0, 0, 15, 133, 18, 42
    map_piece 0, 0, 15, 133, 32, 40
    map_piece 0, 0, 15, 133, 34, 39
    map_piece 0, 0, 15, 133, 38, 38
    map_piece 0, 0, 15, 133, 58, 39
    map_piece 0, 0, 15, 133, 56, 38
    map_piece 0, 0, 15, 133, 52, 38
    map_piece 0, 0, 15, 133, 50, 39
    map_piece 0, 0, 15, 133, 64, 42
    map_piece 0, 0, 15, 133, 14, 41
    map_piece 0, 0, 15, 133, 16, 41
    map_piece 0, 0, 15, 133, 59, 7
    map_piece 0, 0, 15, 133, 61, 7
    map_piece 0, 0, 15, 133, 63, 7
    map_piece 0, 0, 15, 133, 60, 40
    map_piece 0, 0, 15, 133, 62, 40
    map_piece 0, 0, 15, 133, 17, 21
    map_piece 0, 0, 15, 133, 35, 6
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 570, 0, 0
map_015_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 608, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 609, 0, 0
map_016_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 642, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 643, 0, 0
map_017_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 73, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 74, 0, 0
map_018_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 646, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 647, 0, 0
map_019_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 75, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 76, 0, 0
map_01A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 601, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 605, 0, 0
map_01B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 152, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 153, 0, 0
map_01C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 160, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 164, 0, 0
map_01D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 161, 0, 0
    map_piece 94, 1, 15, 159, 14, 18
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 164, 0, 0
map_01E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 162, 0, 0
    map_piece 95, 1, 1, 154, 14, 23
    map_piece 95, 2, 2, 155, 14, 23
    map_piece 95, 3, 15, 156, 14, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 164, 0, 0
map_01F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 163, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 164, 0, 0
map_020_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 505, 0, 0
    map_piece 0, 0, 15, 867, 9, 2
    map_piece 0, 0, 15, 868, 24, 16
    map_piece 0, 0, 15, 867, 9, 32
    map_piece 0, 0, 15, 868, 24, 44
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 506, 0, 0
map_021_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 505, 0, 0
    map_piece 0, 0, 15, 867, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 874, 0, 0
map_022_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 505, 0, 0
    map_piece 0, 0, 15, 867, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 874, 0, 0
map_023_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 519, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 873, 0, 0
map_024_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 648, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 649, 0, 0
map_025_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 650, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 651, 0, 0
map_026_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 157, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 158, 0, 0
map_027_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 277, 0, 0
    map_piece 0, 0, 15, 279, 0, 0
    map_piece 0, 0, 15, 280, 13, 64
    map_piece 0, 0, 15, 281, 40, 46
    map_piece 0, 0, 15, 291, 14, 33
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 278, 0, 0
    map_piece 0, 0, 15, 285, 0, 0
    map_piece 0, 0, 15, 286, 13, 63
    map_piece 0, 0, 15, 287, 39, 44
    map_piece 0, 0, 15, 334, 15, 34
map_028_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 277, 0, 0
    map_piece 0, 0, 15, 325, 24, 35
    map_piece 0, 0, 15, 326, 8, 0
    map_piece 0, 0, 15, 281, 40, 46
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 278, 0, 0
    map_piece 0, 0, 15, 335, 24, 32
    map_piece 0, 0, 15, 504, 8, 0
    map_piece 0, 0, 15, 287, 39, 44
map_029_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 277, 0, 0
    map_piece 0, 0, 15, 284, 0, 37
    map_piece 0, 0, 15, 281, 40, 46
    map_piece 32, 0, 3, 282, 21, 57
    map_piece 0, 0, 15, 262, 35, 37
    map_piece 0, 0, 15, 262, 34, 39
    map_piece 0, 0, 15, 262, 29, 56
    map_piece 0, 0, 15, 262, 31, 54
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 278, 0, 0
    map_piece 0, 0, 15, 290, 0, 35
    map_piece 0, 0, 15, 287, 39, 44
    map_piece 32, 0, 3, 288, 20, 56
map_02A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 652, 0, 0
    map_piece 66, 1, 15, 711, 6, 71
    map_piece 66, 1, 15, 708, 5, 51
    map_piece 66, 2, 15, 711, 68, 17
    map_piece 66, 2, 15, 708, 88, 13
    map_piece 66, 3, 15, 711, 81, 42
    map_piece 66, 5, 15, 711, 88, 17
    map_piece 66, 5, 15, 708, 46, 17
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 653, 0, 0
map_02B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 654, 0, 0
    map_piece 66, 4, 15, 711, 35, 54
    map_piece 66, 6, 15, 711, 89, 85
    map_piece 67, 1, 15, 656, 40, 46
    map_piece 67, 2, 15, 657, 34, 46
    map_piece 67, 3, 15, 658, 37, 46
    map_piece 67, 4, 15, 659, 31, 46
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 655, 0, 0
map_02C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 863, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 864, 0, 0
map_02D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 863, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 864, 0, 0
map_02E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 865, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 866, 0, 0
map_02F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 312, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 313, 0, 0
map_030_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 500, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 501, 0, 0
map_031_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 265, 32, 14
    map_piece 0, 0, 15, 264, 7, 45
    map_piece 0, 0, 15, 262, 17, 35
    map_piece 0, 0, 15, 283, 18, 32
    map_piece 0, 0, 15, 371, 24, 20
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 274, 32, 10
    map_piece 0, 0, 15, 273, 7, 46
    map_piece 0, 0, 15, 289, 16, 31
    map_piece 0, 0, 15, 372, 24, 20
map_033_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 720, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 721, 0, 0
map_034_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 256, 8, 0
    map_piece 0, 0, 15, 258, 38, 34
    map_piece 0, 0, 15, 259, 28, 0
    map_piece 0, 0, 15, 261, 0, 34
    map_piece 0, 0, 15, 262, 22, 23
    map_piece 0, 0, 15, 262, 23, 26
    map_piece 33, 0, 1, 263, 28, 24
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 266, 8, 0
    map_piece 0, 0, 15, 268, 36, 35
    map_piece 0, 0, 15, 269, 28, 0
    map_piece 0, 0, 15, 271, 0, 33
    map_piece 33, 0, 1, 272, 29, 25
map_035_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 258, 38, 34
    map_piece 0, 0, 15, 262, 17, 35
    map_piece 0, 0, 15, 259, 28, 0
    map_piece 0, 0, 15, 261, 0, 34
    map_piece 0, 0, 15, 256, 8, 0
    map_piece 0, 0, 15, 283, 18, 32
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 268, 36, 35
    map_piece 0, 0, 15, 269, 28, 0
    map_piece 0, 0, 15, 271, 0, 33
    map_piece 0, 0, 15, 266, 8, 0
    map_piece 0, 0, 15, 289, 16, 31
map_036_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 257, 0, 18
    map_piece 0, 0, 15, 260, 27, 47
    map_piece 0, 0, 15, 263, 28, 24
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 267, 0, 14
    map_piece 0, 0, 15, 270, 26, 47
    map_piece 0, 0, 15, 272, 29, 25
map_037_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 265, 32, 14
    map_piece 0, 0, 15, 264, 7, 45
    map_piece 0, 0, 15, 262, 17, 35
    map_piece 0, 0, 15, 283, 18, 32
    map_piece 0, 0, 15, 371, 24, 20
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 274, 32, 10
    map_piece 0, 0, 15, 273, 7, 46
    map_piece 0, 0, 15, 289, 16, 31
    map_piece 0, 0, 15, 372, 24, 20
map_038_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 292, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 293, 0, 0
map_039_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_03A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 302, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 303, 0, 0
map_03B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 302, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 303, 0, 0
map_03C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 294, 0, 0
    map_piece 33, 0, 2, 296, 12, 0
    map_piece 33, 0, 2, 298, 16, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 295, 0, 0
    map_piece 33, 0, 2, 297, 12, 0
    map_piece 33, 0, 2, 299, 16, 23
map_03D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 513, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_03E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 512, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 516, 0, 0
    map_piece 0, 0, 15, 515, 0, 20
    map_piece 0, 0, 15, 515, 14, 20
    map_piece 0, 0, 15, 515, 28, 20
    map_piece 0, 0, 15, 515, 42, 20
    map_piece 0, 0, 15, 514, 0, 33
map_03F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 522, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 523, 0, 0
map_040_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 517, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 518, 0, 0
    map_piece 0, 0, 15, 515, 0, 24
    map_piece 0, 0, 15, 515, 14, 24
    map_piece 0, 0, 15, 515, 28, 24
    map_piece 0, 0, 15, 514, 0, 36
map_041_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 520, 0, 0
map_042_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 521, 0, 0
map_043_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 345, 11, 20
    map_piece 0, 0, 15, 345, 20, 20
    map_piece 0, 0, 15, 345, 28, 18
    map_piece 0, 0, 15, 345, 32, 25
    map_piece 0, 0, 15, 345, 27, 30
    map_piece 0, 0, 15, 345, 14, 29
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 342, 0, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_044_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 337, 18, 37
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 341, 15, 19
    map_piece 0, 0, 15, 341, 27, 18
    map_piece 0, 0, 15, 341, 18, 27
    map_piece 0, 0, 15, 341, 32, 25
    map_piece 0, 0, 15, 341, 17, 33
    map_piece 0, 0, 15, 341, 23, 33
    map_piece 0, 0, 15, 340, 30, 32
    map_piece 0, 0, 15, 340, 23, 23
    map_piece 0, 0, 15, 340, 9, 28
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 337, 18, 37
    map_piece 0, 0, 15, 346, 20, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_045_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 344, 14, 17
    map_piece 0, 0, 15, 344, 21, 19
    map_piece 0, 0, 15, 344, 28, 18
    map_piece 0, 0, 15, 344, 31, 25
    map_piece 0, 0, 15, 344, 20, 25
    map_piece 0, 0, 15, 344, 13, 24
    map_piece 0, 0, 15, 344, 16, 31
    map_piece 0, 0, 15, 344, 23, 31
    map_piece 0, 0, 15, 337, 18, 37
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_046_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 344, 11, 18
    map_piece 0, 0, 15, 344, 19, 18
    map_piece 0, 0, 15, 344, 29, 20
    map_piece 0, 0, 15, 344, 11, 28
    map_piece 0, 0, 15, 344, 21, 28
    map_piece 0, 0, 15, 344, 28, 26
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 342, 0, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_047_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 654, 0, 0
    map_piece 66, 4, 15, 711, 35, 54
    map_piece 66, 6, 15, 711, 89, 85
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 655, 0, 0
map_048_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 712, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 713, 0, 0
map_049_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 82, 0, 0
    map_piece 20, 6, 15, 81, 42, 62
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 83, 0, 0
map_04B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 441, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 442, 0, 0
map_04C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 425, 0, 0
    map_piece 0, 0, 15, 397, 14, 0
    map_piece 0, 0, 15, 397, 34, 0
    map_piece 0, 0, 15, 427, 33, 55
    map_piece 0, 0, 15, 403, 34, 40
    map_piece 0, 0, 15, 404, 22, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 426, 0, 0
    map_piece 0, 0, 15, 400, 14, 0
    map_piece 0, 0, 15, 400, 34, 0
    map_piece 0, 0, 15, 428, 33, 55
    map_piece 0, 0, 15, 409, 34, 40
    map_piece 0, 0, 15, 410, 22, 16
map_04D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 425, 0, 0
    map_piece 0, 0, 15, 396, 40, 27
    map_piece 0, 0, 15, 397, 14, 0
    map_piece 0, 0, 15, 404, 22, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 426, 0, 0
    map_piece 0, 0, 15, 399, 40, 27
    map_piece 0, 0, 15, 400, 14, 0
    map_piece 0, 0, 15, 410, 22, 16
map_04E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 417, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 422, 0, 0
map_04F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 405, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 406, 0, 0
map_050_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 423, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 424, 0, 0
map_051_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 425, 0, 0
    map_piece 0, 0, 15, 398, 0, 35
    map_piece 0, 0, 15, 397, 14, 0
    map_piece 0, 0, 15, 396, 40, 27
    map_piece 0, 0, 15, 402, 20, 29
    map_piece 0, 0, 15, 421, 38, 28
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 426, 0, 0
    map_piece 0, 0, 15, 401, 0, 35
    map_piece 0, 0, 15, 400, 14, 0
    map_piece 0, 0, 15, 399, 40, 27
map_052_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 571, 0, 0
    map_piece 52, 2, 14, 722, 19, 33
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 572, 0, 0
    map_piece 52, 2, 14, 723, 19, 33
map_053_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 417, 0, 0
    map_piece 0, 0, 15, 415, 12, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 422, 0, 0
    map_piece 0, 0, 15, 420, 12, 0
map_054_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 340, 13, 19
    map_piece 0, 0, 15, 340, 13, 27
    map_piece 0, 0, 15, 341, 33, 20
    map_piece 0, 0, 15, 341, 26, 25
    map_piece 0, 0, 15, 341, 29, 30
    map_piece 0, 0, 15, 341, 33, 31
    map_piece 0, 0, 15, 341, 18, 30
    map_piece 0, 0, 15, 341, 14, 32
    map_piece 0, 0, 15, 341, 22, 33
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_055_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 337, 18, 37
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 338, 10, 19
    map_piece 0, 0, 15, 338, 29, 21
    map_piece 0, 0, 15, 339, 25, 29
    map_piece 0, 0, 15, 339, 11, 31
    map_piece 0, 0, 15, 341, 24, 17
    map_piece 0, 0, 15, 341, 18, 22
    map_piece 0, 0, 15, 341, 11, 26
    map_piece 0, 0, 15, 341, 24, 34
    map_piece 0, 0, 15, 342, 0, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_056_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 345, 15, 19
    map_piece 0, 0, 15, 345, 32, 20
    map_piece 0, 0, 15, 345, 29, 29
    map_piece 0, 0, 15, 345, 15, 31
    map_piece 0, 0, 15, 341, 22, 32
    map_piece 0, 0, 15, 341, 25, 27
    map_piece 0, 0, 15, 341, 24, 19
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 337, 18, 37
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_057_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 344, 9, 20
    map_piece 0, 0, 15, 344, 9, 26
    map_piece 0, 0, 15, 344, 16, 31
    map_piece 0, 0, 15, 344, 23, 31
    map_piece 0, 0, 15, 344, 31, 29
    map_piece 0, 0, 15, 344, 31, 23
    map_piece 0, 0, 15, 344, 20, 24
    map_piece 0, 0, 15, 344, 18, 16
    map_piece 0, 0, 15, 344, 25, 17
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 337, 18, 37
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_058_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 338, 10, 19
    map_piece 0, 0, 15, 338, 28, 31
    map_piece 0, 0, 15, 339, 29, 19
    map_piece 0, 0, 15, 339, 11, 32
    map_piece 0, 0, 15, 344, 14, 24
    map_piece 0, 0, 15, 344, 22, 24
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 337, 18, 37
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_059_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 369, 0, 0
    map_piece 41, 2, 15, 418, 21, 17
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 370, 0, 0
    map_piece 41, 2, 15, 419, 21, 17
map_05A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 373, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 374, 0, 0
map_05B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 341, 19, 16
    map_piece 0, 0, 15, 341, 18, 21
    map_piece 0, 0, 15, 341, 25, 16
    map_piece 0, 0, 15, 341, 24, 21
    map_piece 0, 0, 15, 341, 28, 24
    map_piece 0, 0, 15, 341, 11, 26
    map_piece 0, 0, 15, 341, 18, 34
    map_piece 0, 0, 15, 341, 25, 29
    map_piece 0, 0, 15, 340, 33, 29
    map_piece 0, 0, 15, 340, 12, 32
    map_piece 0, 0, 15, 340, 10, 19
    map_piece 0, 0, 15, 340, 32, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_05C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 344, 14, 20
    map_piece 0, 0, 15, 344, 26, 22
    map_piece 0, 0, 15, 344, 18, 30
    map_piece 0, 0, 15, 340, 24, 17
    map_piece 0, 0, 15, 340, 11, 30
    map_piece 0, 0, 15, 340, 29, 33
    map_piece 0, 0, 15, 346, 20, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_05D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 344, 18, 18
    map_piece 0, 0, 15, 344, 10, 26
    map_piece 0, 0, 15, 344, 19, 24
    map_piece 0, 0, 15, 344, 26, 23
    map_piece 0, 0, 15, 345, 12, 18
    map_piece 0, 0, 15, 345, 31, 18
    map_piece 0, 0, 15, 345, 31, 29
    map_piece 0, 0, 15, 345, 22, 31
    map_piece 0, 0, 15, 343, 37, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_05E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 344, 11, 18
    map_piece 0, 0, 15, 344, 19, 18
    map_piece 0, 0, 15, 344, 29, 20
    map_piece 0, 0, 15, 344, 11, 28
    map_piece 0, 0, 15, 344, 18, 24
    map_piece 0, 0, 15, 344, 25, 30
    map_piece 0, 0, 15, 344, 30, 26
    map_piece 0, 0, 15, 337, 18, 37
    map_piece 0, 0, 15, 343, 37, 26
    map_piece 0, 0, 15, 342, 0, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_05F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 344, 11, 27
    map_piece 0, 0, 15, 344, 23, 28
    map_piece 0, 0, 15, 344, 19, 18
    map_piece 0, 0, 15, 349, 29, 18
    map_piece 0, 0, 15, 350, 30, 26
    map_piece 0, 0, 15, 350, 11, 18
    map_piece 0, 0, 15, 351, 17, 32
    map_piece 0, 0, 15, 351, 17, 25
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 343, 37, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_060_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 352, 0, 0
    map_piece 0, 0, 15, 349, 14, 19
    map_piece 0, 0, 15, 349, 33, 26
    map_piece 0, 0, 15, 349, 13, 32
    map_piece 0, 0, 15, 350, 28, 31
    map_piece 0, 0, 15, 350, 27, 19
    map_piece 0, 0, 15, 351, 20, 25
    map_piece 0, 0, 15, 351, 11, 25
    map_piece 0, 0, 15, 337, 18, 37
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 353, 0, 0
map_061_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 347, 0, 0
    map_piece 0, 0, 15, 346, 20, 0
    map_piece 0, 0, 15, 337, 18, 37
    map_piece 0, 0, 15, 349, 10, 19
    map_piece 0, 0, 15, 349, 25, 27
    map_piece 0, 0, 15, 350, 19, 19
    map_piece 0, 0, 15, 350, 29, 28
    map_piece 0, 0, 15, 350, 13, 30
    map_piece 0, 0, 15, 351, 22, 30
    map_piece 0, 0, 15, 351, 11, 26
    map_piece 0, 0, 15, 351, 28, 19
    map_piece 0, 0, 15, 342, 0, 23
    map_piece 0, 0, 15, 875, 12, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 348, 0, 0
map_062_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 484, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 485, 0, 0
map_063_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 484, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 485, 0, 0
map_064_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 587, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 588, 0, 0
    map_piece 0, 0, 15, 588, 0, 4
map_065_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 7, 0, 0
    map_piece 0, 0, 15, 4, 36, 14
    map_piece 0, 0, 15, 6, 47, 50
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 8, 0, 0
    map_piece 0, 0, 15, 5, 36, 14
map_066_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 14, 0, 0
    map_piece 16, 6, 15, 13, 29, 28
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 15, 0, 0
map_067_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 41, 0, 0
    map_piece 0, 0, 15, 241, 16, 23
    map_piece 0, 0, 15, 241, 19, 21
    map_piece 0, 0, 15, 241, 19, 24
    map_piece 0, 0, 15, 241, 26, 21
    map_piece 0, 0, 15, 241, 26, 24
    map_piece 0, 0, 15, 241, 29, 23
    map_piece 0, 0, 15, 240, 16, 26
    map_piece 0, 0, 15, 240, 19, 27
    map_piece 0, 0, 15, 240, 26, 27
    map_piece 0, 0, 15, 240, 29, 26
    map_piece 0, 0, 15, 239, 15, 33
    map_piece 0, 0, 15, 239, 18, 35
    map_piece 0, 0, 15, 239, 28, 35
    map_piece 0, 0, 15, 239, 31, 33
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 42, 0, 0
map_068_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 54, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 55, 0, 0
map_069_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_06A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 275, 0, 0
    map_piece 0, 0, 15, 256, 8, 0
    map_piece 0, 0, 15, 258, 38, 34
    map_piece 0, 0, 15, 259, 28, 0
    map_piece 0, 0, 15, 261, 0, 34
    map_piece 0, 0, 15, 262, 22, 23
    map_piece 0, 0, 15, 262, 23, 26
    map_piece 33, 0, 1, 263, 28, 24
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 276, 0, 0
    map_piece 0, 0, 15, 266, 8, 0
    map_piece 0, 0, 15, 268, 36, 35
    map_piece 0, 0, 15, 269, 28, 0
    map_piece 0, 0, 15, 271, 0, 33
    map_piece 33, 0, 1, 272, 29, 25
map_06B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 292, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 293, 0, 0
map_06C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 484, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 485, 0, 0
map_06D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 246, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 247, 0, 0
map_06E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 641, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 641, 0, 0
map_06F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 732, 0, 0
    map_piece 0, 0, 15, 234, 6, 7
    map_piece 0, 0, 15, 234, 14, 5
    map_piece 0, 0, 15, 234, 22, 7
    map_piece 55, 1, 1, 633, 12, 13
    map_piece 55, 2, 2, 631, 12, 13
    map_piece 55, 3, 3, 629, 12, 13
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 733, 0, 0
    map_piece 55, 1, 1, 634, 12, 13
    map_piece 55, 2, 2, 632, 12, 13
    map_piece 55, 3, 3, 630, 12, 13
map_070_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 635, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 636, 0, 0
map_071_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 622, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 623, 0, 0
    map_piece 0, 0, 15, 560, 11, 30
    map_piece 0, 0, 15, 560, 54, 30
    map_piece 0, 0, 15, 560, 42, 33
map_072_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 556, 0, 0
    map_piece 0, 0, 15, 554, 11, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 557, 0, 0
    map_piece 0, 0, 15, 560, 20, 19
    map_piece 0, 0, 15, 560, 37, 20
    map_piece 0, 0, 15, 560, 42, 45
    map_piece 0, 0, 15, 560, 50, 47
    map_piece 0, 0, 15, 555, 11, 19
map_073_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 558, 0, 0
    map_piece 0, 0, 15, 554, 25, 21
    map_piece 0, 0, 15, 554, 32, 21
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 559, 0, 0
    map_piece 0, 0, 15, 560, 48, 44
    map_piece 0, 0, 15, 560, 39, 50
    map_piece 0, 0, 15, 560, 12, 32
    map_piece 0, 0, 15, 560, 52, 9
    map_piece 0, 0, 15, 555, 25, 21
    map_piece 0, 0, 15, 555, 32, 21
map_074_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 625, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 626, 0, 0
map_075_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 627, 0, 0
    map_piece 0, 0, 15, 234, 10, 6
    map_piece 0, 0, 15, 234, 20, 7
    map_piece 0, 0, 15, 234, 30, 6
    map_piece 0, 0, 15, 235, 16, 8
    map_piece 0, 0, 15, 235, 24, 8
    map_piece 0, 0, 15, 133, 7, 7
    map_piece 0, 0, 15, 133, 13, 7
    map_piece 0, 0, 15, 133, 18, 8
    map_piece 0, 0, 15, 133, 22, 8
    map_piece 0, 0, 15, 133, 27, 7
    map_piece 0, 0, 15, 133, 33, 7
    map_piece 0, 0, 15, 133, 7, 23
    map_piece 0, 0, 15, 133, 13, 23
    map_piece 0, 0, 15, 133, 27, 23
    map_piece 0, 0, 15, 133, 33, 23
    map_piece 0, 0, 15, 133, 24, 27
    map_piece 0, 0, 15, 248, 10, 23
    map_piece 164, 1, 15, 132, 9, 23
    map_piece 0, 0, 15, 248, 30, 23
    map_piece 165, 1, 15, 132, 29, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 628, 0, 0
map_076_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 627, 0, 0
    map_piece 0, 0, 15, 234, 10, 6
    map_piece 0, 0, 15, 234, 20, 7
    map_piece 0, 0, 15, 234, 30, 6
    map_piece 0, 0, 15, 235, 16, 8
    map_piece 0, 0, 15, 235, 24, 8
    map_piece 0, 0, 15, 133, 7, 7
    map_piece 0, 0, 15, 133, 13, 7
    map_piece 0, 0, 15, 133, 18, 8
    map_piece 0, 0, 15, 133, 22, 8
    map_piece 0, 0, 15, 133, 27, 7
    map_piece 0, 0, 15, 133, 33, 7
    map_piece 0, 0, 15, 133, 7, 23
    map_piece 0, 0, 15, 133, 13, 23
    map_piece 0, 0, 15, 133, 27, 23
    map_piece 0, 0, 15, 133, 33, 23
    map_piece 0, 0, 15, 133, 24, 27
    map_piece 0, 0, 15, 248, 10, 23
    map_piece 166, 1, 15, 132, 9, 23
    map_piece 0, 0, 15, 248, 30, 23
    map_piece 167, 1, 15, 132, 29, 23
    map_piece 0, 0, 15, 134, 9, 31
    map_piece 0, 0, 15, 510, 9, 29
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 628, 0, 0
    map_piece 0, 0, 15, 511, 10, 31
map_077_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 732, 0, 0
    map_piece 0, 0, 15, 234, 6, 7
    map_piece 0, 0, 15, 234, 14, 5
    map_piece 0, 0, 15, 234, 22, 7
    map_piece 55, 0, 4, 633, 12, 13
    map_piece 55, 5, 5, 631, 12, 13
    map_piece 55, 6, 6, 629, 12, 13
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 733, 0, 0
    map_piece 55, 0, 4, 634, 12, 13
    map_piece 55, 5, 5, 632, 12, 13
    map_piece 55, 6, 6, 630, 12, 13
map_078_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
map_079_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 720, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 721, 0, 0
map_07A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 567, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 85, 16
    map_piece 0, 0, 15, 561, 90, 16
    map_piece 0, 0, 15, 564, 45, 6
    map_piece 0, 0, 15, 564, 65, 6
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 568, 0, 0
map_07B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 565, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 39, 13
    map_piece 0, 0, 15, 561, 64, 16
    map_piece 0, 0, 15, 561, 71, 16
    map_piece 0, 0, 15, 564, 6, 5
    map_piece 0, 0, 15, 564, 82, 32
    map_piece 0, 0, 15, 564, 31, 33
    map_piece 0, 0, 15, 564, 6, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 566, 0, 0
map_07C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 565, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 39, 13
    map_piece 0, 0, 15, 561, 64, 16
    map_piece 0, 0, 15, 561, 71, 16
    map_piece 0, 0, 15, 564, 6, 5
    map_piece 0, 0, 15, 564, 82, 32
    map_piece 0, 0, 15, 564, 31, 33
    map_piece 0, 0, 15, 564, 6, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 566, 0, 0
map_07D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 562, 0, 0
    map_piece 0, 0, 15, 564, 23, 6
    map_piece 0, 0, 15, 564, 6, 26
    map_piece 0, 0, 15, 564, 29, 26
    map_piece 0, 0, 15, 564, 39, 25
    map_piece 0, 0, 15, 561, 39, 12
    map_piece 0, 0, 15, 561, 45, 12
    map_piece 0, 0, 15, 561, 10, 30
    map_piece 0, 0, 15, 561, 13, 30
    map_piece 0, 0, 15, 561, 16, 30
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 563, 0, 0
map_07E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 567, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 85, 16
    map_piece 0, 0, 15, 561, 90, 16
    map_piece 0, 0, 15, 564, 45, 6
    map_piece 0, 0, 15, 564, 65, 6
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 568, 0, 0
map_07F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 565, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 39, 13
    map_piece 0, 0, 15, 561, 64, 16
    map_piece 0, 0, 15, 561, 71, 16
    map_piece 0, 0, 15, 564, 6, 5
    map_piece 0, 0, 15, 564, 82, 32
    map_piece 0, 0, 15, 564, 31, 33
    map_piece 0, 0, 15, 564, 6, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 566, 0, 0
map_080_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 7, 0, 0
    map_piece 0, 0, 15, 4, 36, 14
    map_piece 0, 0, 15, 6, 47, 50
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 8, 0, 0
    map_piece 0, 0, 15, 5, 36, 14
map_081_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 9, 0, 0
    map_piece 0, 0, 15, 4, 0, 0
    map_piece 0, 0, 15, 6, 15, 36
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 10, 0, 0
    map_piece 0, 0, 15, 5, 0, 0
map_082_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 11, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 12, 0, 0
map_083_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 14, 0, 0
    map_piece 16, 6, 15, 13, 29, 28
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 15, 0, 0
map_084_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 28, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 29, 0, 0
map_085_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 30, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 31, 0, 0
map_086_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 869, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 870, 0, 0
map_087_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 39, 0, 0
    map_piece 167, 1, 15, 32, 15, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 40, 0, 0
map_088_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 41, 0, 0
    map_piece 0, 0, 15, 241, 16, 23
    map_piece 0, 0, 15, 241, 19, 21
    map_piece 0, 0, 15, 241, 19, 24
    map_piece 0, 0, 15, 241, 26, 21
    map_piece 0, 0, 15, 241, 26, 24
    map_piece 0, 0, 15, 241, 29, 23
    map_piece 0, 0, 15, 240, 16, 26
    map_piece 0, 0, 15, 240, 19, 27
    map_piece 0, 0, 15, 240, 26, 27
    map_piece 0, 0, 15, 240, 29, 26
    map_piece 0, 0, 15, 239, 15, 33
    map_piece 0, 0, 15, 239, 18, 35
    map_piece 0, 0, 15, 239, 28, 35
    map_piece 0, 0, 15, 239, 31, 33
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 42, 0, 0
map_089_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 35, 0, 0
    map_piece 0, 0, 15, 238, 6, 21
    map_piece 0, 0, 15, 238, 10, 21
    map_piece 0, 0, 15, 238, 6, 16
    map_piece 0, 0, 15, 238, 10, 16
    map_piece 0, 0, 15, 238, 6, 10
    map_piece 0, 0, 15, 238, 10, 10
    map_piece 0, 0, 15, 236, 2, 5
    map_piece 0, 0, 15, 236, 14, 5
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 36, 0, 0
map_08A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 565, 0, 0
    map_piece 0, 0, 15, 561, 10, 10
    map_piece 0, 0, 15, 561, 13, 10
    map_piece 0, 0, 15, 561, 16, 10
    map_piece 0, 0, 15, 561, 39, 13
    map_piece 0, 0, 15, 561, 64, 16
    map_piece 0, 0, 15, 561, 71, 16
    map_piece 0, 0, 15, 564, 6, 5
    map_piece 0, 0, 15, 564, 82, 32
    map_piece 0, 0, 15, 564, 31, 33
    map_piece 0, 0, 15, 564, 6, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 566, 0, 0
map_08B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 37, 0, 0
    map_piece 0, 0, 15, 238, 12, 56
    map_piece 0, 0, 15, 238, 20, 56
    map_piece 0, 0, 15, 238, 12, 51
    map_piece 0, 0, 15, 238, 20, 51
    map_piece 0, 0, 15, 238, 8, 45
    map_piece 0, 0, 15, 238, 24, 45
    map_piece 0, 0, 15, 238, 8, 40
    map_piece 0, 0, 15, 238, 24, 40
    map_piece 0, 0, 15, 238, 8, 35
    map_piece 0, 0, 15, 238, 24, 35
    map_piece 0, 0, 15, 238, 8, 30
    map_piece 0, 0, 15, 238, 24, 30
    map_piece 0, 0, 15, 238, 6, 16
    map_piece 0, 0, 15, 238, 11, 15
    map_piece 0, 0, 15, 238, 22, 15
    map_piece 0, 0, 15, 238, 6, 12
    map_piece 0, 0, 15, 236, 5, 41
    map_piece 0, 0, 15, 236, 27, 41
    map_piece 0, 0, 15, 236, 5, 33
    map_piece 0, 0, 15, 236, 27, 33
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 14, 6
    map_piece 0, 0, 15, 234, 19, 6
    map_piece 0, 0, 15, 234, 21, 7
    map_piece 0, 0, 15, 234, 27, 6
    map_piece 0, 0, 15, 236, 8, 54
    map_piece 0, 0, 15, 236, 24, 54
    map_piece 164, 0, 0, 33, 15, 48
    map_piece 165, 0, 0, 34, 12, 26
    map_piece 166, 0, 0, 34, 19, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 38, 0, 0
map_08C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 35, 0, 0
    map_piece 0, 0, 15, 238, 6, 21
    map_piece 0, 0, 15, 238, 10, 21
    map_piece 0, 0, 15, 238, 6, 16
    map_piece 0, 0, 15, 238, 10, 16
    map_piece 0, 0, 15, 238, 6, 10
    map_piece 0, 0, 15, 238, 10, 10
    map_piece 0, 0, 15, 236, 2, 5
    map_piece 0, 0, 15, 236, 14, 5
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 36, 0, 0
map_08E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 37, 0, 0
    map_piece 0, 0, 15, 238, 12, 56
    map_piece 0, 0, 15, 238, 20, 56
    map_piece 0, 0, 15, 238, 12, 51
    map_piece 0, 0, 15, 238, 20, 51
    map_piece 0, 0, 15, 238, 8, 45
    map_piece 0, 0, 15, 238, 24, 45
    map_piece 0, 0, 15, 238, 8, 40
    map_piece 0, 0, 15, 238, 24, 40
    map_piece 0, 0, 15, 238, 8, 35
    map_piece 0, 0, 15, 238, 24, 35
    map_piece 0, 0, 15, 238, 8, 30
    map_piece 0, 0, 15, 238, 24, 30
    map_piece 0, 0, 15, 238, 6, 16
    map_piece 0, 0, 15, 238, 11, 15
    map_piece 0, 0, 15, 238, 22, 15
    map_piece 0, 0, 15, 238, 6, 12
    map_piece 0, 0, 15, 236, 5, 41
    map_piece 0, 0, 15, 236, 27, 41
    map_piece 0, 0, 15, 236, 5, 33
    map_piece 0, 0, 15, 236, 27, 33
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 14, 6
    map_piece 0, 0, 15, 234, 19, 6
    map_piece 0, 0, 15, 234, 27, 6
    map_piece 0, 0, 15, 234, 21, 7
    map_piece 0, 0, 15, 236, 8, 54
    map_piece 0, 0, 15, 236, 24, 54
    map_piece 164, 0, 0, 33, 15, 48
    map_piece 165, 0, 0, 34, 12, 26
    map_piece 166, 0, 0, 34, 19, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 38, 0, 0
map_08F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 37, 0, 0
    map_piece 0, 0, 15, 238, 12, 56
    map_piece 0, 0, 15, 238, 20, 56
    map_piece 0, 0, 15, 238, 12, 51
    map_piece 0, 0, 15, 238, 20, 51
    map_piece 0, 0, 15, 238, 8, 45
    map_piece 0, 0, 15, 238, 24, 45
    map_piece 0, 0, 15, 238, 8, 40
    map_piece 0, 0, 15, 238, 24, 40
    map_piece 0, 0, 15, 238, 8, 35
    map_piece 0, 0, 15, 238, 24, 35
    map_piece 0, 0, 15, 238, 8, 30
    map_piece 0, 0, 15, 238, 24, 30
    map_piece 0, 0, 15, 238, 6, 16
    map_piece 0, 0, 15, 238, 11, 15
    map_piece 0, 0, 15, 238, 22, 15
    map_piece 0, 0, 15, 238, 6, 12
    map_piece 0, 0, 15, 236, 5, 41
    map_piece 0, 0, 15, 236, 27, 41
    map_piece 0, 0, 15, 236, 5, 33
    map_piece 0, 0, 15, 236, 27, 33
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 14, 6
    map_piece 0, 0, 15, 234, 19, 6
    map_piece 0, 0, 15, 234, 21, 7
    map_piece 0, 0, 15, 234, 27, 6
    map_piece 0, 0, 15, 236, 8, 54
    map_piece 0, 0, 15, 236, 24, 54
    map_piece 164, 0, 0, 33, 15, 48
    map_piece 165, 0, 0, 34, 12, 26
    map_piece 166, 0, 0, 34, 19, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 38, 0, 0
map_090_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 54, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 55, 0, 0
map_091_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 60, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 61, 0, 0
map_092_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 360, 0, 0
    map_piece 0, 0, 15, 360, 24, 0
    map_piece 0, 0, 15, 360, 0, 28
    map_piece 0, 0, 15, 360, 24, 28
    map_piece 0, 0, 15, 360, 0, 56
    map_piece 0, 0, 15, 360, 24, 56
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 358, 0, 0
map_093_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 433, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 434, 0, 0
map_094_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 558, 0, 0
    map_piece 0, 0, 15, 554, 25, 21
    map_piece 0, 0, 15, 554, 32, 21
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 559, 0, 0
    map_piece 0, 0, 15, 560, 48, 44
    map_piece 0, 0, 15, 560, 39, 50
    map_piece 0, 0, 15, 560, 12, 32
    map_piece 0, 0, 15, 560, 52, 9
    map_piece 0, 0, 15, 555, 25, 21
    map_piece 0, 0, 15, 555, 32, 21
map_095_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 646, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 647, 0, 0
map_096_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 512, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 516, 0, 0
    map_piece 0, 0, 15, 515, 0, 20
    map_piece 0, 0, 15, 515, 14, 20
    map_piece 0, 0, 15, 515, 28, 20
    map_piece 0, 0, 15, 515, 42, 20
    map_piece 0, 0, 15, 514, 0, 33
map_097_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 165, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 166, 0, 0
map_098_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 75, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 76, 0, 0
map_099_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 28, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 29, 0, 0
map_09B_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_09C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_09D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_09E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_09F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_0A0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 209, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 210, 0, 0
map_0A1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 211, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 212, 0, 0
map_0A2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 213, 0, 0
    map_piece 0, 0, 15, 213, 30, 0
    map_piece 0, 0, 15, 213, 60, 0
    map_piece 0, 0, 15, 213, 90, 0
    map_piece 0, 0, 15, 213, 0, 30
    map_piece 0, 0, 15, 213, 30, 30
    map_piece 0, 0, 15, 213, 60, 30
    map_piece 0, 0, 15, 213, 90, 30
    map_piece 0, 0, 15, 213, 0, 60
    map_piece 0, 0, 15, 213, 30, 60
    map_piece 0, 0, 15, 213, 60, 60
    map_piece 0, 0, 15, 213, 90, 60
    map_piece 0, 0, 15, 213, 0, 90
    map_piece 0, 0, 15, 213, 30, 90
    map_piece 0, 0, 15, 213, 60, 90
    map_piece 0, 0, 15, 213, 90, 90
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 214, 0, 0
    map_piece 0, 0, 15, 215, 34, 13
    map_piece 0, 0, 15, 216, 19, 13
    map_piece 0, 0, 15, 222, 6, 23
map_0A3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 213, 0, 0
    map_piece 0, 0, 15, 213, 30, 0
    map_piece 0, 0, 15, 213, 60, 0
    map_piece 0, 0, 15, 213, 90, 0
    map_piece 0, 0, 15, 213, 0, 30
    map_piece 0, 0, 15, 213, 30, 30
    map_piece 0, 0, 15, 213, 60, 30
    map_piece 0, 0, 15, 213, 90, 30
    map_piece 0, 0, 15, 213, 0, 60
    map_piece 0, 0, 15, 213, 30, 60
    map_piece 0, 0, 15, 213, 60, 60
    map_piece 0, 0, 15, 213, 90, 60
    map_piece 0, 0, 15, 213, 0, 90
    map_piece 0, 0, 15, 213, 30, 90
    map_piece 0, 0, 15, 213, 60, 90
    map_piece 0, 0, 15, 213, 90, 90
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 217, 0, 0
    map_piece 0, 0, 15, 215, 46, 27
    map_piece 0, 0, 15, 216, 16, 12
    map_piece 0, 0, 15, 216, 31, 27
    map_piece 0, 0, 15, 222, 7, 22
map_0A4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 213, 0, 0
    map_piece 0, 0, 15, 213, 30, 0
    map_piece 0, 0, 15, 213, 60, 0
    map_piece 0, 0, 15, 213, 90, 0
    map_piece 0, 0, 15, 213, 0, 30
    map_piece 0, 0, 15, 213, 30, 30
    map_piece 0, 0, 15, 213, 60, 30
    map_piece 0, 0, 15, 213, 90, 30
    map_piece 0, 0, 15, 213, 0, 60
    map_piece 0, 0, 15, 213, 30, 60
    map_piece 0, 0, 15, 213, 60, 60
    map_piece 0, 0, 15, 213, 90, 60
    map_piece 0, 0, 15, 213, 0, 90
    map_piece 0, 0, 15, 213, 30, 90
    map_piece 0, 0, 15, 213, 60, 90
    map_piece 0, 0, 15, 213, 90, 90
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 218, 0, 0
    map_piece 0, 0, 15, 220, 13, 8
    map_piece 26, 0, 4, 219, 17, 10
    map_piece 26, 6, 15, 219, 17, 10
map_0A5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 137, 0, 0
    map_piece 0, 0, 15, 229, 11, 21
    map_piece 0, 0, 15, 227, 13, 11
    map_piece 0, 0, 15, 226, 41, 10
    map_piece 0, 0, 15, 229, 11, 53
    map_piece 0, 0, 15, 227, 13, 43
    map_piece 0, 0, 15, 228, 42, 43
    map_piece 0, 0, 15, 229, 43, 53
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 225, 0, 0
    map_piece 0, 0, 15, 230, 9, 10
    map_piece 0, 0, 15, 225, 32, 0
    map_piece 0, 0, 15, 231, 41, 10
    map_piece 0, 0, 15, 225, 0, 32
    map_piece 0, 0, 15, 230, 9, 42
    map_piece 0, 0, 15, 225, 32, 32
    map_piece 0, 0, 15, 255, 47, 28
    map_piece 0, 0, 15, 255, 47, 60
    map_piece 0, 0, 15, 255, 15, 28
    map_piece 0, 0, 15, 255, 15, 60
map_0A6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 221, 0, 0
map_0A7_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 213, 0, 0
    map_piece 0, 0, 15, 213, 30, 0
    map_piece 0, 0, 15, 213, 60, 0
    map_piece 0, 0, 15, 213, 90, 0
    map_piece 0, 0, 15, 213, 0, 30
    map_piece 0, 0, 15, 213, 30, 30
    map_piece 0, 0, 15, 213, 60, 30
    map_piece 0, 0, 15, 213, 90, 30
    map_piece 0, 0, 15, 213, 0, 60
    map_piece 0, 0, 15, 213, 30, 60
    map_piece 0, 0, 15, 213, 60, 60
    map_piece 0, 0, 15, 213, 90, 60
    map_piece 0, 0, 15, 213, 0, 90
    map_piece 0, 0, 15, 213, 30, 90
    map_piece 0, 0, 15, 213, 60, 90
    map_piece 0, 0, 15, 213, 90, 90
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 218, 0, 0
    map_piece 0, 0, 15, 220, 13, 8
    map_piece 26, 0, 4, 219, 17, 10
    map_piece 26, 6, 15, 219, 17, 10
map_0A8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 77, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 78, 0, 0
map_0AA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 882, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 883, 0, 0
map_0AB_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 26, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 27, 0, 0
map_0B0_piece_list:
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
map_0B1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 835, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 836, 0, 4
    map_piece 0, 0, 15, 872, 12, 4
map_0B2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 901, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 902, 0, 0
map_0B3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 769, 0, 16
map_0B4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 897, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 898, 0, 0
map_0C2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 899, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 900, 0, 0
map_0C3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 855, 0, 0
    map_piece 2, 0, 1, 853, 0, 0
    map_piece 2, 2, 2, 861, 38, 59
    map_piece 2, 2, 2, 861, 29, 66
    map_piece 2, 2, 2, 861, 20, 59
    map_piece 2, 2, 2, 861, 38, 73
    map_piece 2, 2, 2, 861, 20, 73
    map_piece 2, 2, 2, 861, 29, 80
    map_piece 2, 2, 2, 862, 38, 87
    map_piece 2, 2, 2, 862, 20, 87
    map_piece 2, 2, 2, 857, 26, 59
    map_piece 2, 2, 2, 857, 34, 59
    map_piece 2, 2, 2, 857, 38, 66
    map_piece 2, 2, 2, 857, 22, 66
    map_piece 2, 2, 2, 857, 26, 73
    map_piece 2, 2, 2, 857, 34, 73
    map_piece 2, 2, 2, 857, 38, 80
    map_piece 2, 2, 2, 857, 22, 80
    map_piece 2, 2, 2, 857, 26, 87
    map_piece 2, 2, 2, 857, 34, 87
    map_piece 2, 2, 2, 858, 30, 59
    map_piece 2, 2, 2, 858, 18, 66
    map_piece 2, 2, 2, 858, 26, 66
    map_piece 2, 2, 2, 858, 34, 66
    map_piece 2, 2, 2, 858, 42, 66
    map_piece 2, 2, 2, 858, 30, 73
    map_piece 2, 2, 2, 858, 18, 80
    map_piece 2, 2, 2, 858, 26, 80
    map_piece 2, 2, 2, 858, 34, 80
    map_piece 2, 2, 2, 858, 42, 80
    map_piece 2, 2, 2, 859, 18, 59
    map_piece 2, 2, 2, 859, 16, 64
    map_piece 2, 2, 2, 859, 16, 71
    map_piece 2, 2, 2, 859, 18, 73
    map_piece 2, 2, 2, 859, 16, 78
    map_piece 2, 2, 2, 859, 18, 87
    map_piece 2, 2, 2, 859, 16, 85
    map_piece 2, 2, 2, 860, 44, 87
    map_piece 2, 2, 2, 860, 46, 85
    map_piece 2, 2, 2, 860, 46, 78
    map_piece 2, 2, 2, 860, 44, 73
    map_piece 2, 2, 2, 860, 46, 71
    map_piece 2, 2, 2, 860, 46, 64
    map_piece 2, 2, 2, 860, 44, 59
    map_piece 71, 3, 15, 726, 36, 93
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 856, 0, 0
    map_piece 2, 0, 1, 854, 0, 0
    map_piece 71, 3, 15, 727, 36, 93
map_0C4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 165, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 166, 0, 0
map_0C5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 899, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 900, 0, 0
map_0C6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 70, 0, 7, 837, 0, 0
    map_piece 70, 0, 7, 828, 21, 27
    map_piece 70, 0, 7, 829, 18, 31
    map_piece 70, 8, 15, 896, 0, 0
    map_piece 70, 8, 15, 896, 0, 30
    map_piece 70, 8, 15, 896, 0, 60
    map_piece 70, 8, 15, 896, 0, 90
    map_piece 70, 8, 15, 896, 30, 0
    map_piece 70, 8, 15, 896, 30, 30
    map_piece 70, 8, 15, 896, 30, 60
    map_piece 70, 8, 15, 896, 30, 90
    map_piece 70, 8, 15, 896, 60, 0
    map_piece 70, 8, 15, 896, 60, 30
    map_piece 70, 8, 15, 896, 60, 60
    map_piece 70, 8, 15, 896, 60, 90
    map_piece 70, 8, 15, 896, 90, 0
    map_piece 70, 8, 15, 896, 90, 30
    map_piece 70, 8, 15, 896, 90, 60
    map_piece 70, 8, 15, 896, 90, 90
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 70, 0, 7, 838, 0, 0
map_0C7_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 819, 0, 0
    map_piece 0, 0, 15, 812, 7, 17
    map_piece 0, 0, 15, 813, 16, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 820, 0, 0
map_0C8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 833, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 834, 0, 0
map_0C9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 821, 0, 0
    map_piece 0, 0, 15, 814, 17, 21
    map_piece 0, 0, 15, 816, 6, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 822, 0, 0
map_0CA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 799, 0, 0
    map_piece 0, 0, 15, 788, 22, 14
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 800, 0, 0
map_0CB_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 831, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 832, 0, 0
map_0CC_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 877, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 878, 0, 0
map_0CD_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 837, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 838, 0, 0
map_0CE_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 805, 0, 0
    map_piece 0, 0, 15, 793, 13, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 806, 0, 0
    map_piece 0, 0, 15, 794, 16, 18
map_0CF_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 797, 0, 0
    map_piece 0, 0, 15, 785, 18, 36
    map_piece 0, 0, 15, 786, 27, 30
    map_piece 0, 0, 15, 787, 17, 25
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 798, 0, 0
map_0D0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 819, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 820, 0, 0
map_0D1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 821, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 822, 0, 0
map_0D2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 833, 0, 0
    map_piece 0, 0, 15, 825, 14, 13
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 834, 0, 0
map_0D3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 780, 0, 0
    map_piece 0, 0, 15, 782, 16, 18
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 781, 0, 0
map_0D4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 848, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 849, 0, 0
map_0D5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 779, 0, 0
    map_piece 70, 3, 15, 810, 14, 20
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_0D6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 781, 0, 0
    map_piece 0, 0, 15, 782, 9, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 781, 0, 0
    map_piece 0, 0, 15, 782, 9, 19
map_0D7_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 823, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 824, 0, 0
map_0D8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 803, 0, 0
    map_piece 0, 0, 15, 790, 16, 24
    map_piece 0, 0, 15, 791, 24, 24
    map_piece 0, 0, 15, 792, 14, 19
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 804, 0, 0
map_0D9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 797, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 798, 0, 0
map_0DA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 799, 0, 0
    map_piece 0, 0, 15, 789, 11, 18
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 800, 0, 0
map_0DB_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 801, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 802, 0, 0
map_0DC_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 821, 0, 0
    map_piece 0, 0, 15, 816, 6, 15
    map_piece 0, 0, 15, 817, 22, 19
    map_piece 0, 0, 15, 818, 6, 6
    map_piece 0, 0, 15, 842, 15, 27
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 822, 0, 0
map_0DD_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 805, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 806, 0, 0
map_0DE_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 359, 0, 0
    map_piece 0, 0, 15, 360, 0, 0
    map_piece 0, 0, 15, 360, 24, 0
    map_piece 0, 0, 15, 360, 0, 28
    map_piece 0, 0, 15, 360, 24, 28
    map_piece 0, 0, 15, 360, 0, 56
    map_piece 0, 0, 15, 360, 24, 56
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 359, 0, 0
map_0DF_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 360, 0, 0
    map_piece 0, 0, 15, 360, 24, 0
    map_piece 0, 0, 15, 360, 0, 28
    map_piece 0, 0, 15, 360, 24, 28
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 356, 0, 0
map_0E0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 360, 0, 0
    map_piece 0, 0, 15, 360, 24, 0
    map_piece 0, 0, 15, 360, 0, 28
    map_piece 0, 0, 15, 360, 24, 28
    map_piece 0, 0, 15, 360, 0, 56
    map_piece 0, 0, 15, 360, 24, 56
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 358, 0, 0
map_0E1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 819, 0, 0
    map_piece 0, 0, 15, 809, 21, 22
    map_piece 0, 0, 15, 871, 17, 29
    map_piece 0, 0, 15, 811, 10, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 820, 0, 0
map_0E2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 807, 0, 0
    map_piece 70, 5, 15, 795, 23, 27
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 808, 0, 0
map_0E3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 803, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 804, 0, 0
map_0E4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 429, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 430, 0, 0
map_0E5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 837, 0, 0
    map_piece 0, 0, 15, 826, 13, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 838, 0, 0
map_0E6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 852, 0, 0
map_0E7_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 851, 0, 0
map_0E8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 850, 0, 0
map_0E9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 846, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 847, 0, 0
map_0EA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 846, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 847, 0, 0
map_0EB_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 846, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 847, 0, 0
map_0EC_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 768, 0, 0
    map_piece 0, 0, 15, 768, 0, 1
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 769, 0, 2
map_0ED_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 835, 0, 0
    map_piece 0, 0, 15, 681, 5, 9
    map_piece 0, 0, 15, 681, 29, 9
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 836, 0, 0
    map_piece 0, 0, 15, 872, 12, 0
map_0EE_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 876, 0, 0
map_0F0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 693, 0, 0
    map_piece 0, 0, 15, 709, 7, 14
    map_piece 0, 0, 15, 709, 11, 14
    map_piece 0, 0, 15, 709, 15, 14
    map_piece 0, 0, 15, 709, 19, 14
    map_piece 0, 0, 15, 709, 23, 14
    map_piece 0, 0, 15, 709, 23, 19
    map_piece 0, 0, 15, 709, 7, 19
    map_piece 0, 0, 15, 709, 11, 19
    map_piece 0, 0, 15, 709, 19, 19
    map_piece 0, 0, 15, 709, 7, 24
    map_piece 0, 0, 15, 709, 11, 24
    map_piece 0, 0, 15, 709, 19, 24
    map_piece 0, 0, 15, 709, 23, 24
    map_piece 43, 3, 3, 696, 7, 14
    map_piece 43, 3, 3, 696, 11, 14
    map_piece 43, 3, 3, 696, 15, 14
    map_piece 43, 3, 3, 696, 19, 14
    map_piece 43, 3, 3, 696, 23, 14
    map_piece 43, 3, 3, 696, 23, 19
    map_piece 43, 3, 3, 696, 7, 19
    map_piece 43, 3, 3, 696, 11, 19
    map_piece 43, 3, 3, 696, 19, 19
    map_piece 43, 3, 3, 696, 7, 24
    map_piece 43, 3, 3, 696, 11, 24
    map_piece 43, 3, 15, 696, 19, 24
    map_piece 43, 3, 15, 696, 23, 24
    map_piece 43, 0, 3, 698, 36, 26
    map_piece 43, 4, 15, 698, 21, 26
    map_piece 43, 3, 4, 416, 15, 23
    map_piece 43, 5, 15, 416, 36, 23
    map_piece 43, 5, 15, 699, 14, 22
    map_piece 43, 8, 15, 703, 14, 21
    map_piece 43, 9, 15, 704, 14, 18
    map_piece 43, 10, 15, 706, 14, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 694, 0, 0
    map_piece 43, 5, 15, 700, 14, 18
    map_piece 43, 6, 15, 701, 14, 20
    map_piece 43, 7, 15, 702, 14, 22
    map_piece 43, 9, 15, 705, 15, 22
    map_piece 43, 10, 15, 707, 14, 19
map_0F1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 710, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 717, 0, 0
