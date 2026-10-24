; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-cells.md.
.setcpu "65816"
.smart
.a8
.i16

deliver_native_actor_effect_cell_hit_or_reflected_target = $8E74
steer_native_actor_effect_toward_target_with_fractional_sine_motion = $8E93

.segment "CODE"
.org $8DDE
advance_native_actor_effect_cell_toward_live_target:
    sty $00
    rep #$20
    txa
    ora $00
    tay
    sep #$20
    lda a:$E110,Y
    beq advance_native_actor_effect_cell_toward_live_target_c18df6
    lda a:$E114,Y
    beq advance_native_actor_effect_cell_toward_live_target_c18df7
    dec
    sta a:$E114,Y
advance_native_actor_effect_cell_toward_live_target_c18df6:
    rts
advance_native_actor_effect_cell_toward_live_target_c18df7:
    lda a:$E113,Y
    cmp a:$E115,Y
    bcs advance_native_actor_effect_cell_toward_live_target_c18e04
    inc
    inc
    sta a:$E113,Y
advance_native_actor_effect_cell_toward_live_target_c18e04:
    phy
    lda a:$E117,Y
    xba
    .a8
    lda #$00
    tay
    lda a:$E000,Y
    beq advance_native_actor_effect_cell_toward_live_target_c18e13
    bpl advance_native_actor_effect_cell_toward_live_target_c18e1a
advance_native_actor_effect_cell_toward_live_target_c18e13:
    .a8
    lda #$00
    ply
    sta a:$E110,Y
    rts
advance_native_actor_effect_cell_toward_live_target_c18e1a:
    ply
    rep #$20
    lda a:$E112,Y
    sta $02
    lda a:$E11C,Y
    .a16
    and #$0F0F
    sta $0C
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
    clc
    adc a:$E11A,Y
    sta $06
    lda a:$E116,Y
    phy
    tay
    jsr steer_native_actor_effect_toward_target_with_fractional_sine_motion
    ply
    bcc deliver_native_actor_effect_cell_hit_or_reflected_target
    rep #$20
    lda $02
    sta a:$E112,Y
    lda $0C
    sta a:$E11C,Y
    lda $04
    clc
    adc a:$E118,Y
    sta a:$E118,Y
    lda $06
    clc
    adc a:$E11A,Y
    sta a:$E11A,Y
    rts
