; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9368
derive_world_map_ui_curve_coefficients_and_fraction_bytes:
    rep #$30
    sta $00
    .a16
    and #$00FF
    asl
    tay
    .a16
    eor #$01FE
    inc
    inc
    tax
    .a16
    lda #$0100
    bit $00
    beq derive_world_map_ui_curve_coefficients_and_fraction_bytes_c09382
    phy
    phx
    ply
    plx
derive_world_map_ui_curve_coefficients_and_fraction_bytes_c09382:
    lda a:$FD22,Y
    sta $30
    lsr
    lsr
    adc $30
    lsr
    tay
    lda a:$FD22,X
    sta $32
    lsr
    lsr
    adc $32
    lsr
    tax
    sep #$10
    sty $34
    stx $35
    rts
