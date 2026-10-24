; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-subsystem-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1

.segment "CODE"
.org $CB57
initialize_native_thirty_two_entry_four_byte_resource_table:
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
    ldx #$0080
    jsr allocate_and_fill_bytes
    stx a:$0302
    plb
    plp
    pld
    rts
