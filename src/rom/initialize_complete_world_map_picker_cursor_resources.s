; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_complete_picker_cursor_object_buffer = $AE55
upload_complete_picker_cursor_object_buffer = $AEA5
upload_cursor_tile_high_planes_and_clear_remainder = $AE39
upload_cursor_tile_low_planes_and_clear_remainder = $AE1D

.segment "CODE"
.org $ADEE
initialize_complete_world_map_picker_cursor_resources:
    sep #$20
    .a8
    lda #$80
    sta a:$2115
    stz a:$2116
    .a8
    lda #$7E
    sta a:$2117
    .i8
    ldx #$00
    jsr upload_cursor_tile_low_planes_and_clear_remainder
    jsr upload_cursor_tile_low_planes_and_clear_remainder
    jsr upload_cursor_tile_high_planes_and_clear_remainder
    stz a:$2116
    .a8
    lda #$7F
    sta a:$2117
    jsr upload_cursor_tile_low_planes_and_clear_remainder
    jsr upload_cursor_tile_low_planes_and_clear_remainder
    jsr initialize_complete_picker_cursor_object_buffer
    jsr upload_complete_picker_cursor_object_buffer
    rtl
