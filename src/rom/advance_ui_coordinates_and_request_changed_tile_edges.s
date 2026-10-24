; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-coordinate-contract.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0869b = $869B

.segment "CODE"
.org $8638
advance_ui_coordinates_and_request_changed_tile_edges:
    jsr routine_c0869b
    sep #$30
    .i8
    ldx #$00
    txy
    lda $5F
    .a8
    and #$04
    rep #$20
    beq advance_ui_coordinates_and_request_changed_tile_edges_c08658
    lda $FC
    clc
    adc $68
    sta $FC
    lda $FA
    clc
    adc $66
    sta $FA
    bra advance_ui_coordinates_and_request_changed_tile_edges_c08666
advance_ui_coordinates_and_request_changed_tile_edges_c08658:
    lda $FC
    sec
    sbc $68
    sta $FC
    lda $FA
    sec
    sbc $66
    sta $FA
advance_ui_coordinates_and_request_changed_tile_edges_c08666:
    lda $FA
    .a16
    and #$FFF8
    cmp $70
    beq advance_ui_coordinates_and_request_changed_tile_edges_c0867e
    sta $70
    bmi advance_ui_coordinates_and_request_changed_tile_edges_c0867c
    .i8
    ldx #$01
    bcs advance_ui_coordinates_and_request_changed_tile_edges_c0867e
    .a16
    cmp #$0000
    beq advance_ui_coordinates_and_request_changed_tile_edges_c0867e
advance_ui_coordinates_and_request_changed_tile_edges_c0867c:
    .i8
    ldx #$02
advance_ui_coordinates_and_request_changed_tile_edges_c0867e:
    lda $FC
    .a16
    and #$FFF8
    cmp $72
    beq advance_ui_coordinates_and_request_changed_tile_edges_c08696
    sta $72
    bmi advance_ui_coordinates_and_request_changed_tile_edges_c08694
    .i8
    ldy #$01
    bcs advance_ui_coordinates_and_request_changed_tile_edges_c08696
    .a16
    cmp #$0000
    beq advance_ui_coordinates_and_request_changed_tile_edges_c08696
advance_ui_coordinates_and_request_changed_tile_edges_c08694:
    .i8
    ldy #$02
advance_ui_coordinates_and_request_changed_tile_edges_c08696:
    stx $2F
    sty $2E
    rts
