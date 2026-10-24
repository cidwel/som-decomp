; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

scan_projectile_collision_and_mark_parent_target_contacts = $3CE8

.segment "CODE"
.org $5E5D
prepare_linked_child_tip_collision_and_scan_real_party:
    ldx $87
    sep #$20
    lda a:$00B9,X
    sta a:$00C0,X
    lda a:$00BB,X
    sta a:$00C1,X
    .a8
    lda #$10
    sta a:$00C2,X
    sta a:$00C3,X
    rep #$20
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    rts
