; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-columns.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_one_hundred_twenty_eight_ui_column_tiles = $993C
prepare_upper_or_lower_scene_tile_row_for_publication = $98E4

.segment "CODE"
.org $983A
prepare_complete_ui_frame_tile_row_and_column:
    jsr prepare_upper_or_lower_scene_tile_row_for_publication
    jmp prepare_one_hundred_twenty_eight_ui_column_tiles
