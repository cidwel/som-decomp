; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

expand_packed_native_menu_glyph_byte_to_two_bitplanes = $2191

.segment "CODE"
.org $2169
expand_native_menu_glyph_grid_to_two_bitplanes:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$1C
    sta a:$A176
expand_native_menu_glyph_grid_to_two_bitplanes_c02174:
    .a8
    lda #$10
    sta a:$A171
expand_native_menu_glyph_grid_to_two_bitplanes_c02179:
    jsr expand_packed_native_menu_glyph_byte_to_two_bitplanes
    dec a:$A171
    bne expand_native_menu_glyph_grid_to_two_bitplanes_c02179
    rep #$20
    txa
    clc
    .a16
    adc #$0010
    tax
    sep #$20
    dec a:$A176
    bne expand_native_menu_glyph_grid_to_two_bitplanes_c02174
    rts
