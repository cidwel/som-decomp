; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16

advance_charge_effect_phase_motion_and_terrain_collision = $C26C

.segment "CODE"
.org $C221
update_all_three_actor_charge_effect_records:
    rep #$20
    txa
    lsr
    lsr
    lsr
    tay
    sep #$20
    lda a:$D000,Y
    ora a:$D010,Y
    ora a:$D020,Y
    beq update_all_three_actor_charge_effect_records_c2c23a
    lda a:$E060,X
    bpl update_all_three_actor_charge_effect_records_c2c24e
update_all_three_actor_charge_effect_records_c2c23a:
    stz a:$E061,X
    stz a:$E19B,X
    .a8
    lda #$64
    sec
    sbc a:$E189,X
    lsr
    clc
    .a8
    adc #$32
    sta a:$E1ED,X
    rtl
update_all_three_actor_charge_effect_records_c2c24e:
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    pha
    jsr advance_charge_effect_phase_motion_and_terrain_collision
    rep #$20
    pla
    tay
    clc
    .a16
    adc #$0010
    pha
    jsr advance_charge_effect_phase_motion_and_terrain_collision
    rep #$20
    ply
    jsr advance_charge_effect_phase_motion_and_terrain_collision
    rtl
