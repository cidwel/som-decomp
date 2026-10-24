; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5D17
format_five_native_saved_slot_decimal_digits_via_hardware_division:
    phx
    .i16
    ldx #$0000
    .a8
    lda #$0D
format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d1d:
    stz a:$A22F,X
    inx
    dec
    bne format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d1d
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    cpy #$0000
    beq format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d5f
    .i16
    ldx #$000B
    .a8
    lda #$05
format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d33:
    xba
    sty a:$4204
    .a8
    lda #$0A
    sta a:$4206
    dex
    .a8
    lda #$B5
    .i16
    cpy #$0000
    beq format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d65
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    clc
    adc a:$4216
    sta f:$7EA22F,X
    ldy a:$4214
    xba
    dec
    bne format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d33
    bra format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d65
format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d5f:
    .a8
    lda #$B5
    sta f:$7EA239
format_five_native_saved_slot_decimal_digits_via_hardware_division_c75d65:
    plb
    plx
    rts
