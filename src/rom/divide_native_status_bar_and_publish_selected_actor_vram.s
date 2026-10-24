; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

divide_native_status_field_and_return_hardware_quotient = $6BA5
publish_native_status_bar_full_tiles_and_fractional_tail = $681F

.segment "CODE"
.org $67E6
divide_native_status_bar_and_publish_selected_actor_vram:
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$10
    jsr divide_native_status_field_and_return_hardware_quotient
    rep #$20
    lda f:$7EA1C7
    pha
    sta a:$2116
    lda a:$19FE
    .a16
    and #$00FF
    clc
    .a16
    adc #$0003
    xba
    asl
    asl
    clc
    .a16
    adc #$204E
    tax
    lda a:$4216
    jsr publish_native_status_bar_full_tiles_and_fractional_tail
    pla
    clc
    .a16
    adc #$0040
    sta f:$7EA1C7
    sep #$20
    plb
    rts
