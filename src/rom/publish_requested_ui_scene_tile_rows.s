; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16

publish_pending_ui_scene_tile_column = $984D
publish_scene_tile_row_with_horizontal_page_wrap = $9881

.segment "CODE"
.org $9840
publish_requested_ui_scene_tile_rows:
    sep #$20
    bit $EC
    bpl publish_requested_ui_scene_tile_rows_c0984c
    jsr publish_pending_ui_scene_tile_column
    jmp publish_scene_tile_row_with_horizontal_page_wrap
publish_requested_ui_scene_tile_rows_c0984c:
    rts
