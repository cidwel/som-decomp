; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-entry.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8820 = $8820

.segment "CODE"
.org $8EE0
expand_selected_native_interface_overlay_row:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    txy
    .i16
    ldx #$01A2
    .a16
    and #$00FF
    bne expand_selected_native_interface_overlay_row_8efb
    .i16
    ldx #$019E
expand_selected_native_interface_overlay_row_8efb:
    clc
    tya
    .a16
    adc #$03C0
    tay
    jsr routine_7e8820
    plb
    plp
    pld
    rts
