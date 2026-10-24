; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1187
rotate_boss_palette_color_interval:
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    asl
    sta $56
    lda $46
    .a16
    and #$00F0
    lsr
    lsr
    lsr
    adc $56
    sta $5E
    lda $46
    .a16
    and #$000F
    asl
    adc $56
    tay
    sec
    .a16
    sbc #$0002
    tax
    lda a:$0600,Y
    sta $95
rotate_boss_palette_color_interval_c211b2:
    lda a:$0600,X
    sta a:$0600,Y
    txy
    dex
    dex
    cpy $5E
    bne rotate_boss_palette_color_interval_c211b2
    lda $95
    sta a:$0600,Y
    sep #$20
    rts
