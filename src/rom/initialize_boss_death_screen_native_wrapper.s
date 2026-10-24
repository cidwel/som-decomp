; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_death_palettes_graphics_and_selected_actor = $0B14

.segment "CODE"
.org $5572
initialize_boss_death_screen_native_wrapper:
    jsr prepare_boss_death_palettes_graphics_and_selected_actor
    rts
