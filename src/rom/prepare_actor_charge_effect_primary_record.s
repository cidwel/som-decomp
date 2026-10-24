; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

add_charge_effect_terrain_height = $C171
position_actor_charge_effect_in_wrapped_map = $C04D
prepare_actor_charge_effect_velocity = $C148

.segment "CODE"
.org $C021
prepare_actor_charge_effect_primary_record:
    sta a:$D000,Y
    lda a:$E010,X
    bpl prepare_actor_charge_effect_primary_record_c2c02b
    .a8
    lda #$03
prepare_actor_charge_effect_primary_record_c2c02b:
    sta a:$D001,Y
    lda a:$E00B,X
    .a8
    and #$80
    ora a:$D001,Y
    sta a:$D001,Y
    .a8
    lda #$00
    sta a:$D008,Y
    sta a:$D009,Y
    jsr position_actor_charge_effect_in_wrapped_map
    jsr add_charge_effect_terrain_height
    jsr prepare_actor_charge_effect_velocity
    sep #$20
    rts
