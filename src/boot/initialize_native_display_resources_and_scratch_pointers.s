; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-subsystem-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
routine_7eb081 = $B081

.segment "CODE"
.org $8F08
initialize_native_display_resources_and_scratch_pointers:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    ldx #$0200
    .a8
    lda #$00
    jsr allocate_and_fill_bytes
    stx a:$0064
    .a8
    lda #$00
    .i16
    ldx #$0060
    jsr allocate_and_fill_bytes
    stx a:$0066
    rep #$20
    clc
    txa
    .a16
    adc #$0040
    tax
    stx a:$0068
    .i16
    ldx #$00C0
    jsr routine_7eb081
    stx a:$006A
    stz a:$006C
    plb
    plp
    pld
    rts
