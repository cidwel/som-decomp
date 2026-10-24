; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

store_actor_impact_motion_when_counter_idle = $4F6E

.segment "CODE"
.org $4F1E
select_actor_mp_damage_impact_motion:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$C578
    sep #$20
    bne select_actor_mp_damage_impact_motion_c04f4e
    .a8
    lda #$08
    sta $A4
    lda a:$E1FB,X
    .a8
    bit #$81
    beq select_actor_mp_damage_impact_motion_c04f39
    .a8
    lda #$0D
    sta $A4
select_actor_mp_damage_impact_motion_c04f39:
    lda a:$E187,X
    lsr
    lsr
    cmp $89
    bcs select_actor_mp_damage_impact_motion_c04f44
    inc $A4
select_actor_mp_damage_impact_motion_c04f44:
    lda $A4
    jsr store_actor_impact_motion_when_counter_idle
    .a8
    lda #$03
    sta a:$E1B4,X
select_actor_mp_damage_impact_motion_c04f4e:
    rts
