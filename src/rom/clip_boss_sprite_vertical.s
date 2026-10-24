; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $20C0
clip_boss_sprite_vertical:
    lda ($79)
    .a16
    and #$FF00
    bpl clip_boss_sprite_vertical_c220ca
    .a16
    ora #$00FF
clip_boss_sprite_vertical_c220ca:
    xba
    clc
    adc $91
    sta $97
    clc
    .a16
    adc #$0020
    bmi clip_boss_sprite_vertical_c220e3
    sec
    .a16
    sbc #$0100
    bpl clip_boss_sprite_vertical_c220e3
    lda $97
    sta a:$0801,X
    clc
    rts
clip_boss_sprite_vertical_c220e3:
    .a16
    lda #$00E0
    sta a:$0801,X
    dec $85
    sec
    rts
