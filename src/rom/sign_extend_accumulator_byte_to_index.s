; Recovered Secret of Mana USA routine; behaviour documented in docs/runtime-stack-copy.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $47EC
sign_extend_accumulator_byte_to_index:
    phd
    php
    rep #$30
    .a16
    bit #$0080
    beq sign_extend_accumulator_byte_to_index_c147fa
    .a16
    ora #$FF00
    bra sign_extend_accumulator_byte_to_index_c147fd
sign_extend_accumulator_byte_to_index_c147fa:
    .a16
    and #$00FF
sign_extend_accumulator_byte_to_index_c147fd:
    tax
    plp
    pld
    rts
