; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2095
clip_boss_sprite_horizontal:
    lda ($79)
    .a16
    and #$00FF
    .a16
    bit #$0080
    beq clip_boss_sprite_horizontal_c220a2
    .a16
    ora #$FF00
clip_boss_sprite_horizontal_c220a2:
    clc
    adc $8F
    sta $97
    clc
    .a16
    adc #$0020
    bmi clip_boss_sprite_horizontal_c220bc
    sec
    .a16
    sbc #$0120
    bpl clip_boss_sprite_horizontal_c220bc
    lda $97
    sta a:$0800,X
    sta $99
    clc
    rts
clip_boss_sprite_horizontal_c220bc:
    dec $85
    sec
    rts
