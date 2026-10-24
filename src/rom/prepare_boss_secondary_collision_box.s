; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0779
prepare_boss_secondary_collision_box:
    lda a:$00C2,X
    beq prepare_boss_secondary_collision_box_c207c5
    lda a:$002B,X
    sta $5E
    lda a:$0066,X
    lsr
    .a16
    eor #$FFFF
    inc
    clc
    adc a:$0032,X
    sta $60
    lda a:$0066,X
    sta $64
    txy
    sep #$20
    .i16
    ldx #$0000
prepare_boss_secondary_collision_box_c2079c:
    lda a:$00C0,Y
    sta $56,X
    bpl prepare_boss_secondary_collision_box_c207a9
    .a8
    lda #$FF
    sta $57,X
    bra prepare_boss_secondary_collision_box_c207ab
prepare_boss_secondary_collision_box_c207a9:
    stz $57,X
prepare_boss_secondary_collision_box_c207ab:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_boss_secondary_collision_box_c2079c
    rep #$20
    lda $5E
    clc
    adc $56
    sta $56
    lda $60
    clc
    adc $58
    sta $58
    clc
    rts
prepare_boss_secondary_collision_box_c207c5:
    sec
    rts
