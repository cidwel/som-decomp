; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.smart
.a8
.i16

scan_projectile_collision_and_mark_parent_target_contacts = $3CE8

.segment "CODE"
.org $9C47
finish_directional_spell_on_contact_or_lifetime:
    ldx $87
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    bcs finish_directional_spell_on_contact_or_lifetime_c29c54
    lda a:$0096,X
    .a16
    cmp #$0024
finish_directional_spell_on_contact_or_lifetime_c29c54:
    rts
