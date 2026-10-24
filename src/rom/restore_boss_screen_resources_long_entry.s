; Recovered Secret of Mana USA routine; behaviour documented in docs/event-boss-screen-restore.md.
.setcpu "65816"
.smart
.a8
.i16

restore_complete_boss_screen_resources_and_character_tiles = $019E

.segment "CODE"
.org $0012
restore_boss_screen_resources_long_entry:
    jmp restore_complete_boss_screen_resources_and_character_tiles
