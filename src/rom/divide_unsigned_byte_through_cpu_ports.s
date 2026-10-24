; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-byte-port-math.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2C91
divide_unsigned_byte_through_cpu_ports:
    lda $46
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    lda $4E
    beq divide_unsigned_byte_through_cpu_ports_c22cbc
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004214
    sta $56
    lda f:$004216
    sta $5E
    lda $C5
    rts
divide_unsigned_byte_through_cpu_ports_c22cbc:
    .a8
    lda #$FF
    rts
