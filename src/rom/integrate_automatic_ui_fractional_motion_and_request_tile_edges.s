; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-radial.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c08648 = $8648

.segment "CODE"
.org $8DEE
integrate_automatic_ui_fractional_motion_and_request_tile_edges:
    rep #$30
    lda $84
    clc
    adc $86
    tax
    lda $88
    clc
    adc $8A
    sep #$20
    sta $8A
    xba
    sta $00
    rep #$20
    txa
    sep #$30
    sta $86
    .a8
    lda #$00
    xba
    .a8
    and #$0F
    bit $8D
    rep #$20
    bpl integrate_automatic_ui_fractional_motion_and_request_tile_edges_c08e18
    .a16
    eor #$FFFF
    inc
integrate_automatic_ui_fractional_motion_and_request_tile_edges_c08e18:
    sta $66
    .a16
    lda #$0000
    sep #$20
    lda $00
    .a8
    and #$0F
    bit $8D
    rep #$20
    bvc integrate_automatic_ui_fractional_motion_and_request_tile_edges_c08e2d
    .a16
    eor #$FFFF
    inc
integrate_automatic_ui_fractional_motion_and_request_tile_edges_c08e2d:
    sta $68
    sep #$10
    rep #$20
    .a16
    lda #$0000
    tax
    tay
    jmp routine_c08648
