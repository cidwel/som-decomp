; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $52F0
mark_boss_contact_by_target_index_and_target_by_boss_index:
    lda a:$00A9,X
    txy
    tax
    sep #$20
    lda f:$C205F0,X
    ora a:$0059,Y
    sta a:$0059,Y
    rep #$20
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda $87
    sec
    .a16
    sbc #$E600
    lsr
    xba
    tax
    sep #$20
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    ldx $87
    rts
