; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C148
prepare_actor_charge_effect_velocity:
    sep #$20
    lda a:$E19B,X
    .a8
    eor #$FF
    sec
    .a8
    adc #$0E
    sta a:$D00A,Y
    .a8
    lda #$00
    sta a:$D008,Y
    lda a:$D000,Y
    dec
    beq prepare_actor_charge_effect_velocity_c2c167
    dec
    beq prepare_actor_charge_effect_velocity_c2c16b
    .a8
    lda #$00
    bra prepare_actor_charge_effect_velocity_c2c16d
prepare_actor_charge_effect_velocity_c2c167:
    .a8
    lda #$50
    bra prepare_actor_charge_effect_velocity_c2c16d
prepare_actor_charge_effect_velocity_c2c16b:
    .a8
    lda #$30
prepare_actor_charge_effect_velocity_c2c16d:
    sta a:$D009,Y
    rts
