; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_new_game_save_records_mirror_jump = $3818

.segment "CODE"
.org $0030
initialize_new_game_save_records_public_jump:
    jmp initialize_new_game_save_records_mirror_jump
