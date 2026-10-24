; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16

release_party_control_and_restore_boss_palette_music = $6273

.segment "CODE"
.org $617F
release_selected_party_target_after_alternate_death:
    jsr release_party_control_and_restore_boss_palette_music
    rts
