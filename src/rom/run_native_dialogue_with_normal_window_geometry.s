; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_all_native_dialogue_states_and_scrolling_scene = $0165

.segment "CODE"
.org $0113
run_native_dialogue_with_normal_window_geometry:
    php
    sep #$20
    rep #$10
    lda f:$7EA162
    .a8
    cmp #$02
    beq dispatch_all_native_dialogue_states_and_scrolling_scene
    .a8
    lda #$01
    sta f:$7EA162
    sta f:$001D10
    bra dispatch_all_native_dialogue_states_and_scrolling_scene
