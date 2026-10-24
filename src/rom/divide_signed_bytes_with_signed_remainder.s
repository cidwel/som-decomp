; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-byte-port-math.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_byte_through_cpu_ports = $2C91

.segment "CODE"
.org $2D2E
divide_signed_bytes_with_signed_remainder:
    lda $46
    pha
    eor $4E
    pha
    lda $46
    bpl divide_signed_bytes_with_signed_remainder_c22d3f
    sec
    lda $C5
    sbc $46
    sta $46
divide_signed_bytes_with_signed_remainder_c22d3f:
    lda $4E
    bpl divide_signed_bytes_with_signed_remainder_c22d4a
    sec
    lda $C5
    sbc $4E
    sta $4E
divide_signed_bytes_with_signed_remainder_c22d4a:
    jsr divide_unsigned_byte_through_cpu_ports
    bne divide_signed_bytes_with_signed_remainder_c22d64
    pla
    bpl divide_signed_bytes_with_signed_remainder_c22d59
    sec
    lda $C5
    sbc $56
    sta $56
divide_signed_bytes_with_signed_remainder_c22d59:
    pla
    bpl divide_signed_bytes_with_signed_remainder_c22d63
    sec
    lda $C5
    sbc $5E
    sta $5E
divide_signed_bytes_with_signed_remainder_c22d63:
    rts
divide_signed_bytes_with_signed_remainder_c22d64:
    pla
    pla
    .a8
    lda #$FF
    rts
