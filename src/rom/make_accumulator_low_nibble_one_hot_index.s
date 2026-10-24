; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-index-bits.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4708
make_accumulator_low_nibble_one_hot_index:
    phd
    php
    rep #$30
    .a16
    and #$000F
    tax
    .a16
    lda #$0001
    .i16
    cpx #$0000
    beq make_accumulator_low_nibble_one_hot_index_c1471c
make_accumulator_low_nibble_one_hot_index_c14718:
    asl
    dex
    bne make_accumulator_low_nibble_one_hot_index_c14718
make_accumulator_low_nibble_one_hot_index_c1471c:
    tax
    plp
    pld
    rts
