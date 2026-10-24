; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_status_and_timers = $C8E301
calculate_physical_defence_terms = $4FED
queue_physical_weapon_status_after_damage = $5119
resolve_and_queue_physical_damage = $514B
select_actor_miss_reaction_long = $C04E6B
select_physical_element_and_expire_saber = $50CA
test_physical_hit_accuracy = $505B

.segment "CODE"
.org $4F7B
resolve_actor_pending_physical_hits:
    lda a:$E191,X
    .a8
    bit #$04
    bne resolve_actor_pending_physical_hits_c04f8c
    ldy a:$E182,X
    beq resolve_actor_pending_physical_hits_c04f8c
    lda a:$E059,X
    bne resolve_actor_pending_physical_hits_c04f90
resolve_actor_pending_physical_hits_c04f8c:
    stz a:$E059,X
    rtl
resolve_actor_pending_physical_hits_c04f90:
    sta $92
    stz a:$E059,X
    jsr calculate_physical_defence_terms
    .a8
    lda #$02
    sta $93
    stz $83
resolve_actor_pending_physical_hits_c04f9e:
    lsr $92
    bcs resolve_actor_pending_physical_hits_c04fa9
    dec $93
    bpl resolve_actor_pending_physical_hits_c04f9e
    jmp resolve_actor_pending_physical_hits_c04fe8
resolve_actor_pending_physical_hits_c04fa9:
    .a8
    lda #$05
    sta $A4
    lda a:$E1FB,X
    bmi resolve_actor_pending_physical_hits_c04fb6
    .a8
    lda #$02
    sta $A4
resolve_actor_pending_physical_hits_c04fb6:
    lda $A4
    sec
    sbc $93
    sta $82
    asl
    sta $84
    ldy $83
    rep #$20
    lda a:$E182,Y
    sep #$20
    beq resolve_actor_pending_physical_hits_c04fe4
    jsr test_physical_hit_accuracy
    bcc resolve_actor_pending_physical_hits_c04fe0
    lda $82
    sta a:$E1F0,X
    jsr select_physical_element_and_expire_saber
    jsr resolve_and_queue_physical_damage
    jsr queue_physical_weapon_status_after_damage
    bra resolve_actor_pending_physical_hits_c04fe4
resolve_actor_pending_physical_hits_c04fe0:
    jsl f:select_actor_miss_reaction_long
resolve_actor_pending_physical_hits_c04fe4:
    dec $93
    bpl resolve_actor_pending_physical_hits_c04f9e
resolve_actor_pending_physical_hits_c04fe8:
    jsl f:apply_actor_status_and_timers
    rtl
