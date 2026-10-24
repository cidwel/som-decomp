; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-zero-branch.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ed1da = $D1DA

.segment "CODE"
.org $D500
clear_stopped_palette_identity_and_enter_final_title_fade:
    stz a:$0315
    jsr routine_7ed1da
