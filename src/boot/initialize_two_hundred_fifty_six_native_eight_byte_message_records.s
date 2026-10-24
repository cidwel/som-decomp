; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-subsystem-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1

.segment "CODE"
.org $B129
initialize_two_hundred_fifty_six_native_eight_byte_message_records:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .a8
    lda #$00
    .i16
    ldx #$0800
    jsr allocate_and_fill_bytes
    stx a:$02C4
    stx a:$02C6
    .i16
    ldy #$00FF
    rep #$20
initialize_two_hundred_fifty_six_native_eight_byte_message_records_b147:
    txa
    clc
    .a16
    adc #$0008
    sta a:$0000,X
    tax
    dey
    bne initialize_two_hundred_fifty_six_native_eight_byte_message_records_b147
    stz a:$0000,X
    plb
    plp
    pld
    rts
