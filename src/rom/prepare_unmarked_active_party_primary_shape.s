; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0855
prepare_unmarked_active_party_primary_shape:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0000,Y
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne prepare_unmarked_active_party_primary_shape_c208ba
    sep #$20
    ldx $8B
    lda f:$C205F0,X
    and a:$005A,Y
    rep #$20
    bne prepare_unmarked_active_party_primary_shape_c208ba
    lda a:$00C2,Y
    beq prepare_unmarked_active_party_primary_shape_c208ba
    lda a:$0002,Y
    sta $5E
    lda a:$0004,Y
    sta $60
    lda a:$0045,Y
    asl
    sta $64
    sep #$20
    .i16
    ldx #$0000
prepare_unmarked_active_party_primary_shape_c20891:
    lda a:$00C0,Y
    sta $56,X
    bpl prepare_unmarked_active_party_primary_shape_c2089e
    .a8
    lda #$FF
    sta $57,X
    bra prepare_unmarked_active_party_primary_shape_c208a0
prepare_unmarked_active_party_primary_shape_c2089e:
    stz $57,X
prepare_unmarked_active_party_primary_shape_c208a0:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_unmarked_active_party_primary_shape_c20891
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
prepare_unmarked_active_party_primary_shape_c208ba:
    sec
    rts
