; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-zero-branch.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d503 = $D503
routine_7eacac = $ACAC

.segment "CODE"
.org $D4F5
enter_palette_stop_after_initialized_title_cancellation:
    lda a:$0316
    beq routine_00d503
    lda a:$0315
    jsr routine_7eacac
