; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $234B
initialize_boss_graphics_pattern:
    .a16
    lda #$BC00
    sta f:$002181
    sep #$20
    .a8
    lda #$01
    sta f:$002183
    .i16
    ldx #$0000
initialize_boss_graphics_pattern_c2235d:
    .a8
    lda #$00
    sta f:$002180
    .a8
    lda #$03
    sta f:$002180
    inx
    .i16
    cpx #$0200
    bne initialize_boss_graphics_pattern_c2235d
    rep #$20
    .a16
    lda #$3800
    sta f:$002116
    .i16
    ldx #$0000
    .a16
    lda #$0300
initialize_boss_graphics_pattern_c2237e:
    sta f:$002118
    inx
    .i16
    cpx #$0800
    bne initialize_boss_graphics_pattern_c2237e
    rts
