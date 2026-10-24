; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16

configure_rom_row_cursor_and_execute_relocated_rle_decoder = $99F3

.segment "CODE"
.org $98E4
prepare_upper_or_lower_scene_tile_row_for_publication:
    sep #$10
    rep #$20
    ldx $2E
    bne prepare_upper_or_lower_scene_tile_row_for_publication_c098ed
prepare_upper_or_lower_scene_tile_row_for_publication_c098ec:
    rts
prepare_upper_or_lower_scene_tile_row_for_publication_c098ed:
    bmi prepare_upper_or_lower_scene_tile_row_for_publication_c098ec
    .i8
    cpx #$01
    bne prepare_upper_or_lower_scene_tile_row_for_publication_c09931
    lda $FC
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$003F
prepare_upper_or_lower_scene_tile_row_for_publication_c098fc:
    pha
    jsr configure_rom_row_cursor_and_execute_relocated_rle_decoder
    rep #$20
    pla
    xba
    asl
    .a16
    and #$FE00
    sta $74
    lda $FA
    lsr
    lsr
    lsr
    sec
    .a16
    sbc #$0040
    .a16
    and #$01FF
    ora $74
    sta $74
    .a16
    and #$007F
    sta $76
    lda $74
    lsr
    lsr
    .a16
    and #$3F80
    ora $76
    sta $76
    sep #$10
    .i8
    ldx #$FF
    stx $2E
    rts
prepare_upper_or_lower_scene_tile_row_for_publication_c09931:
    lda $FC
    lsr
    lsr
    lsr
    sec
    .a16
    sbc #$0040
    bra prepare_upper_or_lower_scene_tile_row_for_publication_c098fc
