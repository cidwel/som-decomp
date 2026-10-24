; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-byte-port-math.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2C0A
multiply_signed_bytes_through_mode7_ports:
    lda $46
    php
    sta f:$00211B
    lda $C5
    plp
    bpl multiply_signed_bytes_through_mode7_ports_c22c18
    .a8
    lda #$FF
multiply_signed_bytes_through_mode7_ports_c22c18:
    sta f:$00211B
    lda $4E
    sta f:$00211C
    lda f:$002134
    sta $56
    lda f:$002135
    sta $57
    rts
