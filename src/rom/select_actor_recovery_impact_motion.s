; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

store_actor_impact_motion_when_counter_idle = $4F6E

.segment "CODE"
.org $4F4F
select_actor_recovery_impact_motion:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$C578
    sep #$20
    bne select_actor_recovery_impact_motion_c04f67
    lda a:$E1FB,X
    .a8
    bit #$81
    bne select_actor_recovery_impact_motion_c04f68
    .a8
    lda #$12
    jsr store_actor_impact_motion_when_counter_idle
select_actor_recovery_impact_motion_c04f67:
    rts
select_actor_recovery_impact_motion_c04f68:
    .a8
    lda #$2B
    jsr store_actor_impact_motion_when_counter_idle
    rts
