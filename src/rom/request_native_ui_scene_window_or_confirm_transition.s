; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-exit.md.
.setcpu "65816"
.smart
.a8
.i16

start_ui_window_color_transition = $87B7

.segment "CODE"
.org $87A2
request_native_ui_scene_window_or_confirm_transition:
    bit $F2
    bpl request_native_ui_scene_window_or_confirm_transition_c087ac
    lda $F8
    .a8
    cmp #$20
    bcc request_native_ui_scene_window_or_confirm_transition_c087b6
request_native_ui_scene_window_or_confirm_transition_c087ac:
    .a8
    lda #$03
    bit $F2
    beq start_ui_window_color_transition
    .a8
    lda #$10
    tsb $CC
request_native_ui_scene_window_or_confirm_transition_c087b6:
    rts
