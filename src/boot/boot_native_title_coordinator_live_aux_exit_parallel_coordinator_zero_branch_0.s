; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-zero-branch.md.
.setcpu "65816"
.smart
.a8
.i16

enter_palette_stop_after_initialized_title_cancellation = $D4F5

.segment "CODE"
.org $D490
branch_title_coordinator_after_actual_zero_phase_result:
    .a8
    cmp #$00
    beq enter_palette_stop_after_initialized_title_cancellation
