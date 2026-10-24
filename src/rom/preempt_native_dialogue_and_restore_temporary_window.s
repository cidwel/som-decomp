; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

close_temporary_dialogue_and_reset_message_workspace = $0FE1
dispatch_all_native_dialogue_states_and_scrolling_scene = $0165

.segment "CODE"
.org $012C
preempt_native_dialogue_and_restore_temporary_window:
    php
    sep #$20
    rep #$10
    lda f:$7EA162
    .a8
    cmp #$02
    beq dispatch_all_native_dialogue_states_and_scrolling_scene
    .a8
    lda #$02
    sta f:$001D13
    lda f:$001D10
    .a8
    bit #$01
    beq preempt_native_dialogue_and_restore_temporary_window_c0015f
    .a8
    lda #$00
    sta f:$001D10
    lda f:$7EA170
    .a8
    cmp #$51
    beq preempt_native_dialogue_and_restore_temporary_window_c0015c
    lda a:$1D12
    .a8
    bit #$20
    beq preempt_native_dialogue_and_restore_temporary_window_c0015f
preempt_native_dialogue_and_restore_temporary_window_c0015c:
    jsr close_temporary_dialogue_and_reset_message_workspace
preempt_native_dialogue_and_restore_temporary_window_c0015f:
    .a8
    lda #$00
    sta f:$7EA162
