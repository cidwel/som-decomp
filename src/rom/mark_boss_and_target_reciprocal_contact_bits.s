; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3CAB
mark_boss_and_target_reciprocal_contact_bits:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    txa
    sec
    .a16
    sbc #$E600
    lsr
    xba
    tax
    sep #$20
    lda f:$C205F0,X
    ora a:$0059,Y
    sta a:$0059,Y
    rep #$20
    ldx $87
    tya
    sec
    .a16
    sbc #$E000
    lsr
    xba
    tax
    ldy $87
    sep #$20
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    ldx $87
    rts
