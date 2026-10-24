; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

deliver_complete_cast_hit_to_target = $8D12

.segment "CODE"
.org $894D
advance_native_homing_cast_cell_and_deliver_target:
    .a8
    lda #$05
    sta a:$E124,X
    lda a:$E11E,X
    sta $0E
    sec
    .a8
    sbc #$10
    bpl advance_native_homing_cast_cell_and_deliver_target_c1895e
    .a8
    lda #$20
advance_native_homing_cast_cell_and_deliver_target_c1895e:
    sta $0C
    stz $0D
    stz $0F
    rep #$20
    txa
    ora $0C
    tay
    lda a:$E118,Y
    clc
    adc a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc a:$E022,X
    adc a:$E11A,Y
    sta $06
    phy
    ldy a:$E116,X
    lda a:$E074,Y
    .a16
    and #$007F
    clc
    adc a:$E045,Y
    .a16
    eor #$FFFF
    sec
    adc a:$E022,Y
    sec
    sbc $06
    sta $06
    lda a:$E020,Y
    sec
    sbc $04
    sta $04
    ply
    phx
    txa
    ora $0E
    tax
    lda $04
    bpl advance_native_homing_cast_cell_and_deliver_target_c189bf
    .a16
    cmp #$FFE2
    bcs advance_native_homing_cast_cell_and_deliver_target_c189c7
    .a16
    lda #$FFE2
    bra advance_native_homing_cast_cell_and_deliver_target_c189c7
advance_native_homing_cast_cell_and_deliver_target_c189bf:
    .a16
    cmp #$001E
    bcc advance_native_homing_cast_cell_and_deliver_target_c189c7
    .a16
    lda #$001E
advance_native_homing_cast_cell_and_deliver_target_c189c7:
    clc
    adc a:$E118,Y
    sta a:$E118,X
    lda $06
    bpl advance_native_homing_cast_cell_and_deliver_target_c189dc
    .a16
    cmp #$FFE2
    bcs advance_native_homing_cast_cell_and_deliver_target_c189e4
    .a16
    lda #$FFE2
    bra advance_native_homing_cast_cell_and_deliver_target_c189e4
advance_native_homing_cast_cell_and_deliver_target_c189dc:
    .a16
    cmp #$001E
    bcc advance_native_homing_cast_cell_and_deliver_target_c189e4
    .a16
    lda #$001E
advance_native_homing_cast_cell_and_deliver_target_c189e4:
    clc
    adc a:$E11A,Y
    sta a:$E11A,X
    plx
    sep #$20
    lda a:$E11E,X
    clc
    .a8
    adc #$10
    .a8
    cmp #$30
    bcc advance_native_homing_cast_cell_and_deliver_target_c189fa
    .a8
    lda #$00
advance_native_homing_cast_cell_and_deliver_target_c189fa:
    sta a:$E11E,X
    rep #$20
    lda $04
    bpl advance_native_homing_cast_cell_and_deliver_target_c18a06
    .a16
    eor #$FFFF
advance_native_homing_cast_cell_and_deliver_target_c18a06:
    .a16
    cmp #$0008
    bcs advance_native_homing_cast_cell_and_deliver_target_c18a17
    lda $06
    bpl advance_native_homing_cast_cell_and_deliver_target_c18a12
    .a16
    eor #$FFFF
advance_native_homing_cast_cell_and_deliver_target_c18a12:
    .a16
    cmp #$0008
    bcc advance_native_homing_cast_cell_and_deliver_target_c18a24
advance_native_homing_cast_cell_and_deliver_target_c18a17:
    sep #$20
    ldy a:$E116,X
    lda a:$E000,Y
    beq advance_native_homing_cast_cell_and_deliver_target_c18a24
    bmi advance_native_homing_cast_cell_and_deliver_target_c18a24
    rts
advance_native_homing_cast_cell_and_deliver_target_c18a24:
    ldy a:$E116,X
    phx
    jsr deliver_complete_cast_hit_to_target
    plx
    stx $14
    bcs advance_native_homing_cast_cell_and_deliver_target_c18a51
    rep #$20
    lda a:$E126,X
    bpl advance_native_homing_cast_cell_and_deliver_target_c18a41
    stz a:$E110,X
    stz a:$E120,X
    stz a:$E130,X
    rts
advance_native_homing_cast_cell_and_deliver_target_c18a41:
    sta a:$E116,X
    lda a:$E136,X
    sta a:$E126,X
    .a16
    lda #$8000
    sta a:$E136,X
    rts
advance_native_homing_cast_cell_and_deliver_target_c18a51:
    rep #$20
    sta a:$E116,X
    sep #$20
    .a8
    lda #$80
    sta a:$E127,X
    sta a:$E137,X
    rts
