; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5F60
construct_linked_child_six_piece_strip_records:
    ldy $87
    lda a:$007A,Y
    xba
    asl
    sta $06
    ldx $89
    .a16
    lda #$0006
    sta a:$0000,X
    inx
    .a16
    lda #$F7F8
    sta a:$0000,X
    .a16
    lda #$1AA0
    sta a:$0002,X
    inx
    inx
    inx
    inx
    .a16
    lda #$0003
    sta $08
construct_linked_child_six_piece_strip_records_c25f87:
    ldy $87
    lda a:$00B6,Y
    asl
    asl
    sta $04
    lda $08
    xba
    lsr
    lsr
    clc
    adc $04
    adc $06
    tay
    sep #$20
    lda a:$F501,Y
    sec
    .a8
    sbc #$08
    sta a:$0000,X
    lda a:$F503,Y
    sec
    .a8
    sbc #$08
    sta a:$0001,X
    rep #$20
    .a16
    lda #$1AA0
    sta a:$0002,X
    inx
    inx
    inx
    inx
    dec $08
    bpl construct_linked_child_six_piece_strip_records_c25f87
    ldy $87
    sep #$20
    lda a:$00B9,Y
    sec
    .a8
    sbc #$10
    sta a:$0000,X
    lda a:$00BB,Y
    sec
    .a8
    sbc #$10
    sta a:$0001,X
    rep #$20
    lda a:$00B4,Y
    sta a:$0002,X
    ldx $87
    rts
