; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_bit_tree_symbol = $A14E

.segment "CODE"
.org $A1A7
decode_signed_delta_or_zero_run:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$0007,X
    .a8
    bit #$80
    bne decode_signed_delta_or_zero_run_a1bf
    jsr decode_bit_tree_symbol
    sta a:$0007,X
decode_signed_delta_or_zero_run_a1bf:
    .a8
    bit #$80
    beq decode_signed_delta_or_zero_run_a1ce
    dec
    sta a:$0007,X
    .a8
    lda #$00
    xba
    .a8
    lda #$00
    bra decode_signed_delta_or_zero_run_a1de
decode_signed_delta_or_zero_run_a1ce:
    .a8
    bit #$40
    beq decode_signed_delta_or_zero_run_a1da
    .a8
    ora #$80
    xba
    .a8
    lda #$FF
    xba
    bra decode_signed_delta_or_zero_run_a1de
decode_signed_delta_or_zero_run_a1da:
    xba
    .a8
    lda #$00
    xba
decode_signed_delta_or_zero_run_a1de:
    plb
    plp
    pld
    rts
