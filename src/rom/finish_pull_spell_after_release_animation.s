; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9E44
finish_pull_spell_after_release_animation:
    ldx $87
    lda a:$009E,X
    bne finish_pull_spell_after_release_animation_c29e50
    jsr clear_spell_status_and_mark_reciprocal_contacts
    sec
    rts
finish_pull_spell_after_release_animation_c29e50:
    jsr set_eligible_spell_target_status_and_timer
    clc
    rts
