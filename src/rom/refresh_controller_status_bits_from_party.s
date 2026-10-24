; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3F2C
refresh_controller_status_bits_from_party:
    lda a:$CC6D
    sta a:$00EE
    lda a:$CC6E
    sta a:$00EF
    lda a:$CC6F
    sta a:$00F0
    stz $B4
    .a8
    lda #$04
    sta $B5
    .a8
    lda #$00
    xba
refresh_controller_status_bits_from_party_c03f47:
    ldy $B4
    lda a:$E190,Y
    bpl refresh_controller_status_bits_from_party_c03f62
    lda a:$E02C,Y
    beq refresh_controller_status_bits_from_party_c03f62
    dec
    .a8
    cmp #$03
    bne refresh_controller_status_bits_from_party_c03f59
    dec
refresh_controller_status_bits_from_party_c03f59:
    tay
    lda a:$00EE,Y
    .a8
    eor #$03
    sta a:$00EE,Y
refresh_controller_status_bits_from_party_c03f62:
    dec $B5
    dec $B5
    bpl refresh_controller_status_bits_from_party_c03f47
    rts
