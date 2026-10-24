; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

process_actor_death_rewards_and_drop_conversion = $4203
select_actor_hp_damage_impact_motion = $4EBC
select_actor_mp_damage_impact_motion = $4F1E
select_actor_recovery_impact_motion = $4F4F
send_actor_impact_sound_with_facing_volume = $4157

.segment "CODE"
.org $4004
apply_pending_actor_hp_mp_damage_and_healing:
    lda a:$E1E5,X
    bpl apply_pending_actor_hp_mp_damage_and_healing_c0401a
    lda a:$E175,X
    bne apply_pending_actor_hp_mp_damage_and_healing_c0401a
    lda a:$E060,X
    .a8
    bit #$E0
    bne apply_pending_actor_hp_mp_damage_and_healing_c0401a
    lda a:$E191,X
    bpl apply_pending_actor_hp_mp_damage_and_healing_c0401b
apply_pending_actor_hp_mp_damage_and_healing_c0401a:
    rts
apply_pending_actor_hp_mp_damage_and_healing_c0401b:
    rep #$20
    lda a:$E1F3,X
    beq apply_pending_actor_hp_mp_damage_and_healing_c04053
    .a16
    lda #$03E7
    cmp a:$E1F3,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c0402d
    sta a:$E1F3,X
apply_pending_actor_hp_mp_damage_and_healing_c0402d:
    lda a:$E1F3,X
    clc
    adc a:$E182,X
    cmp a:$E184,X
    bcc apply_pending_actor_hp_mp_damage_and_healing_c0403c
    lda a:$E184,X
apply_pending_actor_hp_mp_damage_and_healing_c0403c:
    sta a:$E182,X
    lda a:$E1F3,X
    sta a:$E17B,X
    stz a:$E1F3,X
    sep #$20
    jsr select_actor_recovery_impact_motion
    .a8
    lda #$D8
    sta a:$E175,X
    rts
apply_pending_actor_hp_mp_damage_and_healing_c04053:
    rep #$20
    lda a:$E1F1,X
    bne apply_pending_actor_hp_mp_damage_and_healing_c0405d
    jmp apply_pending_actor_hp_mp_damage_and_healing_c040de
apply_pending_actor_hp_mp_damage_and_healing_c0405d:
    .a16
    lda #$03E7
    cmp a:$E1F1,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c04068
    sta a:$E1F1,X
apply_pending_actor_hp_mp_damage_and_healing_c04068:
    lda a:$E1B0,X
    .a16
    bit #$1000
    beq apply_pending_actor_hp_mp_damage_and_healing_c040ab
    sep #$20
    lda a:$E1F0,X
    bmi apply_pending_actor_hp_mp_damage_and_healing_c040ab
    lda a:$E1AF,X
    pha
    .a8
    lda #$2F
    sta a:$E1AF,X
    jsr send_actor_impact_sound_with_facing_volume
    pla
    sta a:$E1AF,X
    rep #$20
    lda a:$E1BD,X
    sec
    sbc a:$E1F1,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c04095
    .a16
    lda #$0000
apply_pending_actor_hp_mp_damage_and_healing_c04095:
    sta a:$E1BD,X
    bne apply_pending_actor_hp_mp_damage_and_healing_c040a3
    .a16
    lda #$EFFF
    and a:$E1B0,X
    sta a:$E1B0,X
apply_pending_actor_hp_mp_damage_and_healing_c040a3:
    rep #$20
    stz a:$E1F1,X
    sep #$20
    rts
apply_pending_actor_hp_mp_damage_and_healing_c040ab:
    sep #$20
    jsr send_actor_impact_sound_with_facing_volume
    rep #$20
    lda a:$E182,X
    sec
    sbc a:$E1F1,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c040be
    .a16
    lda #$0000
apply_pending_actor_hp_mp_damage_and_healing_c040be:
    sta a:$E182,X
    bne apply_pending_actor_hp_mp_damage_and_healing_c040c6
    jsr process_actor_death_rewards_and_drop_conversion
apply_pending_actor_hp_mp_damage_and_healing_c040c6:
    rep #$20
    lda a:$E1F1,X
    sta a:$E17B,X
    sta $89
    stz a:$E1F1,X
    sep #$20
    jsr select_actor_hp_damage_impact_motion
    .a8
    lda #$D0
    sta a:$E175,X
    rts
apply_pending_actor_hp_mp_damage_and_healing_c040de:
    sep #$20
    lda a:$E1F6,X
    beq apply_pending_actor_hp_mp_damage_and_healing_c0411c
    .a8
    lda #$63
    cmp a:$E1F6,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c040ef
    sta a:$E1F6,X
apply_pending_actor_hp_mp_damage_and_healing_c040ef:
    lda a:$E1F6,X
    clc
    adc a:$E186,X
    bcc apply_pending_actor_hp_mp_damage_and_healing_c040fa
    .a8
    lda #$63
apply_pending_actor_hp_mp_damage_and_healing_c040fa:
    cmp a:$E187,X
    bcc apply_pending_actor_hp_mp_damage_and_healing_c04102
    lda a:$E187,X
apply_pending_actor_hp_mp_damage_and_healing_c04102:
    sta a:$E186,X
    lda a:$E1F6,X
    sta a:$E17B,X
    stz a:$E17C,X
    stz a:$E1F6,X
    sep #$20
    jsr select_actor_recovery_impact_motion
    .a8
    lda #$E8
    sta a:$E175,X
    rts
apply_pending_actor_hp_mp_damage_and_healing_c0411c:
    lda a:$E1F5,X
    beq apply_pending_actor_hp_mp_damage_and_healing_c04156
    .a8
    lda #$63
    cmp a:$E1F5,X
    bcs apply_pending_actor_hp_mp_damage_and_healing_c0412b
    sta a:$E1F5,X
apply_pending_actor_hp_mp_damage_and_healing_c0412b:
    lda a:$E1F5,X
    sta $A4
    lda a:$E186,X
    sec
    sbc $A4
    bcs apply_pending_actor_hp_mp_damage_and_healing_c0413a
    .a8
    lda #$00
apply_pending_actor_hp_mp_damage_and_healing_c0413a:
    sta a:$E186,X
    lda a:$E1F5,X
    sta $89
    stz $8A
    sta a:$E17B,X
    stz a:$E17C,X
    stz a:$E1F5,X
    jsr select_actor_mp_damage_impact_motion
    .a8
    lda #$E0
    sta a:$E175,X
    rts
apply_pending_actor_hp_mp_damage_and_healing_c04156:
    rts
