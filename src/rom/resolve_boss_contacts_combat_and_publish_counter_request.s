; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

actor_combat_tick_public_jump = $C0002D
apply_boss_contact_class_eight_or_nine_control_reaction = $0F59
floating_combat_number_public_jump = $18015
mark_boss_primary_contact_in_party_and_boss_masks = $052E
mark_boss_secondary_contact_in_party_and_boss_masks = $058F

.segment "CODE"
.org $0F27
resolve_boss_contacts_combat_and_publish_counter_request:
    ldx $87
    jsr mark_boss_secondary_contact_in_party_and_boss_masks
    jsr mark_boss_primary_contact_in_party_and_boss_masks
    jsl f:actor_combat_tick_public_jump
    sta $56
    .a16
    and #$00FF
    beq resolve_boss_contacts_combat_and_publish_counter_request_c20f58
    .a16
    cmp #$0001
    beq resolve_boss_contacts_combat_and_publish_counter_request_c20f48
    .a16
    cmp #$0002
    bne resolve_boss_contacts_combat_and_publish_counter_request_c20f58
    jsr apply_boss_contact_class_eight_or_nine_control_reaction
    rts
resolve_boss_contacts_combat_and_publish_counter_request_c20f48:
    stx $46
    sty $4E
    lda $87
    .a16
    and #$1FFF
    tax
    lda $46
    jsl f:floating_combat_number_public_jump
resolve_boss_contacts_combat_and_publish_counter_request_c20f58:
    rts
