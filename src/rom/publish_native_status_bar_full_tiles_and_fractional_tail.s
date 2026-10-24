; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $681F
publish_native_status_bar_full_tiles_and_fractional_tail:
    pha
    .i16
    cpy #$0000
    beq publish_native_status_bar_full_tiles_and_fractional_tail_c7682b
publish_native_status_bar_full_tiles_and_fractional_tail_c76825:
    stx a:$2118
    dey
    bne publish_native_status_bar_full_tiles_and_fractional_tail_c76825
publish_native_status_bar_full_tiles_and_fractional_tail_c7682b:
    pla
    beq publish_native_status_bar_full_tiles_and_fractional_tail_c7684c
    asl
    sta f:$7EA173
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
    adc f:$7EA173
    clc
    .a16
    adc #$2030
    sta a:$2118
publish_native_status_bar_full_tiles_and_fractional_tail_c7684c:
    rts
