; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $58FA
restore_first_controller_binding_and_clear_other_two:
    lda f:$306000,X
    inx
    sta $D9
    stz $DA
    stz $DB
    rts
