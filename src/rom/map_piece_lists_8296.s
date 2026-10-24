; Bounded native map piece lists; docs/map-piece-list-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8296
.macro map_piece flag_index, flag_min, flag_max, piece_id, tile_x, tile_y
    .byte flag_index, (flag_min << 4) | flag_max, piece_id & $FF
    .byte (tile_x << 1) | ((piece_id >> 8) & 1)
    .byte (tile_y << 1) | ((piece_id >> 9) & 1)
.endmacro
map_190_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    map_piece 0, 0, 15, 529, 6, 6
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 534, 6, 6
    map_piece 0, 0, 15, 617, 7, 62
    map_piece 0, 0, 15, 613, 40, 62
map_191_piece_list:
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
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 612, 67, 7
    map_piece 0, 0, 15, 612, 67, 35
    map_piece 0, 0, 15, 613, 38, 35
    map_piece 0, 0, 15, 617, 7, 7
    map_piece 0, 0, 15, 613, 7, 35
    map_piece 0, 0, 15, 593, 7, 69
map_192_piece_list:
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
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 528, 51, 7
    map_piece 0, 0, 15, 527, 7, 7
map_193_piece_list:
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
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 589, 32, 7
    map_piece 0, 0, 15, 592, 7, 7
    map_piece 0, 0, 15, 595, 7, 31
    map_piece 0, 0, 15, 616, 90, 70
    map_piece 0, 0, 15, 612, 89, 7
    map_piece 0, 0, 15, 594, 61, 61
    map_piece 0, 0, 15, 618, 7, 84
    map_piece 45, 0, 1, 614, 48, 49
    map_piece 45, 2, 15, 614, 31, 49
    map_piece 45, 1, 15, 615, 10, 39
    map_piece 45, 1, 15, 621, 33, 56
map_194_piece_list:
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
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 617, 32, 7
    map_piece 0, 0, 15, 526, 7, 38
    map_piece 45, 3, 15, 596, 21, 52
map_195_piece_list:
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
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 528, 51, 7
    map_piece 0, 0, 15, 527, 7, 7
map_196_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 611, 0, 0
    map_piece 0, 0, 15, 589, 7, 7
    map_piece 0, 0, 15, 589, 51, 7
    map_piece 0, 0, 15, 590, 7, 32
    map_piece 0, 0, 15, 612, 28, 32
    map_piece 0, 0, 15, 612, 51, 32
    map_piece 0, 0, 15, 590, 72, 32
map_197_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 619, 0, 0
map_198_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 213, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 620, 0, 0
map_199_piece_list:
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
map_19A_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 233, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 619, 0, 0
map_19C_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 667, 0, 0
    map_piece 0, 0, 15, 238, 19, 55
    map_piece 0, 0, 15, 238, 29, 55
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 668, 0, 0
map_19D_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 669, 0, 0
    map_piece 0, 0, 15, 238, 17, 12
    map_piece 0, 0, 15, 238, 23, 12
    map_piece 0, 0, 15, 135, 9, 15
    map_piece 0, 0, 15, 135, 31, 15
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 670, 0, 0
map_19E_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 671, 0, 0
    map_piece 0, 0, 15, 238, 19, 11
    map_piece 0, 0, 15, 238, 25, 11
    map_piece 0, 0, 15, 135, 12, 19
    map_piece 0, 0, 15, 135, 32, 19
    map_piece 232, 1, 15, 660, 12, 23
    map_piece 233, 1, 15, 660, 32, 23
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 672, 0, 0
    map_piece 232, 1, 15, 661, 12, 23
    map_piece 233, 1, 15, 661, 32, 23
map_19F_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 673, 0, 0
    map_piece 0, 0, 15, 135, 8, 46
    map_piece 0, 0, 15, 135, 40, 46
    map_piece 234, 1, 15, 714, 12, 50
    map_piece 235, 1, 15, 714, 36, 50
    map_piece 72, 1, 15, 677, 24, 24
    map_piece 72, 1, 15, 677, 24, 25
    map_piece 72, 1, 15, 675, 21, 24
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 674, 0, 0
    map_piece 234, 1, 15, 715, 12, 50
    map_piece 235, 1, 15, 715, 36, 50
map_1A0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 678, 0, 0
    map_piece 236, 0, 0, 680, 9, 14
    map_piece 237, 0, 0, 680, 37, 14
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 679, 0, 0
map_1A1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 682, 0, 0
    map_piece 0, 0, 15, 238, 32, 30
    map_piece 0, 0, 15, 238, 14, 30
    map_piece 0, 0, 15, 135, 10, 34
    map_piece 238, 0, 0, 716, 29, 34
    map_piece 72, 2, 15, 684, 13, 19
    map_piece 72, 2, 15, 552, 14, 12
    map_piece 72, 3, 15, 685, 18, 22
    map_piece 72, 3, 15, 552, 18, 20
    map_piece 73, 2, 15, 684, 32, 19
    map_piece 73, 2, 15, 552, 33, 12
    map_piece 73, 3, 15, 685, 28, 22
    map_piece 73, 3, 15, 552, 29, 20
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 683, 0, 0
    map_piece 72, 3, 15, 686, 18, 22
    map_piece 73, 3, 15, 686, 28, 22
map_1A2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 130, 0, 0
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 17, 7
    map_piece 0, 0, 15, 234, 20, 9
    map_piece 0, 0, 15, 234, 9, 9
    map_piece 68, 0, 5, 138, 14, 6
    map_piece 0, 0, 15, 692, 13, 27
    map_piece 68, 0, 5, 130, 0, 29
    map_piece 0, 0, 15, 130, 0, 31
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 131, 0, 0
    map_piece 68, 0, 5, 139, 14, 6
map_1A3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 676, 15, 8
    map_piece 0, 0, 15, 689, 13, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 17, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A5_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 10, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A6_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 17, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A7_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 10, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 17, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1A9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 10, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1AA_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 663, 0, 0
    map_piece 0, 0, 15, 662, 17, 26
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 664, 0, 0
map_1AC_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 543, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 544, 0, 0
map_1AE_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 687, 0, 0
    map_piece 0, 0, 15, 689, 22, 40
    map_piece 74, 1, 15, 690, 14, 30
    map_piece 75, 1, 15, 690, 23, 30
    map_piece 76, 1, 15, 690, 32, 30
    map_piece 73, 4, 15, 416, 31, 38
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 688, 0, 0
    map_piece 74, 1, 15, 691, 14, 30
    map_piece 75, 1, 15, 691, 23, 30
    map_piece 76, 1, 15, 691, 32, 30
map_1AF_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 249, 0, 0
    map_piece 68, 2, 8, 665, 13, 4
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 250, 0, 0
    map_piece 68, 2, 8, 666, 13, 4
map_1B0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 772, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 773, 0, 0
map_1B1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 770, 0, 0
    map_piece 64, 1, 15, 736, 45, 7
    map_piece 64, 2, 15, 736, 17, 10
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 771, 0, 0
    map_piece 64, 1, 15, 737, 44, 13
    map_piece 64, 2, 15, 738, 16, 18
map_1B2_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 774, 0, 0
    map_piece 64, 3, 15, 739, 13, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 775, 0, 0
    map_piece 64, 3, 15, 740, 13, 16
map_1B3_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 774, 0, 0
    map_piece 0, 0, 15, 739, 13, 16
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 775, 0, 0
    map_piece 0, 0, 15, 740, 13, 16
map_1B4_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 772, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 773, 0, 0
map_1BC_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 852, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_1BD_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 851, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_1BE_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 850, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 233, 0, 0
map_1C0_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 644, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 645, 0, 0
map_1C1_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 367, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 368, 0, 0
