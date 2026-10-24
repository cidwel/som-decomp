; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_weapon_experience_and_level = $43B7

.segment "CODE"
.org $4358
distribute_dead_actor_weapon_experience:
    .a8
    lda #$09
    sec
    sbc a:$E19C,Y
    sta $A6
    lda a:$E181,X
    cmp a:$E181,Y
    bcs distribute_dead_actor_weapon_experience_c0436a
    lsr $A6
distribute_dead_actor_weapon_experience_c0436a:
    lda a:$E1F0,X
    bpl distribute_dead_actor_weapon_experience_c04370
    rts
distribute_dead_actor_weapon_experience_c04370:
    bne distribute_dead_actor_weapon_experience_c04384
    jsr advance_actor_weapon_experience_and_level
    lsr $A6
    .i16
    ldy #$0200
    jsr advance_actor_weapon_experience_and_level
    .i16
    ldy #$0400
    jsr advance_actor_weapon_experience_and_level
    rts
distribute_dead_actor_weapon_experience_c04384:
    .a8
    cmp #$02
    beq distribute_dead_actor_weapon_experience_c0439a
    jsr advance_actor_weapon_experience_and_level
    lsr $A6
    .i16
    ldy #$0000
    jsr advance_actor_weapon_experience_and_level
    .i16
    ldy #$0400
    jsr advance_actor_weapon_experience_and_level
    rts
distribute_dead_actor_weapon_experience_c0439a:
    jsr advance_actor_weapon_experience_and_level
    lsr $A6
    .i16
    ldy #$0000
    jsr advance_actor_weapon_experience_and_level
    .i16
    ldy #$0200
    jsr advance_actor_weapon_experience_and_level
    rts
