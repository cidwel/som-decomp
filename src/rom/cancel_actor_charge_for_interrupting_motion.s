; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

cancel_actor_charge_and_start_weapon_gauge = $CACD

.segment "CODE"
.org $CA58
cancel_actor_charge_for_interrupting_motion:
    sep #$20
    bit $5C
    bpl cancel_actor_charge_for_interrupting_motion_c1ca63
    .i16
    cpx #$0600
    bcs cancel_actor_charge_for_interrupting_motion_c1ca6b
cancel_actor_charge_for_interrupting_motion_c1ca63:
    lda a:$E01C,X
    bpl cancel_actor_charge_for_interrupting_motion_c1ca6b
    jsr cancel_actor_charge_and_start_weapon_gauge
cancel_actor_charge_for_interrupting_motion_c1ca6b:
    rts
