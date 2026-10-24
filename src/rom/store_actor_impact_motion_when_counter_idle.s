; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4F6E
store_actor_impact_motion_when_counter_idle:
    pha
    lda a:$E175,X
    beq store_actor_impact_motion_when_counter_idle_c04f76
    pla
    rts
store_actor_impact_motion_when_counter_idle_c04f76:
    pla
    sta a:$E1E5,X
    rts
