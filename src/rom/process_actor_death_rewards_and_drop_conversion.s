; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

add_dead_actor_gold_to_party_with_native_cap = $44F0
advance_additive_random_generator = $38A0
apply_actor_status_and_timers = $C8E301
award_hero_experience_and_rebuild_each_level = $445B
clear_map_entry_party_effects = $C05D46
clear_six_actor_references_to_dead_actor = $4315
distribute_dead_actor_weapon_experience = $4358
random_below_byte = $3888

.segment "CODE"
.org $4203
process_actor_death_rewards_and_drop_conversion:
    sep #$20
    stz a:$E1B1,X
    stz a:$E1B0,X
    jsr clear_six_actor_references_to_dead_actor
    lda a:$E1FB,X
    .a8
    bit #$40
    beq process_actor_death_rewards_and_drop_conversion_c04247
    lda $80
    .a8
    ora #$80
    sta $80
    rep #$20
    lda a:$E190
    .a16
    and #$8200
    sta a:$E190
    lda a:$E390
    .a16
    and #$8200
    sta a:$E390
    lda a:$E590
    .a16
    and #$8200
    sta a:$E590
    .a16
    lda #$8000
    sta a:$E190,X
    sep #$20
    jsl f:clear_map_entry_party_effects
    ldx $85
    rts
process_actor_death_rewards_and_drop_conversion_c04247:
    lda a:$E1EC,X
    .a8
    cmp #$03
    bcs process_actor_death_rewards_and_drop_conversion_c04260
    sta $82
    asl
    sta $84
    ldy $83
    jsr distribute_dead_actor_weapon_experience
    jsr award_hero_experience_and_rebuild_each_level
    jsr add_dead_actor_gold_to_party_with_native_cap
    ldx $85
process_actor_death_rewards_and_drop_conversion_c04260:
    lda a:$E1FB,X
    .a8
    bit #$C1
    bne process_actor_death_rewards_and_drop_conversion_c042a3
    .a8
    lda #$80
    sta a:$E191,X
    stz a:$E190,X
    lda a:$E1CA,X
    .a8
    and #$1E
    lsr
    clc
    .a8
    adc #$F9
    sta a:$E180,X
    stz a:$E1E3,X
    lda a:$E1FA,X
    .a8
    ora #$07
    sta a:$E1FA,X
    jsl f:apply_actor_status_and_timers
    jsr advance_additive_random_generator
    .a8
    and #$3F
    inc
    sta $A8
    lda a:$E1CE,X
    sta $A4
    .a8
    bit #$40
    bne process_actor_death_rewards_and_drop_conversion_c042a4
    .a8
    and #$3F
    cmp $A8
    bcs process_actor_death_rewards_and_drop_conversion_c042a4
    ldx $85
process_actor_death_rewards_and_drop_conversion_c042a3:
    rts
process_actor_death_rewards_and_drop_conversion_c042a4:
    lda $A4
    bpl process_actor_death_rewards_and_drop_conversion_c042ab
    dec a:$E182,X
process_actor_death_rewards_and_drop_conversion_c042ab:
    .a8
    lda #$80
    sta a:$E1B1,X
    stz a:$E1B0,X
    lda a:$E1CF,X
    beq process_actor_death_rewards_and_drop_conversion_c042bb
    dec
    bra process_actor_death_rewards_and_drop_conversion_c042fd
process_actor_death_rewards_and_drop_conversion_c042bb:
    .a8
    lda #$03
    jsr random_below_byte
    sta $A4
    lda a:$E181,X
    .a8
    cmp #$0A
    bcc process_actor_death_rewards_and_drop_conversion_c042f1
    .a8
    lda #$02
    sta $A4
    lda a:$E181,X
    .a8
    cmp #$0F
    bcc process_actor_death_rewards_and_drop_conversion_c042f1
    inc $A4
    .a8
    cmp #$19
    bcc process_actor_death_rewards_and_drop_conversion_c042f1
    inc $A4
    .a8
    cmp #$1E
    bcc process_actor_death_rewards_and_drop_conversion_c042f1
    inc $A4
    .a8
    cmp #$24
    bcc process_actor_death_rewards_and_drop_conversion_c042f1
    inc $A4
    jsr advance_additive_random_generator
    .a8
    cmp #$20
    bcs process_actor_death_rewards_and_drop_conversion_c042f1
    inc $A4
process_actor_death_rewards_and_drop_conversion_c042f1:
    phx
    .a8
    lda #$00
    xba
    lda $A4
    tax
    lda f:$C0430D,X
    plx
process_actor_death_rewards_and_drop_conversion_c042fd:
    sta a:$E1C8,X
    lda a:$E1E7,X
    sta a:$E1CA,X
    stz a:$E181,X
    stz a:$E184,X
    rts
