; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0E6A
reload_boss_graphics_cache_markers_through_wram_port:
    .a8
    lda #$C1
    sta $78
    .a8
    lda #$00
    sta f:$002183
    rep #$20
    .a16
    lda #$0F55
    sta f:$002181
    lda $CB
    sta $76
    sep #$30
    .i8
    ldy #$00
reload_boss_graphics_cache_markers_through_wram_port_c20e85:
    lda [$76],Y
    sta f:$002180
    iny
    .i8
    cpy #$4D
    bne reload_boss_graphics_cache_markers_through_wram_port_c20e85
    stz a:$0FA8
    .a8
    lda #$30
    sta a:$0FAA
    rep #$10
    rts
