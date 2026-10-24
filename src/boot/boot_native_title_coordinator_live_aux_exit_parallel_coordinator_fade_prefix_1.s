; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-zero-branch.md.
.setcpu "65816"
.smart
.a8
.i16

enter_stop_all_after_actual_palette_identity_clear = $D513

.segment "CODE"
.org $D506
branch_after_actual_initialized_palette_final_fade:
    lda a:$0316
    bne enter_stop_all_after_actual_palette_identity_clear
