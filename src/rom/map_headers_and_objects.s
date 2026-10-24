; Typed map headers and eight-byte objects; docs/map-header-object-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9000
.macro map_header graphics_set, graphics_flags, palette_set, palette_flag, tile_set, tile_flags, trigger_adjust, entry_event, map_flags, transition_zone, transition_flags, screen_set, screen_flags, field_94, object_palette
    .byte graphics_set | (graphics_flags << 6), palette_set | (palette_flag << 7)
    .byte tile_set | (tile_flags << 6), trigger_adjust | (entry_event << 2) | (map_flags << 3)
    .byte transition_zone | (transition_flags << 5), screen_set | (screen_flags << 6)
    .byte field_94, object_palette
.endmacro
.macro map_object flag_index, flag_min, flag_max, tile_x, x_high, tile_y, y_high, facing, palette_layer, foreground, kind, identity, event_word
    .byte flag_index, (flag_min << 4) | flag_max
    .byte tile_x | (x_high << 7), tile_y | (y_high << 7)
    .byte (facing << 6) | (palette_layer << 4) | (foreground << 3) | kind, identity
    .word event_word
.endmacro
map_headers_and_objects:
map_008_header:
    map_header 4, 0, 28, 0, 4, 3, 0, 1, 0, 0, 0, 0, 0, 0, 13
map_00E_header:
    map_header 0, 0, 24, 0, 0, 2, 0, 0, 0, 3, 7, 4, 0, 0, 255
map_00F_header:
    map_header 0, 0, 24, 0, 0, 2, 0, 1, 0, 0, 7, 0, 0, 0, 12
map_00F_object_00:
    map_object 0, 0, 15, 34, 0, 22, 1, 1, 0, 0, 0, 189, 17408
map_00F_object_01:
    map_object 0, 0, 15, 38, 0, 22, 1, 2, 1, 0, 0, 192, 5121
map_00F_object_02:
    map_object 0, 0, 15, 42, 0, 22, 1, 0, 0, 0, 0, 193, 9218
map_00F_object_03:
    map_object 0, 0, 15, 46, 0, 22, 1, 3, 1, 0, 0, 174, 13315
map_00F_object_04:
    map_object 0, 0, 15, 34, 0, 30, 1, 1, 0, 0, 0, 182, 21508
map_00F_object_05:
    map_object 0, 0, 15, 38, 0, 30, 1, 2, 1, 0, 0, 183, 21509
map_00F_object_06:
    map_object 13, 0, 0, 42, 1, 30, 0, 1, 2, 0, 0, 139, 49294
map_00F_object_07:
    map_object 14, 0, 0, 46, 1, 30, 0, 1, 3, 0, 0, 140, 49295
map_00F_object_08:
    map_object 0, 0, 15, 60, 0, 31, 1, 1, 0, 0, 0, 238, 32768
map_010_header:
    map_header 1, 3, 25, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_010_object_00:
    map_object 10, 2, 2, 10, 1, 55, 1, 0, 0, 0, 0, 139, 16384
map_010_object_01:
    map_object 10, 1, 1, 10, 1, 53, 1, 0, 0, 0, 0, 6, 16384
map_010_object_02:
    map_object 10, 1, 1, 10, 1, 54, 1, 0, 0, 0, 0, 6, 16384
map_010_object_03:
    map_object 10, 0, 0, 29, 1, 85, 1, 1, 0, 0, 0, 211, 14073
map_010_object_04:
    map_object 10, 0, 0, 51, 0, 33, 0, 1, 0, 0, 0, 0, 49153
map_010_object_05:
    map_object 10, 0, 0, 50, 0, 53, 0, 1, 0, 0, 0, 0, 49153
map_010_object_06:
    map_object 10, 0, 0, 23, 0, 29, 0, 1, 0, 0, 0, 0, 49153
map_010_object_07:
    map_object 10, 0, 0, 45, 0, 54, 0, 1, 0, 0, 0, 4, 49153
map_010_object_08:
    map_object 10, 0, 0, 9, 0, 52, 0, 1, 0, 0, 0, 4, 49153
map_010_object_09:
    map_object 10, 0, 0, 16, 0, 34, 0, 1, 0, 0, 0, 4, 49153
map_010_object_10:
    map_object 10, 0, 0, 15, 0, 39, 0, 1, 0, 0, 0, 4, 49153
map_010_object_11:
    map_object 10, 0, 0, 35, 0, 63, 0, 1, 0, 0, 0, 4, 49153
map_010_object_12:
    map_object 10, 0, 0, 50, 0, 72, 0, 1, 0, 0, 0, 4, 49153
map_010_object_13:
    map_object 10, 0, 0, 32, 0, 99, 0, 1, 0, 0, 0, 4, 49153
map_010_object_14:
    map_object 10, 0, 0, 31, 0, 71, 0, 1, 0, 0, 0, 0, 49153
map_010_object_15:
    map_object 10, 0, 0, 55, 0, 76, 0, 1, 0, 0, 0, 0, 49153
map_010_object_16:
    map_object 10, 0, 0, 51, 0, 88, 0, 1, 0, 0, 0, 0, 49153
map_010_object_17:
    map_object 10, 0, 0, 28, 0, 53, 0, 1, 0, 0, 0, 2, 49153
map_010_object_18:
    map_object 10, 0, 0, 25, 0, 92, 0, 1, 0, 0, 0, 2, 49153
map_010_object_19:
    map_object 10, 0, 0, 10, 0, 88, 0, 1, 0, 0, 0, 2, 49153
map_010_object_20:
    map_object 10, 0, 0, 42, 0, 100, 0, 1, 0, 0, 0, 2, 49153
map_010_object_21:
    map_object 10, 0, 0, 24, 0, 100, 0, 1, 0, 0, 0, 2, 49153
map_011_header:
    map_header 10, 0, 34, 1, 10, 2, 1, 0, 0, 0, 3, 0, 0, 0, 255
map_011_object_00:
    map_object 0, 0, 15, 21, 0, 34, 0, 1, 0, 0, 0, 66, 49153
map_011_object_01:
    map_object 0, 0, 15, 46, 0, 28, 0, 1, 0, 0, 0, 66, 49153
map_011_object_02:
    map_object 0, 0, 15, 49, 0, 30, 0, 1, 0, 0, 0, 66, 49153
map_011_object_03:
    map_object 0, 0, 15, 76, 0, 37, 0, 1, 0, 0, 0, 66, 49153
map_011_object_04:
    map_object 0, 0, 15, 81, 0, 31, 0, 1, 0, 0, 0, 66, 49153
map_011_object_05:
    map_object 0, 0, 15, 105, 0, 32, 0, 1, 0, 0, 0, 66, 49153
map_011_object_06:
    map_object 0, 0, 15, 100, 0, 13, 0, 1, 0, 0, 0, 66, 49153
map_011_object_07:
    map_object 0, 0, 15, 86, 0, 15, 0, 1, 0, 0, 0, 66, 49153
map_011_object_08:
    map_object 0, 0, 15, 83, 0, 16, 0, 1, 0, 0, 0, 66, 49153
map_011_object_09:
    map_object 0, 0, 15, 74, 0, 14, 0, 1, 0, 0, 0, 66, 49153
map_011_object_10:
    map_object 0, 0, 15, 38, 0, 8, 0, 1, 0, 0, 0, 66, 49153
map_011_object_11:
    map_object 0, 0, 15, 16, 0, 19, 0, 1, 0, 0, 0, 66, 49153
map_011_object_12:
    map_object 0, 0, 15, 57, 0, 36, 0, 1, 0, 0, 0, 79, 49153
map_011_object_13:
    map_object 0, 0, 15, 71, 0, 23, 0, 1, 0, 0, 0, 79, 49153
map_011_object_14:
    map_object 0, 0, 15, 117, 0, 32, 0, 1, 0, 0, 0, 79, 49153
map_011_object_15:
    map_object 0, 0, 15, 113, 0, 28, 0, 1, 0, 0, 0, 79, 49153
map_011_object_16:
    map_object 0, 0, 15, 119, 0, 23, 0, 1, 0, 0, 0, 79, 49153
map_011_object_17:
    map_object 0, 0, 15, 106, 0, 9, 0, 1, 0, 0, 0, 79, 49153
map_011_object_18:
    map_object 0, 0, 15, 93, 0, 22, 0, 1, 0, 0, 0, 79, 49153
map_011_object_19:
    map_object 0, 0, 15, 65, 0, 9, 0, 1, 0, 0, 0, 79, 49153
map_011_object_20:
    map_object 0, 0, 15, 62, 0, 17, 0, 1, 0, 0, 0, 79, 49153
map_011_object_21:
    map_object 0, 0, 15, 17, 0, 12, 0, 1, 0, 0, 0, 79, 49153
map_011_object_22:
    map_object 0, 0, 15, 78, 0, 28, 0, 1, 0, 0, 0, 57, 49153
map_011_object_23:
    map_object 0, 0, 15, 100, 0, 26, 0, 1, 0, 0, 0, 57, 49153
map_011_object_24:
    map_object 0, 0, 15, 103, 0, 19, 0, 1, 0, 0, 0, 57, 49153
map_011_object_25:
    map_object 0, 0, 15, 28, 0, 8, 0, 1, 0, 0, 0, 57, 49153
map_012_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 1, 0, 0, 3, 0, 0, 0, 255
map_012_object_00:
    map_object 63, 0, 15, 19, 1, 13, 1, 1, 0, 0, 0, 163, 17373
map_012_object_01:
    map_object 63, 1, 4, 20, 1, 11, 1, 0, 0, 0, 0, 162, 17372
map_013_header:
    map_header 1, 3, 25, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 18
map_013_object_00:
    map_object 17, 0, 1, 29, 1, 29, 1, 1, 0, 0, 0, 172, 16672
map_013_object_01:
    map_object 17, 0, 1, 26, 1, 32, 1, 0, 1, 0, 0, 183, 16673
map_013_object_02:
    map_object 17, 0, 1, 28, 1, 32, 1, 0, 1, 0, 0, 183, 16674
map_013_object_03:
    map_object 17, 0, 1, 30, 1, 32, 1, 0, 1, 0, 0, 183, 16673
map_013_object_04:
    map_object 17, 0, 1, 32, 1, 32, 1, 0, 1, 0, 0, 183, 16674
map_014_header:
    map_header 23, 3, 100, 1, 23, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_014_object_00:
    map_object 0, 0, 15, 57, 0, 60, 0, 1, 0, 0, 0, 5, 49153
map_014_object_01:
    map_object 0, 0, 15, 54, 0, 61, 0, 1, 0, 0, 0, 5, 49153
map_014_object_02:
    map_object 0, 0, 15, 53, 0, 54, 0, 1, 0, 0, 0, 44, 49153
map_014_object_03:
    map_object 0, 0, 15, 35, 0, 61, 0, 1, 0, 0, 0, 44, 49153
map_014_object_04:
    map_object 0, 0, 15, 31, 0, 52, 0, 1, 0, 0, 0, 44, 49153
map_014_object_05:
    map_object 0, 0, 15, 13, 0, 56, 0, 1, 0, 0, 0, 44, 49153
map_014_object_06:
    map_object 0, 0, 15, 15, 0, 63, 0, 1, 0, 0, 0, 44, 49153
map_014_object_07:
    map_object 0, 0, 15, 63, 0, 19, 0, 1, 0, 0, 0, 44, 49153
map_014_object_08:
    map_object 0, 0, 15, 62, 0, 18, 0, 1, 0, 0, 0, 44, 49153
map_014_object_09:
    map_object 0, 0, 15, 44, 0, 25, 0, 1, 0, 0, 0, 44, 49153
map_014_object_10:
    map_object 0, 0, 15, 42, 0, 20, 0, 1, 0, 0, 0, 44, 49153
map_014_object_11:
    map_object 0, 0, 15, 39, 0, 16, 0, 1, 0, 0, 0, 44, 49153
map_014_object_12:
    map_object 0, 0, 15, 22, 0, 26, 0, 1, 0, 0, 0, 44, 49153
map_014_object_13:
    map_object 0, 0, 15, 12, 0, 29, 0, 1, 0, 0, 0, 44, 49153
map_014_object_14:
    map_object 0, 0, 15, 53, 0, 45, 0, 1, 0, 0, 0, 56, 49153
map_014_object_15:
    map_object 0, 0, 15, 51, 0, 46, 0, 1, 0, 0, 0, 56, 49153
map_014_object_16:
    map_object 0, 0, 15, 59, 0, 54, 0, 1, 0, 0, 0, 56, 49153
map_014_object_17:
    map_object 0, 0, 15, 36, 0, 56, 0, 1, 0, 0, 0, 56, 49153
map_014_object_18:
    map_object 0, 0, 15, 32, 0, 49, 0, 1, 0, 0, 0, 56, 49153
map_014_object_19:
    map_object 0, 0, 15, 15, 0, 49, 0, 1, 0, 0, 0, 56, 49153
map_014_object_20:
    map_object 0, 0, 15, 10, 0, 46, 0, 1, 0, 0, 0, 56, 49153
map_014_object_21:
    map_object 0, 0, 15, 63, 0, 30, 0, 1, 0, 0, 0, 56, 49153
map_014_object_22:
    map_object 0, 0, 15, 56, 0, 15, 0, 1, 0, 0, 0, 56, 49153
map_014_object_23:
    map_object 0, 0, 15, 33, 0, 15, 0, 1, 0, 0, 0, 56, 49153
map_014_object_24:
    map_object 0, 0, 15, 19, 0, 11, 0, 1, 0, 0, 0, 56, 49153
map_014_object_25:
    map_object 0, 0, 15, 22, 0, 16, 0, 1, 0, 0, 0, 56, 49153
map_014_object_26:
    map_object 0, 0, 15, 12, 0, 29, 0, 1, 0, 0, 0, 56, 49153
map_014_object_27:
    map_object 0, 0, 15, 36, 0, 47, 0, 1, 0, 0, 0, 37, 49153
map_014_object_28:
    map_object 0, 0, 15, 55, 0, 30, 0, 1, 0, 0, 0, 37, 49153
map_014_object_29:
    map_object 0, 0, 15, 17, 0, 27, 0, 1, 0, 0, 0, 37, 49153
map_014_object_30:
    map_object 0, 0, 15, 62, 0, 13, 0, 1, 0, 0, 0, 56, 49153
map_015_header:
    map_header 8, 2, 78, 0, 8, 2, 0, 1, 0, 0, 4, 0, 0, 0, 255
map_015_object_00:
    map_object 58, 0, 1, 22, 1, 43, 1, 0, 0, 0, 0, 166, 5470
map_015_object_01:
    map_object 58, 1, 1, 21, 1, 54, 1, 0, 0, 0, 0, 167, 0
map_015_object_02:
    map_object 45, 1, 6, 26, 0, 33, 0, 2, 0, 0, 0, 54, 49153
map_015_object_03:
    map_object 45, 1, 6, 17, 0, 49, 0, 3, 0, 0, 0, 54, 49153
map_015_object_04:
    map_object 45, 1, 6, 26, 0, 49, 0, 2, 0, 0, 0, 54, 49153
map_015_object_05:
    map_object 45, 1, 6, 17, 0, 63, 0, 3, 0, 0, 0, 54, 49153
map_015_object_06:
    map_object 45, 1, 6, 26, 0, 63, 0, 2, 0, 0, 0, 54, 49153
map_015_object_07:
    map_object 189, 0, 3, 34, 0, 27, 1, 1, 0, 0, 0, 235, 50805
map_015_object_08:
    map_object 187, 0, 3, 9, 0, 27, 1, 1, 0, 0, 0, 235, 50803
map_016_header:
    map_header 5, 2, 61, 1, 5, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_017_header:
    map_header 1, 3, 25, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_017_object_00:
    map_object 0, 0, 15, 63, 0, 89, 0, 1, 0, 0, 0, 4, 49153
map_017_object_01:
    map_object 0, 0, 15, 40, 0, 71, 0, 1, 0, 0, 0, 4, 49153
map_017_object_02:
    map_object 0, 0, 15, 39, 0, 72, 0, 1, 0, 0, 0, 4, 49153
map_017_object_03:
    map_object 0, 0, 15, 38, 0, 62, 0, 1, 0, 0, 0, 4, 49153
map_017_object_04:
    map_object 0, 0, 15, 50, 0, 79, 0, 1, 0, 0, 0, 4, 49153
map_017_object_05:
    map_object 0, 0, 15, 32, 0, 57, 0, 1, 0, 0, 0, 4, 49153
map_017_object_06:
    map_object 0, 0, 15, 79, 0, 55, 0, 1, 0, 0, 0, 4, 49153
map_017_object_07:
    map_object 0, 0, 15, 76, 0, 36, 0, 1, 0, 0, 0, 4, 49153
map_017_object_08:
    map_object 0, 0, 15, 66, 0, 87, 0, 1, 0, 0, 0, 2, 49153
map_017_object_09:
    map_object 0, 0, 15, 56, 0, 56, 0, 1, 0, 0, 0, 2, 49153
map_017_object_10:
    map_object 0, 0, 15, 64, 0, 62, 0, 1, 0, 0, 0, 2, 49153
map_017_object_11:
    map_object 0, 0, 15, 81, 0, 35, 0, 1, 0, 0, 0, 2, 49153
map_017_object_12:
    map_object 0, 0, 15, 57, 0, 30, 0, 1, 0, 0, 0, 2, 49153
map_017_object_13:
    map_object 0, 0, 15, 53, 0, 34, 0, 1, 0, 0, 0, 2, 49153
map_017_object_14:
    map_object 0, 0, 15, 47, 0, 42, 0, 1, 0, 0, 0, 2, 49153
map_017_object_15:
    map_object 0, 0, 15, 26, 0, 39, 0, 1, 0, 0, 0, 2, 49153
map_017_object_16:
    map_object 0, 0, 15, 61, 0, 81, 0, 1, 0, 0, 0, 1, 49153
map_017_object_17:
    map_object 0, 0, 15, 38, 0, 55, 0, 1, 0, 0, 0, 1, 49153
map_017_object_18:
    map_object 0, 0, 15, 25, 0, 62, 0, 1, 0, 0, 0, 1, 49153
map_017_object_19:
    map_object 0, 0, 15, 74, 0, 63, 0, 1, 0, 0, 0, 1, 49153
map_017_object_20:
    map_object 0, 0, 15, 36, 0, 38, 0, 1, 0, 0, 0, 1, 49153
map_017_object_21:
    map_object 0, 0, 15, 74, 0, 30, 0, 1, 0, 0, 0, 0, 49153
map_017_object_22:
    map_object 0, 0, 15, 48, 0, 76, 0, 1, 0, 0, 0, 0, 49153
map_017_object_23:
    map_object 0, 0, 15, 79, 0, 45, 0, 1, 0, 0, 0, 0, 49153
map_017_object_24:
    map_object 0, 0, 15, 19, 0, 36, 0, 1, 0, 0, 0, 0, 49153
map_018_header:
    map_header 14, 3, 81, 1, 14, 2, 0, 1, 0, 0, 4, 2, 0, 0, 57
map_018_object_00:
    map_object 150, 1, 15, 9, 1, 27, 0, 1, 1, 0, 0, 183, 49888
map_018_object_01:
    map_object 150, 0, 0, 9, 1, 31, 1, 1, 1, 0, 0, 183, 17120
map_018_object_02:
    map_object 150, 0, 0, 10, 1, 31, 1, 1, 1, 0, 0, 183, 17648
map_019_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_019_object_00:
    map_object 0, 0, 15, 19, 0, 54, 0, 0, 0, 0, 0, 4, 49153
map_019_object_01:
    map_object 0, 0, 15, 47, 0, 39, 0, 0, 0, 0, 0, 1, 49153
map_019_object_02:
    map_object 0, 0, 15, 25, 0, 33, 0, 0, 0, 0, 0, 2, 49153
map_019_object_03:
    map_object 0, 0, 15, 72, 0, 62, 0, 0, 0, 0, 0, 2, 49153
map_019_object_04:
    map_object 0, 0, 15, 30, 0, 72, 0, 0, 0, 0, 0, 4, 49153
map_019_object_05:
    map_object 0, 0, 15, 55, 0, 30, 0, 0, 0, 0, 0, 1, 49153
map_019_object_06:
    map_object 0, 0, 15, 59, 0, 50, 0, 0, 0, 0, 0, 4, 49153
map_019_object_07:
    map_object 0, 0, 15, 73, 0, 47, 0, 0, 0, 0, 0, 1, 49153
map_019_object_08:
    map_object 0, 0, 15, 41, 0, 25, 0, 0, 0, 0, 0, 1, 49153
map_019_object_09:
    map_object 0, 0, 15, 26, 0, 48, 0, 0, 0, 0, 0, 4, 49153
map_019_object_10:
    map_object 0, 0, 15, 66, 0, 36, 0, 0, 0, 0, 0, 4, 49153
map_019_object_11:
    map_object 0, 0, 15, 69, 0, 42, 0, 0, 0, 0, 0, 4, 49153
map_019_object_12:
    map_object 0, 0, 15, 21, 0, 42, 0, 0, 0, 0, 0, 4, 49153
map_019_object_13:
    map_object 0, 0, 15, 42, 0, 52, 0, 0, 0, 0, 0, 1, 49153
map_019_object_14:
    map_object 0, 0, 15, 49, 0, 59, 0, 0, 0, 0, 0, 1, 49153
map_019_object_15:
    map_object 0, 0, 15, 58, 0, 64, 0, 0, 0, 0, 0, 1, 49153
map_019_object_16:
    map_object 0, 0, 15, 49, 0, 50, 0, 0, 0, 0, 0, 1, 49153
map_019_object_17:
    map_object 0, 0, 15, 27, 0, 58, 0, 0, 0, 0, 0, 1, 49153
map_019_object_18:
    map_object 0, 0, 15, 49, 0, 76, 0, 0, 0, 0, 0, 1, 49153
map_019_object_19:
    map_object 0, 0, 15, 69, 0, 69, 0, 0, 0, 0, 0, 1, 49153
map_019_object_20:
    map_object 0, 0, 15, 37, 0, 41, 0, 0, 0, 0, 0, 1, 49153
map_01A_header:
    map_header 14, 3, 81, 1, 14, 2, 0, 0, 0, 0, 4, 2, 0, 0, 57
map_01A_object_00:
    map_object 60, 0, 14, 12, 1, 22, 0, 1, 1, 0, 0, 183, 49889
map_01B_header:
    map_header 1, 3, 25, 1, 1, 2, 0, 1, 0, 0, 4, 0, 0, 0, 255
map_01B_object_00:
    map_object 18, 0, 14, 16, 1, 38, 0, 0, 0, 0, 0, 201, 49692
map_01B_object_01:
    map_object 0, 0, 15, 15, 0, 44, 0, 1, 0, 0, 0, 4, 49153
map_01B_object_02:
    map_object 0, 0, 15, 14, 0, 36, 0, 1, 0, 0, 0, 4, 49153
map_01B_object_03:
    map_object 0, 0, 15, 13, 0, 33, 0, 1, 0, 0, 0, 4, 49153
map_01B_object_04:
    map_object 0, 0, 15, 11, 0, 34, 0, 1, 0, 0, 0, 4, 49153
map_01B_object_05:
    map_object 0, 0, 15, 23, 0, 39, 0, 1, 0, 0, 0, 4, 49153
map_01C_header:
    map_header 7, 2, 31, 1, 7, 2, 0, 1, 0, 7, 3, 5, 0, 0, 255
map_01C_object_00:
    map_object 23, 0, 0, 33, 1, 17, 1, 1, 0, 0, 0, 153, 16855
map_01C_object_01:
    map_object 0, 0, 15, 16, 0, 33, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_02:
    map_object 0, 0, 15, 12, 0, 19, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_03:
    map_object 0, 0, 15, 25, 0, 19, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_04:
    map_object 0, 0, 15, 32, 0, 20, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_05:
    map_object 0, 0, 15, 34, 0, 8, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_06:
    map_object 0, 0, 15, 19, 0, 16, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_07:
    map_object 0, 0, 15, 36, 0, 21, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_08:
    map_object 0, 0, 15, 25, 0, 24, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_09:
    map_object 0, 0, 15, 21, 0, 34, 0, 0, 0, 0, 0, 3, 49153
map_01C_object_10:
    map_object 0, 0, 15, 16, 0, 21, 0, 0, 0, 0, 0, 3, 49153
map_01D_header:
    map_header 7, 2, 31, 1, 7, 2, 0, 0, 0, 7, 3, 5, 0, 0, 255
map_01D_object_00:
    map_object 0, 0, 15, 24, 0, 15, 0, 1, 0, 0, 0, 2, 49153
map_01D_object_01:
    map_object 0, 0, 15, 34, 0, 14, 0, 0, 0, 0, 0, 10, 49153
map_01D_object_02:
    map_object 0, 0, 15, 34, 0, 20, 0, 0, 0, 0, 0, 3, 49153
map_01D_object_03:
    map_object 0, 0, 15, 39, 0, 25, 0, 1, 0, 0, 0, 2, 49153
map_01D_object_04:
    map_object 0, 0, 15, 38, 0, 35, 0, 0, 0, 0, 0, 3, 49153
map_01D_object_05:
    map_object 0, 0, 15, 25, 0, 30, 0, 0, 0, 0, 0, 3, 49153
map_01D_object_06:
    map_object 0, 0, 15, 20, 0, 38, 0, 0, 0, 0, 0, 10, 49153
map_01D_object_07:
    map_object 0, 0, 15, 15, 0, 14, 0, 1, 0, 0, 0, 3, 49153
map_01D_object_08:
    map_object 0, 0, 15, 16, 0, 24, 0, 0, 0, 0, 0, 10, 49153
map_01E_header:
    map_header 7, 2, 31, 1, 7, 2, 0, 0, 0, 7, 3, 5, 0, 0, 255
map_01E_object_00:
    map_object 0, 0, 15, 13, 0, 31, 0, 1, 0, 0, 0, 7, 16385
map_01E_object_01:
    map_object 0, 0, 15, 31, 0, 35, 0, 0, 0, 0, 0, 10, 49153
map_01E_object_02:
    map_object 0, 0, 15, 32, 0, 31, 0, 0, 0, 0, 0, 2, 49153
map_01E_object_03:
    map_object 0, 0, 15, 27, 0, 15, 0, 0, 0, 0, 0, 3, 49153
map_01E_object_04:
    map_object 0, 0, 15, 19, 0, 18, 0, 0, 0, 0, 0, 1, 49153
map_01E_object_05:
    map_object 0, 0, 15, 28, 0, 31, 0, 0, 0, 0, 0, 2, 49153
map_01E_object_06:
    map_object 0, 0, 15, 30, 0, 20, 0, 0, 0, 0, 0, 3, 49153
map_01F_header:
    map_header 7, 2, 31, 1, 7, 2, 0, 1, 0, 7, 3, 5, 0, 0, 255
map_01F_object_00:
    map_object 0, 0, 15, 14, 0, 32, 0, 0, 0, 0, 0, 3, 49153
map_01F_object_01:
    map_object 0, 0, 15, 9, 0, 29, 0, 0, 0, 0, 0, 3, 49153
map_01F_object_02:
    map_object 0, 0, 15, 31, 0, 19, 0, 0, 0, 0, 0, 3, 49153
map_01F_object_03:
    map_object 0, 0, 15, 39, 0, 36, 0, 0, 0, 0, 0, 10, 49153
map_01F_object_04:
    map_object 0, 0, 15, 27, 0, 30, 0, 0, 0, 0, 0, 2, 49153
map_01F_object_05:
    map_object 0, 0, 15, 23, 0, 13, 0, 0, 0, 0, 0, 10, 49153
map_01F_object_06:
    map_object 0, 0, 15, 24, 0, 14, 0, 0, 0, 0, 0, 10, 49153
map_020_header:
    map_header 18, 0, 57, 1, 18, 2, 2, 0, 0, 0, 1, 0, 0, 0, 255
map_020_object_00:
    map_object 148, 1, 15, 21, 1, 17, 1, 3, 0, 0, 0, 28, 49152
map_020_object_01:
    map_object 148, 1, 15, 21, 1, 45, 1, 3, 0, 0, 0, 28, 49152
map_021_header:
    map_header 18, 0, 57, 1, 18, 2, 0, 0, 0, 3, 1, 0, 0, 0, 255
map_021_object_00:
    map_object 0, 0, 15, 10, 1, 11, 1, 0, 0, 0, 0, 28, 49152
map_022_header:
    map_header 18, 0, 57, 1, 18, 2, 0, 0, 0, 4, 1, 0, 0, 0, 255
map_022_object_00:
    map_object 0, 0, 15, 10, 1, 11, 1, 1, 0, 0, 0, 28, 49152
map_023_header:
    map_header 23, 3, 95, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_023_object_00:
    map_object 59, 0, 1, 3, 1, 12, 0, 0, 0, 0, 0, 85, 708
map_023_object_01:
    map_object 0, 0, 15, 30, 0, 17, 0, 1, 0, 0, 0, 57, 49153
map_023_object_02:
    map_object 0, 0, 15, 3, 0, 15, 0, 1, 0, 0, 0, 57, 49153
map_024_header:
    map_header 15, 3, 56, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 66
map_024_object_00:
    map_object 60, 0, 0, 23, 1, 42, 1, 0, 3, 0, 0, 160, 4818
map_024_object_01:
    map_object 60, 4, 14, 24, 1, 33, 0, 1, 1, 0, 0, 187, 49896
map_024_object_02:
    map_object 60, 4, 14, 21, 1, 33, 0, 1, 1, 0, 0, 188, 49898
map_024_object_03:
    map_object 60, 0, 14, 20, 1, 41, 0, 1, 0, 0, 0, 183, 49890
map_024_object_04:
    map_object 60, 0, 14, 25, 1, 41, 0, 1, 0, 0, 0, 183, 49891
map_024_object_05:
    map_object 60, 0, 14, 38, 1, 13, 0, 2, 0, 0, 0, 183, 49892
map_024_object_06:
    map_object 60, 4, 14, 8, 1, 32, 0, 3, 2, 0, 0, 198, 49900
map_024_object_07:
    map_object 60, 4, 14, 36, 1, 33, 0, 2, 2, 0, 0, 200, 49902
map_024_object_08:
    map_object 60, 4, 14, 19, 1, 15, 0, 1, 2, 0, 0, 202, 49899
map_025_header:
    map_header 15, 3, 56, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 65
map_025_object_00:
    map_object 60, 4, 14, 25, 0, 83, 0, 1, 0, 0, 0, 196, 49897
map_025_object_01:
    map_object 60, 4, 14, 31, 0, 80, 0, 2, 2, 0, 0, 199, 49901
map_025_object_02:
    map_object 60, 4, 14, 23, 0, 83, 0, 1, 2, 0, 0, 197, 49903
map_025_object_03:
    map_object 60, 4, 14, 38, 0, 81, 1, 1, 3, 0, 0, 207, 54030
map_025_object_04:
    map_object 60, 0, 14, 8, 0, 79, 0, 1, 1, 0, 0, 183, 49893
map_025_object_05:
    map_object 60, 0, 14, 39, 0, 54, 1, 1, 1, 0, 0, 183, 17126
map_025_object_06:
    map_object 60, 0, 14, 32, 0, 54, 1, 1, 1, 0, 0, 183, 17127
map_026_header:
    map_header 7, 0, 31, 1, 7, 2, 0, 0, 0, 7, 1, 5, 0, 0, 255
map_026_object_00:
    map_object 13, 0, 0, 16, 1, 16, 0, 0, 0, 0, 0, 139, 49626
map_026_object_01:
    map_object 22, 0, 0, 14, 1, 11, 0, 0, 0, 0, 0, 31, 49153
map_026_object_02:
    map_object 22, 0, 0, 18, 1, 11, 0, 0, 0, 0, 0, 31, 49153
map_027_header:
    map_header 1, 3, 62, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_027_object_00:
    map_object 0, 0, 15, 11, 0, 26, 0, 1, 0, 0, 0, 16, 49153
map_027_object_01:
    map_object 0, 0, 15, 13, 0, 50, 0, 1, 0, 0, 0, 16, 49153
map_027_object_02:
    map_object 0, 0, 15, 27, 0, 62, 0, 1, 0, 0, 0, 16, 49153
map_027_object_03:
    map_object 0, 0, 15, 35, 0, 30, 0, 1, 0, 0, 0, 16, 49153
map_027_object_04:
    map_object 0, 0, 15, 32, 0, 28, 0, 1, 0, 0, 0, 16, 49153
map_027_object_05:
    map_object 0, 0, 15, 23, 0, 35, 0, 1, 0, 0, 0, 24, 49153
map_027_object_06:
    map_object 0, 0, 15, 14, 0, 37, 0, 1, 0, 0, 0, 24, 49153
map_027_object_07:
    map_object 0, 0, 15, 16, 0, 43, 0, 1, 0, 0, 0, 24, 49153
map_027_object_08:
    map_object 0, 0, 15, 14, 0, 60, 0, 1, 0, 0, 0, 20, 49153
map_027_object_09:
    map_object 0, 0, 15, 35, 0, 55, 0, 1, 0, 0, 0, 20, 49153
map_027_object_10:
    map_object 0, 0, 15, 26, 0, 52, 0, 1, 0, 0, 0, 21, 49153
map_027_object_11:
    map_object 0, 0, 15, 35, 0, 40, 0, 1, 0, 0, 0, 21, 49153
map_027_object_12:
    map_object 0, 0, 15, 35, 0, 40, 0, 1, 0, 0, 7, 204, 0
map_028_header:
    map_header 1, 3, 62, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_028_object_00:
    map_object 0, 0, 15, 23, 0, 18, 0, 1, 0, 0, 0, 16, 49153
map_028_object_01:
    map_object 0, 0, 15, 16, 0, 31, 0, 1, 0, 0, 0, 20, 49153
map_028_object_02:
    map_object 0, 0, 15, 23, 0, 35, 0, 1, 0, 0, 0, 24, 49153
map_028_object_03:
    map_object 0, 0, 15, 14, 0, 38, 0, 1, 0, 0, 0, 12, 49153
map_028_object_04:
    map_object 0, 0, 15, 20, 0, 45, 0, 1, 0, 0, 0, 24, 49153
map_028_object_05:
    map_object 0, 0, 15, 20, 0, 63, 0, 1, 0, 0, 0, 16, 49153
map_028_object_06:
    map_object 0, 0, 15, 27, 0, 51, 0, 1, 0, 0, 0, 12, 49153
map_028_object_07:
    map_object 0, 0, 15, 35, 0, 57, 0, 1, 0, 0, 0, 24, 49153
map_028_object_08:
    map_object 0, 0, 15, 32, 0, 30, 0, 1, 0, 0, 0, 24, 49153
map_028_object_09:
    map_object 0, 0, 15, 11, 0, 20, 0, 1, 0, 0, 0, 21, 49153
map_028_object_10:
    map_object 0, 0, 15, 13, 0, 60, 0, 1, 0, 0, 0, 16, 49153
map_028_object_11:
    map_object 0, 0, 15, 39, 0, 44, 0, 1, 0, 0, 0, 12, 49153
map_028_object_12:
    map_object 0, 0, 15, 13, 0, 50, 0, 1, 0, 0, 0, 20, 49153
map_028_object_13:
    map_object 0, 0, 15, 32, 0, 19, 0, 1, 0, 0, 0, 20, 49153
map_028_object_14:
    map_object 0, 0, 15, 23, 0, 18, 0, 1, 0, 0, 7, 204, 0
map_029_header:
    map_header 1, 3, 62, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_029_object_00:
    map_object 32, 0, 3, 28, 1, 62, 1, 0, 0, 0, 7, 85, 602
map_029_object_01:
    map_object 0, 0, 15, 23, 0, 18, 0, 1, 0, 0, 0, 16, 49153
map_029_object_02:
    map_object 0, 0, 15, 16, 0, 31, 0, 1, 0, 0, 0, 16, 49153
map_029_object_03:
    map_object 0, 0, 15, 23, 0, 35, 0, 1, 0, 0, 0, 16, 49153
map_029_object_04:
    map_object 0, 0, 15, 14, 0, 38, 0, 1, 0, 0, 0, 16, 49153
map_029_object_05:
    map_object 0, 0, 15, 20, 0, 45, 0, 1, 0, 0, 0, 16, 49153
map_029_object_06:
    map_object 0, 0, 15, 20, 0, 63, 0, 1, 0, 0, 0, 16, 49153
map_029_object_07:
    map_object 0, 0, 15, 27, 0, 51, 0, 1, 0, 0, 0, 16, 49153
map_029_object_08:
    map_object 0, 0, 15, 35, 0, 57, 0, 1, 0, 0, 0, 16, 49153
map_029_object_09:
    map_object 0, 0, 15, 32, 0, 30, 0, 1, 0, 0, 0, 16, 49153
map_029_object_10:
    map_object 0, 0, 15, 11, 0, 20, 0, 1, 0, 0, 0, 20, 49153
map_029_object_11:
    map_object 0, 0, 15, 13, 0, 60, 0, 1, 0, 0, 0, 20, 49153
map_029_object_12:
    map_object 0, 0, 15, 39, 0, 44, 0, 1, 0, 0, 0, 20, 49153
map_029_object_13:
    map_object 0, 0, 15, 13, 0, 50, 0, 1, 0, 0, 0, 21, 49153
map_029_object_14:
    map_object 0, 0, 15, 32, 0, 19, 0, 1, 0, 0, 0, 21, 49153
map_029_object_15:
    map_object 0, 0, 15, 32, 0, 19, 0, 1, 0, 0, 7, 204, 0
map_02A_header:
    map_header 26, 1, 50, 1, 26, 2, 0, 0, 0, 0, 3, 2, 0, 0, 255
map_02A_object_00:
    map_object 0, 0, 15, 16, 0, 11, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_01:
    map_object 0, 0, 15, 24, 0, 12, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_02:
    map_object 0, 0, 15, 6, 0, 36, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_03:
    map_object 0, 0, 15, 7, 0, 36, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_04:
    map_object 0, 0, 15, 57, 0, 77, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_05:
    map_object 0, 0, 15, 57, 0, 67, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_06:
    map_object 0, 0, 15, 48, 0, 67, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_07:
    map_object 0, 0, 15, 83, 0, 6, 0, 1, 0, 0, 0, 49, 49153
map_02A_object_08:
    map_object 0, 0, 15, 31, 0, 12, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_09:
    map_object 0, 0, 15, 24, 0, 21, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_10:
    map_object 0, 0, 15, 34, 0, 77, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_11:
    map_object 0, 0, 15, 42, 0, 77, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_12:
    map_object 0, 0, 15, 67, 0, 25, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_13:
    map_object 0, 0, 15, 96, 0, 16, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_14:
    map_object 0, 0, 15, 97, 0, 27, 0, 1, 0, 0, 0, 71, 49153
map_02A_object_15:
    map_object 0, 0, 15, 17, 0, 33, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_16:
    map_object 0, 0, 15, 23, 0, 38, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_17:
    map_object 0, 0, 15, 15, 0, 76, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_18:
    map_object 0, 0, 15, 54, 0, 31, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_19:
    map_object 0, 0, 15, 85, 0, 21, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_20:
    map_object 0, 0, 15, 87, 0, 35, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_21:
    map_object 0, 0, 15, 77, 0, 35, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_22:
    map_object 0, 0, 15, 88, 0, 45, 0, 1, 0, 0, 0, 65, 49153
map_02A_object_23:
    map_object 0, 0, 15, 16, 0, 67, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_24:
    map_object 0, 0, 15, 9, 0, 66, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_25:
    map_object 0, 0, 15, 44, 0, 30, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_26:
    map_object 0, 0, 15, 55, 0, 30, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_27:
    map_object 0, 0, 15, 67, 0, 35, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_28:
    map_object 0, 0, 15, 39, 0, 31, 0, 1, 0, 0, 0, 58, 49153
map_02A_object_29:
    map_object 0, 0, 15, 21, 0, 76, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_30:
    map_object 0, 0, 15, 48, 0, 21, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_31:
    map_object 0, 0, 15, 43, 0, 17, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_32:
    map_object 0, 0, 15, 55, 0, 9, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_33:
    map_object 0, 0, 15, 85, 0, 13, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_34:
    map_object 0, 0, 15, 69, 0, 7, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_35:
    map_object 0, 0, 15, 97, 0, 36, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_36:
    map_object 0, 0, 15, 97, 0, 7, 0, 1, 0, 0, 0, 47, 49153
map_02A_object_37:
    map_object 0, 0, 15, 41, 0, 67, 0, 1, 0, 0, 0, 78, 49153
map_02A_object_38:
    map_object 0, 0, 15, 32, 0, 67, 0, 1, 0, 0, 0, 78, 49153
map_02A_object_39:
    map_object 0, 0, 15, 72, 0, 22, 0, 1, 0, 0, 0, 78, 49153
map_02A_object_40:
    map_object 0, 0, 15, 97, 0, 7, 0, 1, 0, 0, 0, 78, 49153
map_02A_object_41:
    map_object 0, 0, 15, 91, 0, 45, 0, 1, 0, 0, 0, 78, 49153
map_02A_object_42:
    map_object 0, 0, 15, 85, 0, 45, 0, 1, 0, 0, 0, 78, 49153
map_02B_header:
    map_header 26, 1, 50, 1, 26, 2, 0, 0, 0, 0, 3, 2, 0, 0, 255
map_02B_object_00:
    map_object 0, 0, 15, 50, 0, 72, 0, 1, 0, 0, 0, 49, 49153
map_02B_object_01:
    map_object 0, 0, 15, 52, 0, 72, 0, 1, 0, 0, 0, 49, 49153
map_02B_object_02:
    map_object 0, 0, 15, 47, 0, 80, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_03:
    map_object 0, 0, 15, 54, 0, 80, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_04:
    map_object 0, 0, 15, 70, 0, 40, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_05:
    map_object 0, 0, 15, 77, 0, 40, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_06:
    map_object 0, 0, 15, 62, 0, 79, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_07:
    map_object 0, 0, 15, 84, 0, 77, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_08:
    map_object 0, 0, 15, 89, 0, 77, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_09:
    map_object 0, 0, 15, 94, 0, 77, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_10:
    map_object 0, 0, 15, 24, 0, 29, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_11:
    map_object 0, 0, 15, 28, 0, 29, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_12:
    map_object 0, 0, 15, 32, 0, 29, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_13:
    map_object 0, 0, 15, 36, 0, 52, 0, 1, 0, 0, 0, 47, 49153
map_02B_object_14:
    map_object 0, 0, 15, 93, 0, 44, 0, 1, 0, 0, 0, 47, 49153
map_02B_object_15:
    map_object 0, 0, 15, 8, 0, 70, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_16:
    map_object 0, 0, 15, 19, 0, 70, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_17:
    map_object 0, 0, 15, 47, 0, 55, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_18:
    map_object 0, 0, 15, 55, 0, 49, 0, 1, 0, 0, 0, 65, 49153
map_02B_object_19:
    map_object 0, 0, 15, 78, 0, 74, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_20:
    map_object 0, 0, 15, 86, 0, 62, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_21:
    map_object 0, 0, 15, 93, 0, 62, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_22:
    map_object 0, 0, 15, 18, 0, 32, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_23:
    map_object 0, 0, 15, 18, 0, 35, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_24:
    map_object 0, 0, 15, 32, 0, 49, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_25:
    map_object 0, 0, 15, 40, 0, 49, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_26:
    map_object 0, 0, 15, 86, 0, 33, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_27:
    map_object 0, 0, 15, 94, 0, 33, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_28:
    map_object 0, 0, 15, 90, 0, 26, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_29:
    map_object 0, 0, 15, 23, 0, 13, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_30:
    map_object 0, 0, 15, 28, 0, 13, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_31:
    map_object 0, 0, 15, 33, 0, 13, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_32:
    map_object 0, 0, 15, 9, 0, 31, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_33:
    map_object 0, 0, 15, 73, 0, 67, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_34:
    map_object 0, 0, 15, 73, 0, 84, 0, 1, 0, 0, 0, 77, 49153
map_02B_object_35:
    map_object 0, 0, 15, 36, 0, 80, 0, 1, 0, 0, 0, 69, 49153
map_02B_object_36:
    map_object 0, 0, 15, 61, 0, 39, 0, 1, 0, 0, 0, 69, 49153
map_02B_object_37:
    map_object 0, 0, 15, 51, 0, 39, 0, 1, 0, 0, 0, 69, 49153
map_02B_object_38:
    map_object 0, 0, 15, 51, 0, 28, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_39:
    map_object 0, 0, 15, 60, 0, 28, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_40:
    map_object 0, 0, 15, 66, 0, 28, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_41:
    map_object 0, 0, 15, 88, 0, 13, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_42:
    map_object 0, 0, 15, 91, 0, 15, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_43:
    map_object 0, 0, 15, 95, 0, 14, 0, 1, 0, 0, 0, 79, 49153
map_02B_object_44:
    map_object 185, 0, 5, 17, 1, 52, 1, 1, 0, 0, 0, 235, 50801
map_02B_object_45:
    map_object 184, 0, 5, 10, 1, 52, 1, 1, 0, 0, 0, 235, 50800
map_02C_header:
    map_header 26, 0, 50, 1, 26, 2, 0, 0, 0, 12, 1, 0, 0, 0, 255
map_02C_object_00:
    map_object 0, 0, 15, 12, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_01:
    map_object 0, 0, 15, 12, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_02:
    map_object 0, 0, 15, 16, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_03:
    map_object 0, 0, 15, 29, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_04:
    map_object 0, 0, 15, 35, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_05:
    map_object 0, 0, 15, 43, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_06:
    map_object 0, 0, 15, 47, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_07:
    map_object 0, 0, 15, 52, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_08:
    map_object 0, 0, 15, 60, 0, 17, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_09:
    map_object 0, 0, 15, 70, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_10:
    map_object 0, 0, 15, 74, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_11:
    map_object 0, 0, 15, 82, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_12:
    map_object 0, 0, 15, 97, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02C_object_13:
    map_object 0, 0, 15, 102, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_14:
    map_object 0, 0, 15, 114, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02C_object_15:
    map_object 0, 0, 15, 118, 0, 13, 0, 1, 0, 0, 0, 64, 49153
map_02D_header:
    map_header 26, 0, 50, 1, 26, 2, 0, 0, 0, 13, 1, 0, 0, 0, 255
map_02D_object_00:
    map_object 0, 0, 15, 12, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_01:
    map_object 0, 0, 15, 12, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_02:
    map_object 0, 0, 15, 16, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_03:
    map_object 0, 0, 15, 29, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_04:
    map_object 0, 0, 15, 35, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_05:
    map_object 0, 0, 15, 43, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_06:
    map_object 0, 0, 15, 47, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_07:
    map_object 0, 0, 15, 52, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_08:
    map_object 0, 0, 15, 60, 0, 17, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_09:
    map_object 0, 0, 15, 70, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_10:
    map_object 0, 0, 15, 74, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_11:
    map_object 0, 0, 15, 82, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_12:
    map_object 0, 0, 15, 97, 0, 12, 0, 0, 0, 0, 0, 54, 49153
map_02D_object_13:
    map_object 0, 0, 15, 102, 0, 17, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_14:
    map_object 0, 0, 15, 114, 0, 12, 0, 1, 0, 0, 0, 54, 49153
map_02D_object_15:
    map_object 0, 0, 15, 118, 0, 13, 0, 1, 0, 0, 0, 64, 49153
map_02E_header:
    map_header 26, 0, 50, 1, 26, 2, 0, 0, 0, 0, 1, 0, 0, 0, 255
map_02E_object_00:
    map_object 71, 0, 1, 11, 1, 13, 1, 1, 0, 0, 0, 164, 0
map_02E_object_01:
    map_object 71, 0, 1, 9, 1, 13, 1, 1, 0, 0, 0, 165, 0
map_02E_object_02:
    map_object 71, 0, 1, 13, 1, 13, 1, 1, 0, 0, 0, 165, 0
map_02E_object_03:
    map_object 71, 2, 2, 11, 1, 11, 0, 1, 0, 0, 0, 112, 1226
map_02F_header:
    map_header 31, 0, 55, 0, 31, 2, 0, 0, 0, 0, 4, 0, 0, 0, 255
map_030_header:
    map_header 22, 0, 96, 0, 22, 2, 0, 0, 0, 0, 0, 0, 0, 0, 255
map_030_object_00:
    map_object 0, 0, 15, 26, 0, 16, 0, 1, 0, 0, 0, 57, 49153
map_030_object_01:
    map_object 0, 0, 15, 35, 0, 16, 0, 1, 0, 0, 0, 57, 49153
map_030_object_02:
    map_object 0, 0, 15, 31, 0, 27, 0, 1, 0, 0, 0, 57, 49153
map_031_header:
    map_header 1, 3, 66, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_031_object_00:
    map_object 0, 1, 15, 23, 0, 22, 0, 1, 0, 0, 0, 24, 49153
map_031_object_01:
    map_object 0, 1, 15, 27, 0, 20, 0, 1, 0, 0, 0, 24, 49153
map_031_object_02:
    map_object 0, 1, 15, 38, 0, 29, 0, 1, 0, 0, 0, 24, 49153
map_031_object_03:
    map_object 0, 1, 15, 36, 0, 44, 0, 1, 0, 0, 0, 24, 49153
map_031_object_04:
    map_object 0, 1, 15, 25, 0, 46, 0, 1, 0, 0, 0, 24, 49153
map_031_object_05:
    map_object 0, 1, 15, 39, 0, 40, 0, 1, 0, 0, 0, 24, 49153
map_031_object_06:
    map_object 0, 1, 15, 19, 0, 31, 0, 1, 0, 0, 0, 24, 49153
map_031_object_07:
    map_object 0, 1, 15, 11, 0, 23, 0, 1, 0, 0, 0, 21, 49153
map_031_object_08:
    map_object 0, 1, 15, 11, 0, 38, 0, 1, 0, 0, 0, 21, 49153
map_031_object_09:
    map_object 0, 1, 15, 36, 0, 42, 0, 1, 0, 0, 0, 21, 49153
map_031_object_10:
    map_object 0, 1, 15, 36, 0, 42, 0, 1, 0, 0, 7, 204, 0
map_033_header:
    map_header 15, 3, 56, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 57
map_033_object_00:
    map_object 60, 0, 3, 12, 1, 12, 1, 1, 0, 0, 0, 189, 4820
map_033_object_01:
    map_object 60, 2, 2, 12, 1, 23, 1, 0, 3, 0, 0, 160, 16384
map_033_object_02:
    map_object 60, 0, 2, 8, 0, 12, 1, 1, 1, 0, 0, 183, 17107
map_033_object_03:
    map_object 60, 0, 2, 14, 0, 12, 1, 1, 1, 0, 0, 183, 17107
map_033_object_04:
    map_object 60, 4, 14, 12, 1, 12, 1, 1, 0, 0, 0, 189, 17109
map_033_object_05:
    map_object 60, 4, 5, 13, 1, 14, 1, 2, 3, 0, 0, 160, 17110
map_033_object_06:
    map_object 60, 4, 14, 7, 0, 11, 1, 3, 1, 0, 0, 183, 17112
map_033_object_07:
    map_object 60, 4, 14, 16, 0, 11, 1, 2, 1, 0, 0, 183, 17113
map_033_object_08:
    map_object 60, 4, 14, 7, 0, 17, 1, 1, 1, 0, 0, 183, 17114
map_033_object_09:
    map_object 60, 4, 14, 16, 0, 17, 1, 1, 1, 0, 0, 183, 17115
map_033_object_10:
    map_object 60, 4, 14, 16, 0, 21, 1, 1, 1, 0, 0, 183, 17116
map_033_object_11:
    map_object 60, 4, 14, 7, 0, 21, 1, 1, 1, 0, 0, 183, 17117
map_034_header:
    map_header 1, 3, 63, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_034_object_00:
    map_object 32, 0, 2, 19, 1, 25, 1, 1, 0, 0, 0, 153, 16956
map_034_object_01:
    map_object 0, 1, 15, 18, 0, 25, 0, 1, 0, 0, 0, 20, 49153
map_034_object_02:
    map_object 0, 1, 15, 11, 0, 38, 0, 1, 0, 0, 0, 20, 49153
map_034_object_03:
    map_object 0, 1, 15, 18, 0, 39, 0, 1, 0, 0, 0, 20, 49153
map_034_object_04:
    map_object 0, 1, 15, 18, 0, 25, 0, 1, 0, 0, 0, 20, 49153
map_034_object_05:
    map_object 0, 1, 15, 13, 0, 45, 0, 1, 0, 0, 0, 20, 49153
map_034_object_06:
    map_object 0, 1, 15, 24, 0, 48, 0, 1, 0, 0, 0, 20, 49153
map_034_object_07:
    map_object 0, 1, 15, 18, 0, 25, 0, 1, 0, 0, 0, 20, 49153
map_034_object_08:
    map_object 0, 1, 15, 35, 0, 43, 0, 1, 0, 0, 0, 20, 49153
map_034_object_09:
    map_object 0, 1, 15, 20, 0, 25, 0, 1, 0, 0, 0, 20, 49153
map_034_object_10:
    map_object 0, 1, 15, 38, 0, 34, 0, 1, 0, 0, 0, 24, 49153
map_034_object_11:
    map_object 0, 1, 15, 28, 0, 29, 0, 1, 0, 0, 0, 20, 49153
map_034_object_12:
    map_object 0, 1, 15, 28, 0, 29, 0, 1, 0, 0, 7, 204, 0
map_035_header:
    map_header 1, 3, 64, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_035_object_00:
    map_object 0, 1, 15, 22, 0, 22, 0, 1, 0, 0, 0, 20, 49153
map_035_object_01:
    map_object 0, 1, 15, 38, 0, 19, 0, 1, 0, 0, 0, 20, 49153
map_035_object_02:
    map_object 0, 1, 15, 29, 0, 22, 0, 1, 0, 0, 0, 20, 49153
map_035_object_03:
    map_object 0, 1, 15, 16, 0, 27, 0, 1, 0, 0, 0, 12, 49153
map_035_object_04:
    map_object 0, 1, 15, 22, 0, 30, 0, 1, 0, 0, 0, 12, 49153
map_035_object_05:
    map_object 0, 1, 15, 15, 0, 35, 0, 1, 0, 0, 0, 12, 49153
map_035_object_06:
    map_object 0, 1, 15, 18, 0, 44, 0, 1, 0, 0, 0, 12, 49153
map_035_object_07:
    map_object 0, 1, 15, 23, 0, 47, 0, 1, 0, 0, 0, 12, 49153
map_035_object_08:
    map_object 0, 1, 15, 36, 0, 38, 0, 1, 0, 0, 0, 12, 49153
map_035_object_09:
    map_object 0, 1, 15, 35, 0, 27, 0, 1, 0, 0, 0, 12, 49153
map_035_object_10:
    map_object 0, 1, 15, 30, 0, 30, 0, 1, 0, 0, 0, 12, 49153
map_035_object_11:
    map_object 0, 1, 15, 30, 0, 30, 0, 1, 0, 0, 7, 204, 0
map_036_header:
    map_header 1, 3, 65, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 255
map_036_object_00:
    map_object 0, 1, 15, 24, 0, 29, 0, 1, 0, 0, 0, 12, 49153
map_036_object_01:
    map_object 0, 1, 15, 37, 0, 28, 0, 1, 0, 0, 0, 12, 49153
map_036_object_02:
    map_object 0, 1, 15, 12, 0, 20, 0, 1, 0, 0, 0, 21, 49153
map_036_object_03:
    map_object 0, 1, 15, 17, 0, 30, 0, 1, 0, 0, 0, 21, 49153
map_036_object_04:
    map_object 0, 1, 15, 20, 0, 35, 0, 1, 0, 0, 0, 21, 49153
map_036_object_05:
    map_object 0, 1, 15, 28, 0, 44, 0, 1, 0, 0, 0, 21, 49153
map_036_object_06:
    map_object 0, 1, 15, 34, 0, 37, 0, 1, 0, 0, 0, 21, 49153
map_036_object_07:
    map_object 0, 1, 15, 36, 0, 36, 0, 1, 0, 0, 0, 21, 49153
map_036_object_08:
    map_object 0, 1, 15, 36, 0, 43, 0, 1, 0, 0, 0, 21, 49153
map_036_object_09:
    map_object 0, 1, 15, 38, 0, 29, 0, 1, 0, 0, 0, 21, 49153
map_036_object_10:
    map_object 0, 1, 15, 38, 0, 29, 0, 1, 0, 0, 7, 204, 0
map_037_header:
    map_header 1, 3, 66, 1, 1, 2, 0, 1, 0, 0, 4, 4, 0, 0, 39
map_037_object_00:
    map_object 32, 0, 2, 28, 1, 20, 1, 0, 0, 0, 0, 156, 16957
map_037_object_01:
    map_object 32, 0, 2, 16, 1, 36, 0, 1, 2, 0, 0, 152, 49739
map_037_object_02:
    map_object 32, 0, 2, 21, 1, 32, 0, 3, 2, 0, 0, 152, 49739
map_037_object_03:
    map_object 32, 0, 2, 35, 1, 26, 0, 2, 2, 0, 0, 152, 49739
map_037_object_04:
    map_object 32, 0, 2, 24, 1, 27, 0, 1, 2, 0, 0, 152, 49739
map_037_object_05:
    map_object 32, 0, 2, 35, 1, 42, 0, 0, 2, 0, 0, 136, 49739
map_037_object_06:
    map_object 32, 0, 2, 21, 1, 46, 0, 3, 2, 0, 0, 136, 49739
map_038_header:
    map_header 5, 2, 29, 0, 5, 2, 0, 1, 0, 0, 4, 0, 0, 0, 255
map_038_object_00:
    map_object 0, 0, 15, 16, 0, 16, 0, 1, 0, 0, 7, 204, 0
map_038_object_01:
    map_object 0, 0, 15, 23, 0, 18, 0, 2, 0, 0, 7, 204, 0
map_038_object_02:
    map_object 0, 0, 15, 22, 0, 20, 0, 1, 0, 0, 7, 204, 0
map_039_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 14
map_039_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_039_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_039_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_039_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_039_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_039_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_039_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_039_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_039_object_08:
    map_object 0, 0, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16591
map_03A_header:
    map_header 5, 3, 61, 1, 5, 2, 0, 0, 0, 0, 0, 4, 0, 0, 255
map_03A_object_00:
    map_object 32, 0, 2, 19, 1, 20, 0, 1, 0, 0, 0, 22, 49153
map_03A_object_01:
    map_object 32, 0, 2, 19, 1, 27, 0, 0, 0, 0, 0, 22, 49153
map_03A_object_02:
    map_object 32, 0, 2, 26, 1, 24, 0, 0, 0, 0, 0, 22, 49153
map_03B_header:
    map_header 5, 3, 61, 1, 5, 2, 0, 1, 0, 0, 0, 4, 0, 0, 39
map_03B_object_00:
    map_object 32, 3, 15, 28, 1, 27, 1, 1, 0, 0, 0, 156, 16957
map_03B_object_01:
    map_object 32, 3, 15, 19, 1, 19, 1, 1, 1, 0, 0, 153, 16956
map_03B_object_02:
    map_object 32, 3, 15, 22, 1, 16, 0, 1, 2, 0, 0, 152, 49738
map_03B_object_03:
    map_object 32, 3, 15, 26, 1, 20, 0, 3, 2, 0, 0, 152, 49738
map_03B_object_04:
    map_object 32, 3, 15, 16, 1, 24, 0, 2, 2, 0, 0, 152, 49738
map_03B_object_05:
    map_object 32, 3, 15, 25, 1, 27, 0, 3, 2, 0, 0, 136, 49738
map_03B_object_06:
    map_object 32, 3, 15, 22, 1, 22, 0, 0, 2, 0, 0, 136, 49738
map_03B_object_07:
    map_object 184, 0, 1, 23, 1, 16, 1, 0, 3, 0, 0, 235, 18032
map_03B_object_08:
    map_object 186, 0, 1, 28, 1, 20, 1, 0, 3, 0, 0, 235, 18034
map_03C_header:
    map_header 1, 0, 25, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 255
map_03C_object_00:
    map_object 33, 0, 2, 15, 1, 10, 0, 1, 0, 0, 0, 93, 49745
map_03D_header:
    map_header 12, 2, 36, 0, 12, 2, 0, 1, 0, 0, 4, 0, 0, 0, 255
map_03D_object_00:
    map_object 0, 0, 15, 20, 0, 9, 0, 1, 0, 0, 0, 41, 49153
map_03D_object_01:
    map_object 0, 0, 15, 46, 0, 8, 0, 2, 0, 0, 0, 41, 49153
map_03D_object_02:
    map_object 0, 0, 15, 47, 0, 12, 0, 3, 0, 0, 0, 41, 49153
map_03D_object_03:
    map_object 0, 0, 15, 36, 0, 18, 0, 2, 0, 0, 0, 41, 49153
map_03D_object_04:
    map_object 0, 0, 15, 23, 0, 29, 0, 1, 0, 0, 0, 41, 49153
map_03D_object_05:
    map_object 0, 0, 15, 15, 0, 12, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_06:
    map_object 0, 0, 15, 25, 0, 9, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_07:
    map_object 0, 0, 15, 41, 0, 10, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_08:
    map_object 0, 0, 15, 43, 0, 10, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_09:
    map_object 0, 0, 15, 40, 0, 20, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_10:
    map_object 0, 0, 15, 38, 0, 19, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_11:
    map_object 0, 0, 15, 30, 0, 17, 0, 1, 0, 0, 0, 43, 49153
map_03D_object_12:
    map_object 0, 0, 15, 27, 0, 16, 0, 1, 0, 0, 0, 43, 49153
map_03E_header:
    map_header 12, 2, 36, 0, 12, 2, 1, 1, 0, 6, 4, 9, 0, 0, 255
map_03E_object_00:
    map_object 63, 0, 5, 35, 0, 33, 1, 1, 0, 0, 0, 153, 17176
map_03E_object_01:
    map_object 0, 0, 15, 26, 0, 25, 0, 1, 0, 0, 0, 40, 49153
map_03E_object_02:
    map_object 0, 0, 15, 39, 0, 42, 0, 1, 0, 0, 0, 40, 49153
map_03E_object_03:
    map_object 0, 0, 15, 52, 0, 47, 0, 1, 0, 0, 0, 40, 49153
map_03E_object_04:
    map_object 0, 0, 15, 49, 0, 37, 0, 1, 0, 0, 0, 40, 49153
map_03E_object_05:
    map_object 0, 0, 15, 26, 0, 21, 0, 3, 0, 0, 0, 40, 49153
map_03E_object_06:
    map_object 0, 0, 15, 20, 0, 24, 0, 2, 0, 0, 0, 40, 49153
map_03E_object_07:
    map_object 0, 0, 15, 20, 0, 30, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_08:
    map_object 0, 0, 15, 26, 0, 31, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_09:
    map_object 0, 0, 15, 14, 0, 42, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_10:
    map_object 0, 0, 15, 20, 0, 48, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_11:
    map_object 0, 0, 15, 29, 0, 26, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_12:
    map_object 0, 0, 15, 35, 0, 37, 0, 1, 0, 0, 0, 41, 49153
map_03E_object_13:
    map_object 0, 0, 15, 15, 0, 36, 0, 1, 0, 0, 0, 43, 49153
map_03E_object_14:
    map_object 0, 0, 15, 14, 0, 37, 0, 1, 0, 0, 0, 43, 49153
map_03E_object_15:
    map_object 0, 0, 15, 54, 0, 40, 0, 1, 0, 0, 0, 43, 49153
map_03E_object_16:
    map_object 0, 0, 15, 48, 0, 31, 0, 1, 0, 0, 0, 43, 49153
map_03E_object_17:
    map_object 0, 0, 15, 36, 0, 48, 0, 1, 0, 0, 0, 43, 49153
map_03E_object_18:
    map_object 0, 0, 15, 30, 0, 25, 0, 1, 0, 0, 0, 43, 49153
map_03F_header:
    map_header 0, 3, 24, 0, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 61
map_03F_object_00:
    map_object 62, 0, 15, 16, 1, 29, 0, 1, 1, 0, 0, 170, 50131
map_03F_object_01:
    map_object 62, 0, 15, 25, 1, 8, 0, 1, 1, 0, 0, 170, 50132
map_03F_object_02:
    map_object 62, 0, 15, 10, 1, 18, 0, 3, 2, 0, 0, 201, 50133
map_03F_object_03:
    map_object 62, 0, 15, 15, 1, 9, 0, 1, 2, 0, 0, 202, 50134
map_03F_object_04:
    map_object 62, 0, 15, 22, 1, 29, 0, 0, 0, 0, 0, 197, 50129
map_03F_object_05:
    map_object 62, 0, 15, 32, 1, 30, 0, 1, 0, 0, 0, 196, 50128
map_03F_object_06:
    map_object 62, 0, 15, 25, 1, 24, 0, 2, 0, 0, 0, 199, 50130
map_040_header:
    map_header 34, 2, 68, 0, 8, 2, 0, 1, 0, 6, 4, 9, 0, 0, 61
map_040_object_00:
    map_object 62, 0, 15, 17, 1, 38, 0, 1, 1, 0, 0, 170, 50147
map_040_object_01:
    map_object 62, 0, 15, 30, 1, 52, 0, 1, 1, 0, 0, 170, 50148
map_040_object_02:
    map_object 62, 0, 15, 24, 1, 57, 0, 1, 1, 0, 0, 170, 50149
map_040_object_03:
    map_object 62, 0, 15, 13, 1, 30, 0, 1, 1, 0, 0, 170, 50150
map_040_object_04:
    map_object 62, 0, 15, 25, 1, 44, 0, 3, 2, 0, 0, 201, 50151
map_040_object_05:
    map_object 62, 0, 15, 13, 1, 55, 0, 1, 2, 0, 0, 202, 50152
map_040_object_06:
    map_object 62, 0, 15, 12, 1, 44, 0, 2, 0, 0, 0, 200, 50146
map_041_header:
    map_header 35, 2, 60, 0, 9, 2, 0, 1, 0, 0, 3, 0, 0, 0, 13
map_041_object_00:
    map_object 62, 0, 15, 16, 1, 8, 1, 1, 3, 1, 7, 210, 21481
map_041_object_01:
    map_object 62, 0, 15, 20, 1, 8, 1, 1, 3, 1, 7, 210, 21486
map_041_object_02:
    map_object 62, 0, 15, 15, 1, 10, 1, 1, 3, 1, 7, 210, 21482
map_041_object_03:
    map_object 62, 0, 15, 18, 1, 10, 1, 1, 3, 1, 7, 210, 21487
map_041_object_04:
    map_object 62, 0, 15, 21, 1, 10, 1, 1, 3, 1, 7, 210, 21485
map_041_object_05:
    map_object 62, 0, 15, 16, 1, 12, 1, 1, 3, 1, 7, 210, 21483
map_041_object_06:
    map_object 62, 0, 15, 20, 1, 12, 1, 1, 3, 1, 7, 210, 21484
map_042_header:
    map_header 35, 2, 60, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_043_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_043_object_00:
    map_object 0, 0, 15, 23, 0, 17, 0, 1, 0, 0, 0, 50, 49153
map_043_object_01:
    map_object 0, 0, 15, 28, 0, 24, 0, 1, 0, 0, 0, 50, 49153
map_043_object_02:
    map_object 0, 0, 15, 16, 0, 24, 0, 1, 0, 0, 0, 50, 49153
map_043_object_03:
    map_object 0, 0, 15, 18, 0, 29, 0, 1, 0, 0, 0, 23, 49153
map_043_object_04:
    map_object 0, 0, 15, 27, 0, 29, 0, 1, 0, 0, 0, 23, 49153
map_043_object_05:
    map_object 0, 0, 15, 22, 0, 31, 0, 1, 0, 0, 0, 23, 49153
map_044_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_044_object_00:
    map_object 0, 0, 15, 17, 0, 20, 0, 1, 0, 0, 0, 36, 49153
map_044_object_01:
    map_object 0, 0, 15, 20, 0, 28, 0, 1, 0, 0, 0, 36, 49153
map_044_object_02:
    map_object 0, 0, 15, 29, 0, 19, 0, 1, 0, 0, 0, 36, 49153
map_044_object_03:
    map_object 0, 0, 15, 34, 0, 26, 0, 1, 0, 0, 0, 36, 49153
map_044_object_04:
    map_object 0, 0, 15, 24, 0, 34, 0, 1, 0, 0, 0, 36, 49153
map_044_object_05:
    map_object 0, 0, 15, 15, 0, 31, 0, 1, 0, 0, 0, 36, 49153
map_044_object_06:
    map_object 0, 1, 15, 28, 0, 29, 0, 1, 0, 0, 7, 204, 0
map_045_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_045_object_00:
    map_object 0, 0, 15, 34, 0, 28, 0, 1, 0, 0, 0, 50, 49153
map_045_object_01:
    map_object 0, 0, 15, 31, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_045_object_02:
    map_object 0, 0, 15, 24, 0, 22, 0, 1, 0, 0, 0, 50, 49153
map_045_object_03:
    map_object 0, 0, 15, 17, 0, 20, 0, 1, 0, 0, 0, 50, 49153
map_045_object_04:
    map_object 0, 0, 15, 16, 0, 27, 0, 1, 0, 0, 0, 50, 49153
map_045_object_05:
    map_object 0, 0, 15, 19, 0, 34, 0, 1, 0, 0, 0, 50, 49153
map_045_object_06:
    map_object 0, 0, 15, 26, 0, 34, 0, 1, 0, 0, 0, 50, 49153
map_046_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_046_object_00:
    map_object 0, 0, 15, 22, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_046_object_01:
    map_object 0, 0, 15, 14, 0, 31, 0, 1, 0, 0, 0, 50, 49153
map_046_object_02:
    map_object 0, 0, 15, 14, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_046_object_03:
    map_object 0, 0, 15, 32, 0, 23, 0, 1, 0, 0, 0, 50, 49153
map_046_object_04:
    map_object 0, 0, 15, 24, 0, 31, 0, 1, 0, 0, 0, 50, 49153
map_047_header:
    map_header 26, 1, 50, 0, 26, 2, 0, 0, 0, 0, 3, 2, 0, 0, 255
map_047_object_00:
    map_object 71, 0, 0, 9, 0, 50, 0, 1, 0, 0, 0, 183, 50540
map_047_object_01:
    map_object 71, 0, 0, 18, 0, 50, 0, 3, 0, 0, 0, 167, 49193
map_047_object_02:
    map_object 71, 0, 0, 12, 0, 53, 0, 0, 0, 0, 0, 194, 50350
map_047_object_03:
    map_object 71, 0, 0, 18, 0, 65, 1, 1, 0, 0, 0, 156, 16958
map_048_header:
    map_header 10, 0, 34, 0, 10, 2, 0, 1, 0, 0, 1, 0, 0, 0, 255
map_048_object_00:
    map_object 63, 0, 4, 15, 1, 13, 0, 1, 0, 0, 0, 46, 49152
map_048_object_01:
    map_object 63, 0, 4, 13, 1, 13, 0, 1, 0, 0, 0, 63, 49152
map_048_object_02:
    map_object 63, 0, 4, 17, 1, 13, 0, 1, 0, 0, 0, 32, 49152
map_049_header:
    map_header 10, 2, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_049_object_00:
    map_object 23, 0, 0, 39, 0, 59, 1, 1, 0, 0, 0, 153, 16855
map_04B_header:
    map_header 14, 3, 84, 1, 14, 2, 0, 1, 0, 0, 4, 2, 0, 0, 255
map_04B_object_00:
    map_object 38, 0, 3, 16, 0, 18, 0, 1, 0, 0, 0, 52, 49153
map_04B_object_01:
    map_object 38, 0, 3, 23, 0, 18, 0, 1, 0, 0, 0, 52, 49153
map_04C_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_04C_object_00:
    map_object 0, 0, 15, 21, 0, 29, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_01:
    map_object 0, 0, 15, 22, 0, 34, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_02:
    map_object 0, 0, 15, 18, 0, 52, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_03:
    map_object 0, 0, 15, 12, 0, 55, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_04:
    map_object 0, 0, 15, 27, 0, 38, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_05:
    map_object 0, 0, 15, 31, 0, 38, 0, 1, 0, 0, 0, 27, 49153
map_04C_object_06:
    map_object 0, 0, 15, 10, 0, 18, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_07:
    map_object 0, 0, 15, 25, 0, 53, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_08:
    map_object 0, 0, 15, 38, 0, 52, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_09:
    map_object 0, 0, 15, 33, 0, 49, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_10:
    map_object 0, 0, 15, 38, 0, 20, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_11:
    map_object 0, 0, 15, 31, 0, 18, 0, 1, 0, 0, 0, 52, 49153
map_04C_object_12:
    map_object 0, 0, 15, 10, 0, 23, 0, 1, 0, 0, 0, 29, 49153
map_04C_object_13:
    map_object 0, 0, 15, 15, 0, 41, 0, 1, 0, 0, 0, 29, 49153
map_04C_object_14:
    map_object 0, 0, 15, 14, 0, 45, 0, 1, 0, 0, 0, 29, 49153
map_04C_object_15:
    map_object 0, 0, 15, 35, 0, 33, 0, 1, 0, 0, 0, 29, 49153
map_04D_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_04D_object_00:
    map_object 0, 0, 15, 9, 0, 20, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_01:
    map_object 0, 0, 15, 21, 0, 32, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_02:
    map_object 0, 0, 15, 20, 0, 32, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_03:
    map_object 0, 0, 15, 10, 0, 45, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_04:
    map_object 0, 0, 15, 16, 0, 54, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_05:
    map_object 0, 0, 15, 24, 0, 41, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_06:
    map_object 0, 0, 15, 36, 0, 31, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_07:
    map_object 0, 0, 15, 36, 0, 21, 0, 1, 0, 0, 0, 27, 49153
map_04D_object_08:
    map_object 0, 0, 15, 14, 0, 26, 0, 1, 0, 0, 0, 29, 49153
map_04D_object_09:
    map_object 0, 0, 15, 18, 0, 41, 0, 1, 0, 0, 0, 29, 49153
map_04D_object_10:
    map_object 0, 0, 15, 26, 0, 53, 0, 1, 0, 0, 0, 29, 49153
map_04D_object_11:
    map_object 0, 0, 15, 36, 0, 40, 0, 1, 0, 0, 0, 29, 49153
map_04D_object_12:
    map_object 0, 0, 15, 29, 0, 38, 0, 1, 0, 0, 0, 29, 49153
map_04D_object_13:
    map_object 0, 0, 15, 10, 0, 52, 0, 1, 0, 0, 0, 22, 49153
map_04D_object_14:
    map_object 0, 0, 15, 37, 0, 50, 0, 1, 0, 0, 0, 22, 49153
map_04D_object_15:
    map_object 0, 0, 15, 30, 0, 18, 0, 1, 0, 0, 0, 22, 49153
map_04D_object_16:
    map_object 0, 1, 15, 28, 0, 29, 0, 1, 0, 0, 7, 204, 0
map_04E_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_04E_object_00:
    map_object 0, 0, 15, 16, 0, 16, 1, 1, 0, 0, 0, 153, 18015
map_04F_header:
    map_header 13, 0, 37, 1, 13, 2, 0, 0, 0, 0, 0, 1, 0, 0, 255
map_04F_object_00:
    map_object 0, 0, 15, 16, 1, 22, 0, 1, 0, 0, 0, 104, 17281
map_050_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_050_object_00:
    map_object 0, 0, 15, 23, 0, 34, 0, 1, 0, 0, 0, 27, 49153
map_050_object_01:
    map_object 0, 0, 15, 46, 0, 34, 0, 1, 0, 0, 0, 27, 49153
map_050_object_02:
    map_object 0, 0, 15, 40, 0, 17, 0, 1, 0, 0, 0, 27, 49153
map_050_object_03:
    map_object 0, 0, 15, 14, 0, 18, 0, 1, 0, 0, 0, 27, 49153
map_050_object_04:
    map_object 0, 0, 15, 9, 0, 27, 0, 1, 0, 0, 0, 27, 49153
map_050_object_05:
    map_object 0, 0, 15, 8, 0, 33, 0, 1, 0, 0, 0, 27, 49153
map_050_object_06:
    map_object 0, 0, 15, 15, 0, 35, 0, 1, 0, 0, 0, 27, 49153
map_050_object_07:
    map_object 0, 0, 15, 37, 0, 37, 0, 1, 0, 0, 0, 27, 49153
map_050_object_08:
    map_object 0, 0, 15, 48, 0, 30, 0, 1, 0, 0, 0, 27, 49153
map_050_object_09:
    map_object 0, 0, 15, 41, 0, 22, 0, 1, 0, 0, 0, 27, 49153
map_050_object_10:
    map_object 0, 0, 15, 52, 0, 20, 0, 1, 0, 0, 0, 27, 49153
map_050_object_11:
    map_object 0, 0, 15, 34, 0, 17, 0, 1, 0, 0, 0, 27, 49153
map_050_object_12:
    map_object 0, 0, 15, 26, 0, 28, 0, 1, 0, 0, 0, 27, 49153
map_050_object_13:
    map_object 0, 0, 15, 21, 0, 22, 0, 1, 0, 0, 0, 27, 49153
map_051_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_051_object_00:
    map_object 0, 0, 15, 22, 0, 37, 0, 1, 0, 0, 0, 27, 49153
map_051_object_01:
    map_object 0, 0, 15, 22, 0, 37, 0, 1, 0, 0, 0, 22, 49153
map_051_object_02:
    map_object 0, 0, 15, 12, 0, 52, 0, 1, 0, 0, 0, 22, 49153
map_051_object_03:
    map_object 0, 0, 15, 37, 0, 50, 0, 1, 0, 0, 0, 22, 49153
map_051_object_04:
    map_object 0, 0, 15, 36, 0, 21, 0, 1, 0, 0, 0, 22, 49153
map_051_object_05:
    map_object 0, 0, 15, 21, 0, 32, 0, 1, 0, 0, 0, 27, 49153
map_051_object_06:
    map_object 0, 0, 15, 16, 0, 41, 0, 1, 0, 0, 0, 27, 49153
map_051_object_07:
    map_object 0, 0, 15, 15, 0, 51, 0, 1, 0, 0, 0, 27, 49153
map_051_object_08:
    map_object 0, 0, 15, 36, 0, 40, 0, 1, 0, 0, 0, 27, 49153
map_051_object_09:
    map_object 0, 0, 15, 29, 0, 47, 0, 1, 0, 0, 0, 27, 49153
map_051_object_10:
    map_object 0, 0, 15, 35, 0, 36, 0, 1, 0, 0, 0, 27, 49153
map_051_object_11:
    map_object 0, 0, 15, 37, 0, 29, 0, 1, 0, 0, 0, 27, 49153
map_051_object_12:
    map_object 0, 0, 15, 28, 0, 18, 0, 1, 0, 0, 0, 27, 49153
map_051_object_13:
    map_object 0, 0, 15, 21, 0, 20, 0, 1, 0, 0, 0, 27, 49153
map_051_object_14:
    map_object 0, 0, 15, 13, 0, 21, 0, 1, 0, 0, 0, 27, 49153
map_051_object_15:
    map_object 0, 0, 15, 12, 0, 42, 0, 1, 0, 0, 0, 52, 49153
map_051_object_16:
    map_object 0, 0, 15, 23, 0, 53, 0, 1, 0, 0, 0, 52, 49153
map_052_header:
    map_header 14, 3, 83, 1, 14, 2, 0, 1, 0, 0, 4, 2, 0, 0, 255
map_052_object_00:
    map_object 52, 0, 3, 8, 1, 16, 1, 1, 0, 0, 0, 182, 17698
map_052_object_01:
    map_object 52, 0, 3, 31, 1, 16, 1, 1, 0, 0, 0, 182, 17698
map_052_object_02:
    map_object 52, 4, 14, 20, 0, 36, 0, 1, 0, 0, 0, 62, 49153
map_052_object_03:
    map_object 52, 4, 14, 16, 0, 32, 0, 1, 0, 0, 0, 62, 49153
map_052_object_04:
    map_object 52, 4, 14, 6, 0, 18, 0, 1, 0, 0, 0, 62, 49153
map_052_object_05:
    map_object 52, 4, 14, 10, 0, 18, 0, 1, 0, 0, 0, 62, 49153
map_052_object_06:
    map_object 52, 4, 14, 29, 0, 18, 0, 1, 0, 0, 0, 62, 49153
map_052_object_07:
    map_object 52, 4, 14, 33, 0, 18, 0, 1, 0, 0, 0, 62, 49153
map_052_object_08:
    map_object 52, 4, 14, 23, 0, 32, 0, 1, 0, 0, 0, 62, 49153
map_053_header:
    map_header 13, 2, 37, 1, 13, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_053_object_00:
    map_object 0, 0, 15, 16, 0, 18, 0, 1, 0, 0, 0, 52, 49153
map_053_object_01:
    map_object 0, 0, 15, 12, 0, 23, 0, 3, 0, 0, 0, 27, 49153
map_053_object_02:
    map_object 0, 0, 15, 19, 0, 22, 0, 2, 0, 0, 0, 27, 49153
map_054_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_055_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_055_object_00:
    map_object 0, 0, 15, 28, 0, 29, 0, 1, 0, 0, 0, 36, 49153
map_055_object_01:
    map_object 0, 0, 15, 20, 0, 23, 0, 1, 0, 0, 0, 36, 49153
map_055_object_02:
    map_object 0, 0, 15, 14, 0, 31, 0, 1, 0, 0, 0, 36, 49153
map_055_object_03:
    map_object 0, 0, 15, 26, 0, 35, 0, 1, 0, 0, 0, 36, 49153
map_055_object_04:
    map_object 0, 0, 15, 26, 0, 18, 0, 1, 0, 0, 0, 36, 49153
map_055_object_05:
    map_object 0, 0, 15, 21, 0, 32, 0, 1, 0, 0, 0, 36, 49153
map_056_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_056_object_00:
    map_object 0, 0, 15, 23, 0, 33, 0, 1, 0, 0, 0, 36, 49153
map_056_object_01:
    map_object 0, 0, 15, 26, 0, 20, 0, 1, 0, 0, 0, 36, 49153
map_056_object_02:
    map_object 0, 0, 15, 15, 0, 20, 0, 1, 0, 0, 0, 36, 49153
map_056_object_03:
    map_object 0, 0, 15, 21, 0, 23, 0, 1, 0, 0, 0, 22, 49153
map_056_object_04:
    map_object 0, 0, 15, 13, 0, 31, 0, 1, 0, 0, 0, 22, 49153
map_056_object_05:
    map_object 0, 0, 15, 34, 0, 33, 0, 1, 0, 0, 0, 22, 49153
map_057_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_057_object_00:
    map_object 0, 0, 15, 23, 0, 27, 0, 1, 0, 0, 0, 50, 49153
map_057_object_01:
    map_object 0, 0, 15, 34, 0, 26, 0, 1, 0, 0, 0, 50, 49153
map_057_object_02:
    map_object 0, 0, 15, 19, 0, 34, 0, 1, 0, 0, 0, 50, 49153
map_057_object_03:
    map_object 0, 0, 15, 12, 0, 29, 0, 1, 0, 0, 0, 50, 49153
map_057_object_04:
    map_object 0, 0, 15, 21, 0, 19, 0, 1, 0, 0, 0, 50, 49153
map_057_object_05:
    map_object 0, 0, 15, 28, 0, 20, 0, 1, 0, 0, 0, 50, 49153
map_058_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_058_object_00:
    map_object 0, 0, 15, 17, 0, 27, 0, 1, 0, 0, 0, 50, 49153
map_058_object_01:
    map_object 0, 0, 15, 25, 0, 27, 0, 1, 0, 0, 0, 50, 49153
map_058_object_02:
    map_object 0, 0, 15, 22, 0, 20, 0, 1, 0, 0, 0, 23, 49153
map_058_object_03:
    map_object 0, 0, 15, 33, 0, 26, 0, 1, 0, 0, 0, 23, 49153
map_058_object_04:
    map_object 0, 0, 15, 23, 0, 31, 0, 1, 0, 0, 0, 23, 49153
map_058_object_05:
    map_object 0, 0, 15, 12, 0, 24, 0, 1, 0, 0, 0, 23, 49153
map_059_header:
    map_header 32, 2, 71, 0, 25, 2, 0, 1, 0, 0, 4, 4, 0, 0, 45
map_059_object_00:
    map_object 41, 0, 14, 23, 1, 16, 0, 1, 0, 0, 0, 207, 17072
map_059_object_01:
    map_object 41, 0, 14, 25, 1, 16, 1, 1, 1, 0, 0, 187, 17076
map_059_object_02:
    map_object 41, 0, 14, 29, 1, 33, 0, 1, 2, 0, 0, 207, 49845
map_059_object_03:
    map_object 41, 0, 14, 33, 1, 14, 0, 1, 2, 0, 0, 207, 49846
map_059_object_04:
    map_object 41, 0, 14, 33, 1, 25, 0, 1, 2, 0, 0, 207, 21257
map_059_object_05:
    map_object 41, 0, 14, 11, 1, 11, 0, 3, 1, 0, 0, 198, 49847
map_059_object_06:
    map_object 41, 0, 14, 24, 1, 23, 0, 1, 1, 0, 0, 199, 49848
map_059_object_07:
    map_object 41, 0, 14, 17, 1, 40, 0, 2, 1, 0, 0, 200, 49849
map_059_object_08:
    map_object 36, 0, 15, 37, 1, 15, 1, 0, 3, 0, 0, 156, 17084
map_05A_header:
    map_header 33, 0, 74, 0, 31, 2, 0, 1, 0, 0, 4, 0, 0, 0, 255
map_05A_object_00:
    map_object 44, 0, 2, 33, 0, 32, 0, 1, 0, 0, 0, 28, 49153
map_05A_object_01:
    map_object 44, 0, 2, 24, 0, 32, 0, 1, 0, 0, 0, 28, 49153
map_05A_object_02:
    map_object 44, 0, 2, 29, 0, 51, 0, 1, 0, 0, 0, 36, 49153
map_05A_object_03:
    map_object 44, 0, 2, 36, 0, 53, 0, 1, 0, 0, 0, 36, 49153
map_05A_object_04:
    map_object 44, 0, 2, 28, 0, 38, 0, 1, 0, 0, 0, 50, 49153
map_05A_object_05:
    map_object 44, 0, 2, 38, 0, 50, 0, 1, 0, 0, 0, 50, 49153
map_05A_object_06:
    map_object 44, 0, 2, 28, 0, 58, 0, 1, 0, 0, 0, 50, 49153
map_05B_header:
    map_header 3, 0, 27, 0, 3, 2, 0, 0, 0, 1, 0, 6, 0, 0, 44
map_05B_object_00:
    map_object 40, 0, 15, 22, 1, 21, 1, 1, 0, 0, 0, 185, 17058
map_05B_object_01:
    map_object 40, 0, 15, 24, 1, 21, 1, 2, 2, 0, 0, 184, 17059
map_05B_object_02:
    map_object 40, 0, 15, 23, 1, 25, 0, 3, 3, 0, 0, 168, 49828
map_05B_object_03:
    map_object 40, 0, 15, 26, 1, 27, 0, 0, 1, 0, 0, 183, 49829
map_05B_object_04:
    map_object 40, 0, 15, 15, 1, 31, 0, 0, 1, 0, 0, 183, 49830
map_05B_object_05:
    map_object 40, 0, 15, 29, 1, 22, 0, 1, 1, 0, 0, 183, 49831
map_05C_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_05C_object_00:
    map_object 0, 0, 15, 17, 0, 23, 0, 1, 0, 0, 0, 50, 49153
map_05C_object_01:
    map_object 0, 0, 15, 29, 0, 25, 0, 1, 0, 0, 0, 50, 49153
map_05C_object_02:
    map_object 0, 0, 15, 21, 0, 33, 0, 1, 0, 0, 0, 50, 49153
map_05C_object_03:
    map_object 0, 0, 15, 12, 0, 23, 0, 1, 0, 0, 0, 37, 49153
map_05C_object_04:
    map_object 0, 0, 15, 20, 0, 27, 0, 1, 0, 0, 0, 37, 49153
map_05C_object_05:
    map_object 0, 0, 15, 29, 0, 30, 0, 1, 0, 0, 0, 37, 49153
map_05C_object_06:
    map_object 0, 1, 15, 28, 0, 29, 0, 1, 0, 0, 7, 204, 0
map_05D_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_05D_object_00:
    map_object 0, 0, 15, 21, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_05D_object_01:
    map_object 0, 0, 15, 13, 0, 29, 0, 1, 0, 0, 0, 50, 49153
map_05D_object_02:
    map_object 0, 0, 15, 12, 0, 24, 0, 1, 0, 0, 0, 37, 49153
map_05D_object_03:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 37, 49153
map_05D_object_04:
    map_object 0, 0, 15, 28, 0, 19, 0, 1, 0, 0, 0, 37, 49153
map_05D_object_05:
    map_object 0, 0, 15, 28, 0, 26, 0, 1, 0, 0, 0, 37, 49153
map_05E_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_05E_object_00:
    map_object 0, 0, 15, 33, 0, 29, 0, 1, 0, 0, 0, 50, 49153
map_05E_object_01:
    map_object 0, 0, 15, 14, 0, 31, 0, 1, 0, 0, 0, 50, 49153
map_05E_object_02:
    map_object 0, 0, 15, 21, 0, 27, 0, 1, 0, 0, 0, 50, 49153
map_05E_object_03:
    map_object 0, 0, 15, 28, 0, 33, 0, 1, 0, 0, 0, 50, 49153
map_05E_object_04:
    map_object 0, 0, 15, 14, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_05E_object_05:
    map_object 0, 0, 15, 32, 0, 23, 0, 1, 0, 0, 0, 50, 49153
map_05F_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_05F_object_00:
    map_object 0, 0, 15, 14, 0, 30, 0, 1, 0, 0, 0, 50, 49153
map_05F_object_01:
    map_object 0, 0, 15, 22, 0, 21, 0, 1, 0, 0, 0, 50, 49153
map_05F_object_02:
    map_object 0, 0, 15, 26, 0, 31, 0, 1, 0, 0, 0, 50, 49153
map_05F_object_03:
    map_object 0, 0, 15, 32, 0, 23, 0, 1, 0, 0, 0, 50, 49153
map_05F_object_04:
    map_object 0, 0, 15, 24, 0, 26, 0, 1, 0, 0, 0, 50, 49153
map_060_header:
    map_header 3, 0, 110, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_060_object_00:
    map_object 0, 0, 15, 26, 0, 35, 0, 1, 0, 0, 0, 37, 49153
map_060_object_01:
    map_object 0, 0, 15, 18, 0, 30, 0, 1, 0, 0, 0, 37, 49153
map_060_object_02:
    map_object 0, 0, 15, 28, 0, 27, 0, 1, 0, 0, 0, 37, 49153
map_060_object_03:
    map_object 0, 0, 15, 17, 0, 23, 0, 1, 0, 0, 0, 37, 49153
map_060_object_04:
    map_object 0, 0, 15, 26, 0, 20, 0, 1, 0, 0, 0, 37, 49153
map_060_object_05:
    map_object 0, 0, 15, 16, 0, 33, 0, 1, 0, 0, 0, 37, 49153
map_061_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 1, 0, 1, 4, 6, 0, 0, 255
map_061_object_00:
    map_object 0, 0, 15, 15, 0, 21, 0, 1, 0, 0, 0, 37, 49153
map_061_object_01:
    map_object 0, 0, 15, 26, 0, 23, 0, 1, 0, 0, 0, 37, 49153
map_061_object_02:
    map_object 0, 0, 15, 21, 0, 27, 0, 1, 0, 0, 0, 37, 49153
map_061_object_03:
    map_object 0, 0, 15, 20, 0, 33, 0, 1, 0, 0, 0, 37, 49153
map_061_object_04:
    map_object 0, 0, 15, 27, 0, 26, 0, 1, 0, 0, 0, 37, 49153
map_062_header:
    map_header 18, 0, 111, 1, 18, 2, 0, 1, 0, 0, 0, 0, 0, 0, 43
map_062_object_00:
    map_object 40, 10, 11, 25, 1, 5, 1, 1, 0, 0, 0, 177, 4766
map_062_object_01:
    map_object 40, 10, 11, 23, 1, 6, 1, 1, 2, 0, 0, 182, 4766
map_062_object_02:
    map_object 40, 10, 11, 28, 1, 6, 1, 1, 2, 0, 0, 182, 4766
map_062_object_03:
    map_object 40, 10, 11, 21, 1, 10, 1, 2, 2, 0, 0, 182, 17055
map_062_object_04:
    map_object 40, 10, 11, 19, 1, 10, 1, 3, 1, 0, 0, 183, 17056
map_062_object_05:
    map_object 40, 10, 11, 32, 1, 10, 1, 1, 2, 0, 0, 182, 17055
map_062_object_06:
    map_object 40, 10, 11, 32, 1, 12, 1, 0, 1, 0, 0, 183, 17056
map_062_object_07:
    map_object 40, 0, 9, 25, 1, 22, 1, 0, 1, 0, 0, 183, 17066
map_063_header:
    map_header 18, 0, 111, 1, 18, 2, 0, 1, 0, 3, 0, 0, 0, 0, 43
map_063_object_00:
    map_object 40, 10, 11, 25, 1, 5, 1, 1, 0, 0, 0, 177, 4766
map_063_object_01:
    map_object 40, 10, 11, 23, 1, 6, 1, 1, 2, 0, 0, 182, 4766
map_063_object_02:
    map_object 40, 10, 11, 28, 1, 6, 1, 1, 2, 0, 0, 182, 4766
map_063_object_03:
    map_object 40, 10, 11, 21, 1, 10, 1, 2, 2, 0, 0, 182, 17055
map_063_object_04:
    map_object 40, 10, 11, 19, 1, 10, 1, 3, 1, 0, 0, 183, 17056
map_063_object_05:
    map_object 40, 10, 11, 32, 1, 10, 1, 1, 2, 0, 0, 182, 17055
map_063_object_06:
    map_object 40, 10, 11, 32, 1, 12, 1, 0, 1, 0, 0, 183, 17056
map_063_object_07:
    map_object 40, 0, 9, 25, 1, 22, 1, 0, 1, 0, 0, 183, 17066
map_064_header:
    map_header 17, 0, 109, 0, 17, 2, 0, 0, 0, 6, 0, 19, 0, 0, 255
map_064_object_00:
    map_object 53, 0, 5, 26, 1, 20, 0, 1, 0, 0, 0, 100, 1327
map_064_object_01:
    map_object 53, 7, 7, 36, 1, 20, 1, 2, 0, 0, 0, 158, 17714
map_065_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 0, 0, 0, 0, 1, 1, 0, 74
map_065_object_00:
    map_object 104, 2, 15, 31, 1, 59, 1, 0, 2, 0, 7, 216, 0
map_066_header:
    map_header 0, 3, 24, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75
map_066_object_00:
    map_object 0, 0, 15, 18, 1, 25, 1, 2, 0, 0, 0, 192, 0
map_066_object_01:
    map_object 0, 0, 15, 18, 1, 23, 1, 2, 1, 0, 0, 193, 0
map_066_object_02:
    map_object 0, 0, 15, 19, 1, 24, 1, 2, 2, 0, 0, 201, 0
map_066_object_03:
    map_object 0, 0, 15, 19, 1, 26, 1, 2, 3, 0, 0, 200, 0
map_067_header:
    map_header 22, 3, 99, 1, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 19
map_067_object_00:
    map_object 0, 0, 15, 24, 1, 29, 1, 1, 0, 0, 0, 161, 0
map_068_header:
    map_header 0, 3, 112, 1, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0, 25
map_068_object_00:
    map_object 0, 0, 15, 33, 1, 44, 1, 2, 0, 0, 0, 187, 0
map_068_object_01:
    map_object 0, 0, 15, 22, 1, 43, 1, 3, 1, 0, 0, 166, 0
map_068_object_02:
    map_object 0, 0, 15, 22, 1, 41, 1, 1, 2, 0, 0, 201, 0
map_068_object_03:
    map_object 0, 0, 15, 23, 1, 43, 1, 2, 2, 0, 0, 202, 0
map_068_object_04:
    map_object 104, 1, 15, 31, 1, 44, 1, 2, 3, 0, 0, 139, 0
map_069_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 14
map_069_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_069_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_069_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_069_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_069_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_069_object_05:
    map_object 0, 0, 15, 10, 1, 15, 0, 1, 3, 0, 0, 206, 0
map_069_object_06:
    map_object 0, 0, 15, 9, 1, 17, 0, 1, 3, 0, 0, 206, 0
map_069_object_07:
    map_object 0, 0, 15, 11, 1, 17, 0, 1, 3, 0, 0, 206, 0
map_069_object_08:
    map_object 0, 0, 15, 10, 1, 16, 0, 1, 3, 0, 0, 206, 0
map_06A_header:
    map_header 1, 3, 63, 1, 1, 2, 0, 0, 0, 0, 0, 4, 0, 0, 39
map_06B_header:
    map_header 5, 2, 29, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 255
map_06B_object_00:
    map_object 0, 0, 15, 27, 1, 21, 1, 1, 0, 0, 0, 140, 0
map_06C_header:
    map_header 18, 0, 111, 1, 18, 2, 0, 0, 0, 3, 0, 0, 0, 0, 69
map_06C_object_00:
    map_object 0, 0, 15, 24, 1, 51, 0, 1, 0, 0, 0, 185, 0
map_06C_object_01:
    map_object 0, 0, 15, 25, 1, 6, 1, 1, 1, 0, 0, 184, 0
map_06C_object_02:
    map_object 0, 0, 15, 25, 1, 13, 0, 0, 2, 0, 0, 168, 0
map_06C_object_03:
    map_object 0, 0, 15, 14, 1, 18, 0, 1, 3, 0, 0, 183, 0
map_06C_object_04:
    map_object 0, 0, 15, 20, 1, 46, 0, 2, 3, 0, 0, 183, 0
map_06C_object_05:
    map_object 0, 0, 15, 14, 1, 34, 0, 1, 3, 0, 0, 183, 0
map_06C_object_06:
    map_object 0, 0, 15, 25, 1, 38, 1, 0, 3, 0, 0, 183, 0
map_06D_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_06D_object_00:
    map_object 17, 13, 13, 15, 0, 11, 0, 2, 0, 0, 0, 5, 16385
map_06D_object_01:
    map_object 17, 13, 13, 8, 0, 10, 0, 1, 0, 0, 0, 5, 16385
map_06D_object_02:
    map_object 17, 13, 13, 11, 0, 14, 0, 0, 0, 0, 0, 5, 16385
map_06E_header:
    map_header 14, 3, 38, 0, 14, 0, 0, 0, 0, 0, 4, 9, 0, 0, 255
map_06E_object_00:
    map_object 62, 0, 15, 14, 1, 24, 0, 1, 0, 0, 0, 171, 16554
map_06F_header:
    map_header 23, 2, 93, 0, 23, 2, 1, 1, 0, 0, 1, 0, 0, 0, 255
map_06F_object_00:
    map_object 55, 0, 1, 14, 1, 14, 0, 1, 0, 0, 0, 107, 17826
map_070_header:
    map_header 14, 3, 38, 1, 14, 2, 0, 1, 0, 0, 4, 2, 0, 0, 255
map_071_header:
    map_header 24, 2, 72, 1, 24, 2, 0, 1, 0, 0, 4, 4, 0, 0, 59
map_071_object_00:
    map_object 55, 0, 14, 35, 1, 41, 0, 1, 0, 0, 0, 196, 49328
map_071_object_01:
    map_object 55, 0, 14, 25, 1, 29, 0, 1, 1, 0, 0, 197, 49329
map_071_object_02:
    map_object 55, 0, 14, 50, 1, 52, 0, 0, 1, 0, 0, 187, 49330
map_071_object_03:
    map_object 55, 0, 14, 29, 1, 42, 0, 1, 0, 0, 0, 188, 49332
map_071_object_04:
    map_object 55, 0, 14, 41, 1, 17, 0, 2, 0, 0, 0, 201, 49331
map_071_object_05:
    map_object 55, 0, 14, 15, 1, 38, 0, 1, 1, 0, 0, 187, 49333
map_071_object_06:
    map_object 55, 0, 14, 50, 1, 30, 1, 1, 2, 0, 0, 182, 16566
map_071_object_07:
    map_object 55, 0, 14, 33, 1, 23, 1, 1, 2, 0, 0, 182, 16567
map_072_header:
    map_header 24, 2, 48, 1, 24, 2, 0, 1, 0, 0, 4, 4, 0, 0, 51
map_072_object_00:
    map_object 48, 0, 0, 14, 1, 29, 1, 1, 0, 0, 0, 203, 5016
map_072_object_01:
    map_object 49, 0, 0, 57, 1, 41, 1, 2, 3, 0, 0, 194, 5026
map_072_object_02:
    map_object 49, 1, 14, 59, 1, 26, 1, 1, 3, 0, 0, 194, 17315
map_072_object_03:
    map_object 48, 0, 14, 54, 0, 18, 0, 2, 1, 0, 0, 182, 50074
map_072_object_04:
    map_object 48, 0, 14, 34, 0, 26, 0, 0, 2, 0, 0, 197, 50075
map_072_object_05:
    map_object 48, 0, 14, 26, 0, 54, 0, 1, 2, 0, 0, 196, 50076
map_072_object_06:
    map_object 48, 0, 14, 35, 0, 50, 0, 1, 2, 0, 0, 199, 50078
map_072_object_07:
    map_object 48, 0, 14, 49, 0, 54, 0, 0, 2, 0, 0, 201, 50079
map_072_object_08:
    map_object 48, 0, 14, 44, 0, 19, 0, 2, 1, 0, 0, 182, 50081
map_073_header:
    map_header 24, 2, 48, 1, 24, 2, 0, 1, 0, 0, 4, 4, 0, 0, 52
map_073_object_00:
    map_object 51, 0, 14, 36, 0, 43, 0, 2, 0, 0, 0, 198, 50092
map_073_object_01:
    map_object 51, 0, 14, 42, 0, 39, 0, 0, 0, 0, 0, 197, 50093
map_073_object_02:
    map_object 51, 0, 14, 31, 0, 30, 0, 1, 1, 0, 0, 196, 50094
map_073_object_03:
    map_object 51, 0, 14, 43, 0, 27, 0, 0, 0, 0, 0, 200, 50095
map_073_object_04:
    map_object 51, 0, 14, 46, 0, 50, 0, 1, 1, 0, 0, 199, 50096
map_073_object_05:
    map_object 51, 0, 14, 16, 0, 40, 0, 0, 0, 0, 0, 201, 50097
map_073_object_06:
    map_object 51, 0, 14, 62, 0, 19, 0, 1, 1, 0, 0, 202, 50098
map_073_object_07:
    map_object 51, 0, 14, 22, 0, 16, 1, 1, 2, 0, 0, 182, 17331
map_073_object_08:
    map_object 51, 0, 14, 46, 0, 15, 0, 2, 2, 0, 0, 182, 50100
map_074_header:
    map_header 31, 0, 94, 0, 31, 2, 0, 0, 0, 0, 4, 0, 0, 0, 255
map_075_header:
    map_header 23, 2, 93, 0, 23, 2, 1, 0, 0, 0, 3, 0, 0, 0, 255
map_075_object_00:
    map_object 187, 0, 4, 12, 1, 29, 1, 1, 0, 0, 0, 235, 50803
map_075_object_01:
    map_object 172, 0, 1, 9, 0, 29, 0, 1, 0, 0, 0, 53, 49153
map_075_object_02:
    map_object 172, 0, 1, 12, 0, 29, 0, 1, 0, 0, 0, 53, 49153
map_075_object_03:
    map_object 172, 0, 1, 30, 0, 14, 0, 1, 0, 0, 0, 53, 49153
map_075_object_04:
    map_object 172, 0, 1, 30, 0, 15, 0, 1, 0, 0, 0, 53, 49153
map_075_object_05:
    map_object 172, 0, 1, 11, 0, 14, 0, 1, 0, 0, 0, 72, 49153
map_075_object_06:
    map_object 172, 0, 1, 20, 0, 12, 0, 1, 0, 0, 0, 26, 49153
map_075_object_07:
    map_object 172, 0, 1, 30, 0, 30, 0, 1, 0, 0, 0, 53, 49153
map_076_header:
    map_header 23, 3, 93, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_076_object_00:
    map_object 186, 0, 4, 12, 1, 29, 1, 1, 0, 0, 0, 235, 50802
map_076_object_01:
    map_object 172, 0, 1, 20, 0, 12, 0, 1, 0, 0, 0, 72, 49153
map_076_object_02:
    map_object 172, 0, 1, 11, 0, 14, 0, 1, 0, 0, 0, 53, 49153
map_076_object_03:
    map_object 172, 0, 1, 30, 0, 14, 0, 1, 0, 0, 0, 53, 49153
map_076_object_04:
    map_object 172, 0, 1, 30, 0, 30, 0, 1, 0, 0, 0, 38, 49153
map_077_header:
    map_header 23, 2, 93, 0, 23, 2, 1, 1, 0, 0, 1, 0, 0, 0, 255
map_077_object_00:
    map_object 55, 0, 4, 14, 1, 14, 0, 1, 0, 0, 0, 102, 17829
map_078_header:
    map_header 23, 2, 93, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_078_object_00:
    map_object 148, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25996
map_078_object_01:
    map_object 148, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21900
map_078_object_02:
    map_object 172, 0, 1, 14, 1, 15, 1, 1, 0, 0, 0, 148, 5511
map_079_header:
    map_header 15, 3, 56, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_079_object_00:
    map_object 60, 3, 3, 14, 1, 12, 0, 1, 0, 0, 0, 77, 16385
map_079_object_01:
    map_object 60, 0, 3, 12, 1, 12, 1, 1, 0, 0, 0, 189, 17105
map_07A_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 53
map_07A_object_00:
    map_object 50, 0, 0, 44, 1, 37, 1, 0, 0, 0, 0, 167, 50114
map_07A_object_01:
    map_object 50, 0, 0, 42, 1, 38, 1, 2, 1, 0, 0, 195, 50115
map_07A_object_02:
    map_object 50, 0, 0, 46, 1, 38, 1, 3, 2, 0, 0, 194, 50116
map_07A_object_03:
    map_object 50, 1, 1, 44, 1, 38, 0, 1, 0, 0, 0, 167, 50114
map_07A_object_04:
    map_object 50, 1, 1, 42, 1, 38, 0, 1, 1, 0, 0, 195, 50115
map_07A_object_05:
    map_object 50, 1, 1, 46, 1, 38, 0, 1, 2, 0, 0, 194, 50116
map_07A_object_06:
    map_object 50, 0, 14, 38, 1, 34, 1, 1, 3, 0, 0, 201, 17349
map_07A_object_07:
    map_object 50, 0, 14, 39, 0, 12, 0, 1, 2, 0, 0, 194, 50118
map_07B_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 53
map_07B_object_00:
    map_object 50, 2, 2, 74, 1, 37, 1, 0, 0, 0, 0, 167, 0
map_07B_object_01:
    map_object 50, 2, 2, 72, 1, 36, 1, 2, 1, 0, 0, 195, 0
map_07B_object_02:
    map_object 50, 2, 2, 76, 1, 37, 1, 0, 2, 0, 0, 194, 0
map_07B_object_03:
    map_object 50, 0, 14, 77, 0, 35, 1, 1, 3, 0, 0, 197, 54220
map_07B_object_04:
    map_object 50, 0, 14, 70, 0, 37, 0, 1, 3, 0, 0, 199, 50125
map_07B_object_05:
    map_object 53, 8, 8, 74, 0, 37, 0, 0, 0, 0, 0, 167, 50126
map_07B_object_06:
    map_object 50, 0, 14, 78, 0, 64, 1, 2, 1, 0, 0, 195, 54215
map_07B_object_07:
    map_object 50, 0, 14, 73, 0, 54, 0, 1, 3, 0, 0, 196, 50120
map_07B_object_08:
    map_object 50, 0, 14, 87, 0, 64, 1, 0, 3, 0, 0, 201, 17353
map_07B_object_09:
    map_object 50, 0, 14, 92, 0, 57, 0, 0, 3, 0, 0, 200, 50122
map_07B_object_10:
    map_object 50, 0, 14, 79, 0, 59, 0, 0, 3, 0, 0, 197, 50123
map_07C_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 0, 0, 0, 0, 3, 0, 0, 51
map_07C_object_00:
    map_object 48, 0, 14, 43, 1, 13, 0, 0, 0, 0, 0, 203, 50073
map_07D_header:
    map_header 28, 2, 73, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 60
map_07D_object_00:
    map_object 55, 0, 14, 54, 1, 10, 1, 1, 1, 0, 0, 189, 16576
map_07D_object_01:
    map_object 55, 0, 14, 42, 1, 13, 0, 0, 3, 0, 0, 187, 16568
map_07D_object_02:
    map_object 55, 0, 14, 56, 1, 9, 1, 1, 3, 0, 0, 188, 16569
map_07D_object_03:
    map_object 55, 0, 14, 13, 1, 50, 1, 1, 0, 0, 0, 156, 20668
map_07D_object_04:
    map_object 55, 0, 14, 24, 1, 32, 0, 1, 2, 0, 0, 207, 21288
map_07D_object_05:
    map_object 55, 0, 14, 40, 1, 50, 0, 1, 2, 0, 0, 207, 21261
map_07D_object_06:
    map_object 55, 0, 14, 46, 0, 32, 1, 1, 3, 0, 0, 202, 20669
map_07D_object_07:
    map_object 55, 0, 14, 66, 0, 34, 0, 1, 3, 0, 0, 198, 49342
map_07D_object_08:
    map_object 55, 0, 14, 16, 0, 13, 0, 1, 3, 0, 0, 198, 49338
map_07D_object_09:
    map_object 55, 0, 14, 13, 0, 16, 0, 0, 3, 0, 0, 198, 49339
map_07E_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 68
map_07E_object_00:
    map_object 51, 0, 14, 24, 0, 12, 0, 1, 3, 0, 0, 207, 21286
map_07E_object_01:
    map_object 51, 0, 14, 93, 0, 35, 0, 1, 3, 0, 0, 207, 21259
map_07E_object_02:
    map_object 51, 0, 14, 67, 0, 34, 0, 0, 0, 0, 0, 201, 50101
map_07E_object_03:
    map_object 51, 0, 14, 89, 0, 17, 0, 0, 0, 0, 0, 201, 50102
map_07E_object_04:
    map_object 58, 2, 2, 88, 0, 14, 0, 0, 1, 0, 0, 166, 50127
map_07E_object_05:
    map_object 51, 0, 14, 62, 0, 17, 0, 0, 0, 0, 0, 197, 50103
map_07E_object_06:
    map_object 51, 0, 14, 59, 0, 11, 1, 1, 2, 0, 0, 156, 17272
map_07F_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 52
map_07F_object_00:
    map_object 48, 0, 14, 24, 1, 12, 0, 1, 3, 0, 0, 207, 21285
map_07F_object_01:
    map_object 48, 0, 14, 52, 1, 57, 0, 1, 3, 0, 0, 207, 21258
map_080_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 0, 0, 0, 4, 1, 1, 0, 255
map_080_object_00:
    map_object 16, 0, 0, 31, 1, 59, 1, 0, 2, 0, 7, 216, 24835
map_080_object_01:
    map_object 16, 0, 0, 30, 1, 27, 1, 0, 2, 0, 7, 219, 0
map_080_object_02:
    map_object 10, 1, 1, 31, 1, 59, 1, 0, 1, 0, 7, 215, 0
map_081_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_081_object_00:
    map_object 0, 0, 15, 22, 0, 37, 0, 1, 0, 0, 0, 0, 49153
map_081_object_01:
    map_object 0, 0, 15, 20, 0, 26, 0, 1, 0, 0, 0, 0, 49153
map_081_object_02:
    map_object 0, 0, 15, 33, 0, 21, 0, 1, 0, 0, 0, 0, 49153
map_081_object_03:
    map_object 0, 0, 15, 44, 0, 20, 0, 1, 0, 0, 0, 0, 49153
map_081_object_04:
    map_object 0, 0, 15, 46, 0, 30, 0, 1, 0, 0, 0, 0, 49153
map_081_object_05:
    map_object 0, 0, 15, 36, 0, 45, 0, 1, 0, 0, 0, 0, 49153
map_081_object_06:
    map_object 0, 0, 15, 48, 0, 50, 0, 1, 0, 0, 0, 0, 49153
map_081_object_07:
    map_object 0, 0, 15, 34, 0, 60, 0, 3, 0, 0, 0, 0, 49153
map_081_object_08:
    map_object 0, 0, 15, 36, 0, 60, 0, 2, 0, 0, 0, 0, 49153
map_081_object_09:
    map_object 0, 0, 15, 26, 0, 62, 0, 1, 0, 0, 0, 0, 49153
map_081_object_10:
    map_object 0, 0, 15, 19, 0, 60, 0, 1, 0, 0, 0, 0, 49153
map_082_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_082_object_00:
    map_object 0, 0, 15, 24, 0, 13, 0, 1, 0, 0, 0, 0, 49153
map_082_object_01:
    map_object 0, 0, 15, 29, 0, 17, 0, 1, 0, 0, 0, 0, 49153
map_082_object_02:
    map_object 0, 0, 15, 10, 0, 12, 0, 1, 0, 0, 0, 0, 49153
map_082_object_03:
    map_object 0, 0, 15, 11, 0, 16, 0, 1, 0, 0, 0, 0, 49153
map_082_object_04:
    map_object 0, 0, 15, 10, 0, 29, 0, 1, 0, 0, 0, 0, 49153
map_082_object_05:
    map_object 0, 0, 15, 11, 0, 34, 0, 1, 0, 0, 0, 0, 49153
map_082_object_06:
    map_object 0, 0, 15, 14, 0, 25, 0, 1, 0, 0, 0, 0, 49153
map_082_object_07:
    map_object 0, 0, 15, 15, 0, 34, 0, 1, 0, 0, 0, 0, 49153
map_082_object_08:
    map_object 0, 0, 15, 27, 0, 30, 0, 1, 0, 0, 0, 0, 49153
map_082_object_09:
    map_object 0, 0, 15, 27, 0, 35, 0, 1, 0, 0, 0, 0, 49153
map_083_header:
    map_header 0, 3, 24, 0, 0, 2, 0, 1, 0, 0, 4, 0, 0, 0, 16
map_083_object_00:
    map_object 16, 0, 5, 35, 1, 18, 1, 1, 0, 0, 0, 192, 16384
map_083_object_01:
    map_object 16, 0, 9, 35, 1, 19, 1, 3, 1, 0, 0, 193, 16654
map_083_object_02:
    map_object 16, 0, 6, 36, 1, 19, 1, 2, 2, 0, 0, 201, 8460
map_083_object_03:
    map_object 16, 6, 6, 27, 1, 25, 1, 1, 3, 0, 0, 160, 16384
map_083_object_04:
    map_object 16, 7, 8, 29, 1, 26, 1, 1, 3, 0, 0, 160, 16384
map_083_object_05:
    map_object 16, 7, 7, 31, 1, 26, 1, 1, 0, 0, 0, 192, 16384
map_083_object_06:
    map_object 16, 0, 6, 10, 1, 21, 0, 2, 2, 0, 0, 202, 16647
map_083_object_07:
    map_object 16, 0, 6, 20, 1, 31, 0, 3, 2, 0, 0, 197, 16648
map_083_object_08:
    map_object 16, 0, 6, 29, 1, 25, 1, 1, 2, 0, 0, 199, 16649
map_083_object_09:
    map_object 16, 0, 15, 33, 1, 37, 1, 1, 2, 0, 0, 196, 16651
map_084_header:
    map_header 0, 3, 24, 0, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 16
map_085_header:
    map_header 5, 2, 29, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 22
map_085_object_00:
    map_object 0, 0, 15, 25, 1, 4, 1, 2, 0, 0, 0, 139, 49152
map_085_object_01:
    map_object 0, 0, 15, 18, 1, 12, 1, 2, 1, 0, 0, 6, 49152
map_085_object_02:
    map_object 0, 0, 15, 14, 1, 12, 1, 3, 1, 0, 0, 6, 49152
map_085_object_03:
    map_object 0, 0, 15, 24, 1, 11, 1, 1, 1, 0, 0, 6, 49152
map_085_object_04:
    map_object 0, 0, 15, 14, 1, 19, 1, 1, 1, 0, 0, 6, 49152
map_085_object_05:
    map_object 0, 0, 15, 17, 1, 19, 1, 1, 1, 0, 0, 6, 49152
map_085_object_06:
    map_object 0, 0, 15, 13, 1, 21, 1, 3, 1, 0, 0, 6, 49152
map_085_object_07:
    map_object 0, 0, 15, 18, 1, 21, 1, 2, 1, 0, 0, 6, 49152
map_085_object_08:
    map_object 0, 0, 15, 16, 1, 23, 1, 0, 1, 0, 0, 6, 49152
map_086_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 1, 0, 0, 3, 5, 0, 0, 255
map_086_object_00:
    map_object 36, 5, 6, 30, 1, 34, 1, 1, 0, 0, 0, 181, 17028
map_086_object_01:
    map_object 36, 5, 6, 30, 1, 34, 1, 1, 0, 0, 0, 205, 17028
map_087_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 0, 0, 0, 1, 13, 0, 0, 19
map_087_object_00:
    map_object 17, 15, 15, 17, 1, 10, 0, 1, 0, 0, 0, 161, 16906
map_088_header:
    map_header 22, 3, 99, 1, 22, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_088_object_00:
    map_object 17, 0, 2, 24, 1, 30, 1, 1, 0, 0, 7, 160, 4387
map_088_object_01:
    map_object 80, 1, 3, 24, 0, 32, 0, 1, 0, 0, 0, 12, 49153
map_088_object_02:
    map_object 80, 1, 3, 23, 0, 41, 0, 3, 0, 0, 0, 5, 49153
map_088_object_03:
    map_object 80, 1, 3, 27, 0, 49, 0, 0, 0, 0, 0, 5, 49153
map_088_object_04:
    map_object 80, 1, 3, 34, 0, 47, 0, 2, 0, 0, 0, 5, 49153
map_088_object_05:
    map_object 80, 1, 3, 34, 0, 26, 0, 1, 0, 0, 0, 5, 49153
map_088_object_06:
    map_object 80, 1, 3, 47, 0, 28, 0, 2, 0, 0, 0, 5, 49153
map_088_object_07:
    map_object 80, 1, 3, 24, 0, 45, 0, 1, 0, 0, 0, 5, 49153
map_089_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 0, 0, 0, 1, 13, 0, 0, 19
map_089_object_00:
    map_object 17, 3, 3, 9, 1, 23, 1, 1, 3, 0, 0, 160, 0
map_08A_header:
    map_header 28, 2, 52, 0, 28, 2, 0, 1, 0, 0, 0, 3, 0, 0, 59
map_08A_object_00:
    map_object 51, 0, 14, 75, 0, 16, 0, 2, 1, 0, 0, 188, 50104
map_08A_object_01:
    map_object 51, 0, 14, 75, 0, 10, 0, 0, 1, 0, 0, 200, 50105
map_08A_object_02:
    map_object 51, 0, 14, 26, 0, 31, 0, 1, 0, 0, 0, 196, 50106
map_08A_object_03:
    map_object 51, 0, 14, 11, 0, 31, 0, 0, 1, 0, 0, 197, 50107
map_08A_object_04:
    map_object 51, 0, 14, 15, 0, 37, 0, 1, 1, 0, 0, 199, 50108
map_08B_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 1, 0, 0, 1, 13, 0, 0, 19
map_08B_object_00:
    map_object 144, 0, 1, 17, 1, 12, 1, 1, 2, 0, 7, 223, 24878
map_08B_object_01:
    map_object 144, 2, 2, 17, 1, 12, 1, 3, 2, 0, 7, 223, 20782
map_08B_object_02:
    map_object 17, 0, 13, 17, 1, 16, 1, 0, 0, 0, 0, 161, 16688
map_08B_object_03:
    map_object 17, 14, 14, 18, 1, 17, 1, 1, 0, 0, 0, 161, 16701
map_08B_object_04:
    map_object 17, 0, 7, 13, 1, 25, 1, 0, 3, 0, 0, 160, 16689
map_08B_object_05:
    map_object 17, 8, 9, 16, 1, 17, 1, 3, 3, 0, 0, 160, 16689
map_08B_object_06:
    map_object 30, 5, 7, 16, 1, 19, 1, 0, 3, 0, 0, 160, 16914
map_08C_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 0, 0, 0, 1, 13, 0, 0, 255
map_08C_object_00:
    map_object 80, 1, 3, 6, 0, 19, 0, 3, 0, 0, 0, 12, 49153
map_08C_object_01:
    map_object 80, 1, 3, 11, 0, 13, 0, 2, 0, 0, 0, 12, 49153
map_08C_object_02:
    map_object 80, 1, 3, 7, 0, 10, 0, 3, 0, 0, 0, 12, 49153
map_08E_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 1, 0, 0, 1, 13, 0, 0, 20
map_08E_object_00:
    map_object 30, 1, 3, 17, 1, 17, 1, 0, 0, 0, 0, 161, 16688
map_08E_object_01:
    map_object 30, 1, 3, 18, 1, 17, 1, 1, 1, 0, 0, 177, 16704
map_08E_object_02:
    map_object 30, 1, 3, 16, 1, 17, 1, 1, 3, 0, 0, 182, 16384
map_08E_object_03:
    map_object 30, 1, 3, 14, 1, 14, 1, 1, 3, 0, 0, 182, 16384
map_08E_object_04:
    map_object 30, 1, 3, 20, 1, 14, 1, 1, 3, 0, 0, 182, 16384
map_08E_object_05:
    map_object 30, 1, 3, 11, 1, 18, 1, 2, 3, 0, 0, 182, 16384
map_08E_object_06:
    map_object 30, 1, 3, 22, 1, 18, 1, 3, 3, 0, 0, 182, 16384
map_08E_object_07:
    map_object 144, 2, 2, 17, 1, 12, 1, 3, 2, 0, 7, 223, 16686
map_08F_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 1, 0, 0, 1, 13, 0, 0, 255
map_08F_object_00:
    map_object 80, 1, 1, 17, 1, 38, 0, 1, 0, 0, 0, 92, 16908
map_08F_object_01:
    map_object 80, 2, 2, 17, 1, 38, 0, 1, 0, 0, 0, 92, 16909
map_08F_object_02:
    map_object 80, 3, 3, 17, 1, 38, 0, 1, 0, 0, 0, 92, 16910
map_090_header:
    map_header 0, 3, 112, 1, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 23
map_090_object_00:
    map_object 18, 0, 0, 12, 1, 21, 1, 0, 0, 0, 0, 183, 16704
map_090_object_01:
    map_object 18, 0, 14, 13, 1, 34, 0, 1, 1, 0, 0, 196, 49473
map_090_object_02:
    map_object 18, 0, 14, 28, 1, 52, 0, 1, 1, 0, 0, 197, 49474
map_090_object_03:
    map_object 18, 0, 14, 46, 1, 27, 0, 3, 3, 0, 0, 188, 49475
map_090_object_04:
    map_object 18, 0, 14, 52, 1, 40, 0, 2, 1, 0, 0, 202, 49476
map_090_object_05:
    map_object 18, 0, 14, 43, 1, 19, 1, 1, 0, 0, 0, 183, 16709
map_090_object_06:
    map_object 18, 6, 6, 26, 1, 61, 0, 0, 2, 0, 0, 166, 49478
map_090_object_07:
    map_object 18, 1, 14, 11, 1, 22, 0, 3, 0, 0, 0, 183, 49479
map_091_header:
    map_header 14, 3, 38, 0, 14, 2, 0, 0, 0, 0, 4, 2, 0, 0, 0
map_092_header:
    map_header 16, 2, 40, 0, 16, 1, 0, 0, 0, 0, 0, 10, 0, 0, 77
map_092_object_00:
    map_object 0, 0, 15, 16, 1, 33, 1, 1, 0, 1, 0, 158, 0
map_092_object_01:
    map_object 0, 0, 15, 14, 1, 34, 1, 0, 1, 1, 0, 175, 0
map_092_object_02:
    map_object 0, 0, 15, 18, 1, 34, 1, 0, 2, 1, 0, 175, 0
map_092_object_03:
    map_object 0, 0, 15, 13, 1, 37, 1, 0, 3, 1, 0, 175, 0
map_092_object_04:
    map_object 0, 0, 15, 20, 1, 37, 1, 0, 3, 1, 0, 175, 0
map_093_header:
    map_header 25, 2, 49, 0, 25, 2, 0, 0, 0, 0, 0, 3, 0, 0, 50
map_093_object_00:
    map_object 0, 0, 15, 12, 1, 14, 1, 3, 1, 0, 0, 174, 0
map_093_object_01:
    map_object 0, 0, 15, 16, 1, 11, 0, 0, 0, 0, 0, 173, 0
map_094_header:
    map_header 24, 2, 48, 1, 24, 2, 0, 0, 0, 0, 0, 4, 0, 0, 70
map_094_object_00:
    map_object 0, 0, 15, 42, 1, 42, 1, 0, 0, 0, 0, 167, 0
map_094_object_01:
    map_object 0, 0, 15, 44, 1, 43, 1, 2, 1, 0, 0, 195, 0
map_094_object_02:
    map_object 0, 0, 15, 40, 1, 43, 1, 3, 2, 0, 0, 194, 0
map_094_object_03:
    map_object 0, 0, 15, 42, 1, 40, 1, 1, 3, 0, 0, 203, 0
map_095_header:
    map_header 14, 3, 81, 1, 14, 2, 0, 0, 0, 0, 0, 2, 0, 0, 26
map_095_object_00:
    map_object 0, 0, 15, 10, 1, 17, 1, 1, 0, 0, 0, 160, 16384
map_095_object_01:
    map_object 0, 0, 15, 9, 1, 16, 1, 1, 3, 0, 0, 183, 16384
map_095_object_02:
    map_object 0, 0, 15, 6, 1, 31, 1, 2, 3, 0, 0, 183, 16384
map_095_object_03:
    map_object 0, 0, 15, 13, 1, 31, 1, 3, 3, 0, 0, 183, 16384
map_095_object_04:
    map_object 0, 0, 15, 6, 1, 37, 1, 1, 3, 0, 0, 183, 16384
map_095_object_05:
    map_object 0, 0, 15, 13, 1, 37, 1, 1, 3, 0, 0, 183, 16384
map_096_header:
    map_header 12, 2, 36, 0, 12, 2, 0, 0, 0, 6, 0, 9, 0, 0, 71
map_096_object_00:
    map_object 0, 0, 15, 27, 1, 12, 1, 1, 0, 0, 0, 163, 0
map_096_object_01:
    map_object 0, 0, 0, 16, 1, 31, 1, 3, 1, 0, 0, 164, 0
map_096_object_02:
    map_object 0, 0, 0, 15, 1, 31, 1, 3, 2, 0, 0, 165, 0
map_096_object_03:
    map_object 0, 0, 0, 14, 1, 31, 1, 3, 2, 0, 0, 165, 0
map_097_header:
    map_header 14, 1, 82, 0, 14, 2, 0, 0, 0, 0, 0, 2, 0, 0, 72
map_097_object_00:
    map_object 0, 0, 15, 11, 1, 29, 1, 3, 0, 0, 0, 202, 0
map_097_object_01:
    map_object 0, 0, 15, 11, 1, 29, 1, 3, 1, 0, 0, 13, 0
map_097_object_02:
    map_object 0, 0, 15, 12, 1, 29, 1, 3, 1, 0, 0, 13, 0
map_098_header:
    map_header 2, 3, 26, 1, 2, 2, 0, 0, 0, 0, 0, 1, 0, 0, 60
map_098_object_00:
    map_object 0, 0, 15, 35, 0, 42, 1, 3, 0, 0, 0, 156, 0
map_099_header:
    map_header 0, 3, 24, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0, 73
map_099_object_00:
    map_object 0, 0, 15, 19, 1, 19, 0, 1, 0, 0, 0, 153, 0
map_09B_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 14
map_09B_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_09B_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_09B_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_09B_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_09B_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_09B_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_09B_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_09B_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_09B_object_08:
    map_object 36, 8, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16610
map_09C_header:
    map_header 2, 2, 107, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 14
map_09C_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_09C_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_09C_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_09C_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_09C_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_09C_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_09C_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_09C_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_09C_object_08:
    map_object 36, 8, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16608
map_09D_header:
    map_header 36, 2, 108, 0, 2, 2, 0, 0, 0, 0, 0, 20, 0, 0, 14
map_09D_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_09D_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_09D_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_09D_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_09D_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_09D_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_09D_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_09D_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_09D_object_08:
    map_object 36, 8, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16609
map_09E_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 14
map_09E_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_09E_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_09E_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_09E_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_09E_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_09E_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_09E_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_09E_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_09E_object_08:
    map_object 36, 8, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16592
map_09F_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 14
map_09F_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_09F_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_09F_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_09F_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_09F_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_09F_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_09F_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_09F_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_09F_object_08:
    map_object 0, 0, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16590
map_0A0_header:
    map_header 8, 2, 32, 0, 8, 2, 0, 0, 0, 0, 4, 0, 0, 0, 31
map_0A0_object_00:
    map_object 26, 0, 0, 18, 1, 27, 1, 1, 0, 0, 0, 169, 16736
map_0A0_object_01:
    map_object 26, 0, 0, 19, 1, 27, 1, 1, 0, 0, 0, 169, 16736
map_0A0_object_02:
    map_object 18, 7, 7, 19, 1, 31, 1, 0, 1, 0, 0, 166, 16743
map_0A0_object_03:
    map_object 26, 0, 1, 9, 0, 30, 0, 3, 3, 0, 0, 201, 49505
map_0A0_object_04:
    map_object 26, 0, 1, 24, 0, 31, 0, 1, 3, 0, 0, 202, 49506
map_0A0_object_05:
    map_object 26, 0, 1, 9, 0, 37, 0, 1, 3, 0, 0, 196, 49507
map_0A0_object_06:
    map_object 26, 0, 1, 17, 0, 35, 0, 1, 3, 0, 0, 197, 49508
map_0A0_object_07:
    map_object 26, 0, 1, 20, 0, 42, 0, 1, 0, 0, 0, 169, 49509
map_0A0_object_08:
    map_object 26, 0, 1, 29, 0, 41, 0, 0, 0, 0, 0, 169, 49510
map_0A1_header:
    map_header 9, 2, 33, 0, 9, 2, 0, 1, 0, 0, 3, 0, 0, 0, 255
map_0A1_object_00:
    map_object 26, 0, 6, 18, 0, 18, 0, 1, 0, 1, 0, 34, 49153
map_0A1_object_01:
    map_object 26, 0, 6, 12, 0, 19, 0, 3, 0, 1, 0, 18, 49153
map_0A1_object_02:
    map_object 26, 0, 6, 26, 0, 19, 0, 2, 0, 1, 0, 18, 49153
map_0A1_object_03:
    map_object 26, 0, 6, 7, 0, 44, 0, 1, 0, 1, 0, 25, 49153
map_0A1_object_04:
    map_object 26, 0, 6, 14, 0, 44, 0, 1, 0, 1, 0, 25, 49153
map_0A2_header:
    map_header 9, 2, 33, 0, 9, 2, 0, 0, 0, 8, 3, 8, 0, 0, 255
map_0A2_object_00:
    map_object 26, 0, 6, 11, 0, 17, 0, 1, 0, 1, 0, 33, 49153
map_0A2_object_01:
    map_object 26, 0, 6, 30, 0, 30, 0, 1, 0, 1, 0, 33, 49153
map_0A2_object_02:
    map_object 26, 0, 6, 39, 0, 21, 0, 1, 0, 1, 0, 33, 49153
map_0A2_object_03:
    map_object 26, 0, 6, 37, 0, 37, 0, 3, 0, 1, 0, 25, 49153
map_0A2_object_04:
    map_object 26, 0, 6, 38, 0, 13, 0, 3, 0, 1, 0, 18, 49153
map_0A2_object_05:
    map_object 26, 0, 6, 43, 0, 13, 0, 2, 0, 1, 0, 18, 49153
map_0A2_object_06:
    map_object 26, 0, 6, 44, 0, 29, 0, 1, 0, 1, 0, 34, 49153
map_0A2_object_07:
    map_object 26, 0, 6, 22, 0, 22, 0, 1, 0, 1, 0, 34, 49153
map_0A2_object_08:
    map_object 26, 0, 6, 10, 0, 30, 0, 1, 0, 1, 0, 34, 49153
map_0A3_header:
    map_header 9, 2, 33, 0, 9, 2, 0, 0, 0, 8, 3, 8, 0, 0, 255
map_0A3_object_00:
    map_object 26, 0, 6, 51, 0, 33, 0, 0, 0, 1, 0, 18, 49153
map_0A3_object_01:
    map_object 26, 0, 6, 27, 0, 28, 0, 1, 0, 1, 0, 18, 49153
map_0A3_object_02:
    map_object 26, 0, 6, 49, 0, 51, 0, 1, 0, 1, 0, 33, 49153
map_0A3_object_03:
    map_object 26, 0, 6, 35, 0, 36, 0, 3, 0, 1, 0, 25, 49153
map_0A3_object_04:
    map_object 26, 0, 6, 39, 0, 13, 0, 1, 0, 1, 0, 34, 49153
map_0A3_object_05:
    map_object 26, 0, 6, 49, 0, 23, 0, 1, 0, 1, 0, 34, 49153
map_0A3_object_06:
    map_object 26, 0, 6, 54, 0, 42, 0, 1, 0, 1, 0, 34, 49153
map_0A3_object_07:
    map_object 26, 0, 6, 42, 0, 43, 0, 1, 0, 1, 0, 34, 49153
map_0A3_object_08:
    map_object 26, 0, 6, 12, 0, 27, 0, 1, 0, 1, 0, 34, 49153
map_0A3_object_09:
    map_object 26, 0, 6, 19, 0, 21, 0, 1, 0, 1, 0, 34, 49153
map_0A4_header:
    map_header 9, 2, 33, 0, 9, 2, 0, 1, 0, 8, 1, 8, 0, 0, 32
map_0A4_object_00:
    map_object 26, 0, 5, 19, 1, 14, 1, 1, 0, 1, 0, 191, 4461
map_0A4_object_01:
    map_object 26, 6, 6, 19, 1, 9, 1, 1, 0, 1, 0, 191, 4096
map_0A4_object_02:
    map_object 26, 3, 6, 20, 1, 9, 1, 1, 1, 1, 0, 166, 16384
map_0A4_object_03:
    map_object 26, 4, 6, 18, 1, 9, 1, 1, 2, 1, 0, 172, 16384
map_0A4_object_04:
    map_object 26, 0, 6, 8, 1, 17, 1, 3, 3, 1, 0, 169, 16751
map_0A4_object_05:
    map_object 26, 0, 6, 8, 1, 23, 1, 3, 3, 1, 0, 169, 16751
map_0A4_object_06:
    map_object 26, 0, 6, 29, 1, 17, 1, 2, 3, 1, 0, 169, 16751
map_0A4_object_07:
    map_object 26, 0, 6, 29, 1, 23, 1, 2, 3, 1, 0, 169, 16751
map_0A4_object_08:
    map_object 26, 0, 6, 15, 1, 26, 1, 0, 3, 1, 0, 169, 16751
map_0A4_object_09:
    map_object 26, 0, 6, 22, 1, 26, 1, 0, 3, 1, 0, 169, 16751
map_0A5_header:
    map_header 9, 2, 67, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_0A5_object_00:
    map_object 26, 0, 6, 12, 0, 23, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_01:
    map_object 26, 0, 6, 20, 0, 23, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_02:
    map_object 26, 0, 6, 16, 0, 17, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_03:
    map_object 26, 0, 6, 48, 0, 16, 0, 0, 0, 1, 0, 34, 49153
map_0A5_object_04:
    map_object 26, 0, 6, 44, 0, 23, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_05:
    map_object 26, 0, 6, 52, 0, 23, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_06:
    map_object 26, 0, 6, 16, 0, 48, 0, 0, 0, 1, 0, 34, 49153
map_0A5_object_07:
    map_object 26, 0, 6, 12, 0, 55, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_08:
    map_object 26, 0, 6, 20, 0, 55, 0, 1, 0, 1, 0, 33, 49153
map_0A5_object_09:
    map_object 26, 0, 6, 47, 0, 48, 0, 1, 0, 1, 0, 34, 49153
map_0A5_object_10:
    map_object 26, 0, 6, 44, 0, 55, 0, 1, 0, 1, 0, 18, 49153
map_0A5_object_11:
    map_object 26, 0, 6, 52, 0, 55, 0, 1, 0, 1, 0, 18, 49153
map_0A6_header:
    map_header 9, 2, 33, 0, 9, 1, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_0A6_object_00:
    map_object 0, 0, 15, 14, 0, 6, 0, 1, 0, 0, 0, 88, 49518
map_0A7_header:
    map_header 9, 2, 33, 0, 9, 2, 0, 1, 0, 8, 1, 8, 0, 0, 63
map_0A7_object_00:
    map_object 26, 7, 7, 8, 1, 17, 0, 3, 0, 1, 0, 183, 49520
map_0A7_object_01:
    map_object 26, 7, 7, 8, 1, 23, 0, 3, 2, 1, 0, 196, 49521
map_0A7_object_02:
    map_object 26, 7, 7, 29, 1, 17, 0, 3, 2, 1, 0, 197, 49522
map_0A7_object_03:
    map_object 26, 7, 7, 29, 1, 23, 0, 3, 3, 1, 0, 160, 49523
map_0A7_object_04:
    map_object 26, 7, 7, 15, 1, 26, 0, 0, 2, 1, 0, 202, 49524
map_0A7_object_05:
    map_object 26, 7, 7, 22, 1, 26, 0, 0, 2, 1, 0, 188, 49525
map_0A8_header:
    map_header 0, 3, 24, 1, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 15
map_0A8_object_00:
    map_object 0, 0, 15, 25, 1, 38, 0, 0, 0, 0, 0, 197, 49696
map_0A8_object_01:
    map_object 0, 0, 15, 11, 1, 24, 0, 1, 2, 0, 0, 196, 49697
map_0A8_object_02:
    map_object 0, 0, 15, 15, 1, 37, 0, 2, 1, 0, 0, 200, 49698
map_0AA_header:
    map_header 11, 0, 35, 0, 11, 2, 0, 0, 0, 0, 4, 0, 0, 0, 255
map_0AB_header:
    map_header 2, 2, 26, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 14
map_0AB_object_00:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 217, 0
map_0AB_object_01:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 218, 0
map_0AB_object_02:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 220, 0
map_0AB_object_03:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 221, 0
map_0AB_object_04:
    map_object 0, 0, 15, 13, 1, 7, 1, 0, 0, 0, 7, 222, 0
map_0AB_object_05:
    map_object 87, 0, 0, 13, 1, 8, 1, 0, 1, 0, 7, 212, 0
map_0AB_object_06:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 213, 0
map_0AB_object_07:
    map_object 87, 1, 1, 13, 1, 6, 1, 0, 1, 0, 7, 214, 0
map_0AB_object_08:
    map_object 0, 0, 15, 10, 1, 15, 1, 1, 3, 0, 0, 206, 16607
map_0B0_header:
    map_header 20, 0, 117, 0, 20, 2, 0, 0, 0, 16, 0, 15, 0, 0, 255
map_0B1_header:
    map_header 21, 0, 116, 0, 21, 2, 0, 0, 0, 17, 1, 0, 0, 0, 255
map_0B2_header:
    map_header 30, 0, 115, 1, 30, 2, 0, 0, 0, 18, 0, 21, 0, 0, 255
map_0B3_header:
    map_header 11, 0, 114, 0, 11, 2, 0, 0, 0, 19, 0, 22, 0, 0, 255
map_0B4_header:
    map_header 12, 0, 118, 0, 12, 2, 0, 0, 0, 6, 0, 23, 0, 0, 255
map_0C2_header:
    map_header 0, 3, 76, 0, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 46
map_0C2_object_00:
    map_object 39, 3, 3, 23, 1, 20, 1, 1, 0, 0, 0, 146, 0
map_0C2_object_01:
    map_object 39, 0, 1, 24, 1, 20, 1, 1, 1, 0, 0, 137, 13196
map_0C2_object_02:
    map_object 39, 2, 15, 24, 1, 20, 1, 3, 1, 0, 0, 137, 0
map_0C2_object_03:
    map_object 39, 0, 0, 24, 1, 21, 1, 0, 2, 0, 0, 165, 4996
map_0C2_object_04:
    map_object 39, 0, 3, 23, 1, 27, 0, 1, 3, 0, 0, 196, 50053
map_0C2_object_05:
    map_object 39, 0, 3, 10, 1, 17, 0, 1, 3, 0, 0, 197, 50054
map_0C2_object_06:
    map_object 39, 0, 3, 9, 1, 29, 0, 1, 3, 0, 0, 198, 50055
map_0C2_object_07:
    map_object 39, 0, 3, 31, 1, 12, 0, 1, 3, 0, 0, 187, 50056
map_0C2_object_08:
    map_object 39, 0, 3, 20, 1, 21, 0, 1, 3, 0, 0, 188, 50057
map_0C3_header:
    map_header 22, 3, 98, 1, 22, 2, 0, 1, 0, 0, 4, 1, 0, 0, 255
map_0C3_object_00:
    map_object 65, 3, 4, 28, 0, 45, 1, 1, 0, 0, 0, 160, 16424
map_0C3_object_01:
    map_object 65, 3, 4, 26, 0, 51, 0, 3, 0, 0, 0, 167, 49193
map_0C3_object_02:
    map_object 65, 3, 4, 23, 0, 48, 0, 0, 0, 0, 0, 194, 49194
map_0C3_object_03:
    map_object 65, 3, 4, 17, 0, 51, 0, 2, 0, 0, 0, 183, 49195
map_0C3_object_04:
    map_object 65, 3, 4, 32, 0, 54, 0, 0, 0, 0, 0, 168, 49196
map_0C3_object_05:
    map_object 65, 3, 4, 42, 0, 42, 1, 1, 0, 0, 0, 153, 17177
map_0C3_object_06:
    map_object 65, 1, 2, 28, 0, 50, 0, 0, 0, 0, 0, 160, 17580
map_0C3_object_07:
    map_object 65, 1, 2, 28, 0, 72, 0, 1, 0, 0, 0, 183, 50349
map_0C3_object_08:
    map_object 65, 1, 2, 13, 0, 97, 0, 1, 0, 0, 0, 183, 50350
map_0C3_object_09:
    map_object 2, 2, 2, 53, 0, 84, 0, 1, 0, 0, 0, 71, 49153
map_0C3_object_10:
    map_object 2, 2, 2, 51, 0, 97, 0, 1, 0, 0, 0, 71, 49153
map_0C3_object_11:
    map_object 2, 2, 2, 45, 0, 101, 0, 1, 0, 0, 0, 71, 49153
map_0C3_object_12:
    map_object 2, 2, 2, 36, 0, 99, 0, 1, 0, 0, 0, 71, 49153
map_0C3_object_13:
    map_object 2, 2, 2, 24, 0, 101, 0, 1, 0, 0, 0, 57, 49153
map_0C3_object_14:
    map_object 2, 2, 2, 17, 0, 93, 0, 1, 0, 0, 0, 57, 49153
map_0C3_object_15:
    map_object 2, 2, 2, 13, 0, 102, 0, 1, 0, 0, 0, 57, 49153
map_0C3_object_16:
    map_object 2, 2, 2, 2, 0, 79, 0, 1, 0, 0, 0, 57, 49153
map_0C3_object_17:
    map_object 2, 2, 2, 4, 0, 102, 0, 1, 0, 0, 0, 57, 49153
map_0C3_object_18:
    map_object 2, 2, 2, 25, 0, 95, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_19:
    map_object 2, 2, 2, 31, 0, 104, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_20:
    map_object 2, 2, 2, 18, 0, 104, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_21:
    map_object 2, 2, 2, 9, 0, 104, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_22:
    map_object 2, 2, 2, 6, 0, 95, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_23:
    map_object 2, 2, 2, 9, 0, 87, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_24:
    map_object 2, 2, 2, 41, 0, 96, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_25:
    map_object 2, 2, 2, 49, 0, 96, 0, 1, 0, 0, 0, 44, 49153
map_0C3_object_26:
    map_object 2, 2, 2, 28, 0, 46, 0, 1, 0, 0, 0, 78, 49153
map_0C3_object_27:
    map_object 2, 2, 2, 36, 0, 46, 0, 1, 0, 0, 0, 78, 49153
map_0C3_object_28:
    map_object 2, 2, 2, 19, 0, 71, 0, 1, 0, 0, 0, 78, 49153
map_0C3_object_29:
    map_object 2, 2, 2, 44, 0, 71, 0, 1, 0, 0, 0, 78, 49153
map_0C3_object_30:
    map_object 2, 2, 2, 32, 0, 94, 0, 1, 0, 0, 0, 78, 49153
map_0C3_object_31:
    map_object 2, 2, 2, 19, 0, 49, 0, 1, 0, 0, 0, 79, 49153
map_0C3_object_32:
    map_object 2, 2, 2, 44, 0, 49, 0, 1, 0, 0, 0, 79, 49153
map_0C3_object_33:
    map_object 2, 2, 2, 32, 0, 65, 0, 1, 0, 0, 0, 79, 49153
map_0C3_object_34:
    map_object 2, 2, 2, 31, 0, 57, 0, 1, 0, 0, 0, 49, 49153
map_0C3_object_35:
    map_object 2, 2, 2, 32, 0, 78, 0, 1, 0, 0, 0, 49, 49153
map_0C3_object_36:
    map_object 2, 2, 2, 25, 0, 85, 0, 1, 0, 0, 0, 49, 49153
map_0C3_object_37:
    map_object 2, 2, 2, 36, 0, 85, 0, 1, 0, 0, 0, 49, 49153
map_0C4_header:
    map_header 14, 1, 82, 0, 14, 2, 0, 1, 0, 0, 4, 2, 0, 0, 255
map_0C4_object_00:
    map_object 23, 0, 6, 37, 0, 26, 0, 1, 0, 0, 0, 3, 49153
map_0C4_object_01:
    map_object 23, 0, 6, 15, 0, 23, 0, 1, 0, 0, 0, 3, 49153
map_0C4_object_02:
    map_object 23, 0, 6, 23, 0, 33, 0, 1, 0, 0, 0, 31, 49153
map_0C4_object_03:
    map_object 23, 0, 6, 24, 0, 22, 0, 1, 0, 0, 0, 31, 49153
map_0C4_object_04:
    map_object 23, 0, 6, 40, 0, 32, 0, 1, 0, 0, 0, 2, 49153
map_0C4_object_05:
    map_object 23, 0, 6, 34, 0, 20, 0, 1, 0, 0, 0, 2, 49153
map_0C4_object_06:
    map_object 23, 0, 6, 36, 0, 39, 0, 1, 0, 0, 0, 7, 16385
map_0C4_object_07:
    map_object 23, 0, 6, 33, 0, 29, 0, 1, 0, 0, 0, 7, 16385
map_0C4_object_08:
    map_object 23, 0, 6, 13, 0, 29, 0, 1, 0, 0, 0, 7, 16385
map_0C5_header:
    map_header 0, 3, 77, 0, 0, 2, 0, 1, 0, 0, 4, 4, 0, 0, 47
map_0C5_object_00:
    map_object 39, 2, 15, 24, 1, 20, 1, 3, 1, 0, 0, 137, 0
map_0C5_object_01:
    map_object 39, 4, 4, 28, 1, 21, 1, 2, 0, 0, 0, 164, 0
map_0C5_object_02:
    map_object 39, 4, 4, 28, 1, 19, 1, 2, 2, 0, 0, 165, 0
map_0C5_object_03:
    map_object 39, 4, 4, 28, 1, 23, 1, 2, 2, 0, 0, 165, 0
map_0C6_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 1, 0, 0, 4, 21, 0, 0, 255
map_0C6_object_00:
    map_object 70, 0, 7, 19, 0, 33, 0, 1, 0, 0, 0, 60, 49153
map_0C6_object_01:
    map_object 70, 0, 7, 19, 0, 25, 0, 1, 0, 0, 0, 59, 49153
map_0C7_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0C7_object_00:
    map_object 0, 0, 15, 19, 0, 19, 0, 1, 0, 0, 0, 59, 49153
map_0C7_object_01:
    map_object 0, 0, 15, 16, 0, 23, 0, 1, 0, 0, 0, 59, 49153
map_0C7_object_02:
    map_object 0, 0, 15, 11, 0, 23, 0, 1, 0, 0, 0, 59, 49153
map_0C8_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0C8_object_00:
    map_object 0, 0, 15, 11, 0, 20, 0, 1, 0, 0, 0, 42, 49153
map_0C8_object_01:
    map_object 0, 0, 15, 19, 0, 23, 0, 1, 0, 0, 0, 42, 49153
map_0C9_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0C9_object_00:
    map_object 0, 0, 15, 9, 0, 23, 0, 1, 0, 0, 0, 60, 49153
map_0C9_object_01:
    map_object 0, 0, 15, 13, 0, 24, 0, 1, 0, 0, 0, 59, 49153
map_0C9_object_02:
    map_object 0, 0, 15, 4, 0, 18, 0, 1, 0, 0, 0, 42, 49153
map_0CA_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0CA_object_00:
    map_object 0, 0, 15, 11, 0, 21, 0, 1, 0, 0, 0, 60, 49153
map_0CA_object_01:
    map_object 0, 0, 15, 24, 0, 20, 0, 1, 0, 0, 0, 59, 49153
map_0CA_object_02:
    map_object 0, 0, 15, 18, 0, 16, 0, 1, 0, 0, 0, 42, 49153
map_0CB_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0CB_object_00:
    map_object 0, 0, 15, 30, 0, 32, 0, 1, 0, 0, 0, 59, 49153
map_0CB_object_01:
    map_object 0, 0, 15, 17, 0, 21, 0, 1, 0, 0, 0, 59, 49153
map_0CB_object_02:
    map_object 0, 0, 15, 42, 0, 20, 0, 1, 0, 0, 0, 59, 49153
map_0CB_object_03:
    map_object 0, 0, 15, 13, 0, 41, 0, 1, 0, 0, 0, 42, 49153
map_0CB_object_04:
    map_object 0, 0, 15, 43, 0, 42, 0, 1, 0, 0, 0, 42, 49153
map_0CB_object_05:
    map_object 0, 0, 15, 44, 0, 25, 0, 1, 0, 0, 0, 42, 49153
map_0CB_object_06:
    map_object 0, 0, 15, 21, 0, 28, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_07:
    map_object 0, 0, 15, 25, 0, 39, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_08:
    map_object 0, 0, 15, 31, 0, 43, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_09:
    map_object 0, 0, 15, 36, 0, 32, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_10:
    map_object 0, 0, 15, 37, 0, 15, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_11:
    map_object 0, 0, 15, 33, 0, 10, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_12:
    map_object 0, 0, 15, 30, 0, 13, 0, 1, 0, 0, 0, 17, 49153
map_0CB_object_13:
    map_object 0, 0, 15, 25, 0, 22, 0, 1, 0, 0, 0, 59, 49153
map_0CB_object_14:
    map_object 0, 0, 15, 33, 0, 39, 0, 1, 0, 0, 0, 59, 49153
map_0CB_object_15:
    map_object 0, 0, 15, 35, 0, 26, 0, 1, 0, 0, 0, 59, 49153
map_0CC_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 1, 0, 0, 1, 21, 0, 0, 255
map_0CC_object_00:
    map_object 70, 0, 0, 10, 1, 10, 0, 1, 0, 0, 0, 123, 1517
map_0CD_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0CD_object_00:
    map_object 0, 0, 15, 23, 0, 33, 0, 1, 0, 0, 0, 60, 49153
map_0CD_object_01:
    map_object 0, 0, 15, 17, 0, 35, 0, 1, 0, 0, 0, 59, 49153
map_0CD_object_02:
    map_object 0, 0, 15, 28, 0, 37, 0, 1, 0, 0, 0, 42, 49153
map_0CD_object_03:
    map_object 0, 0, 15, 19, 0, 27, 0, 1, 0, 0, 0, 42, 49153
map_0CE_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0CE_object_00:
    map_object 0, 0, 15, 17, 0, 20, 0, 1, 0, 0, 0, 48, 49153
map_0CE_object_01:
    map_object 0, 0, 15, 21, 0, 20, 0, 1, 0, 0, 0, 48, 49153
map_0CE_object_02:
    map_object 0, 0, 15, 17, 0, 22, 0, 1, 0, 0, 0, 48, 49153
map_0CF_header:
    map_header 30, 0, 104, 1, 30, 2, 0, 0, 0, 0, 7, 24, 0, 0, 255
map_0CF_object_00:
    map_object 0, 0, 15, 22, 0, 22, 0, 1, 0, 0, 0, 60, 49153
map_0CF_object_01:
    map_object 0, 0, 15, 14, 0, 27, 0, 1, 0, 0, 0, 59, 49153
map_0CF_object_02:
    map_object 0, 0, 15, 19, 0, 35, 0, 1, 0, 0, 0, 59, 49153
map_0CF_object_03:
    map_object 0, 0, 15, 21, 0, 28, 0, 1, 0, 0, 0, 48, 49153
map_0D0_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D0_object_00:
    map_object 0, 0, 15, 16, 0, 18, 0, 1, 0, 0, 0, 59, 49153
map_0D0_object_01:
    map_object 0, 0, 15, 14, 0, 27, 0, 1, 0, 0, 0, 59, 49153
map_0D0_object_02:
    map_object 0, 0, 15, 23, 0, 23, 0, 1, 0, 0, 0, 59, 49153
map_0D1_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D1_object_00:
    map_object 0, 0, 15, 17, 0, 24, 0, 1, 0, 0, 0, 59, 49153
map_0D1_object_01:
    map_object 0, 0, 15, 27, 0, 23, 0, 1, 0, 0, 0, 42, 49153
map_0D1_object_02:
    map_object 0, 0, 15, 13, 0, 21, 0, 1, 0, 0, 0, 64, 49153
map_0D1_object_03:
    map_object 0, 0, 15, 5, 0, 22, 0, 1, 0, 0, 0, 42, 49153
map_0D2_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D2_object_00:
    map_object 0, 0, 15, 11, 0, 22, 0, 1, 0, 0, 0, 59, 49153
map_0D2_object_01:
    map_object 0, 0, 15, 15, 0, 22, 0, 1, 0, 0, 0, 64, 49153
map_0D2_object_02:
    map_object 0, 0, 15, 18, 0, 19, 0, 1, 0, 0, 0, 42, 49153
map_0D3_header:
    map_header 10, 2, 101, 1, 10, 0, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_0D3_object_00:
    map_object 0, 0, 15, 11, 0, 14, 0, 1, 0, 0, 0, 17, 49153
map_0D3_object_01:
    map_object 0, 0, 15, 8, 0, 18, 0, 1, 0, 0, 0, 17, 49153
map_0D3_object_02:
    map_object 0, 0, 15, 14, 0, 17, 0, 1, 0, 0, 0, 48, 49153
map_0D4_header:
    map_header 10, 2, 101, 1, 10, 0, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_0D4_object_00:
    map_object 0, 0, 15, 16, 0, 39, 0, 1, 0, 0, 0, 17, 49153
map_0D4_object_01:
    map_object 0, 0, 15, 13, 0, 48, 0, 1, 0, 0, 0, 17, 49153
map_0D4_object_02:
    map_object 0, 0, 15, 12, 0, 29, 0, 1, 0, 0, 0, 60, 49153
map_0D4_object_03:
    map_object 0, 0, 15, 18, 0, 27, 0, 1, 0, 0, 0, 60, 49153
map_0D4_object_04:
    map_object 0, 0, 15, 16, 0, 22, 0, 1, 0, 0, 0, 64, 49153
map_0D5_header:
    map_header 10, 2, 101, 1, 10, 0, 0, 1, 0, 0, 0, 13, 0, 0, 255
map_0D5_object_00:
    map_object 70, 0, 2, 19, 1, 21, 0, 1, 0, 0, 0, 118, 1521
map_0D6_header:
    map_header 10, 0, 101, 0, 10, 0, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_0D6_object_00:
    map_object 0, 0, 15, 14, 0, 15, 0, 1, 0, 0, 0, 60, 49153
map_0D6_object_01:
    map_object 0, 0, 15, 18, 0, 16, 0, 1, 0, 0, 0, 60, 49153
map_0D6_object_02:
    map_object 0, 0, 15, 10, 0, 17, 0, 1, 0, 0, 0, 64, 49153
map_0D7_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D7_object_00:
    map_object 0, 0, 15, 15, 0, 18, 0, 1, 0, 0, 0, 59, 49153
map_0D7_object_01:
    map_object 0, 0, 15, 18, 0, 25, 0, 1, 0, 0, 0, 59, 49153
map_0D7_object_02:
    map_object 0, 0, 15, 15, 0, 22, 0, 1, 0, 0, 0, 48, 49153
map_0D8_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D8_object_00:
    map_object 0, 0, 15, 24, 0, 24, 0, 1, 0, 0, 0, 60, 49153
map_0D8_object_01:
    map_object 0, 0, 15, 16, 0, 24, 0, 1, 0, 0, 0, 64, 49153
map_0D8_object_02:
    map_object 0, 0, 15, 20, 0, 26, 0, 1, 0, 0, 0, 42, 49153
map_0D9_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0D9_object_00:
    map_object 0, 0, 15, 21, 0, 24, 0, 1, 0, 0, 0, 17, 49153
map_0D9_object_01:
    map_object 0, 0, 15, 25, 0, 30, 0, 1, 0, 0, 0, 17, 49153
map_0D9_object_02:
    map_object 0, 0, 15, 14, 0, 26, 0, 1, 0, 0, 0, 48, 49153
map_0D9_object_03:
    map_object 0, 0, 15, 20, 0, 32, 0, 1, 0, 0, 0, 48, 49153
map_0DA_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0DA_object_00:
    map_object 0, 0, 15, 20, 0, 19, 0, 1, 0, 0, 0, 59, 49153
map_0DA_object_01:
    map_object 0, 0, 15, 25, 0, 20, 0, 1, 0, 0, 0, 42, 49153
map_0DA_object_02:
    map_object 0, 0, 15, 13, 0, 19, 0, 1, 0, 0, 0, 60, 49153
map_0DA_object_03:
    map_object 0, 0, 15, 28, 0, 21, 0, 1, 0, 0, 0, 64, 49153
map_0DB_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0DB_object_00:
    map_object 0, 0, 15, 25, 0, 29, 0, 1, 0, 0, 0, 59, 49153
map_0DB_object_01:
    map_object 0, 0, 15, 21, 0, 33, 0, 1, 0, 0, 0, 42, 49153
map_0DB_object_02:
    map_object 0, 0, 15, 18, 0, 18, 0, 1, 0, 0, 0, 64, 49153
map_0DB_object_03:
    map_object 0, 0, 15, 25, 0, 21, 0, 1, 0, 0, 0, 48, 49153
map_0DC_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0DC_object_00:
    map_object 0, 0, 15, 23, 0, 23, 0, 1, 0, 0, 0, 60, 49153
map_0DC_object_01:
    map_object 0, 0, 15, 16, 0, 27, 0, 1, 0, 0, 0, 60, 49153
map_0DC_object_02:
    map_object 0, 0, 15, 13, 0, 22, 0, 1, 0, 0, 0, 42, 49153
map_0DC_object_03:
    map_object 0, 0, 15, 8, 0, 20, 0, 1, 0, 0, 0, 59, 49153
map_0DC_object_04:
    map_object 0, 0, 15, 7, 0, 13, 0, 1, 0, 0, 0, 64, 49153
map_0DD_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0DD_object_00:
    map_object 0, 0, 15, 22, 0, 19, 0, 1, 0, 0, 0, 17, 49153
map_0DD_object_01:
    map_object 0, 0, 15, 18, 0, 18, 0, 1, 0, 0, 0, 17, 49153
map_0DD_object_02:
    map_object 0, 0, 15, 15, 0, 18, 0, 1, 0, 0, 0, 48, 49153
map_0DD_object_03:
    map_object 0, 0, 15, 16, 0, 25, 0, 1, 0, 0, 0, 48, 49153
map_0DE_header:
    map_header 16, 2, 40, 0, 16, 1, 0, 1, 0, 0, 4, 10, 0, 0, 255
map_0DE_object_00:
    map_object 0, 0, 15, 28, 0, 11, 0, 1, 0, 1, 0, 16, 49153
map_0DE_object_01:
    map_object 0, 0, 15, 30, 0, 16, 0, 1, 0, 1, 0, 16, 49153
map_0DE_object_02:
    map_object 0, 0, 15, 28, 0, 19, 0, 1, 0, 1, 0, 16, 49153
map_0DE_object_03:
    map_object 0, 0, 15, 14, 0, 40, 0, 1, 0, 1, 0, 24, 49153
map_0DE_object_04:
    map_object 0, 0, 15, 24, 0, 34, 0, 1, 0, 1, 0, 24, 49153
map_0DE_object_05:
    map_object 0, 0, 15, 26, 0, 22, 0, 1, 0, 1, 0, 24, 49153
map_0DE_object_06:
    map_object 0, 0, 15, 30, 0, 33, 0, 1, 0, 1, 0, 24, 49153
map_0DE_object_07:
    map_object 0, 0, 15, 21, 0, 29, 0, 1, 0, 1, 0, 12, 49153
map_0DE_object_08:
    map_object 0, 0, 15, 20, 0, 45, 0, 1, 0, 1, 0, 12, 49153
map_0DE_object_09:
    map_object 0, 0, 15, 10, 0, 30, 0, 1, 0, 1, 0, 12, 49153
map_0DF_header:
    map_header 16, 2, 40, 0, 16, 1, 0, 1, 0, 0, 4, 10, 0, 0, 36
map_0DF_object_00:
    map_object 36, 0, 15, 32, 1, 20, 1, 3, 1, 1, 0, 175, 17005
map_0DF_object_01:
    map_object 36, 0, 15, 35, 1, 28, 0, 1, 1, 1, 0, 175, 49774
map_0DF_object_02:
    map_object 36, 0, 14, 27, 1, 48, 1, 1, 1, 1, 0, 175, 17008
map_0DF_object_03:
    map_object 36, 0, 14, 24, 1, 39, 0, 2, 2, 1, 0, 175, 49777
map_0DF_object_04:
    map_object 36, 0, 14, 14, 1, 45, 0, 1, 2, 1, 0, 175, 49778
map_0DF_object_05:
    map_object 36, 0, 14, 15, 1, 28, 0, 0, 3, 1, 0, 175, 49779
map_0DF_object_06:
    map_object 36, 0, 14, 14, 1, 45, 0, 1, 1, 1, 0, 175, 49780
map_0DF_object_07:
    map_object 36, 0, 14, 24, 1, 38, 0, 2, 2, 1, 0, 175, 49781
map_0E0_header:
    map_header 16, 2, 40, 0, 16, 1, 0, 1, 0, 0, 4, 10, 0, 0, 36
map_0E0_object_00:
    map_object 36, 15, 15, 16, 1, 33, 1, 2, 0, 1, 0, 158, 17016
map_0E0_object_01:
    map_object 36, 0, 14, 14, 1, 50, 1, 1, 1, 1, 0, 175, 17007
map_0E0_object_02:
    map_object 36, 0, 14, 18, 1, 54, 0, 1, 1, 1, 0, 175, 49780
map_0E0_object_03:
    map_object 36, 0, 14, 13, 1, 30, 0, 2, 2, 1, 0, 175, 49781
map_0E1_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0E1_object_00:
    map_object 0, 0, 15, 22, 0, 25, 0, 1, 0, 0, 0, 59, 49153
map_0E1_object_01:
    map_object 0, 0, 15, 19, 0, 18, 0, 1, 0, 0, 0, 42, 49153
map_0E1_object_02:
    map_object 0, 0, 15, 15, 0, 24, 0, 1, 0, 0, 0, 59, 49153
map_0E1_object_03:
    map_object 0, 0, 15, 17, 0, 28, 0, 1, 0, 0, 0, 59, 49153
map_0E1_object_04:
    map_object 0, 0, 15, 17, 0, 21, 0, 1, 0, 0, 0, 64, 49153
map_0E2_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 1, 0, 0, 0, 21, 0, 0, 255
map_0E2_object_00:
    map_object 70, 0, 4, 24, 1, 32, 0, 1, 0, 0, 0, 125, 1525
map_0E3_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0E3_object_00:
    map_object 0, 0, 15, 25, 0, 16, 0, 1, 0, 0, 0, 17, 49153
map_0E3_object_01:
    map_object 0, 0, 15, 24, 0, 24, 0, 1, 0, 0, 0, 17, 49153
map_0E3_object_02:
    map_object 0, 0, 15, 16, 0, 16, 0, 1, 0, 0, 0, 17, 49153
map_0E3_object_03:
    map_object 0, 0, 15, 17, 0, 17, 0, 1, 0, 0, 0, 48, 49153
map_0E3_object_04:
    map_object 0, 0, 15, 17, 0, 24, 0, 1, 0, 0, 0, 48, 49153
map_0E3_object_05:
    map_object 0, 0, 15, 24, 0, 12, 0, 1, 0, 0, 0, 48, 49153
map_0E4_header:
    map_header 25, 2, 49, 0, 25, 2, 0, 1, 0, 0, 4, 3, 0, 0, 35
map_0E4_object_00:
    map_object 0, 0, 15, 15, 0, 32, 0, 0, 3, 0, 0, 159, 50032
map_0E4_object_01:
    map_object 0, 0, 15, 38, 0, 25, 0, 0, 3, 0, 0, 159, 50033
map_0E4_object_02:
    map_object 0, 0, 15, 19, 0, 40, 0, 0, 3, 0, 0, 159, 50034
map_0E4_object_03:
    map_object 0, 0, 15, 26, 0, 33, 0, 0, 3, 0, 0, 159, 50035
map_0E4_object_04:
    map_object 0, 0, 15, 20, 0, 38, 0, 0, 3, 0, 0, 159, 50036
map_0E5_header:
    map_header 30, 0, 54, 1, 30, 2, 0, 0, 0, 0, 7, 21, 0, 0, 255
map_0E5_object_00:
    map_object 0, 0, 15, 21, 0, 31, 0, 1, 0, 0, 0, 59, 49153
map_0E5_object_01:
    map_object 0, 0, 15, 17, 0, 36, 0, 1, 0, 0, 0, 42, 49153
map_0E5_object_02:
    map_object 0, 0, 15, 19, 0, 26, 0, 1, 0, 0, 0, 64, 49153
map_0E5_object_03:
    map_object 0, 0, 15, 27, 0, 36, 0, 1, 0, 0, 0, 60, 49153
map_0E6_header:
    map_header 30, 0, 105, 0, 30, 0, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_0E6_object_00:
    map_object 70, 0, 1, 12, 1, 16, 0, 1, 0, 0, 0, 115, 1519
map_0E7_header:
    map_header 10, 0, 102, 0, 10, 0, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_0E7_object_00:
    map_object 70, 0, 3, 12, 1, 16, 0, 1, 0, 0, 0, 117, 1523
map_0E8_header:
    map_header 17, 0, 41, 0, 17, 0, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_0E8_object_00:
    map_object 70, 0, 5, 12, 1, 16, 0, 1, 0, 0, 0, 119, 1527
map_0E9_header:
    map_header 17, 0, 41, 0, 17, 2, 0, 1, 0, 0, 6, 13, 0, 0, 0
map_0EA_header:
    map_header 17, 0, 41, 0, 17, 2, 0, 1, 0, 0, 6, 13, 0, 0, 0
map_0EB_header:
    map_header 17, 0, 41, 0, 17, 2, 0, 1, 0, 0, 6, 13, 0, 0, 0
map_0EC_header:
    map_header 11, 0, 103, 0, 11, 2, 0, 0, 0, 10, 0, 18, 0, 0, 255
map_0EC_object_00:
    map_object 70, 0, 6, 8, 1, 22, 1, 0, 0, 0, 0, 138, 0
map_0EC_object_01:
    map_object 70, 0, 6, 7, 1, 23, 1, 0, 0, 0, 0, 139, 0
map_0EC_object_02:
    map_object 70, 0, 6, 9, 1, 23, 1, 0, 0, 0, 0, 140, 0
map_0EC_object_03:
    map_object 70, 8, 8, 9, 1, 15, 1, 0, 0, 1, 0, 190, 0
map_0EC_object_04:
    map_object 70, 8, 8, 9, 1, 11, 1, 3, 0, 1, 0, 190, 0
map_0ED_header:
    map_header 21, 0, 45, 1, 21, 2, 0, 0, 0, 6, 0, 0, 0, 0, 255
map_0ED_object_00:
    map_object 0, 0, 15, 16, 1, 20, 0, 1, 0, 0, 0, 114, 1188
map_0EE_header:
    map_header 31, 0, 74, 0, 31, 2, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_0EE_object_00:
    map_object 69, 1, 1, 13, 1, 11, 0, 1, 0, 0, 0, 110, 17588
map_0F0_header:
    map_header 23, 3, 91, 1, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_0F0_object_00:
    map_object 43, 3, 3, 16, 1, 19, 1, 0, 0, 0, 0, 85, 1742
map_0F1_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_0F4_header:
    map_header 21, 0, 45, 1, 21, 2, 0, 0, 0, 0, 0, 0, 0, 0, 255
map_0F4_object_00:
    map_object 78, 0, 1, 17, 1, 45, 0, 1, 0, 0, 0, 120, 17442
map_0F5_header:
    map_header 21, 0, 113, 1, 21, 0, 0, 1, 0, 14, 0, 0, 0, 0, 255
map_0F5_object_00:
    map_object 78, 0, 5, 18, 1, 24, 1, 1, 0, 0, 0, 172, 0
map_0F5_object_01:
    map_object 78, 0, 4, 17, 1, 25, 1, 1, 0, 0, 0, 191, 0
map_0F5_object_02:
    map_object 78, 6, 6, 18, 1, 21, 0, 1, 0, 0, 0, 121, 17453
map_0F6_header:
    map_header 21, 0, 113, 1, 21, 0, 0, 1, 30, 14, 0, 0, 0, 0, 255
map_0F6_object_00:
    map_object 78, 0, 5, 18, 1, 24, 1, 1, 0, 0, 0, 172, 0
map_0F6_object_01:
    map_object 78, 0, 4, 17, 1, 25, 1, 1, 0, 0, 0, 191, 0
map_0F6_object_02:
    map_object 78, 6, 6, 18, 1, 21, 0, 1, 0, 0, 0, 121, 17453
map_0F8_header:
    map_header 21, 0, 45, 1, 21, 2, 1, 1, 0, 0, 0, 0, 0, 0, 255
map_0F8_object_00:
    map_object 0, 0, 15, 64, 0, 88, 0, 3, 0, 0, 0, 61, 49153
map_0F8_object_01:
    map_object 0, 0, 15, 69, 0, 88, 0, 2, 0, 0, 0, 61, 49153
map_0F8_object_02:
    map_object 0, 0, 15, 40, 0, 89, 0, 1, 0, 0, 0, 61, 49153
map_0F8_object_03:
    map_object 0, 0, 15, 53, 0, 90, 0, 0, 0, 0, 0, 61, 49153
map_0F8_object_04:
    map_object 0, 0, 15, 67, 0, 84, 0, 1, 0, 0, 0, 73, 49153
map_0F8_object_05:
    map_object 0, 0, 15, 52, 0, 37, 0, 0, 0, 0, 0, 73, 49153
map_0F8_object_06:
    map_object 0, 0, 15, 37, 0, 50, 0, 1, 0, 0, 0, 73, 49153
map_0F8_object_07:
    map_object 0, 0, 15, 46, 0, 89, 0, 3, 0, 0, 0, 73, 49153
map_0F8_object_08:
    map_object 0, 0, 15, 69, 0, 72, 0, 2, 0, 0, 0, 67, 49153
map_0F8_object_09:
    map_object 0, 0, 15, 63, 0, 70, 0, 1, 0, 0, 0, 67, 49153
map_0F8_object_10:
    map_object 0, 0, 15, 54, 0, 30, 0, 2, 0, 0, 0, 67, 49153
map_0F8_object_11:
    map_object 0, 0, 15, 48, 0, 30, 0, 3, 0, 0, 0, 67, 49153
map_0F8_object_12:
    map_object 0, 0, 15, 67, 0, 50, 0, 1, 0, 0, 0, 75, 49153
map_0F8_object_13:
    map_object 0, 0, 15, 53, 0, 72, 0, 1, 0, 0, 0, 75, 49153
map_0F8_object_14:
    map_object 0, 0, 15, 71, 0, 48, 0, 1, 0, 0, 0, 77, 49153
map_0F8_object_15:
    map_object 0, 0, 15, 62, 0, 48, 0, 1, 0, 0, 0, 77, 49153
map_0F8_object_16:
    map_object 0, 0, 15, 48, 0, 69, 0, 1, 0, 0, 0, 77, 49153
map_0F8_object_17:
    map_object 0, 0, 15, 61, 0, 33, 0, 1, 0, 0, 0, 74, 49153
map_0F8_object_18:
    map_object 0, 0, 15, 72, 0, 33, 0, 1, 0, 0, 0, 74, 49153
map_0F8_object_19:
    map_object 0, 0, 15, 37, 0, 16, 0, 1, 0, 0, 0, 74, 49153
map_0F8_object_20:
    map_object 0, 0, 15, 38, 0, 12, 0, 1, 0, 0, 0, 74, 49153
map_0F8_object_21:
    map_object 0, 0, 15, 22, 0, 11, 0, 1, 0, 0, 0, 74, 49153
map_0F8_object_22:
    map_object 0, 0, 15, 18, 0, 14, 0, 3, 0, 0, 0, 74, 49153
map_0F8_object_23:
    map_object 0, 0, 15, 67, 0, 29, 0, 1, 0, 0, 0, 80, 49153
map_0F8_object_24:
    map_object 0, 0, 15, 29, 0, 14, 0, 3, 0, 0, 0, 80, 49153
map_0F8_object_25:
    map_object 0, 0, 15, 70, 0, 70, 0, 0, 0, 0, 0, 68, 49153
map_0F8_object_26:
    map_object 0, 0, 15, 73, 0, 15, 0, 2, 0, 0, 0, 68, 49153
map_0F8_object_27:
    map_object 0, 0, 15, 38, 0, 30, 0, 3, 0, 0, 0, 68, 49153
map_0F8_object_28:
    map_object 0, 0, 15, 28, 0, 72, 0, 3, 0, 0, 0, 68, 49153
map_0F8_object_29:
    map_object 0, 0, 15, 38, 0, 45, 0, 1, 0, 0, 0, 81, 49153
map_0F8_object_30:
    map_object 0, 0, 15, 53, 0, 51, 0, 1, 0, 0, 0, 81, 49153
map_0F8_object_31:
    map_object 0, 0, 15, 50, 0, 51, 0, 1, 0, 0, 0, 81, 49153
map_0F8_object_32:
    map_object 0, 0, 15, 38, 0, 54, 0, 1, 0, 0, 0, 81, 49153
map_0F8_object_33:
    map_object 0, 0, 15, 12, 0, 90, 0, 3, 0, 0, 0, 65, 49153
map_0F8_object_34:
    map_object 0, 0, 15, 19, 0, 91, 0, 3, 0, 0, 0, 65, 49153
map_0F8_object_35:
    map_object 0, 0, 15, 25, 0, 90, 0, 0, 0, 0, 0, 65, 49153
map_0F8_object_36:
    map_object 0, 0, 15, 40, 0, 74, 0, 1, 0, 0, 0, 57, 49153
map_0F8_object_37:
    map_object 0, 0, 15, 52, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_0F8_object_38:
    map_object 0, 0, 15, 52, 0, 55, 0, 1, 0, 0, 0, 76, 49153
map_0F9_header:
    map_header 21, 0, 45, 1, 21, 2, 1, 1, 0, 0, 0, 0, 0, 0, 255
map_0F9_object_00:
    map_object 0, 0, 15, 65, 0, 19, 0, 1, 0, 0, 0, 67, 49153
map_0F9_object_01:
    map_object 0, 0, 15, 49, 0, 23, 0, 1, 0, 0, 0, 67, 49153
map_0F9_object_02:
    map_object 0, 0, 15, 12, 0, 55, 0, 1, 0, 0, 0, 67, 49153
map_0F9_object_03:
    map_object 0, 0, 15, 24, 0, 55, 0, 1, 0, 0, 0, 67, 49153
map_0F9_object_04:
    map_object 0, 0, 15, 63, 0, 59, 0, 1, 0, 0, 0, 75, 49153
map_0F9_object_05:
    map_object 0, 0, 15, 47, 0, 59, 0, 1, 0, 0, 0, 75, 49153
map_0F9_object_06:
    map_object 0, 0, 15, 49, 0, 36, 0, 1, 0, 0, 0, 75, 49153
map_0F9_object_07:
    map_object 0, 0, 15, 68, 0, 64, 0, 2, 0, 0, 0, 77, 49153
map_0F9_object_08:
    map_object 0, 0, 15, 52, 0, 63, 0, 2, 0, 0, 0, 77, 49153
map_0F9_object_09:
    map_object 0, 0, 15, 6, 0, 38, 0, 1, 0, 0, 0, 77, 49153
map_0F9_object_10:
    map_object 0, 0, 15, 13, 0, 39, 0, 1, 0, 0, 0, 77, 49153
map_0F9_object_11:
    map_object 0, 0, 15, 33, 0, 36, 0, 1, 0, 0, 0, 74, 49153
map_0F9_object_12:
    map_object 0, 0, 15, 9, 0, 83, 0, 3, 0, 0, 0, 74, 49153
map_0F9_object_13:
    map_object 0, 0, 15, 22, 0, 83, 0, 2, 0, 0, 0, 74, 49153
map_0F9_object_14:
    map_object 0, 0, 15, 36, 0, 68, 0, 1, 0, 0, 0, 80, 49153
map_0F9_object_15:
    map_object 0, 0, 15, 21, 0, 68, 0, 1, 0, 0, 0, 80, 49153
map_0F9_object_16:
    map_object 0, 0, 15, 10, 0, 71, 0, 1, 0, 0, 0, 80, 49153
map_0F9_object_17:
    map_object 0, 0, 15, 41, 0, 36, 0, 1, 0, 0, 0, 80, 49153
map_0F9_object_18:
    map_object 0, 0, 15, 63, 0, 79, 0, 1, 0, 0, 0, 68, 49153
map_0F9_object_19:
    map_object 0, 0, 15, 65, 0, 30, 0, 1, 0, 0, 0, 68, 49153
map_0F9_object_20:
    map_object 0, 0, 15, 58, 0, 21, 0, 1, 0, 0, 0, 68, 49153
map_0F9_object_21:
    map_object 0, 0, 15, 43, 0, 13, 0, 1, 0, 0, 0, 68, 49153
map_0F9_object_22:
    map_object 0, 0, 15, 14, 0, 51, 0, 1, 0, 0, 0, 68, 49153
map_0F9_object_23:
    map_object 0, 0, 15, 12, 0, 17, 0, 1, 0, 0, 0, 65, 49153
map_0F9_object_24:
    map_object 0, 0, 15, 20, 0, 14, 0, 1, 0, 0, 0, 65, 49153
map_0F9_object_25:
    map_object 0, 0, 15, 52, 0, 16, 0, 1, 0, 0, 0, 57, 49153
map_0F9_object_26:
    map_object 0, 0, 15, 34, 0, 56, 0, 1, 0, 0, 0, 76, 49153
map_0F9_object_27:
    map_object 0, 0, 15, 66, 0, 83, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_28:
    map_object 0, 0, 15, 60, 0, 83, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_29:
    map_object 0, 0, 15, 34, 0, 42, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_30:
    map_object 0, 0, 15, 8, 0, 66, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_31:
    map_object 0, 0, 15, 11, 0, 66, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_32:
    map_object 0, 0, 15, 29, 0, 68, 0, 1, 0, 0, 0, 79, 49153
map_0F9_object_33:
    map_object 0, 0, 15, 67, 0, 13, 0, 1, 0, 0, 0, 69, 49153
map_0F9_object_34:
    map_object 0, 0, 15, 36, 0, 84, 0, 1, 0, 0, 0, 49, 49153
map_0F9_object_35:
    map_object 0, 0, 15, 30, 0, 17, 0, 1, 0, 0, 0, 49, 49153
map_0F9_object_36:
    map_object 0, 0, 15, 37, 0, 17, 0, 1, 0, 0, 0, 49, 49153
map_0F9_object_37:
    map_object 0, 0, 15, 33, 0, 17, 0, 1, 0, 0, 0, 61, 49153
map_0F9_object_38:
    map_object 0, 0, 15, 41, 0, 84, 0, 1, 0, 0, 0, 61, 49153
map_0F9_object_39:
    map_object 0, 0, 15, 47, 0, 84, 0, 1, 0, 0, 0, 73, 49153
map_0F9_object_40:
    map_object 0, 0, 15, 25, 0, 15, 0, 1, 0, 0, 0, 73, 49153
map_0FA_header:
    map_header 21, 0, 45, 1, 21, 2, 1, 0, 0, 0, 0, 0, 0, 0, 255
map_0FA_object_00:
    map_object 0, 0, 15, 13, 0, 43, 0, 1, 0, 0, 0, 61, 49153
map_0FA_object_01:
    map_object 0, 0, 15, 42, 0, 95, 0, 1, 0, 0, 0, 73, 49153
map_0FA_object_02:
    map_object 0, 0, 15, 16, 0, 67, 0, 1, 0, 0, 0, 73, 49153
map_0FA_object_03:
    map_object 0, 0, 15, 93, 0, 45, 0, 1, 0, 0, 0, 73, 49153
map_0FA_object_04:
    map_object 0, 0, 15, 68, 0, 39, 0, 3, 0, 0, 0, 75, 49153
map_0FA_object_05:
    map_object 0, 0, 15, 12, 0, 21, 0, 3, 0, 0, 0, 75, 49153
map_0FA_object_06:
    map_object 0, 0, 15, 16, 0, 95, 0, 0, 0, 0, 0, 75, 49153
map_0FA_object_07:
    map_object 0, 0, 15, 103, 0, 66, 0, 1, 0, 0, 0, 77, 49153
map_0FA_object_08:
    map_object 0, 0, 15, 92, 0, 66, 0, 1, 0, 0, 0, 77, 49153
map_0FA_object_09:
    map_object 0, 0, 15, 76, 0, 39, 0, 1, 0, 0, 0, 77, 49153
map_0FA_object_10:
    map_object 0, 0, 15, 24, 0, 23, 0, 1, 0, 0, 0, 77, 49153
map_0FA_object_11:
    map_object 0, 0, 15, 46, 0, 34, 0, 1, 0, 0, 0, 74, 49153
map_0FA_object_12:
    map_object 0, 0, 15, 76, 0, 21, 0, 1, 0, 0, 0, 74, 49153
map_0FA_object_13:
    map_object 0, 0, 15, 97, 0, 22, 0, 1, 0, 0, 0, 74, 49153
map_0FA_object_14:
    map_object 0, 0, 15, 95, 0, 19, 0, 1, 0, 0, 0, 80, 49153
map_0FA_object_15:
    map_object 0, 0, 15, 78, 0, 19, 0, 1, 0, 0, 0, 80, 49153
map_0FA_object_16:
    map_object 0, 0, 15, 29, 0, 35, 0, 1, 0, 0, 0, 80, 49153
map_0FA_object_17:
    map_object 0, 0, 15, 18, 0, 60, 0, 1, 0, 0, 0, 80, 49153
map_0FA_object_18:
    map_object 0, 0, 15, 12, 0, 60, 0, 1, 0, 0, 0, 80, 49153
map_0FA_object_19:
    map_object 0, 0, 15, 41, 0, 91, 0, 1, 0, 0, 0, 68, 49153
map_0FA_object_20:
    map_object 0, 0, 15, 36, 0, 96, 0, 1, 0, 0, 0, 68, 49153
map_0FA_object_21:
    map_object 0, 0, 15, 16, 0, 87, 0, 0, 0, 0, 0, 68, 49153
map_0FA_object_22:
    map_object 0, 0, 15, 103, 0, 41, 0, 1, 0, 0, 0, 81, 49153
map_0FA_object_23:
    map_object 0, 0, 15, 15, 0, 37, 0, 1, 0, 0, 0, 81, 49153
map_0FA_object_24:
    map_object 0, 0, 15, 98, 0, 37, 0, 1, 0, 0, 0, 82, 49153
map_0FA_object_25:
    map_object 0, 0, 15, 53, 0, 13, 0, 1, 0, 0, 0, 82, 49153
map_0FA_object_26:
    map_object 0, 0, 15, 22, 0, 49, 0, 0, 0, 0, 0, 82, 49153
map_0FA_object_27:
    map_object 0, 0, 15, 10, 0, 49, 0, 0, 0, 0, 0, 82, 49153
map_0FA_object_28:
    map_object 0, 0, 15, 38, 0, 111, 0, 1, 0, 0, 0, 82, 49153
map_0FA_object_29:
    map_object 0, 0, 15, 36, 0, 114, 0, 1, 0, 0, 0, 82, 49153
map_0FA_object_30:
    map_object 0, 0, 15, 39, 0, 114, 0, 1, 0, 0, 0, 82, 49153
map_0FA_object_31:
    map_object 0, 0, 15, 61, 0, 19, 0, 1, 0, 0, 0, 62, 49153
map_0FA_object_32:
    map_object 0, 0, 15, 45, 0, 19, 0, 1, 0, 0, 0, 78, 49153
map_0FA_object_33:
    map_object 0, 0, 15, 37, 0, 37, 0, 1, 0, 0, 0, 79, 49153
map_0FA_object_34:
    map_object 0, 0, 15, 37, 0, 42, 0, 1, 0, 0, 0, 79, 49153
map_0FA_object_35:
    map_object 0, 0, 15, 61, 0, 34, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_36:
    map_object 0, 0, 15, 32, 0, 22, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_37:
    map_object 0, 0, 15, 20, 0, 17, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_38:
    map_object 0, 0, 15, 18, 0, 113, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_39:
    map_object 0, 0, 15, 16, 0, 115, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_40:
    map_object 0, 0, 15, 14, 0, 117, 0, 1, 0, 0, 0, 83, 49153
map_0FA_object_41:
    map_object 0, 0, 15, 98, 0, 62, 0, 1, 0, 0, 0, 83, 49153
map_0FB_header:
    map_header 21, 0, 45, 1, 21, 2, 0, 0, 0, 6, 1, 0, 0, 0, 255
map_0FD_header:
    map_header 23, 0, 47, 0, 23, 0, 0, 0, 31, 0, 0, 0, 0, 0, 255
map_0FD_object_00:
    map_object 78, 8, 8, 18, 1, 18, 0, 1, 0, 0, 0, 127, 17455
map_0FF_header:
    map_header 20, 0, 44, 1, 20, 2, 0, 1, 0, 15, 4, 15, 0, 0, 255
map_0FF_object_00:
    map_object 78, 0, 6, 21, 0, 22, 0, 1, 0, 0, 0, 75, 49153
map_0FF_object_01:
    map_object 78, 0, 6, 12, 0, 32, 0, 1, 0, 0, 0, 77, 49153
map_0FF_object_02:
    map_object 78, 0, 6, 26, 0, 25, 0, 1, 0, 0, 0, 77, 49153
map_0FF_object_03:
    map_object 78, 0, 6, 19, 0, 40, 0, 3, 0, 0, 0, 65, 49153
map_0FF_object_04:
    map_object 78, 0, 6, 22, 0, 40, 0, 2, 0, 0, 0, 65, 49153
map_0FF_object_05:
    map_object 78, 0, 6, 12, 0, 32, 0, 1, 0, 0, 0, 47, 49153
map_100_header:
    map_header 2, 3, 59, 1, 2, 3, 0, 1, 1, 11, 0, 11, 0, 0, 2
map_100_object_00:
    map_object 12, 0, 0, 14, 0, 8, 1, 2, 0, 1, 7, 138, 49318
map_100_object_01:
    map_object 0, 0, 15, 4, 0, 8, 1, 3, 1, 1, 7, 192, 49320
map_100_object_02:
    map_object 0, 0, 15, 5, 0, 8, 1, 3, 3, 1, 7, 193, 49321
map_101_header:
    map_header 4, 2, 28, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 17
map_101_object_00:
    map_object 16, 0, 15, 13, 1, 13, 0, 2, 0, 1, 0, 197, 49418
map_101_object_01:
    map_object 16, 10, 15, 16, 1, 13, 0, 1, 0, 1, 0, 196, 49429
map_101_object_02:
    map_object 16, 0, 15, 15, 1, 31, 0, 1, 2, 1, 0, 207, 53519
map_101_object_03:
    map_object 16, 0, 6, 9, 1, 35, 0, 3, 1, 1, 0, 198, 49424
map_101_object_04:
    map_object 16, 10, 15, 9, 1, 35, 0, 3, 1, 1, 0, 198, 49424
map_101_object_05:
    map_object 16, 1, 5, 17, 1, 33, 1, 0, 3, 1, 2, 160, 16657
map_101_object_06:
    map_object 16, 0, 15, 31, 1, 13, 0, 1, 2, 1, 0, 207, 54016
map_102_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 21
map_102_object_00:
    map_object 16, 0, 9, 54, 1, 13, 1, 2, 0, 1, 0, 196, 16661
map_102_object_01:
    map_object 16, 0, 9, 52, 1, 14, 1, 0, 0, 1, 0, 197, 16662
map_102_object_02:
    map_object 16, 0, 9, 50, 1, 12, 1, 1, 0, 1, 0, 202, 16663
map_102_object_03:
    map_object 16, 0, 9, 51, 1, 14, 1, 0, 1, 1, 0, 198, 16664
map_102_object_04:
    map_object 16, 0, 15, 52, 1, 12, 1, 1, 0, 1, 0, 201, 16660
map_102_object_05:
    map_object 16, 0, 15, 49, 1, 32, 0, 0, 1, 1, 0, 200, 49433
map_102_object_06:
    map_object 208, 0, 0, 49, 1, 34, 1, 0, 2, 1, 0, 235, 18048
map_103_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 15
map_103_object_00:
    map_object 16, 0, 15, 20, 0, 11, 0, 1, 3, 1, 6, 207, 54048
map_104_header:
    map_header 10, 0, 34, 0, 10, 2, 0, 0, 0, 0, 0, 1, 0, 0, 255
map_104_object_00:
    map_object 16, 0, 15, 13, 0, 14, 0, 1, 0, 0, 0, 87, 16658
map_105_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 24
map_105_object_00:
    map_object 18, 0, 14, 67, 0, 32, 0, 1, 0, 1, 0, 207, 53467
map_105_object_01:
    map_object 18, 0, 14, 14, 0, 78, 0, 1, 0, 1, 0, 207, 53466
map_105_object_02:
    map_object 18, 0, 14, 17, 1, 53, 1, 1, 2, 1, 0, 196, 20816
map_105_object_03:
    map_object 18, 0, 14, 16, 1, 57, 1, 0, 3, 1, 0, 197, 16721
map_105_object_04:
    map_object 18, 0, 14, 16, 1, 60, 0, 3, 2, 1, 0, 199, 49490
map_105_object_05:
    map_object 18, 0, 14, 26, 1, 55, 0, 2, 2, 1, 0, 200, 49491
map_105_object_06:
    map_object 18, 0, 14, 47, 0, 17, 0, 0, 3, 1, 0, 196, 49492
map_105_object_07:
    map_object 18, 0, 14, 41, 1, 56, 0, 1, 3, 1, 0, 201, 16725
map_105_object_08:
    map_object 18, 0, 5, 51, 1, 58, 1, 2, 2, 1, 0, 202, 16718
map_105_object_09:
    map_object 18, 0, 5, 37, 1, 76, 0, 1, 1, 1, 0, 166, 49495
map_105_object_10:
    map_object 18, 9, 14, 43, 1, 78, 1, 2, 2, 1, 0, 202, 16726
map_106_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 15
map_106_object_00:
    map_object 18, 0, 14, 20, 0, 11, 0, 1, 3, 1, 6, 207, 53468
map_107_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 25
map_107_object_00:
    map_object 18, 0, 14, 10, 1, 12, 0, 0, 2, 1, 0, 197, 49480
map_107_object_01:
    map_object 18, 4, 4, 18, 1, 14, 1, 2, 3, 1, 0, 139, 16714
map_107_object_02:
    map_object 18, 3, 14, 39, 1, 11, 0, 1, 0, 1, 0, 187, 49481
map_107_object_03:
    map_object 18, 3, 3, 46, 1, 8, 1, 1, 3, 1, 0, 139, 16715
map_108_header:
    map_header 15, 3, 87, 0, 15, 2, 0, 0, 0, 0, 3, 2, 0, 0, 29
map_108_object_00:
    map_object 19, 0, 1, 28, 0, 27, 0, 1, 3, 0, 0, 188, 49546
map_108_object_01:
    map_object 18, 0, 14, 19, 0, 24, 0, 2, 0, 0, 0, 183, 49547
map_108_object_02:
    map_object 18, 0, 14, 6, 0, 26, 0, 1, 3, 0, 0, 198, 49549
map_108_object_03:
    map_object 18, 0, 14, 12, 0, 23, 0, 1, 2, 0, 0, 199, 49550
map_108_object_04:
    map_object 18, 0, 8, 28, 0, 26, 0, 1, 3, 0, 0, 200, 49551
map_108_object_05:
    map_object 18, 0, 14, 12, 0, 8, 0, 1, 3, 0, 0, 196, 49552
map_108_object_06:
    map_object 18, 0, 14, 28, 0, 9, 0, 1, 2, 0, 0, 197, 49553
map_109_header:
    map_header 15, 3, 87, 0, 15, 2, 1, 0, 0, 0, 3, 2, 0, 0, 30
map_109_object_00:
    map_object 19, 0, 1, 33, 1, 7, 1, 1, 1, 0, 0, 139, 16384
map_109_object_01:
    map_object 18, 0, 8, 46, 0, 7, 0, 1, 0, 0, 0, 183, 49548
map_109_object_02:
    map_object 18, 0, 8, 64, 0, 7, 0, 3, 2, 0, 0, 187, 49545
map_109_object_03:
    map_object 18, 0, 14, 14, 1, 26, 1, 0, 0, 0, 7, 183, 16792
map_109_object_04:
    map_object 18, 0, 14, 10, 1, 33, 0, 0, 0, 0, 0, 183, 49561
map_109_object_05:
    map_object 18, 0, 14, 9, 1, 27, 0, 3, 0, 0, 0, 183, 49562
map_109_object_06:
    map_object 18, 0, 14, 14, 1, 34, 1, 2, 2, 0, 2, 196, 16795
map_10A_header:
    map_header 15, 3, 87, 0, 15, 2, 0, 1, 0, 0, 3, 2, 0, 0, 26
map_10A_object_00:
    map_object 19, 0, 4, 11, 1, 14, 1, 0, 0, 0, 0, 160, 16768
map_10A_object_01:
    map_object 19, 0, 5, 11, 1, 9, 1, 1, 1, 0, 7, 189, 16769
map_10A_object_02:
    map_object 19, 0, 5, 13, 1, 9, 1, 1, 2, 0, 7, 188, 16770
map_10A_object_03:
    map_object 18, 0, 14, 7, 1, 10, 1, 3, 2, 0, 0, 187, 16771
map_10A_object_04:
    map_object 18, 0, 14, 5, 1, 15, 1, 3, 3, 0, 0, 183, 16772
map_10A_object_05:
    map_object 18, 0, 14, 18, 1, 15, 1, 2, 3, 0, 0, 183, 16773
map_10A_object_06:
    map_object 18, 0, 14, 8, 1, 23, 1, 0, 3, 0, 0, 183, 16773
map_10A_object_07:
    map_object 18, 0, 14, 16, 1, 23, 1, 0, 3, 0, 0, 183, 16772
map_10B_header:
    map_header 15, 3, 87, 0, 15, 2, 0, 1, 0, 0, 3, 2, 0, 0, 64
map_10B_object_00:
    map_object 19, 0, 3, 7, 1, 12, 1, 3, 1, 0, 7, 187, 16786
map_10B_object_01:
    map_object 19, 0, 2, 11, 1, 11, 1, 2, 0, 0, 7, 192, 16788
map_10B_object_02:
    map_object 19, 0, 2, 11, 1, 13, 1, 2, 3, 0, 7, 201, 16787
map_10C_header:
    map_header 15, 3, 87, 0, 15, 2, 0, 0, 0, 0, 3, 2, 0, 0, 29
map_10C_object_00:
    map_object 185, 0, 1, 3, 1, 16, 1, 0, 1, 0, 0, 235, 18033
map_10C_object_01:
    map_object 187, 0, 1, 5, 1, 16, 1, 0, 1, 0, 0, 235, 18035
map_10C_object_02:
    map_object 211, 0, 0, 7, 1, 16, 1, 0, 1, 0, 0, 235, 18051
map_10C_object_03:
    map_object 212, 0, 0, 3, 1, 14, 1, 0, 1, 0, 0, 235, 18052
map_10C_object_04:
    map_object 213, 0, 0, 5, 1, 14, 1, 0, 1, 0, 0, 235, 18053
map_10C_object_05:
    map_object 214, 0, 0, 7, 1, 14, 1, 0, 1, 0, 0, 235, 18054
map_10D_header:
    map_header 23, 3, 89, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_10D_object_00:
    map_object 24, 0, 7, 6, 0, 12, 0, 1, 0, 0, 0, 25, 49153
map_10D_object_01:
    map_object 24, 0, 7, 8, 0, 12, 0, 1, 0, 0, 0, 25, 49153
map_10D_object_02:
    map_object 24, 0, 7, 11, 0, 17, 0, 1, 0, 0, 0, 11, 49153
map_10D_object_03:
    map_object 24, 0, 7, 27, 0, 15, 0, 1, 0, 0, 0, 11, 49153
map_10D_object_04:
    map_object 24, 0, 7, 40, 0, 13, 0, 0, 0, 0, 0, 11, 49153
map_10E_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 1, 0, 0, 0, 40
map_10E_object_00:
    map_object 40, 0, 1, 26, 1, 19, 1, 3, 0, 0, 0, 185, 16384
map_10E_object_01:
    map_object 40, 0, 9, 15, 1, 21, 1, 1, 1, 0, 0, 183, 17039
map_10E_object_02:
    map_object 40, 0, 9, 20, 1, 21, 1, 1, 1, 0, 0, 183, 17038
map_10F_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 1, 0, 0, 0, 40
map_10F_object_00:
    map_object 40, 0, 3, 14, 1, 19, 1, 1, 1, 0, 0, 183, 17037
map_10F_object_01:
    map_object 40, 0, 3, 15, 1, 19, 1, 1, 1, 0, 0, 183, 17037
map_10F_object_02:
    map_object 40, 4, 9, 14, 1, 19, 0, 1, 1, 0, 0, 183, 49805
map_10F_object_03:
    map_object 40, 4, 9, 15, 1, 19, 0, 1, 1, 0, 0, 183, 49805
map_10F_object_04:
    map_object 40, 0, 9, 10, 1, 19, 0, 0, 1, 0, 0, 183, 49806
map_10F_object_05:
    map_object 40, 0, 9, 6, 1, 16, 0, 2, 1, 0, 0, 183, 49807
map_10F_object_06:
    map_object 40, 0, 9, 10, 1, 13, 0, 3, 2, 0, 0, 196, 49808
map_10F_object_07:
    map_object 40, 0, 9, 10, 1, 7, 0, 0, 3, 0, 0, 168, 49809
map_111_header:
    map_header 23, 3, 47, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_111_object_00:
    map_object 146, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25994
map_111_object_01:
    map_object 146, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21898
map_111_object_02:
    map_object 33, 4, 4, 12, 1, 10, 1, 1, 0, 0, 0, 147, 16384
map_111_object_03:
    map_object 33, 3, 12, 12, 1, 12, 1, 2, 0, 0, 0, 157, 12882
map_112_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 1, 0, 0, 0, 0, 0, 0, 36
map_112_object_00:
    map_object 36, 0, 15, 19, 0, 10, 0, 1, 2, 1, 6, 175, 54052
map_113_header:
    map_header 10, 2, 101, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_113_object_00:
    map_object 0, 0, 15, 14, 0, 15, 0, 1, 0, 0, 0, 5, 16385
map_113_object_01:
    map_object 0, 0, 15, 13, 0, 17, 0, 1, 0, 0, 0, 5, 16385
map_113_object_02:
    map_object 0, 0, 15, 18, 0, 16, 0, 1, 0, 0, 0, 5, 16385
map_114_header:
    map_header 23, 3, 89, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_114_object_00:
    map_object 147, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25995
map_114_object_01:
    map_object 147, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21899
map_114_object_02:
    map_object 168, 1, 1, 14, 1, 15, 1, 1, 0, 0, 0, 144, 4654
map_115_header:
    map_header 10, 2, 101, 1, 10, 2, 0, 1, 0, 0, 1, 13, 0, 0, 255
map_115_object_00:
    map_object 169, 0, 0, 19, 1, 12, 0, 1, 0, 0, 0, 113, 16947
map_116_header:
    map_header 10, 2, 101, 1, 10, 2, 0, 0, 0, 0, 3, 13, 0, 0, 34
map_116_object_00:
    map_object 169, 0, 1, 20, 1, 12, 1, 1, 0, 0, 0, 145, 5505
map_117_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 18
map_117_object_00:
    map_object 0, 0, 15, 20, 1, 11, 1, 1, 2, 1, 6, 153, 53401
map_118_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 33
map_118_object_00:
    map_object 18, 0, 14, 42, 0, 32, 0, 1, 0, 1, 0, 207, 21251
map_118_object_01:
    map_object 18, 0, 14, 53, 1, 13, 0, 0, 1, 1, 0, 198, 16931
map_118_object_02:
    map_object 18, 0, 14, 37, 1, 12, 0, 2, 2, 1, 0, 206, 16932
map_118_object_03:
    map_object 18, 0, 14, 10, 1, 13, 0, 3, 1, 1, 0, 201, 16933
map_118_object_04:
    map_object 18, 0, 14, 20, 1, 14, 0, 1, 1, 1, 0, 202, 16934
map_119_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 15
map_119_object_00:
    map_object 18, 0, 14, 20, 0, 11, 0, 1, 3, 1, 6, 207, 54049
map_11A_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 36
map_11A_object_00:
    map_object 0, 0, 15, 10, 1, 11, 0, 1, 2, 1, 6, 175, 21255
map_11B_header:
    map_header 15, 3, 87, 0, 15, 2, 1, 0, 0, 0, 3, 2, 0, 0, 26
map_11B_object_00:
    map_object 19, 6, 7, 69, 1, 37, 0, 1, 1, 0, 0, 189, 49568
map_11B_object_01:
    map_object 19, 6, 7, 70, 1, 35, 1, 1, 2, 0, 7, 188, 16801
map_11B_object_02:
    map_object 18, 0, 14, 77, 1, 39, 1, 3, 3, 0, 0, 183, 16802
map_11B_object_03:
    map_object 18, 0, 14, 79, 1, 34, 1, 1, 2, 0, 0, 197, 16803
map_11B_object_04:
    map_object 18, 0, 9, 71, 1, 40, 1, 0, 3, 0, 0, 183, 16789
map_11C_header:
    map_header 10, 2, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_11C_object_00:
    map_object 0, 0, 15, 25, 0, 64, 0, 0, 0, 0, 0, 10, 49153
map_11C_object_01:
    map_object 0, 0, 15, 22, 0, 61, 0, 0, 0, 0, 0, 10, 49153
map_11C_object_02:
    map_object 0, 0, 15, 23, 0, 52, 0, 0, 0, 0, 0, 6, 49153
map_11C_object_03:
    map_object 0, 0, 15, 35, 0, 53, 0, 0, 0, 0, 0, 8, 49153
map_11C_object_04:
    map_object 0, 0, 15, 15, 0, 21, 0, 0, 0, 0, 0, 6, 49153
map_11C_object_05:
    map_object 0, 0, 15, 19, 0, 12, 0, 0, 0, 0, 0, 6, 49153
map_11C_object_06:
    map_object 0, 0, 15, 22, 0, 27, 0, 0, 0, 0, 0, 6, 49153
map_11C_object_07:
    map_object 0, 0, 15, 15, 0, 10, 0, 0, 0, 0, 0, 6, 49153
map_11D_header:
    map_header 10, 2, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_11D_object_00:
    map_object 0, 0, 15, 29, 0, 47, 0, 0, 0, 0, 0, 10, 49153
map_11D_object_01:
    map_object 0, 0, 15, 20, 0, 36, 0, 0, 0, 0, 0, 6, 49153
map_11D_object_02:
    map_object 0, 0, 15, 12, 0, 48, 0, 0, 0, 0, 0, 10, 49153
map_11D_object_03:
    map_object 0, 0, 15, 16, 0, 46, 0, 0, 0, 0, 0, 10, 49153
map_11D_object_04:
    map_object 0, 0, 15, 29, 0, 48, 0, 0, 0, 0, 0, 10, 49153
map_11D_object_05:
    map_object 0, 0, 15, 14, 0, 7, 0, 0, 0, 0, 0, 6, 49153
map_11D_object_06:
    map_object 0, 0, 15, 16, 0, 12, 0, 0, 0, 0, 0, 6, 49153
map_11D_object_07:
    map_object 0, 0, 15, 12, 0, 22, 0, 0, 0, 0, 0, 6, 49153
map_11D_object_08:
    map_object 0, 0, 15, 26, 0, 78, 0, 1, 0, 0, 0, 6, 49153
map_11D_object_09:
    map_object 0, 0, 15, 29, 0, 78, 0, 1, 0, 0, 0, 6, 49153
map_11D_object_10:
    map_object 0, 0, 15, 12, 0, 77, 0, 0, 0, 0, 0, 8, 49153
map_11D_object_11:
    map_object 0, 0, 15, 23, 0, 82, 0, 0, 0, 0, 0, 2, 49153
map_11E_header:
    map_header 10, 2, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_11E_object_00:
    map_object 0, 0, 15, 19, 0, 20, 0, 0, 0, 0, 0, 10, 49153
map_11E_object_01:
    map_object 0, 0, 15, 45, 0, 31, 0, 0, 0, 0, 0, 6, 49153
map_11E_object_02:
    map_object 0, 0, 15, 12, 0, 47, 0, 0, 0, 0, 0, 6, 49153
map_11E_object_03:
    map_object 0, 0, 15, 23, 0, 56, 0, 0, 0, 0, 0, 6, 49153
map_11E_object_04:
    map_object 0, 0, 15, 35, 0, 50, 0, 0, 0, 0, 0, 6, 49153
map_11E_object_05:
    map_object 0, 0, 15, 32, 0, 40, 0, 0, 0, 0, 0, 10, 49153
map_11E_object_06:
    map_object 0, 0, 15, 43, 0, 18, 0, 0, 0, 0, 0, 8, 49153
map_11E_object_07:
    map_object 0, 0, 15, 42, 0, 47, 0, 0, 0, 0, 0, 8, 49153
map_11E_object_08:
    map_object 0, 0, 15, 20, 0, 16, 0, 0, 0, 0, 0, 10, 49153
map_11F_header:
    map_header 10, 2, 70, 0, 10, 2, 1, 1, 0, 0, 3, 0, 0, 0, 62
map_11F_object_00:
    map_object 27, 1, 3, 23, 1, 30, 1, 1, 1, 0, 0, 160, 17253
map_11F_object_01:
    map_object 21, 7, 15, 25, 1, 33, 1, 1, 2, 0, 0, 155, 17254
map_11F_object_02:
    map_object 20, 0, 3, 25, 1, 40, 0, 1, 0, 0, 0, 154, 49600
map_11F_object_03:
    map_object 20, 0, 3, 18, 1, 37, 0, 1, 0, 0, 0, 154, 49601
map_11F_object_04:
    map_object 20, 0, 3, 29, 1, 32, 0, 1, 0, 0, 0, 154, 49602
map_11F_object_05:
    map_object 20, 0, 3, 30, 1, 19, 0, 1, 0, 0, 0, 154, 49603
map_11F_object_06:
    map_object 20, 0, 3, 14, 1, 17, 0, 1, 0, 0, 0, 154, 49604
map_120_header:
    map_header 10, 0, 34, 0, 10, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_121_header:
    map_header 10, 2, 34, 0, 10, 0, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_121_object_00:
    map_object 215, 0, 0, 15, 1, 15, 1, 0, 0, 0, 0, 235, 18055
map_121_object_01:
    map_object 0, 0, 15, 13, 0, 15, 0, 1, 0, 0, 0, 6, 49153
map_121_object_02:
    map_object 0, 0, 15, 17, 0, 15, 0, 1, 0, 0, 0, 6, 49153
map_122_header:
    map_header 10, 2, 70, 0, 10, 2, 0, 0, 0, 0, 1, 0, 0, 0, 255
map_122_object_00:
    map_object 20, 0, 3, 24, 1, 38, 0, 1, 0, 0, 7, 89, 441
map_122_object_01:
    map_object 20, 4, 5, 27, 1, 40, 1, 3, 0, 0, 0, 140, 16851
map_122_object_02:
    map_object 20, 4, 6, 27, 1, 42, 1, 3, 0, 0, 0, 155, 16852
map_123_header:
    map_header 10, 2, 34, 0, 10, 2, 0, 1, 0, 0, 2, 13, 0, 0, 255
map_123_object_00:
    map_object 24, 0, 1, 11, 1, 16, 1, 0, 0, 0, 0, 85, 569
map_124_header:
    map_header 10, 0, 69, 0, 10, 2, 0, 1, 0, 0, 1, 0, 0, 0, 27
map_124_object_00:
    map_object 0, 0, 15, 24, 1, 20, 0, 1, 0, 0, 6, 154, 54050
map_125_header:
    map_header 10, 0, 69, 0, 10, 2, 0, 0, 0, 0, 1, 0, 0, 0, 27
map_125_object_00:
    map_object 0, 0, 15, 17, 1, 11, 0, 1, 0, 0, 6, 154, 54020
map_126_header:
    map_header 10, 2, 69, 0, 10, 2, 0, 0, 0, 0, 1, 0, 0, 0, 255
map_126_object_00:
    map_object 20, 0, 14, 9, 1, 14, 1, 1, 0, 0, 0, 156, 16816
map_127_header:
    map_header 10, 0, 34, 0, 10, 0, 0, 0, 0, 0, 3, 0, 0, 0, 28
map_128_header:
    map_header 10, 0, 69, 0, 10, 2, 0, 1, 0, 0, 1, 0, 0, 0, 28
map_128_object_00:
    map_object 21, 0, 0, 19, 1, 17, 1, 3, 1, 0, 0, 155, 16841
map_128_object_01:
    map_object 21, 4, 6, 13, 1, 13, 1, 1, 1, 0, 0, 155, 16841
map_128_object_02:
    map_object 21, 4, 5, 11, 1, 13, 1, 1, 3, 0, 0, 140, 4554
map_129_header:
    map_header 10, 0, 69, 0, 10, 2, 0, 1, 0, 0, 1, 0, 0, 0, 28
map_129_object_00:
    map_object 21, 0, 3, 22, 1, 18, 1, 2, 1, 0, 0, 155, 49152
map_129_object_01:
    map_object 21, 1, 1, 20, 1, 9, 1, 1, 2, 0, 0, 154, 49152
map_129_object_02:
    map_object 21, 1, 1, 19, 1, 11, 1, 1, 0, 0, 0, 0, 49152
map_129_object_03:
    map_object 21, 2, 2, 19, 1, 10, 1, 1, 3, 0, 0, 226, 49152
map_129_object_04:
    map_object 21, 3, 3, 19, 1, 10, 1, 1, 3, 0, 0, 140, 49152
map_12A_header:
    map_header 4, 2, 28, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 35
map_12A_object_00:
    map_object 0, 0, 15, 10, 1, 28, 1, 1, 3, 1, 6, 159, 54024
map_12A_object_01:
    map_object 0, 0, 15, 11, 1, 11, 0, 1, 3, 1, 6, 159, 17270
map_12A_object_02:
    map_object 0, 0, 15, 14, 1, 9, 1, 1, 0, 1, 6, 156, 17269
map_12B_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 35
map_12B_object_00:
    map_object 0, 0, 15, 20, 1, 11, 1, 1, 3, 1, 6, 159, 54052
map_12C_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 1, 0, 0, 1, 2, 0, 0, 255
map_12C_object_00:
    map_object 23, 0, 6, 9, 0, 18, 0, 1, 0, 0, 0, 7, 16385
map_12D_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_12D_object_00:
    map_object 23, 0, 6, 8, 0, 15, 0, 3, 0, 0, 0, 13, 49153
map_12D_object_01:
    map_object 23, 0, 6, 8, 0, 13, 0, 3, 0, 0, 0, 13, 49153
map_12D_object_02:
    map_object 23, 0, 6, 12, 0, 15, 0, 2, 0, 0, 0, 13, 49153
map_12E_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_12E_object_00:
    map_object 23, 0, 6, 11, 0, 15, 0, 3, 0, 0, 0, 7, 16385
map_12E_object_01:
    map_object 23, 0, 6, 19, 0, 15, 0, 2, 0, 0, 0, 7, 16385
map_12F_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_12F_object_00:
    map_object 23, 0, 6, 23, 0, 11, 0, 1, 0, 0, 0, 31, 49153
map_12F_object_01:
    map_object 23, 0, 6, 16, 0, 12, 0, 0, 0, 0, 0, 31, 49153
map_12F_object_02:
    map_object 23, 0, 6, 8, 0, 13, 0, 1, 0, 0, 0, 7, 16385
map_130_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_130_object_00:
    map_object 23, 0, 6, 13, 0, 14, 0, 1, 0, 0, 0, 7, 16385
map_130_object_01:
    map_object 23, 0, 6, 19, 0, 14, 0, 1, 0, 0, 0, 7, 16385
map_131_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_131_object_00:
    map_object 23, 0, 6, 11, 0, 12, 0, 0, 0, 0, 0, 7, 16385
map_132_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 1, 0, 0, 1, 2, 0, 0, 255
map_132_object_00:
    map_object 23, 2, 2, 12, 1, 12, 1, 1, 0, 0, 0, 186, 4577
map_132_object_01:
    map_object 23, 2, 2, 11, 1, 25, 0, 1, 0, 0, 0, 13, 16385
map_132_object_02:
    map_object 23, 2, 2, 12, 1, 25, 0, 1, 0, 0, 0, 13, 16385
map_132_object_03:
    map_object 23, 6, 6, 8, 1, 23, 1, 1, 0, 0, 0, 186, 16867
map_132_object_04:
    map_object 23, 7, 14, 8, 1, 23, 0, 1, 0, 0, 0, 202, 16867
map_132_object_05:
    map_object 216, 1, 1, 16, 1, 25, 1, 0, 0, 0, 0, 235, 18056
map_132_object_06:
    map_object 217, 1, 1, 16, 1, 27, 1, 0, 0, 0, 0, 235, 18057
map_133_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_133_object_00:
    map_object 36, 0, 3, 3, 1, 18, 1, 0, 0, 0, 0, 85, 638
map_133_object_01:
    map_object 0, 0, 15, 7, 0, 19, 0, 1, 0, 0, 0, 22, 49153
map_133_object_02:
    map_object 0, 0, 15, 10, 0, 11, 0, 1, 0, 0, 0, 22, 49153
map_134_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 1, 0, 0, 1, 2, 0, 0, 18
map_134_object_00:
    map_object 23, 0, 2, 13, 1, 19, 0, 3, 1, 0, 0, 183, 0
map_134_object_01:
    map_object 23, 0, 2, 14, 1, 23, 1, 1, 1, 0, 0, 183, 20956
map_134_object_02:
    map_object 23, 0, 2, 21, 1, 22, 0, 0, 1, 0, 0, 183, 0
map_134_object_03:
    map_object 23, 0, 2, 22, 1, 18, 0, 2, 1, 0, 0, 183, 0
map_134_object_04:
    map_object 23, 0, 7, 22, 1, 20, 1, 1, 2, 0, 0, 153, 20958
map_135_header:
    map_header 14, 3, 82, 0, 14, 2, 0, 1, 0, 0, 1, 2, 0, 0, 255
map_135_object_00:
    map_object 23, 3, 4, 13, 1, 18, 1, 0, 0, 0, 0, 186, 0
map_135_object_01:
    map_object 23, 3, 3, 13, 1, 16, 1, 1, 0, 0, 0, 172, 0
map_136_header:
    map_header 14, 3, 82, 0, 14, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_136_object_00:
    map_object 23, 5, 5, 13, 1, 13, 0, 1, 0, 0, 0, 91, 482
map_137_header:
    map_header 18, 0, 42, 1, 18, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_138_header:
    map_header 23, 3, 89, 0, 23, 2, 0, 1, 0, 0, 3, 0, 0, 0, 255
map_138_object_00:
    map_object 24, 0, 7, 12, 0, 13, 0, 3, 0, 0, 0, 25, 49153
map_138_object_01:
    map_object 24, 0, 7, 35, 0, 13, 0, 2, 0, 0, 0, 25, 49153
map_138_object_02:
    map_object 24, 0, 7, 24, 0, 14, 0, 0, 0, 0, 0, 11, 49153
map_138_object_03:
    map_object 24, 0, 7, 22, 0, 30, 0, 0, 0, 0, 0, 11, 49153
map_138_object_04:
    map_object 24, 0, 7, 25, 0, 30, 0, 0, 0, 0, 0, 11, 49153
map_138_object_05:
    map_object 24, 0, 7, 10, 0, 30, 0, 0, 0, 0, 0, 8, 49153
map_138_object_06:
    map_object 24, 0, 7, 40, 0, 38, 0, 0, 0, 0, 0, 8, 49153
map_138_object_07:
    map_object 24, 0, 7, 7, 0, 41, 0, 0, 0, 0, 0, 10, 49153
map_138_object_08:
    map_object 24, 0, 7, 39, 0, 29, 0, 0, 0, 0, 0, 10, 49153
map_139_header:
    map_header 23, 3, 89, 0, 23, 2, 0, 1, 0, 0, 3, 0, 0, 0, 255
map_139_object_00:
    map_object 24, 0, 7, 26, 0, 17, 0, 0, 0, 0, 0, 11, 49153
map_139_object_01:
    map_object 24, 0, 7, 21, 0, 38, 0, 0, 0, 0, 0, 11, 49153
map_139_object_02:
    map_object 24, 0, 7, 12, 0, 14, 0, 0, 0, 0, 0, 11, 49153
map_139_object_03:
    map_object 24, 0, 7, 8, 0, 32, 0, 0, 0, 0, 0, 11, 49153
map_139_object_04:
    map_object 24, 0, 7, 7, 0, 38, 0, 0, 0, 0, 0, 8, 49153
map_13A_header:
    map_header 23, 3, 89, 0, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_13A_object_00:
    map_object 24, 3, 3, 16, 1, 35, 1, 1, 0, 0, 0, 144, 16384
map_13B_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_13B_object_00:
    map_object 188, 0, 0, 24, 1, 17, 1, 1, 0, 0, 0, 235, 50804
map_13C_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 1, 0, 0, 3, 0, 0, 0, 38
map_13C_object_00:
    map_object 27, 0, 1, 19, 1, 24, 1, 1, 0, 0, 0, 223, 0
map_13C_object_01:
    map_object 27, 0, 2, 19, 1, 25, 1, 0, 1, 0, 0, 164, 0
map_13C_object_02:
    map_object 27, 0, 2, 17, 1, 25, 1, 0, 2, 0, 0, 165, 0
map_13C_object_03:
    map_object 27, 0, 2, 21, 1, 25, 1, 0, 2, 0, 0, 165, 0
map_13C_object_04:
    map_object 27, 4, 4, 19, 1, 23, 1, 0, 1, 0, 0, 164, 0
map_13C_object_05:
    map_object 27, 4, 4, 17, 1, 23, 1, 0, 2, 0, 0, 165, 0
map_13C_object_06:
    map_object 27, 4, 4, 21, 1, 23, 1, 0, 2, 0, 0, 165, 0
map_13D_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 1, 0, 0, 0, 255
map_13D_object_00:
    map_object 27, 0, 3, 19, 1, 22, 0, 1, 0, 0, 0, 101, 17258
map_13E_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 1, 0, 0, 0, 40
map_13F_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 1, 0, 0, 1, 0, 0, 0, 41
map_13F_object_00:
    map_object 14, 8, 15, 8, 1, 7, 1, 1, 3, 0, 0, 140, 17046
map_13F_object_01:
    map_object 40, 0, 9, 7, 1, 8, 1, 3, 2, 0, 0, 201, 17047
map_13F_object_02:
    map_object 40, 0, 9, 11, 1, 7, 0, 2, 1, 0, 0, 183, 49816
map_140_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_140_object_00:
    map_object 0, 0, 15, 54, 0, 57, 0, 1, 0, 0, 0, 19, 49153
map_140_object_01:
    map_object 0, 0, 15, 44, 0, 73, 0, 1, 0, 0, 0, 24, 49153
map_140_object_02:
    map_object 0, 0, 15, 16, 0, 59, 0, 1, 0, 0, 0, 19, 49153
map_140_object_03:
    map_object 0, 0, 15, 22, 0, 53, 0, 1, 0, 0, 0, 19, 49153
map_141_header:
    map_header 10, 0, 34, 1, 10, 2, 1, 0, 0, 0, 3, 13, 0, 0, 255
map_141_object_00:
    map_object 0, 0, 15, 35, 0, 24, 0, 1, 0, 0, 0, 19, 49153
map_141_object_01:
    map_object 0, 0, 15, 44, 0, 27, 0, 1, 0, 0, 0, 19, 49153
map_141_object_02:
    map_object 0, 0, 15, 13, 0, 27, 0, 1, 0, 0, 0, 19, 49153
map_141_object_03:
    map_object 0, 0, 15, 22, 0, 14, 0, 1, 0, 0, 0, 21, 49153
map_141_object_04:
    map_object 0, 0, 15, 18, 0, 25, 0, 1, 0, 0, 0, 21, 49153
map_141_object_05:
    map_object 0, 0, 15, 7, 0, 10, 0, 1, 0, 0, 0, 21, 49153
map_141_object_06:
    map_object 0, 0, 15, 8, 0, 21, 0, 1, 0, 0, 0, 21, 49153
map_141_object_07:
    map_object 0, 0, 15, 36, 0, 26, 0, 1, 0, 0, 0, 22, 49153
map_141_object_08:
    map_object 0, 0, 15, 39, 0, 31, 0, 1, 0, 0, 0, 22, 49153
map_141_object_09:
    map_object 0, 0, 15, 43, 0, 30, 0, 1, 0, 0, 0, 22, 49153
map_142_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_142_object_00:
    map_object 0, 0, 15, 14, 0, 25, 0, 1, 0, 0, 0, 19, 49153
map_142_object_01:
    map_object 0, 0, 15, 11, 0, 16, 0, 1, 0, 0, 0, 19, 49153
map_142_object_02:
    map_object 0, 0, 15, 14, 0, 18, 0, 1, 0, 0, 0, 21, 49153
map_142_object_03:
    map_object 0, 0, 15, 19, 0, 15, 0, 1, 0, 0, 0, 21, 49153
map_142_object_04:
    map_object 0, 0, 15, 38, 0, 29, 0, 1, 0, 0, 0, 12, 49153
map_142_object_05:
    map_object 0, 0, 15, 36, 0, 27, 0, 1, 0, 0, 0, 12, 49153
map_143_header:
    map_header 10, 0, 34, 1, 10, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_143_object_00:
    map_object 0, 0, 15, 6, 0, 22, 0, 1, 0, 0, 0, 19, 49153
map_143_object_01:
    map_object 0, 0, 15, 22, 0, 24, 0, 1, 0, 0, 0, 19, 49153
map_143_object_02:
    map_object 0, 0, 15, 18, 0, 10, 0, 1, 0, 0, 0, 19, 49153
map_143_object_03:
    map_object 0, 0, 15, 14, 0, 14, 0, 1, 0, 0, 0, 21, 49153
map_143_object_04:
    map_object 0, 0, 15, 25, 0, 11, 0, 1, 0, 0, 0, 21, 49153
map_143_object_05:
    map_object 0, 0, 15, 36, 0, 8, 0, 1, 0, 0, 0, 21, 49153
map_143_object_06:
    map_object 0, 0, 15, 7, 0, 10, 0, 1, 0, 0, 0, 22, 49153
map_143_object_07:
    map_object 0, 0, 15, 8, 0, 32, 0, 1, 0, 0, 0, 22, 49153
map_143_object_08:
    map_object 0, 0, 15, 17, 0, 32, 0, 1, 0, 0, 0, 22, 49153
map_143_object_09:
    map_object 0, 0, 15, 19, 0, 23, 0, 1, 0, 0, 0, 22, 49153
map_144_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 0, 0, 0, 1, 0, 0, 0, 40
map_144_object_00:
    map_object 40, 0, 6, 16, 1, 9, 1, 1, 1, 0, 0, 183, 17050
map_144_object_01:
    map_object 40, 0, 6, 17, 1, 9, 1, 1, 1, 0, 0, 183, 17050
map_145_header:
    map_header 16, 2, 40, 0, 16, 1, 0, 1, 0, 0, 0, 10, 0, 0, 255
map_145_object_00:
    map_object 36, 0, 4, 7, 1, 13, 0, 1, 0, 1, 0, 105, 17026
map_146_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_146_object_00:
    map_object 44, 0, 2, 11, 0, 22, 0, 3, 0, 0, 0, 28, 49153
map_146_object_01:
    map_object 44, 0, 2, 22, 0, 22, 0, 2, 0, 0, 0, 28, 49153
map_147_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_147_object_00:
    map_object 44, 0, 2, 11, 0, 12, 0, 1, 0, 0, 0, 39, 49153
map_147_object_01:
    map_object 44, 0, 2, 11, 0, 15, 0, 1, 0, 0, 0, 28, 49153
map_147_object_02:
    map_object 44, 0, 2, 14, 0, 15, 0, 1, 0, 0, 0, 28, 49153
map_148_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_148_object_00:
    map_object 218, 0, 0, 7, 1, 21, 1, 1, 0, 0, 0, 235, 50826
map_148_object_01:
    map_object 44, 0, 2, 8, 0, 12, 0, 1, 0, 0, 0, 28, 49153
map_148_object_02:
    map_object 44, 0, 2, 14, 0, 17, 0, 1, 0, 0, 0, 28, 49153
map_149_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_149_object_00:
    map_object 44, 0, 2, 14, 0, 23, 0, 1, 0, 0, 0, 39, 49153
map_149_object_01:
    map_object 44, 0, 2, 21, 0, 23, 0, 1, 0, 0, 0, 39, 49153
map_14A_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_14A_object_00:
    map_object 44, 0, 2, 26, 0, 27, 0, 1, 0, 0, 0, 15, 49153
map_14A_object_01:
    map_object 44, 0, 2, 18, 0, 12, 0, 1, 0, 0, 0, 15, 49153
map_14A_object_02:
    map_object 44, 0, 2, 16, 0, 12, 0, 1, 0, 0, 0, 15, 49153
map_14A_object_03:
    map_object 44, 0, 2, 11, 0, 13, 0, 1, 0, 0, 0, 37, 49153
map_14A_object_04:
    map_object 44, 0, 2, 5, 0, 25, 0, 1, 0, 0, 0, 37, 49153
map_14A_object_05:
    map_object 44, 0, 2, 14, 0, 23, 0, 1, 0, 0, 0, 39, 49153
map_14A_object_06:
    map_object 44, 0, 2, 25, 0, 29, 0, 1, 0, 0, 0, 39, 49153
map_14A_object_07:
    map_object 44, 0, 2, 37, 0, 19, 0, 1, 0, 0, 0, 28, 49153
map_14A_object_08:
    map_object 44, 0, 2, 42, 0, 19, 0, 1, 0, 0, 0, 28, 49153
map_14A_object_09:
    map_object 44, 0, 2, 39, 0, 10, 0, 1, 0, 0, 0, 28, 49153
map_14B_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_14B_object_00:
    map_object 186, 0, 2, 13, 1, 7, 1, 1, 0, 0, 0, 235, 50802
map_14B_object_01:
    map_object 44, 0, 2, 15, 0, 16, 0, 1, 0, 0, 0, 28, 49153
map_14B_object_02:
    map_object 44, 0, 2, 13, 0, 9, 0, 1, 0, 0, 0, 28, 49153
map_14B_object_03:
    map_object 44, 0, 2, 11, 0, 18, 0, 1, 0, 0, 0, 28, 49153
map_14C_header:
    map_header 25, 2, 49, 0, 25, 2, 0, 1, 0, 0, 4, 3, 0, 0, 50
map_14C_object_00:
    map_object 38, 0, 2, 10, 1, 15, 0, 3, 0, 0, 0, 173, 50044
map_14C_object_01:
    map_object 38, 6, 15, 10, 1, 15, 0, 3, 0, 0, 0, 173, 50045
map_14D_header:
    map_header 4, 2, 28, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 50
map_14D_object_00:
    map_object 38, 6, 15, 13, 1, 13, 0, 1, 1, 1, 0, 174, 50046
map_14D_object_01:
    map_object 187, 0, 2, 13, 1, 12, 1, 1, 2, 1, 0, 235, 50803
map_14F_header:
    map_header 4, 2, 28, 0, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 48
map_14F_object_00:
    map_object 39, 0, 4, 8, 1, 55, 0, 3, 2, 1, 0, 165, 50062
map_14F_object_01:
    map_object 39, 0, 4, 18, 1, 51, 0, 2, 2, 1, 0, 165, 50063
map_14F_object_02:
    map_object 39, 0, 4, 48, 1, 10, 0, 2, 1, 1, 0, 188, 50066
map_14F_object_03:
    map_object 39, 0, 4, 38, 1, 12, 1, 3, 3, 1, 0, 196, 17299
map_14F_object_04:
    map_object 39, 0, 4, 41, 1, 58, 0, 1, 1, 1, 0, 196, 50064
map_14F_object_05:
    map_object 39, 0, 4, 52, 1, 56, 0, 0, 3, 1, 0, 197, 50065
map_150_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 1, 0, 0, 0, 0, 0, 0, 37
map_150_object_00:
    map_object 36, 0, 2, 27, 1, 16, 1, 0, 0, 1, 0, 175, 16989
map_150_object_01:
    map_object 36, 3, 15, 28, 1, 13, 1, 1, 0, 1, 0, 175, 16990
map_150_object_02:
    map_object 36, 0, 15, 19, 1, 12, 0, 1, 0, 1, 0, 175, 49759
map_150_object_03:
    map_object 36, 0, 15, 11, 1, 11, 1, 2, 1, 1, 0, 175, 17000
map_150_object_04:
    map_object 36, 0, 15, 10, 1, 11, 1, 3, 3, 1, 0, 156, 16999
map_151_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 1, 0, 0, 0, 0, 0, 0, 12
map_151_object_00:
    map_object 36, 0, 14, 10, 1, 9, 1, 1, 0, 1, 7, 158, 16993
map_151_object_01:
    map_object 36, 0, 15, 14, 1, 10, 1, 1, 2, 1, 0, 175, 16994
map_151_object_02:
    map_object 36, 0, 15, 7, 1, 12, 1, 3, 1, 1, 0, 175, 16995
map_151_object_03:
    map_object 36, 0, 15, 15, 1, 12, 1, 2, 1, 1, 0, 175, 16996
map_151_object_04:
    map_object 36, 0, 15, 9, 1, 15, 0, 1, 1, 1, 0, 175, 49765
map_151_object_05:
    map_object 36, 7, 9, 12, 1, 9, 1, 1, 3, 1, 0, 181, 16998
map_151_object_06:
    map_object 36, 7, 9, 12, 1, 9, 1, 1, 3, 1, 0, 205, 16998
map_152_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 29
map_152_object_00:
    map_object 191, 0, 1, 17, 1, 8, 1, 1, 1, 1, 0, 235, 50807
map_153_header:
    map_header 19, 2, 43, 0, 19, 2, 0, 1, 0, 0, 1, 0, 0, 0, 42
map_153_object_00:
    map_object 13, 8, 15, 17, 1, 14, 1, 2, 3, 1, 0, 139, 0
map_153_object_01:
    map_object 40, 0, 10, 16, 1, 14, 1, 3, 0, 1, 0, 185, 0
map_153_object_02:
    map_object 40, 8, 10, 16, 1, 20, 1, 0, 2, 1, 0, 184, 0
map_153_object_03:
    map_object 40, 9, 10, 16, 1, 20, 1, 0, 1, 1, 0, 183, 0
map_153_object_04:
    map_object 40, 9, 10, 17, 1, 20, 1, 0, 1, 1, 0, 183, 0
map_153_object_05:
    map_object 40, 10, 10, 17, 1, 20, 1, 0, 1, 1, 0, 183, 0
map_154_header:
    map_header 3, 0, 27, 1, 3, 2, 0, 0, 0, 1, 1, 6, 0, 0, 255
map_154_object_00:
    map_object 40, 0, 15, 16, 1, 16, 1, 1, 0, 0, 0, 96, 17057
map_155_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 15
map_155_object_00:
    map_object 16, 0, 15, 20, 0, 11, 0, 1, 3, 1, 6, 207, 54055
map_156_header:
    map_header 4, 2, 28, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45
map_156_object_00:
    map_object 62, 0, 15, 31, 0, 13, 0, 1, 2, 1, 6, 207, 54028
map_156_object_01:
    map_object 62, 0, 15, 16, 1, 9, 0, 0, 1, 1, 0, 201, 17367
map_156_object_02:
    map_object 62, 0, 15, 13, 1, 12, 0, 3, 1, 1, 0, 202, 17368
map_156_object_03:
    map_object 62, 0, 14, 16, 1, 12, 1, 2, 3, 1, 0, 156, 17369
map_157_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_157_object_00:
    map_object 23, 0, 6, 5, 0, 12, 0, 0, 0, 0, 0, 13, 49153
map_157_object_01:
    map_object 23, 0, 6, 7, 0, 12, 0, 0, 0, 0, 0, 13, 49153
map_157_object_02:
    map_object 23, 0, 6, 9, 0, 12, 0, 0, 0, 0, 0, 13, 49153
map_158_header:
    map_header 15, 3, 86, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_158_object_00:
    map_object 23, 0, 6, 5, 0, 13, 0, 1, 0, 0, 0, 10, 49153
map_158_object_01:
    map_object 23, 0, 6, 9, 0, 13, 0, 1, 0, 0, 0, 10, 49153
map_158_object_02:
    map_object 23, 0, 6, 7, 0, 13, 0, 1, 0, 0, 0, 10, 49153
map_159_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_159_object_00:
    map_object 43, 0, 0, 3, 1, 12, 0, 0, 0, 0, 0, 85, 1739
map_159_object_01:
    map_object 219, 0, 0, 21, 1, 34, 1, 1, 0, 0, 0, 235, 50827
map_159_object_02:
    map_object 44, 0, 2, 8, 0, 13, 0, 1, 0, 0, 0, 28, 49153
map_159_object_03:
    map_object 44, 0, 2, 21, 0, 15, 0, 1, 0, 0, 0, 28, 49153
map_159_object_04:
    map_object 44, 0, 2, 21, 0, 16, 0, 1, 0, 0, 0, 28, 49153
map_159_object_05:
    map_object 44, 0, 2, 21, 0, 17, 0, 1, 0, 0, 0, 28, 49153
map_15A_header:
    map_header 23, 3, 91, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_15A_object_00:
    map_object 44, 0, 2, 9, 0, 8, 0, 1, 0, 0, 0, 15, 49153
map_15A_object_01:
    map_object 44, 0, 2, 7, 0, 28, 0, 1, 0, 0, 0, 15, 49153
map_15A_object_02:
    map_object 44, 0, 2, 25, 0, 30, 0, 1, 0, 0, 0, 15, 49153
map_15A_object_03:
    map_object 44, 0, 2, 25, 0, 8, 0, 1, 0, 0, 0, 15, 49153
map_15A_object_04:
    map_object 44, 0, 2, 17, 0, 19, 0, 1, 0, 0, 0, 15, 49153
map_15A_object_05:
    map_object 44, 0, 2, 7, 0, 19, 0, 1, 0, 0, 0, 37, 49153
map_15A_object_06:
    map_object 44, 0, 2, 15, 0, 30, 0, 1, 0, 0, 0, 37, 49153
map_15A_object_07:
    map_object 44, 0, 2, 27, 0, 19, 0, 1, 0, 0, 0, 39, 49153
map_15A_object_08:
    map_object 44, 0, 2, 17, 0, 10, 0, 1, 0, 0, 0, 28, 49153
map_15B_header:
    map_header 23, 2, 91, 0, 23, 2, 0, 1, 0, 0, 1, 0, 0, 0, 255
map_15B_object_00:
    map_object 44, 0, 2, 16, 1, 17, 0, 1, 0, 0, 0, 90, 17098
map_15C_header:
    map_header 10, 2, 102, 1, 10, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_15C_object_00:
    map_object 44, 0, 0, 18, 1, 14, 0, 0, 0, 0, 7, 85, 712
map_15C_object_01:
    map_object 44, 0, 2, 17, 0, 17, 0, 1, 0, 0, 0, 15, 49153
map_15C_object_02:
    map_object 44, 0, 2, 22, 0, 12, 0, 1, 0, 0, 0, 15, 49153
map_15D_header:
    map_header 23, 3, 91, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_15D_object_00:
    map_object 147, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25993
map_15D_object_01:
    map_object 147, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21897
map_15E_header:
    map_header 23, 3, 95, 1, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_15F_header:
    map_header 23, 3, 95, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_15F_object_00:
    map_object 150, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25998
map_15F_object_01:
    map_object 150, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21902
map_15F_object_02:
    map_object 174, 0, 1, 14, 1, 15, 1, 1, 0, 0, 0, 150, 5508
map_160_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_160_object_00:
    map_object 38, 0, 3, 8, 0, 20, 0, 1, 0, 0, 0, 52, 49153
map_160_object_01:
    map_object 38, 0, 3, 31, 0, 20, 0, 1, 0, 0, 0, 52, 49153
map_160_object_02:
    map_object 38, 0, 3, 20, 0, 25, 0, 1, 0, 0, 0, 52, 49153
map_161_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_161_object_00:
    map_object 38, 0, 3, 10, 0, 13, 0, 1, 0, 0, 0, 56, 49153
map_162_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_162_object_00:
    map_object 38, 0, 3, 7, 0, 12, 0, 1, 0, 0, 0, 52, 49153
map_162_object_01:
    map_object 38, 0, 3, 14, 0, 12, 0, 1, 0, 0, 0, 52, 49153
map_162_object_02:
    map_object 38, 0, 3, 10, 0, 10, 0, 1, 0, 0, 0, 29, 49153
map_163_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_163_object_00:
    map_object 38, 0, 3, 11, 0, 15, 0, 1, 0, 0, 0, 52, 49153
map_163_object_01:
    map_object 38, 0, 3, 19, 0, 15, 0, 1, 0, 0, 0, 52, 49153
map_163_object_02:
    map_object 38, 0, 3, 4, 0, 19, 0, 1, 0, 0, 0, 56, 49153
map_163_object_03:
    map_object 38, 0, 3, 26, 0, 19, 0, 1, 0, 0, 0, 56, 49153
map_164_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_164_object_00:
    map_object 184, 0, 2, 7, 1, 11, 1, 1, 0, 0, 0, 235, 50800
map_164_object_01:
    map_object 38, 0, 3, 5, 0, 14, 0, 1, 0, 0, 0, 9, 49153
map_164_object_02:
    map_object 38, 0, 3, 9, 0, 14, 0, 1, 0, 0, 0, 9, 49153
map_165_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_165_object_00:
    map_object 38, 0, 3, 4, 0, 15, 0, 1, 0, 0, 0, 9, 49153
map_165_object_01:
    map_object 38, 0, 3, 5, 0, 16, 0, 1, 0, 0, 0, 9, 49153
map_165_object_02:
    map_object 38, 0, 3, 10, 0, 15, 0, 1, 0, 0, 0, 9, 49153
map_165_object_03:
    map_object 38, 0, 3, 9, 0, 16, 0, 1, 0, 0, 0, 9, 49153
map_166_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_166_object_00:
    map_object 38, 0, 3, 10, 0, 14, 0, 1, 0, 0, 0, 51, 49153
map_167_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_167_object_00:
    map_object 38, 0, 3, 12, 0, 14, 0, 1, 0, 0, 0, 35, 49153
map_167_object_01:
    map_object 38, 0, 3, 19, 0, 32, 0, 1, 0, 0, 0, 35, 49153
map_167_object_02:
    map_object 38, 0, 3, 25, 0, 14, 0, 1, 0, 0, 0, 35, 49153
map_167_object_03:
    map_object 38, 0, 3, 31, 0, 23, 0, 1, 0, 0, 0, 51, 49153
map_167_object_04:
    map_object 38, 0, 3, 23, 0, 23, 0, 1, 0, 0, 0, 9, 49153
map_167_object_05:
    map_object 38, 0, 3, 17, 0, 23, 0, 1, 0, 0, 0, 9, 49153
map_167_object_06:
    map_object 38, 0, 3, 9, 0, 33, 0, 1, 0, 0, 0, 29, 49153
map_168_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 1, 0, 0, 1, 2, 0, 0, 255
map_168_object_00:
    map_object 38, 0, 3, 15, 0, 23, 0, 1, 0, 0, 0, 35, 49153
map_168_object_01:
    map_object 38, 0, 3, 9, 0, 19, 0, 1, 0, 0, 0, 35, 49153
map_168_object_02:
    map_object 38, 0, 3, 22, 0, 19, 0, 1, 0, 0, 0, 35, 49153
map_169_header:
    map_header 14, 3, 84, 0, 14, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_169_object_00:
    map_object 86, 0, 4, 11, 1, 13, 0, 1, 0, 0, 0, 113, 18026
map_169_object_01:
    map_object 86, 0, 4, 6, 1, 17, 0, 1, 0, 0, 0, 113, 18026
map_169_object_02:
    map_object 86, 0, 4, 17, 1, 17, 0, 1, 0, 0, 0, 113, 18026
map_16A_header:
    map_header 15, 3, 85, 0, 15, 2, 1, 0, 0, 0, 1, 2, 0, 0, 255
map_16A_object_00:
    map_object 38, 0, 3, 7, 0, 14, 0, 1, 0, 0, 0, 9, 49153
map_16A_object_01:
    map_object 38, 0, 3, 15, 0, 25, 0, 1, 0, 0, 0, 9, 49153
map_16A_object_02:
    map_object 38, 0, 3, 25, 0, 16, 0, 1, 0, 0, 0, 29, 49153
map_16A_object_03:
    map_object 38, 0, 3, 7, 0, 23, 0, 1, 0, 0, 0, 56, 49153
map_16A_object_04:
    map_object 38, 0, 3, 19, 0, 32, 0, 1, 0, 0, 0, 56, 49153
map_16B_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 1, 0, 0, 1, 2, 0, 0, 255
map_16B_object_00:
    map_object 38, 4, 5, 12, 1, 12, 1, 1, 0, 0, 0, 174, 49152
map_16B_object_01:
    map_object 38, 5, 5, 12, 1, 23, 1, 0, 0, 0, 0, 173, 49152
map_16C_header:
    map_header 15, 2, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_16C_object_00:
    map_object 38, 0, 3, 10, 1, 12, 0, 1, 0, 0, 0, 94, 1645
map_16D_header:
    map_header 15, 3, 85, 0, 15, 2, 0, 0, 0, 0, 1, 2, 0, 0, 255
map_16D_object_00:
    map_object 38, 0, 3, 7, 0, 11, 0, 1, 0, 0, 0, 51, 49153
map_16D_object_01:
    map_object 38, 0, 3, 5, 0, 13, 0, 1, 0, 0, 0, 51, 49153
map_16D_object_02:
    map_object 38, 0, 3, 9, 0, 13, 0, 1, 0, 0, 0, 51, 49153
map_16F_header:
    map_header 10, 0, 106, 0, 10, 0, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_16F_object_00:
    map_object 173, 0, 1, 8, 0, 10, 0, 1, 0, 0, 0, 58, 49153
map_170_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_170_object_00:
    map_object 222, 0, 0, 20, 1, 36, 1, 1, 0, 0, 0, 235, 50830
map_170_object_01:
    map_object 173, 0, 1, 10, 0, 16, 0, 1, 0, 0, 0, 78, 49153
map_170_object_02:
    map_object 173, 0, 1, 19, 0, 19, 0, 1, 0, 0, 0, 78, 49153
map_170_object_03:
    map_object 173, 0, 1, 31, 0, 16, 0, 1, 0, 0, 0, 78, 49153
map_170_object_04:
    map_object 173, 0, 1, 1, 0, 39, 0, 1, 0, 0, 0, 78, 49153
map_170_object_05:
    map_object 173, 0, 1, 15, 0, 37, 0, 1, 0, 0, 0, 78, 49153
map_170_object_06:
    map_object 173, 0, 1, 25, 0, 37, 0, 1, 0, 0, 0, 78, 49153
map_170_object_07:
    map_object 173, 0, 1, 39, 0, 39, 0, 1, 0, 0, 0, 78, 49153
map_170_object_08:
    map_object 173, 0, 1, 10, 0, 39, 0, 1, 0, 0, 0, 58, 49153
map_170_object_09:
    map_object 173, 0, 1, 29, 0, 45, 0, 1, 0, 0, 0, 58, 49153
map_171_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_171_object_00:
    map_object 173, 0, 1, 8, 0, 15, 0, 1, 0, 0, 0, 72, 49153
map_171_object_01:
    map_object 173, 0, 1, 20, 0, 14, 0, 1, 0, 0, 0, 72, 49153
map_171_object_02:
    map_object 173, 0, 1, 26, 0, 17, 0, 1, 0, 0, 0, 72, 49153
map_171_object_03:
    map_object 173, 0, 1, 31, 0, 15, 0, 1, 0, 0, 0, 72, 49153
map_171_object_04:
    map_object 173, 0, 1, 14, 0, 19, 0, 1, 0, 0, 0, 55, 49153
map_171_object_05:
    map_object 173, 0, 1, 26, 0, 9, 0, 1, 0, 0, 0, 55, 49153
map_172_header:
    map_header 10, 0, 106, 0, 10, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_172_object_00:
    map_object 173, 0, 1, 10, 0, 14, 0, 1, 0, 0, 0, 38, 49153
map_172_object_01:
    map_object 173, 0, 1, 16, 0, 11, 0, 1, 0, 0, 0, 38, 49153
map_172_object_02:
    map_object 173, 0, 1, 22, 0, 12, 0, 1, 0, 0, 0, 38, 49153
map_172_object_03:
    map_object 173, 0, 1, 31, 0, 12, 0, 1, 0, 0, 0, 38, 49153
map_172_object_04:
    map_object 173, 0, 1, 26, 0, 15, 0, 1, 0, 0, 0, 38, 49153
map_173_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_173_object_00:
    map_object 173, 0, 1, 7, 0, 9, 0, 1, 0, 0, 0, 58, 49153
map_173_object_01:
    map_object 173, 0, 1, 10, 0, 9, 0, 1, 0, 0, 0, 58, 49153
map_173_object_02:
    map_object 184, 0, 4, 9, 1, 7, 1, 1, 0, 0, 0, 235, 50800
map_174_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_174_object_00:
    map_object 173, 0, 1, 7, 0, 9, 0, 1, 0, 0, 0, 58, 49153
map_174_object_01:
    map_object 173, 0, 1, 10, 0, 9, 0, 1, 0, 0, 0, 58, 49153
map_175_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_175_object_00:
    map_object 173, 0, 1, 5, 0, 16, 0, 1, 0, 0, 0, 38, 49153
map_175_object_01:
    map_object 173, 0, 1, 12, 0, 16, 0, 1, 0, 0, 0, 38, 49153
map_175_object_02:
    map_object 173, 0, 1, 9, 0, 8, 0, 1, 0, 0, 0, 58, 49153
map_176_header:
    map_header 23, 3, 92, 0, 23, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_176_object_00:
    map_object 173, 0, 1, 5, 0, 12, 0, 1, 0, 0, 0, 78, 49153
map_176_object_01:
    map_object 173, 0, 1, 6, 0, 22, 0, 1, 0, 0, 0, 78, 49153
map_176_object_02:
    map_object 173, 0, 1, 12, 0, 27, 0, 1, 0, 0, 0, 78, 49153
map_176_object_03:
    map_object 173, 0, 1, 18, 0, 25, 0, 1, 0, 0, 0, 78, 49153
map_176_object_04:
    map_object 173, 0, 1, 19, 0, 21, 0, 1, 0, 0, 0, 78, 49153
map_176_object_05:
    map_object 173, 0, 1, 29, 0, 12, 0, 1, 0, 0, 0, 72, 49153
map_176_object_06:
    map_object 173, 0, 1, 12, 0, 17, 0, 1, 0, 0, 0, 55, 49153
map_176_object_07:
    map_object 173, 0, 1, 6, 0, 32, 0, 1, 0, 0, 0, 55, 49153
map_176_object_08:
    map_object 173, 0, 1, 26, 0, 32, 0, 1, 0, 0, 0, 55, 49153
map_176_object_09:
    map_object 173, 0, 1, 28, 0, 18, 0, 1, 0, 0, 0, 55, 49153
map_176_object_10:
    map_object 173, 0, 1, 16, 0, 12, 0, 1, 0, 0, 0, 38, 49153
map_177_header:
    map_header 23, 3, 92, 1, 23, 2, 1, 1, 0, 0, 3, 0, 0, 0, 255
map_177_object_00:
    map_object 149, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25997
map_177_object_01:
    map_object 149, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21901
map_177_object_02:
    map_object 173, 0, 1, 14, 1, 15, 1, 1, 0, 0, 0, 149, 5510
map_178_header:
    map_header 4, 2, 28, 0, 4, 2, 1, 1, 0, 0, 0, 0, 0, 0, 15
map_178_object_00:
    map_object 16, 0, 15, 20, 0, 11, 0, 1, 3, 1, 6, 207, 54052
map_179_header:
    map_header 14, 3, 83, 0, 14, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_179_object_00:
    map_object 52, 0, 3, 12, 1, 16, 0, 1, 0, 0, 0, 99, 1319
map_17A_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_17A_object_00:
    map_object 52, 0, 15, 11, 1, 23, 1, 2, 0, 0, 0, 211, 14073
map_17A_object_01:
    map_object 52, 0, 15, 15, 1, 24, 1, 3, 0, 0, 0, 211, 14073
map_17A_object_02:
    map_object 221, 0, 0, 14, 1, 11, 1, 0, 0, 0, 0, 235, 18061
map_17B_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_17B_object_00:
    map_object 52, 4, 14, 10, 0, 11, 0, 1, 0, 0, 0, 38, 49153
map_17B_object_01:
    map_object 52, 4, 14, 8, 0, 13, 0, 1, 0, 0, 0, 38, 49153
map_17B_object_02:
    map_object 52, 4, 14, 12, 0, 13, 0, 1, 0, 0, 0, 38, 49153
map_17C_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 55
map_17C_object_00:
    map_object 52, 0, 4, 18, 1, 16, 0, 1, 0, 0, 0, 167, 50467
map_17C_object_01:
    map_object 52, 0, 4, 19, 1, 14, 0, 3, 1, 0, 0, 195, 50468
map_17C_object_02:
    map_object 52, 0, 4, 20, 1, 12, 0, 2, 2, 0, 0, 194, 50469
map_17C_object_03:
    map_object 52, 0, 3, 19, 1, 20, 1, 0, 3, 0, 0, 182, 21798
map_17C_object_04:
    map_object 52, 0, 3, 17, 1, 22, 1, 3, 3, 0, 0, 182, 21798
map_17D_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_17D_object_00:
    map_object 52, 4, 14, 10, 0, 11, 0, 1, 0, 0, 0, 38, 49153
map_17D_object_01:
    map_object 52, 4, 14, 10, 0, 16, 0, 1, 0, 0, 0, 38, 49153
map_17E_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_17E_object_00:
    map_object 52, 4, 14, 8, 0, 21, 0, 1, 0, 0, 0, 62, 49153
map_17E_object_01:
    map_object 52, 4, 14, 10, 0, 21, 0, 1, 0, 0, 0, 62, 49153
map_17E_object_02:
    map_object 52, 4, 14, 9, 0, 24, 0, 1, 0, 0, 0, 62, 49153
map_17F_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_17F_object_00:
    map_object 186, 0, 3, 6, 1, 13, 1, 0, 0, 0, 0, 235, 18034
map_17F_object_01:
    map_object 188, 0, 4, 8, 1, 13, 1, 0, 0, 0, 0, 235, 18036
map_17F_object_02:
    map_object 52, 4, 14, 6, 0, 12, 0, 3, 0, 0, 0, 62, 49153
map_17F_object_03:
    map_object 52, 4, 14, 7, 0, 13, 0, 0, 0, 0, 0, 62, 49153
map_17F_object_04:
    map_object 52, 4, 14, 8, 0, 12, 0, 2, 0, 0, 0, 62, 49153
map_180_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_180_object_00:
    map_object 52, 0, 3, 12, 1, 12, 1, 1, 3, 0, 0, 182, 17697
map_180_object_01:
    map_object 52, 0, 3, 13, 1, 12, 1, 1, 3, 0, 0, 182, 17697
map_180_object_02:
    map_object 52, 4, 14, 12, 0, 24, 0, 1, 0, 0, 0, 62, 49153
map_180_object_03:
    map_object 52, 4, 14, 19, 0, 24, 0, 1, 0, 0, 0, 62, 49153
map_180_object_04:
    map_object 52, 4, 14, 15, 0, 15, 0, 1, 0, 0, 0, 72, 49153
map_181_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_181_object_00:
    map_object 52, 0, 3, 24, 1, 14, 1, 1, 3, 0, 0, 182, 17698
map_181_object_01:
    map_object 52, 0, 3, 30, 1, 30, 1, 1, 3, 0, 0, 182, 17698
map_181_object_02:
    map_object 52, 4, 14, 7, 0, 31, 0, 1, 0, 0, 0, 62, 49153
map_181_object_03:
    map_object 52, 4, 14, 23, 0, 16, 0, 1, 0, 0, 0, 62, 49153
map_181_object_04:
    map_object 52, 4, 14, 32, 0, 16, 0, 1, 0, 0, 0, 62, 49153
map_181_object_05:
    map_object 52, 4, 14, 32, 0, 30, 0, 1, 0, 0, 0, 62, 49153
map_181_object_06:
    map_object 52, 4, 14, 17, 0, 29, 0, 1, 0, 0, 0, 72, 49153
map_182_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_182_object_00:
    map_object 52, 4, 14, 11, 0, 10, 0, 1, 0, 0, 0, 35, 49153
map_182_object_01:
    map_object 52, 4, 14, 10, 0, 17, 0, 1, 0, 0, 0, 72, 49153
map_182_object_02:
    map_object 52, 4, 14, 12, 0, 17, 0, 1, 0, 0, 0, 72, 49153
map_183_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 1, 0, 0, 0, 2, 0, 0, 54
map_183_object_00:
    map_object 52, 0, 1, 9, 1, 14, 1, 3, 3, 0, 0, 182, 17698
map_183_object_01:
    map_object 52, 0, 1, 15, 1, 14, 1, 2, 3, 0, 0, 182, 17698
map_183_object_02:
    map_object 52, 0, 0, 12, 1, 16, 1, 1, 0, 0, 0, 176, 17693
map_184_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_184_object_00:
    map_object 52, 4, 14, 7, 0, 13, 0, 1, 0, 0, 0, 72, 49153
map_185_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_185_object_00:
    map_object 52, 4, 14, 29, 0, 13, 0, 1, 0, 0, 0, 62, 49153
map_185_object_01:
    map_object 52, 4, 14, 20, 0, 13, 0, 1, 0, 0, 0, 62, 49153
map_185_object_02:
    map_object 52, 4, 14, 12, 0, 13, 0, 1, 0, 0, 0, 62, 49153
map_185_object_03:
    map_object 52, 4, 14, 12, 0, 25, 0, 1, 0, 0, 0, 62, 49153
map_185_object_04:
    map_object 52, 4, 14, 20, 0, 25, 0, 1, 0, 0, 0, 62, 49153
map_185_object_05:
    map_object 52, 4, 14, 29, 0, 25, 0, 2, 0, 0, 0, 62, 49153
map_186_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 0, 0, 0, 0, 2, 0, 0, 255
map_186_object_00:
    map_object 52, 4, 14, 8, 0, 17, 0, 1, 0, 0, 0, 72, 49153
map_186_object_01:
    map_object 52, 4, 14, 31, 0, 17, 0, 1, 0, 0, 0, 72, 49153
map_186_object_02:
    map_object 52, 4, 14, 20, 0, 26, 0, 1, 0, 0, 0, 72, 49153
map_187_header:
    map_header 15, 3, 58, 0, 15, 2, 0, 1, 0, 0, 0, 2, 0, 0, 56
map_187_object_00:
    map_object 53, 0, 4, 20, 1, 14, 1, 1, 0, 0, 0, 176, 16384
map_187_object_01:
    map_object 53, 0, 5, 20, 1, 16, 1, 1, 1, 0, 0, 177, 16384
map_187_object_02:
    map_object 53, 0, 4, 18, 1, 15, 1, 1, 2, 0, 0, 178, 16384
map_187_object_03:
    map_object 53, 0, 4, 22, 1, 15, 1, 1, 3, 0, 0, 180, 16384
map_189_header:
    map_header 23, 2, 100, 0, 23, 2, 0, 0, 0, 0, 3, 17, 0, 0, 255
map_18A_header:
    map_header 23, 2, 100, 0, 23, 2, 0, 0, 0, 0, 3, 17, 0, 0, 255
map_18B_header:
    map_header 23, 2, 100, 0, 23, 2, 0, 0, 0, 0, 3, 17, 0, 0, 255
map_18C_header:
    map_header 23, 2, 100, 0, 23, 2, 0, 0, 0, 0, 3, 17, 0, 0, 255
map_190_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_190_object_00:
    map_object 45, 0, 6, 10, 0, 32, 0, 1, 0, 1, 0, 54, 49153
map_190_object_01:
    map_object 45, 0, 6, 41, 0, 77, 0, 1, 0, 1, 0, 54, 49153
map_190_object_02:
    map_object 45, 0, 6, 43, 0, 72, 0, 1, 0, 1, 0, 54, 49153
map_190_object_03:
    map_object 45, 0, 6, 41, 0, 32, 0, 1, 0, 1, 0, 54, 49153
map_190_object_04:
    map_object 45, 0, 6, 11, 0, 16, 0, 1, 0, 1, 0, 26, 16385
map_190_object_05:
    map_object 45, 0, 6, 8, 0, 72, 0, 1, 0, 1, 0, 26, 16385
map_190_object_06:
    map_object 45, 0, 6, 40, 0, 17, 0, 1, 0, 1, 0, 26, 16385
map_190_object_07:
    map_object 45, 0, 6, 26, 0, 27, 0, 1, 0, 1, 0, 26, 16385
map_190_object_08:
    map_object 45, 0, 6, 13, 0, 72, 0, 1, 0, 1, 0, 51, 49153
map_190_object_09:
    map_object 45, 0, 6, 16, 0, 72, 0, 1, 0, 1, 0, 51, 49153
map_190_object_10:
    map_object 45, 0, 6, 42, 0, 74, 0, 1, 0, 1, 0, 9, 49153
map_191_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 8, 3, 8, 0, 0, 255
map_191_object_00:
    map_object 45, 0, 6, 13, 0, 17, 0, 1, 0, 1, 0, 54, 49153
map_191_object_01:
    map_object 45, 0, 6, 15, 0, 17, 0, 1, 0, 1, 0, 54, 49153
map_191_object_02:
    map_object 45, 0, 6, 12, 0, 78, 0, 3, 0, 1, 0, 54, 49153
map_191_object_03:
    map_object 45, 0, 6, 18, 0, 78, 0, 2, 0, 1, 0, 54, 49153
map_191_object_04:
    map_object 45, 0, 6, 34, 0, 78, 0, 3, 0, 1, 0, 28, 49153
map_191_object_05:
    map_object 45, 0, 6, 40, 0, 78, 0, 2, 0, 1, 0, 28, 49153
map_191_object_06:
    map_object 45, 0, 6, 56, 0, 78, 0, 3, 0, 1, 0, 54, 49153
map_191_object_07:
    map_object 45, 0, 6, 62, 0, 78, 0, 2, 0, 1, 0, 54, 49153
map_191_object_08:
    map_object 45, 0, 6, 8, 0, 17, 0, 1, 0, 1, 0, 55, 49153
map_191_object_09:
    map_object 45, 0, 6, 9, 0, 45, 0, 1, 0, 1, 0, 56, 49153
map_191_object_10:
    map_object 45, 0, 6, 9, 0, 47, 0, 1, 0, 1, 0, 56, 49153
map_191_object_11:
    map_object 45, 0, 6, 72, 0, 46, 0, 1, 0, 1, 0, 56, 49153
map_191_object_12:
    map_object 45, 0, 6, 9, 0, 47, 0, 1, 0, 1, 0, 8, 49153
map_191_object_13:
    map_object 45, 0, 6, 69, 0, 50, 0, 3, 0, 1, 0, 39, 49153
map_191_object_14:
    map_object 45, 0, 6, 75, 0, 50, 0, 2, 0, 1, 0, 8, 49153
map_191_object_15:
    map_object 45, 0, 6, 40, 0, 45, 0, 1, 0, 1, 0, 30, 49153
map_191_object_16:
    map_object 45, 0, 6, 40, 0, 47, 0, 1, 0, 1, 0, 30, 49153
map_191_object_17:
    map_object 45, 0, 6, 69, 0, 17, 0, 3, 0, 1, 0, 30, 49153
map_191_object_18:
    map_object 45, 0, 6, 75, 0, 17, 0, 2, 0, 1, 0, 30, 49153
map_191_object_19:
    map_object 45, 0, 6, 72, 0, 19, 0, 1, 0, 1, 0, 30, 49153
map_191_object_20:
    map_object 45, 0, 6, 47, 0, 19, 0, 1, 0, 1, 0, 35, 49153
map_192_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 1, 0, 8, 3, 8, 0, 0, 255
map_192_object_00:
    map_object 45, 0, 6, 66, 1, 23, 1, 0, 0, 1, 0, 172, 5461
map_192_object_01:
    map_object 45, 0, 5, 76, 0, 28, 0, 1, 0, 1, 0, 169, 17750
map_192_object_02:
    map_object 45, 0, 5, 61, 0, 40, 0, 0, 0, 1, 0, 169, 17750
map_192_object_03:
    map_object 45, 0, 5, 70, 0, 35, 0, 3, 0, 1, 0, 169, 17750
map_192_object_04:
    map_object 45, 0, 5, 54, 0, 30, 0, 2, 0, 1, 0, 169, 17750
map_193_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 8, 3, 8, 0, 0, 255
map_193_object_00:
    map_object 45, 0, 6, 37, 0, 49, 0, 1, 0, 1, 0, 55, 49153
map_193_object_01:
    map_object 45, 0, 6, 8, 0, 16, 0, 3, 0, 1, 0, 54, 49153
map_193_object_02:
    map_object 45, 0, 6, 14, 0, 16, 0, 2, 0, 1, 0, 54, 49153
map_193_object_03:
    map_object 45, 0, 6, 92, 0, 81, 0, 1, 0, 1, 0, 55, 49153
map_193_object_04:
    map_object 45, 0, 6, 95, 0, 81, 0, 1, 0, 1, 0, 55, 49153
map_193_object_05:
    map_object 45, 0, 6, 22, 0, 93, 0, 1, 0, 1, 0, 55, 49153
map_193_object_06:
    map_object 45, 0, 6, 38, 0, 41, 0, 1, 0, 1, 0, 54, 49153
map_193_object_07:
    map_object 45, 0, 6, 66, 0, 70, 0, 1, 0, 1, 0, 56, 49153
map_193_object_08:
    map_object 45, 0, 6, 65, 0, 70, 0, 1, 0, 1, 0, 56, 49153
map_193_object_09:
    map_object 45, 0, 6, 94, 0, 20, 0, 1, 0, 1, 0, 56, 49153
map_193_object_10:
    map_object 45, 0, 6, 40, 0, 17, 0, 1, 0, 1, 0, 30, 49153
map_193_object_11:
    map_object 45, 0, 6, 44, 0, 17, 0, 1, 0, 1, 0, 39, 49153
map_193_object_12:
    map_object 45, 0, 6, 48, 0, 17, 0, 1, 0, 1, 0, 30, 49153
map_193_object_13:
    map_object 45, 0, 6, 22, 0, 94, 0, 1, 0, 1, 0, 30, 49153
map_193_object_14:
    map_object 45, 0, 6, 22, 0, 92, 0, 1, 0, 1, 0, 30, 49153
map_193_object_15:
    map_object 45, 0, 6, 18, 0, 42, 0, 1, 0, 1, 0, 54, 49153
map_193_object_16:
    map_object 45, 0, 6, 18, 0, 56, 0, 1, 0, 1, 0, 26, 16385
map_193_object_17:
    map_object 45, 0, 6, 9, 0, 45, 0, 0, 0, 1, 0, 26, 16385
map_193_object_18:
    map_object 45, 0, 6, 42, 0, 68, 0, 1, 0, 1, 0, 26, 16385
map_193_object_19:
    map_object 45, 0, 6, 66, 0, 69, 0, 1, 0, 1, 0, 29, 49153
map_193_object_20:
    map_object 45, 0, 6, 92, 0, 17, 0, 1, 0, 1, 0, 29, 49153
map_193_object_21:
    map_object 45, 0, 6, 96, 0, 17, 0, 1, 0, 1, 0, 15, 49153
map_193_object_22:
    map_object 45, 0, 6, 27, 0, 55, 0, 1, 0, 1, 0, 28, 49153
map_193_object_23:
    map_object 45, 0, 6, 27, 0, 40, 0, 1, 0, 1, 0, 28, 49153
map_193_object_24:
    map_object 185, 0, 3, 12, 1, 13, 1, 1, 0, 1, 0, 235, 50801
map_194_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 8, 3, 8, 0, 0, 255
map_194_object_00:
    map_object 45, 0, 6, 11, 0, 46, 0, 3, 0, 1, 0, 54, 49153
map_194_object_01:
    map_object 45, 0, 6, 15, 0, 46, 0, 2, 0, 1, 0, 54, 49153
map_194_object_02:
    map_object 45, 0, 6, 30, 0, 55, 0, 1, 0, 1, 0, 55, 49153
map_194_object_03:
    map_object 45, 0, 6, 25, 0, 55, 0, 1, 0, 1, 0, 55, 49153
map_194_object_04:
    map_object 45, 0, 6, 39, 0, 15, 0, 1, 0, 1, 0, 55, 49153
map_194_object_05:
    map_object 45, 0, 6, 35, 0, 15, 0, 1, 0, 1, 0, 30, 49153
map_194_object_06:
    map_object 45, 0, 6, 43, 0, 15, 0, 1, 0, 1, 0, 30, 49153
map_194_object_07:
    map_object 45, 0, 6, 16, 0, 67, 0, 1, 0, 1, 0, 26, 16385
map_194_object_08:
    map_object 45, 0, 6, 28, 0, 65, 0, 1, 0, 1, 0, 26, 16385
map_195_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 1, 0, 8, 3, 8, 0, 0, 255
map_195_object_00:
    map_object 45, 0, 6, 11, 0, 17, 0, 1, 0, 1, 0, 26, 16385
map_195_object_01:
    map_object 45, 0, 6, 19, 0, 33, 0, 1, 0, 1, 0, 28, 49153
map_195_object_02:
    map_object 45, 0, 6, 22, 0, 33, 0, 1, 0, 1, 0, 28, 49153
map_196_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_196_object_00:
    map_object 45, 0, 6, 10, 0, 45, 0, 1, 0, 1, 0, 54, 49153
map_196_object_01:
    map_object 45, 0, 6, 12, 0, 42, 0, 1, 0, 1, 0, 54, 49153
map_196_object_02:
    map_object 45, 0, 6, 63, 0, 16, 0, 3, 0, 1, 0, 54, 49153
map_196_object_03:
    map_object 45, 0, 6, 33, 0, 45, 0, 1, 0, 1, 0, 55, 49153
map_196_object_04:
    map_object 45, 0, 6, 54, 0, 42, 0, 1, 0, 1, 0, 55, 49153
map_196_object_05:
    map_object 45, 0, 6, 59, 0, 42, 0, 1, 0, 1, 0, 55, 49153
map_196_object_06:
    map_object 45, 0, 6, 15, 0, 16, 0, 1, 0, 1, 0, 56, 49153
map_196_object_07:
    map_object 45, 0, 6, 24, 0, 16, 0, 1, 0, 1, 0, 56, 49153
map_196_object_08:
    map_object 45, 0, 6, 58, 0, 16, 0, 1, 0, 1, 0, 9, 49153
map_196_object_09:
    map_object 45, 0, 6, 68, 0, 16, 0, 3, 0, 1, 0, 9, 49153
map_196_object_10:
    map_object 45, 0, 6, 14, 0, 44, 0, 1, 0, 1, 0, 34, 49153
map_196_object_11:
    map_object 45, 0, 6, 31, 0, 42, 0, 1, 0, 1, 0, 30, 49153
map_196_object_12:
    map_object 45, 0, 6, 36, 0, 42, 0, 1, 0, 1, 0, 30, 49153
map_196_object_13:
    map_object 45, 0, 6, 56, 0, 45, 0, 1, 0, 1, 0, 26, 16385
map_196_object_14:
    map_object 45, 0, 6, 77, 0, 42, 0, 1, 0, 1, 0, 26, 16385
map_196_object_15:
    map_object 45, 0, 6, 19, 0, 16, 0, 1, 0, 1, 0, 29, 49153
map_196_object_16:
    map_object 45, 0, 6, 79, 0, 45, 0, 1, 0, 1, 0, 51, 49153
map_196_object_17:
    map_object 45, 0, 6, 75, 0, 42, 0, 1, 0, 1, 0, 51, 49153
map_197_header:
    map_header 9, 2, 79, 0, 9, 1, 0, 0, 30, 14, 1, 0, 0, 0, 255
map_197_object_00:
    map_object 45, 0, 3, 14, 1, 8, 0, 1, 0, 0, 0, 97, 50515
map_198_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 8, 1, 8, 0, 0, 255
map_198_object_00:
    map_object 45, 5, 5, 14, 1, 19, 1, 0, 0, 1, 0, 139, 0
map_198_object_01:
    map_object 45, 5, 6, 14, 1, 18, 1, 1, 0, 1, 0, 191, 0
map_198_object_02:
    map_object 45, 7, 7, 14, 1, 18, 1, 1, 0, 1, 0, 98, 1369
map_199_header:
    map_header 9, 2, 80, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_199_object_00:
    map_object 45, 0, 6, 12, 0, 24, 0, 1, 0, 1, 0, 54, 49153
map_199_object_01:
    map_object 45, 0, 6, 20, 0, 24, 0, 1, 0, 1, 0, 54, 49153
map_199_object_02:
    map_object 45, 0, 6, 12, 0, 23, 0, 1, 0, 1, 0, 55, 49153
map_199_object_03:
    map_object 45, 0, 6, 18, 0, 23, 0, 1, 0, 1, 0, 55, 49153
map_199_object_04:
    map_object 45, 0, 6, 16, 0, 15, 0, 1, 0, 1, 0, 55, 49153
map_199_object_05:
    map_object 45, 0, 6, 16, 0, 17, 0, 1, 0, 1, 0, 35, 49153
map_19A_header:
    map_header 9, 2, 79, 0, 9, 2, 0, 0, 0, 0, 3, 0, 0, 0, 255
map_19C_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_19C_object_00:
    map_object 0, 0, 15, 14, 0, 32, 0, 1, 0, 0, 0, 70, 49153
map_19C_object_01:
    map_object 0, 0, 15, 35, 0, 32, 0, 1, 0, 0, 0, 70, 49153
map_19C_object_02:
    map_object 0, 0, 15, 17, 0, 46, 0, 1, 0, 0, 0, 74, 49153
map_19C_object_03:
    map_object 0, 0, 15, 31, 0, 46, 0, 1, 0, 0, 0, 74, 49153
map_19C_object_04:
    map_object 0, 0, 15, 9, 0, 43, 0, 1, 0, 0, 0, 67, 49153
map_19C_object_05:
    map_object 0, 0, 15, 40, 0, 43, 0, 1, 0, 0, 0, 67, 49153
map_19C_object_06:
    map_object 0, 0, 15, 25, 0, 42, 0, 1, 0, 0, 0, 81, 49153
map_19D_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_19D_object_00:
    map_object 0, 0, 15, 21, 0, 9, 0, 1, 0, 0, 0, 70, 49153
map_19D_object_01:
    map_object 0, 0, 15, 18, 0, 19, 0, 1, 0, 0, 0, 70, 49153
map_19D_object_02:
    map_object 0, 0, 15, 24, 0, 19, 0, 1, 0, 0, 0, 70, 49153
map_19D_object_03:
    map_object 0, 0, 15, 9, 0, 22, 0, 1, 0, 0, 0, 74, 49153
map_19D_object_04:
    map_object 0, 0, 15, 32, 0, 22, 0, 1, 0, 0, 0, 74, 49153
map_19D_object_05:
    map_object 0, 0, 15, 15, 0, 9, 0, 1, 0, 0, 0, 67, 49153
map_19D_object_06:
    map_object 0, 0, 15, 26, 0, 9, 0, 1, 0, 0, 0, 67, 49153
map_19E_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_19E_object_00:
    map_object 0, 0, 15, 20, 0, 16, 0, 1, 0, 0, 0, 70, 49153
map_19E_object_01:
    map_object 0, 0, 15, 25, 0, 16, 0, 1, 0, 0, 0, 70, 49153
map_19E_object_02:
    map_object 0, 0, 15, 38, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_19E_object_03:
    map_object 0, 0, 15, 8, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_19E_object_04:
    map_object 0, 0, 15, 8, 0, 22, 0, 1, 0, 0, 0, 67, 49153
map_19E_object_05:
    map_object 0, 0, 15, 37, 0, 22, 0, 1, 0, 0, 0, 67, 49153
map_19E_object_06:
    map_object 0, 0, 15, 23, 0, 27, 0, 1, 0, 0, 0, 57, 49153
map_19E_object_07:
    map_object 0, 0, 15, 17, 0, 23, 0, 1, 0, 0, 0, 81, 49153
map_19E_object_08:
    map_object 0, 0, 15, 28, 0, 23, 0, 1, 0, 0, 0, 81, 49153
map_19E_object_09:
    map_object 0, 0, 15, 32, 0, 49, 0, 1, 0, 0, 0, 81, 49153
map_19E_object_10:
    map_object 0, 0, 15, 12, 0, 49, 0, 1, 0, 0, 0, 81, 49153
map_19E_object_11:
    map_object 0, 0, 15, 23, 0, 47, 0, 1, 0, 0, 0, 76, 49153
map_19F_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_19F_object_00:
    map_object 0, 0, 15, 28, 0, 29, 0, 1, 0, 0, 0, 70, 49153
map_19F_object_01:
    map_object 0, 0, 15, 21, 0, 29, 0, 1, 0, 0, 0, 70, 49153
map_19F_object_02:
    map_object 0, 0, 15, 21, 0, 52, 0, 1, 0, 0, 0, 70, 49153
map_19F_object_03:
    map_object 0, 0, 15, 28, 0, 52, 0, 1, 0, 0, 0, 70, 49153
map_19F_object_04:
    map_object 0, 0, 15, 17, 0, 16, 0, 1, 0, 0, 0, 74, 49153
map_19F_object_05:
    map_object 0, 0, 15, 32, 0, 16, 0, 1, 0, 0, 0, 74, 49153
map_19F_object_06:
    map_object 0, 0, 15, 9, 0, 51, 0, 1, 0, 0, 0, 74, 49153
map_19F_object_07:
    map_object 0, 0, 15, 40, 0, 51, 0, 1, 0, 0, 0, 74, 49153
map_19F_object_08:
    map_object 0, 0, 15, 11, 0, 31, 0, 1, 0, 0, 0, 67, 49153
map_19F_object_09:
    map_object 0, 0, 15, 39, 0, 31, 0, 1, 0, 0, 0, 67, 49153
map_19F_object_10:
    map_object 0, 0, 15, 24, 0, 13, 0, 1, 0, 0, 0, 81, 49153
map_19F_object_11:
    map_object 0, 0, 15, 25, 0, 49, 0, 1, 0, 0, 0, 81, 49153
map_19F_object_12:
    map_object 185, 0, 5, 25, 1, 49, 1, 1, 0, 0, 0, 235, 50801
map_1A0_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A0_object_00:
    map_object 0, 0, 15, 9, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_1A0_object_01:
    map_object 0, 0, 15, 37, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_1A0_object_02:
    map_object 0, 0, 15, 14, 0, 22, 0, 1, 0, 0, 0, 67, 49153
map_1A0_object_03:
    map_object 0, 0, 15, 33, 0, 22, 0, 1, 0, 0, 0, 67, 49153
map_1A0_object_04:
    map_object 0, 0, 15, 22, 0, 32, 0, 1, 0, 0, 0, 67, 49153
map_1A0_object_05:
    map_object 0, 0, 15, 25, 0, 32, 0, 1, 0, 0, 0, 67, 49153
map_1A0_object_06:
    map_object 0, 0, 15, 15, 0, 12, 0, 1, 0, 0, 0, 81, 49153
map_1A0_object_07:
    map_object 0, 0, 15, 31, 0, 12, 0, 1, 0, 0, 0, 81, 49153
map_1A0_object_08:
    map_object 0, 0, 15, 14, 0, 39, 0, 1, 0, 0, 0, 81, 49153
map_1A0_object_09:
    map_object 0, 0, 15, 33, 0, 39, 0, 1, 0, 0, 0, 81, 49153
map_1A0_object_10:
    map_object 0, 0, 15, 30, 0, 17, 0, 1, 0, 0, 0, 76, 49153
map_1A0_object_11:
    map_object 0, 0, 15, 15, 0, 17, 0, 1, 0, 0, 0, 76, 49153
map_1A1_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A1_object_00:
    map_object 0, 0, 15, 18, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_1A1_object_01:
    map_object 0, 0, 15, 29, 0, 27, 0, 1, 0, 0, 0, 74, 49153
map_1A1_object_02:
    map_object 0, 0, 15, 9, 0, 16, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_03:
    map_object 0, 0, 15, 38, 0, 16, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_04:
    map_object 0, 0, 15, 9, 0, 37, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_05:
    map_object 0, 0, 15, 12, 0, 37, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_06:
    map_object 0, 0, 15, 35, 0, 37, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_07:
    map_object 0, 0, 15, 38, 0, 37, 0, 1, 0, 0, 0, 67, 49153
map_1A1_object_08:
    map_object 0, 0, 15, 21, 0, 17, 0, 1, 0, 0, 0, 81, 49153
map_1A1_object_09:
    map_object 0, 0, 15, 26, 0, 17, 0, 1, 0, 0, 0, 81, 49153
map_1A1_object_10:
    map_object 0, 0, 15, 10, 0, 16, 0, 1, 0, 0, 0, 81, 49153
map_1A1_object_11:
    map_object 0, 0, 15, 30, 0, 16, 0, 1, 0, 0, 0, 81, 49153
map_1A1_object_12:
    map_object 0, 0, 15, 15, 0, 31, 0, 1, 0, 0, 0, 81, 49153
map_1A1_object_13:
    map_object 0, 0, 15, 32, 0, 31, 0, 1, 0, 0, 0, 81, 49153
map_1A2_header:
    map_header 23, 2, 97, 0, 23, 2, 1, 1, 0, 0, 1, 13, 0, 0, 255
map_1A2_object_00:
    map_object 68, 0, 4, 15, 1, 25, 1, 1, 0, 0, 0, 178, 16384
map_1A2_object_01:
    map_object 68, 4, 4, 16, 1, 20, 1, 1, 0, 0, 0, 191, 16384
map_1A2_object_02:
    map_object 68, 5, 5, 15, 1, 20, 0, 1, 0, 0, 0, 111, 17570
map_1A3_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A4_header:
    map_header 23, 3, 89, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A4_object_00:
    map_object 232, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1392
map_1A4_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A4_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A4_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1A5_header:
    map_header 23, 3, 88, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A5_object_00:
    map_object 233, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1393
map_1A5_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A5_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A5_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1A6_header:
    map_header 23, 3, 47, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A6_object_00:
    map_object 234, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1394
map_1A6_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A6_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A6_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1A7_header:
    map_header 23, 3, 91, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A7_object_00:
    map_object 235, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1395
map_1A7_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A7_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A7_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1A8_header:
    map_header 23, 3, 93, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A8_object_00:
    map_object 236, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1396
map_1A8_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A8_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A8_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1A9_header:
    map_header 23, 3, 92, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1A9_object_00:
    map_object 237, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1397
map_1A9_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A9_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1A9_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1AA_header:
    map_header 23, 3, 95, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1AA_object_00:
    map_object 238, 0, 0, 15, 1, 8, 1, 1, 0, 0, 0, 85, 1398
map_1AA_object_01:
    map_object 0, 0, 15, 14, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1AA_object_02:
    map_object 0, 0, 15, 16, 0, 20, 0, 1, 0, 0, 0, 81, 49153
map_1AA_object_03:
    map_object 0, 0, 15, 15, 0, 11, 0, 1, 0, 0, 0, 76, 49153
map_1AC_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 0, 0, 0, 3, 13, 0, 0, 255
map_1AE_header:
    map_header 23, 3, 97, 1, 23, 2, 0, 1, 0, 0, 3, 13, 0, 0, 255
map_1AE_object_00:
    map_object 68, 1, 1, 23, 1, 26, 0, 1, 0, 0, 0, 95, 17592
map_1AE_object_01:
    map_object 69, 0, 0, 24, 1, 24, 1, 1, 0, 0, 0, 176, 16384
map_1AE_object_02:
    map_object 69, 0, 0, 22, 1, 25, 1, 1, 0, 0, 0, 178, 16384
map_1AE_object_03:
    map_object 69, 0, 1, 26, 1, 25, 1, 1, 0, 0, 0, 180, 16384
map_1AE_object_04:
    map_object 65, 3, 4, 24, 0, 19, 1, 0, 0, 0, 0, 166, 4144
map_1AE_object_05:
    map_object 65, 3, 4, 23, 0, 32, 1, 1, 0, 0, 0, 203, 16433
map_1AE_object_06:
    map_object 65, 3, 4, 25, 0, 27, 0, 2, 0, 0, 0, 195, 49202
map_1AF_header:
    map_header 23, 3, 97, 1, 23, 2, 2, 1, 0, 0, 1, 13, 0, 0, 255
map_1AF_object_00:
    map_object 151, 0, 1, 14, 1, 12, 1, 1, 0, 0, 7, 223, 25999
map_1AF_object_01:
    map_object 151, 2, 2, 14, 1, 12, 1, 3, 0, 0, 7, 223, 21685
map_1AF_object_02:
    map_object 175, 1, 1, 14, 1, 18, 1, 1, 0, 0, 0, 151, 0
map_1AF_object_03:
    map_object 68, 2, 3, 14, 1, 14, 1, 1, 0, 0, 7, 176, 5290
map_1B0_header:
    map_header 27, 3, 51, 1, 27, 2, 0, 1, 0, 0, 3, 16, 0, 0, 255
map_1B0_object_00:
    map_object 0, 0, 15, 22, 0, 21, 0, 3, 0, 1, 0, 71, 49153
map_1B0_object_01:
    map_object 190, 0, 5, 20, 1, 14, 1, 1, 0, 1, 7, 235, 50806
map_1B0_object_02:
    map_object 0, 0, 15, 10, 1, 20, 1, 1, 0, 1, 7, 211, 14073
map_1B1_header:
    map_header 27, 3, 51, 1, 27, 2, 0, 1, 0, 0, 3, 16, 0, 0, 255
map_1B1_object_00:
    map_object 0, 0, 15, 67, 0, 48, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_01:
    map_object 0, 0, 15, 69, 0, 48, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_02:
    map_object 0, 0, 15, 70, 0, 21, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_03:
    map_object 0, 0, 15, 72, 0, 16, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_04:
    map_object 0, 0, 15, 9, 0, 43, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_05:
    map_object 0, 0, 15, 14, 0, 55, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_06:
    map_object 0, 0, 15, 25, 0, 55, 0, 1, 0, 1, 0, 49, 49153
map_1B1_object_07:
    map_object 0, 0, 15, 73, 0, 37, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_08:
    map_object 0, 0, 15, 67, 0, 33, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_09:
    map_object 0, 0, 15, 71, 0, 28, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_10:
    map_object 0, 0, 15, 31, 0, 55, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_11:
    map_object 0, 0, 15, 38, 0, 55, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_12:
    map_object 0, 0, 15, 9, 0, 25, 0, 1, 0, 1, 0, 71, 49153
map_1B1_object_13:
    map_object 0, 0, 15, 58, 0, 14, 0, 1, 0, 1, 0, 69, 49153
map_1B1_object_14:
    map_object 0, 0, 15, 58, 0, 16, 0, 1, 0, 1, 0, 69, 49153
map_1B1_object_15:
    map_object 0, 0, 15, 40, 0, 14, 0, 1, 0, 1, 0, 69, 49153
map_1B1_object_16:
    map_object 0, 0, 15, 31, 0, 25, 0, 1, 0, 1, 0, 69, 49153
map_1B1_object_17:
    map_object 0, 0, 15, 69, 0, 42, 0, 1, 0, 1, 0, 47, 49153
map_1B1_object_18:
    map_object 0, 0, 15, 15, 0, 20, 0, 1, 0, 1, 0, 57, 49153
map_1B1_object_19:
    map_object 0, 0, 15, 23, 0, 25, 0, 1, 0, 1, 0, 57, 49153
map_1B1_object_20:
    map_object 0, 0, 15, 54, 0, 55, 0, 1, 0, 1, 0, 57, 49153
map_1B2_header:
    map_header 27, 3, 51, 1, 27, 2, 0, 1, 0, 0, 1, 16, 0, 0, 255
map_1B2_object_00:
    map_object 64, 3, 3, 15, 1, 23, 1, 0, 0, 1, 0, 176, 16384
map_1B2_object_01:
    map_object 64, 3, 3, 13, 1, 24, 1, 0, 0, 1, 0, 178, 16384
map_1B2_object_02:
    map_object 64, 3, 3, 17, 1, 24, 1, 0, 0, 1, 0, 182, 16384
map_1B2_object_03:
    map_object 64, 0, 2, 15, 1, 23, 0, 1, 0, 1, 0, 109, 17819
map_1B3_header:
    map_header 27, 3, 51, 1, 27, 2, 0, 1, 0, 0, 3, 16, 0, 0, 255
map_1B4_header:
    map_header 27, 3, 51, 1, 27, 2, 0, 1, 0, 0, 3, 16, 0, 0, 255
map_1B4_object_00:
    map_object 0, 0, 15, 10, 0, 46, 0, 1, 0, 1, 0, 49, 49153
map_1B4_object_01:
    map_object 0, 0, 15, 13, 0, 45, 0, 1, 0, 1, 0, 49, 49153
map_1B4_object_02:
    map_object 0, 0, 15, 17, 0, 45, 0, 1, 0, 1, 0, 47, 49153
map_1BC_header:
    map_header 30, 0, 105, 0, 30, 0, 0, 1, 0, 14, 1, 0, 0, 0, 255
map_1BD_header:
    map_header 10, 0, 102, 0, 10, 0, 0, 1, 0, 14, 1, 0, 0, 0, 255
map_1BE_header:
    map_header 17, 0, 41, 0, 17, 0, 0, 1, 0, 14, 1, 0, 0, 0, 255
map_1C0_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 67
map_1C0_object_00:
    map_object 111, 0, 2, 40, 1, 33, 0, 1, 0, 1, 0, 196, 49904
map_1C0_object_01:
    map_object 111, 0, 2, 37, 1, 37, 0, 3, 0, 1, 0, 197, 49905
map_1C0_object_02:
    map_object 111, 0, 2, 43, 1, 37, 0, 3, 2, 1, 0, 199, 49906
map_1C0_object_03:
    map_object 111, 0, 2, 40, 1, 11, 0, 3, 2, 1, 0, 201, 49907
map_1C0_object_04:
    map_object 111, 0, 2, 36, 1, 14, 0, 2, 1, 1, 0, 198, 49908
map_1C0_object_05:
    map_object 111, 0, 2, 11, 1, 10, 0, 1, 0, 1, 0, 187, 49909
map_1C0_object_06:
    map_object 111, 0, 2, 16, 1, 14, 0, 1, 0, 1, 0, 188, 49910
map_1C0_object_07:
    map_object 111, 0, 2, 10, 1, 34, 0, 3, 2, 1, 0, 199, 49912
map_1C0_object_08:
    map_object 111, 0, 2, 14, 1, 33, 0, 2, 2, 1, 0, 200, 49911
map_1C1_header:
    map_header 6, 2, 30, 0, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 67
map_1C1_object_00:
    map_object 111, 0, 2, 10, 1, 11, 0, 1, 3, 1, 6, 207, 21241
map_1E8_header:
    map_header 23, 0, 47, 0, 23, 0, 0, 0, 31, 0, 1, 14, 0, 0, 255
map_1E8_object_00:
    map_object 78, 0, 3, 12, 1, 12, 0, 1, 0, 0, 0, 124, 17445
map_1E9_header:
    map_header 23, 0, 47, 0, 23, 0, 0, 0, 31, 0, 1, 14, 0, 0, 255
map_1E9_object_00:
    map_object 173, 0, 0, 12, 1, 12, 0, 1, 0, 0, 0, 106, 17732
map_1EF_header:
    map_header 23, 2, 89, 0, 23, 2, 0, 0, 0, 0, 1, 0, 0, 0, 255
map_1EF_object_00:
    map_object 24, 5, 5, 17, 1, 23, 0, 1, 0, 0, 0, 116, 16951
