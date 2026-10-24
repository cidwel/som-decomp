; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-zero-branch.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eacac = $ACAC

.segment "CODE"
.org $D513
enter_stop_all_after_actual_palette_identity_clear:
    lda a:$0315
    jsr routine_7eacac
