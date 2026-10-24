; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-subsystem-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1

.segment "CODE"
.org $BB67
initialize_native_sixteen_screen_records_with_inactive_markers:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    ldx #$0400
    .a16
    lda #$0000
    jsr allocate_and_fill_bytes
    stx a:$02D2
    .i16
    ldy #$0010
initialize_native_sixteen_screen_records_with_inactive_markers_bb83:
    .a16
    lda #$8000
    sta a:$0000,X
    clc
    txa
    .a16
    adc #$0020
    tax
    dey
    bne initialize_native_sixteen_screen_records_with_inactive_markers_bb83
    plb
    plp
    pld
    rts
