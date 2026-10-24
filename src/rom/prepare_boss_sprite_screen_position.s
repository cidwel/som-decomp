; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2005
prepare_boss_sprite_screen_position:
    lda a:$002B,X
    sta $8F
    sta a:$0002,X
    lda $8D
    .a16
    and #$0003
    beq prepare_boss_sprite_screen_position_c22020
    dec
    asl
    asl
    tay
    lda $8F
    sec
    sbc a:$00A8,Y
    sta $8F
prepare_boss_sprite_screen_position_c22020:
    lda $8F
    sta a:$0020,X
    lda a:$0032,X
    sta $91
    sta a:$0004,X
    lda $8D
    .a16
    and #$0003
    beq prepare_boss_sprite_screen_position_c22054
    dec
    asl
    asl
    tay
    lda $91
    sec
    sbc a:$00AA,Y
    sta $91
    lda a:$00C2,Y
    sec
    .a16
    sbc #$0070
    cmp a:$00AA,Y
    bcs prepare_boss_sprite_screen_position_c22054
    lda $91
    clc
    adc a:$00C2,Y
    sta $91
prepare_boss_sprite_screen_position_c22054:
    lda a:$0098,X
    .a16
    bit #$0020
    bne prepare_boss_sprite_screen_position_c22061
    lda $91
    sta a:$0022,X
prepare_boss_sprite_screen_position_c22061:
    lda a:$0066,X
    lsr
    sep #$20
    sta a:$0045,X
    rep #$20
    rts
