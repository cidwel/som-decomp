; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

select_zero_hp_actor_impact_motion = $4EA9
store_actor_impact_motion_when_counter_idle = $4F6E

.segment "CODE"
.org $4EBC
select_actor_hp_damage_impact_motion:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$C578
    sep #$20
    bne select_actor_hp_damage_impact_motion_c04f1d
    .a8
    lda #$01
    sta $AC
    .a8
    lda #$0D
    sta $A4
    lda a:$E1FB,X
    .a8
    bit #$81
    bne select_actor_hp_damage_impact_motion_c04edb
    .a8
    lda #$08
    sta $A4
select_actor_hp_damage_impact_motion_c04edb:
    rep #$20
    lda a:$E182,X
    beq select_zero_hp_actor_impact_motion
    lda a:$E184,X
    lsr
    lsr
    sta $A8
    cmp $89
    bcs select_actor_hp_damage_impact_motion_c04ef1
    inc $A4
    asl $AC
select_actor_hp_damage_impact_motion_c04ef1:
    lda $89
    lsr
    lsr
    lsr
    sep #$20
    .a8
    cmp #$06
    bcs select_actor_hp_damage_impact_motion_c04efe
    .a8
    lda #$06
select_actor_hp_damage_impact_motion_c04efe:
    sta $AA
    lda $A4
    jsr store_actor_impact_motion_when_counter_idle
    lda a:$E190,X
    .a8
    and #$FC
    ora $AC
    sta a:$E190,X
    lda a:$E1FB,X
    bpl select_actor_hp_damage_impact_motion_c04f18
    .a8
    lda #$01
    bra select_actor_hp_damage_impact_motion_c04f1a
select_actor_hp_damage_impact_motion_c04f18:
    lda $AA
select_actor_hp_damage_impact_motion_c04f1a:
    sta a:$E1B4,X
select_actor_hp_damage_impact_motion_c04f1d:
    rts
