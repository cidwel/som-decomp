; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c7538f = $538F

.segment "CODE"
.org $5389
append_native_saved_slot_text_space_token:
    .a8
    lda #$80
    bra routine_c7538f
