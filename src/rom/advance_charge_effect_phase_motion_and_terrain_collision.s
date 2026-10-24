; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16

read_charge_effect_terrain_or_start_actual_tile_event = $C183
test_charge_effect_contact_or_transfer_native_homing_continuation = $C526

.segment "CODE"
.org $C26C
advance_charge_effect_phase_motion_and_terrain_collision:
    sep #$20
    lda a:$D000,Y
    bne advance_charge_effect_phase_motion_and_terrain_collision_c2c274
    rts
advance_charge_effect_phase_motion_and_terrain_collision_c2c274:
    .a8
    bit #$F8
    beq advance_charge_effect_phase_motion_and_terrain_collision_c2c27f
    sec
    .a8
    sbc #$08
    sta a:$D000,Y
    rts
advance_charge_effect_phase_motion_and_terrain_collision_c2c27f:
    lda a:$D007,Y
    beq advance_charge_effect_phase_motion_and_terrain_collision_c2c28e
    dec
    sta a:$D007,Y
    bne advance_charge_effect_phase_motion_and_terrain_collision_c2c28d
    sta a:$D000,Y
advance_charge_effect_phase_motion_and_terrain_collision_c2c28d:
    rts
advance_charge_effect_phase_motion_and_terrain_collision_c2c28e:
    jsr test_charge_effect_contact_or_transfer_native_homing_continuation
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c29b
    jsr read_charge_effect_terrain_or_start_actual_tile_event
    cmp a:$D006,Y
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c29e
advance_charge_effect_phase_motion_and_terrain_collision_c2c29b:
    brl advance_charge_effect_phase_motion_and_terrain_collision_c2c312
advance_charge_effect_phase_motion_and_terrain_collision_c2c29e:
    lda a:$D008,Y
    clc
    adc a:$D00A,Y
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c2ae
    .a8
    lda #$00
    sta a:$D00A,Y
    .a8
    lda #$FF
advance_charge_effect_phase_motion_and_terrain_collision_c2c2ae:
    sta a:$D008,Y
    lda a:$D009,Y
    clc
    adc a:$D00A,Y
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c2bc
    .a8
    lda #$FF
advance_charge_effect_phase_motion_and_terrain_collision_c2c2bc:
    sta a:$D009,Y
    phx
    rep #$20
    .a16
    and #$00FF
    .a16
    cmp #$0080
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c2cd
    .a16
    eor #$00FF
advance_charge_effect_phase_motion_and_terrain_collision_c2c2cd:
    asl
    asl
    tax
    lda f:$00FD22,X
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    sta $00
    lda a:$D008,Y
    .a16
    and #$00FF
    asl
    tax
    lda f:$00FD22,X
    plx
    lsr
    lsr
    lsr
    lsr
    lsr
    sep #$20
    .a8
    eor #$FF
    sec
    .a8
    adc #$08
    sta $01
    .a8
    lda #$04
    sec
    sbc $00
    sta $00
    lda a:$D000,Y
    .a8
    cmp #$03
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c338
    lda a:$D009,Y
    bpl advance_charge_effect_phase_motion_and_terrain_collision_c2c321
    lda a:$D006,Y
    sec
    sbc $00
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c32c
advance_charge_effect_phase_motion_and_terrain_collision_c2c312:
    .a8
    lda #$08
    sta a:$D007,Y
    lda a:$D00E,Y
    clc
    .a8
    adc #$02
    sta a:$D00E,Y
    rts
advance_charge_effect_phase_motion_and_terrain_collision_c2c321:
    lda $00
    lsr
    clc
    adc $00
    sta $00
    adc a:$D006,Y
advance_charge_effect_phase_motion_and_terrain_collision_c2c32c:
    sta a:$D006,Y
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c338
    lda $00
    .a8
    eor #$FF
    inc
    sta $00
advance_charge_effect_phase_motion_and_terrain_collision_c2c338:
    lda a:$D001,Y
    .a8
    and #$03
    .a8
    cmp #$02
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c395
    lda a:$D000,Y
    .a8
    cmp #$03
    lda $00
    rep #$20
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c36b
    bpl advance_charge_effect_phase_motion_and_terrain_collision_c2c35b
    .a16
    ora #$FF00
    clc
    adc a:$D004,Y
    bpl advance_charge_effect_phase_motion_and_terrain_collision_c2c368
    adc $C2
    bra advance_charge_effect_phase_motion_and_terrain_collision_c2c368
advance_charge_effect_phase_motion_and_terrain_collision_c2c35b:
    .a16
    and #$00FF
    clc
    adc a:$D004,Y
    cmp $C2
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c368
    sbc $C2
advance_charge_effect_phase_motion_and_terrain_collision_c2c368:
    sta a:$D004,Y
advance_charge_effect_phase_motion_and_terrain_collision_c2c36b:
    lda a:$D001,Y
    lsr
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c382
    lda $01
    .a16
    and #$00FF
    .a16
    eor #$FFFF
    adc a:$D002,Y
    bpl advance_charge_effect_phase_motion_and_terrain_collision_c2c391
    adc $C0
    bra advance_charge_effect_phase_motion_and_terrain_collision_c2c391
advance_charge_effect_phase_motion_and_terrain_collision_c2c382:
    lda $01
    .a16
    and #$00FF
    clc
    adc a:$D002,Y
    cmp $C0
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c391
    sbc $C0
advance_charge_effect_phase_motion_and_terrain_collision_c2c391:
    sta a:$D002,Y
    rts
advance_charge_effect_phase_motion_and_terrain_collision_c2c395:
    lda a:$D001,Y
    lsr
    rep #$20
    bcs advance_charge_effect_phase_motion_and_terrain_collision_c2c3ae
    lda $01
    .a16
    and #$00FF
    .a16
    eor #$FFFF
    adc a:$D004,Y
    bpl advance_charge_effect_phase_motion_and_terrain_collision_c2c3bd
    adc $C2
    bra advance_charge_effect_phase_motion_and_terrain_collision_c2c3bd
advance_charge_effect_phase_motion_and_terrain_collision_c2c3ae:
    lda $01
    .a16
    and #$00FF
    clc
    adc a:$D004,Y
    cmp $C2
    bcc advance_charge_effect_phase_motion_and_terrain_collision_c2c3bd
    sbc $C2
advance_charge_effect_phase_motion_and_terrain_collision_c2c3bd:
    sta a:$D004,Y
    rts
