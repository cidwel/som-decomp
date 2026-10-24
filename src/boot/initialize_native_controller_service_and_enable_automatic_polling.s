; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-subsystem-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
detect_controller_interface = $A4E9

.segment "CODE"
.org $A2EB
initialize_native_controller_service_and_enable_automatic_polling:
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
    ldx #$0050
    jsr allocate_and_fill_bytes
    stx a:$0092
    jsr detect_controller_interface
    lda a:$0090
    .a8
    ora #$01
    sta a:$0090
    sta f:$004200
    plb
    plp
    pld
    rts
