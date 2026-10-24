; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

divide_native_status_field_and_return_hardware_quotient = $6BA5

.segment "CODE"
.org $684D
scale_native_status_bar_fields_with_shift_or_mode7_product:
    phb
    .a8
    lda #$00
    pha
    plb
    lda f:$7EA175
    .a8
    cmp #$05
    beq scale_native_status_bar_fields_with_shift_or_mode7_product_c76872
    .a8
    cmp #$07
    beq scale_native_status_bar_fields_with_shift_or_mode7_product_c76862
    .a8
    cmp #$09
    bne scale_native_status_bar_fields_with_shift_or_mode7_product_c7688e
scale_native_status_bar_fields_with_shift_or_mode7_product_c76862:
    .a8
    lda #$00
    pha
    plb
    dey
    rep #$20
    tya
    lsr
    lsr
    lsr
    tay
    sep #$20
    bra scale_native_status_bar_fields_with_shift_or_mode7_product_c7688e
scale_native_status_bar_fields_with_shift_or_mode7_product_c76872:
    .a8
    lda #$00
    pha
    plb
    tya
    sta a:$211B
    xba
    sta a:$211B
    .a8
    lda #$0A
    sta a:$211C
    ldy a:$2134
    .a8
    lda #$10
    sta a:$211C
    jsr divide_native_status_field_and_return_hardware_quotient
scale_native_status_bar_fields_with_shift_or_mode7_product_c7688e:
    plb
    rts
