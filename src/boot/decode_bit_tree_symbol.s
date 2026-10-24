; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A14E
decode_bit_tree_symbol:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda a:$0000,X
    sta $01
    lda a:$0002,X
    sta $03
    ldy a:$008A
decode_bit_tree_symbol_a166:
    lda a:$0006,X
    .a16
    bit #$00FF
    bne decode_bit_tree_symbol_a17f
    clc
    .a16
    adc #$0010
    sta a:$0006,X
    lda [$01]
    xba
    sta a:$0004,X
    inc $01
    inc $01
decode_bit_tree_symbol_a17f:
    dec a:$0006,X
    asl a:$0004,X
    bcc decode_bit_tree_symbol_a189
    iny
    iny
decode_bit_tree_symbol_a189:
    lda a:$0000,Y
    tay
    lda a:$0000,Y
    .a16
    bit #$FF00
    bne decode_bit_tree_symbol_a166
    tay
    lda $01
    sta a:$0000,X
    tya
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
