; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16

advance_two_scene_attribute_windows_and_rom_rows = $8455
install_relocated_scene_row_rle_decoder = $9985
prepare_upper_or_lower_scene_tile_row_for_publication = $98E4
publish_changed_scene_attribute_window_rows = $8890
publish_scene_tile_row_with_horizontal_page_wrap = $9881

.segment "CODE"
.org $9996
initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes:
    rep #$20
    sep #$10
    jsr install_relocated_scene_row_rle_decoder
    .i8
    ldx #$80
    lda $FC
    pha
initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes_c099a2:
    phx
    .i8
    ldy #$02
    sty $2E
    jsr prepare_upper_or_lower_scene_tile_row_for_publication
    jsr publish_scene_tile_row_with_horizontal_page_wrap
    rep #$20
    sep #$10
    plx
    lda $FC
    clc
    .a16
    adc #$0008
    sta $FC
    dex
    bne initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes_c099a2
    pla
    sta $FC
    lda $F6
    sec
    .a16
    sbc #$0100
    .a16
    and #$03FF
    sta $F6
    .i8
    ldx #$40
    stx $11
initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes_c099cf:
    rep #$20
    sep #$10
    .a16
    lda #$0004
    clc
    adc $F6
    .a16
    and #$03FF
    sta $F6
    .i8
    ldy #$04
    .i8
    ldx #$00
    jsr advance_two_scene_attribute_windows_and_rom_rows
    rep #$20
    sep #$10
    jsr publish_changed_scene_attribute_window_rows
    sep #$20
    dec $11
    bne initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes_c099cf
    rts
