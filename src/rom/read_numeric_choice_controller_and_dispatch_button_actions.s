; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

cancel_numeric_choice_when_script_cancellation_is_available = $1AF1
confirm_numeric_choice_and_advance_selected_script = $1ACF
move_numeric_choice_down_with_native_wraparound = $1B3B
move_numeric_choice_up_with_native_wraparound = $1B20
routine_008000 = $8000

.segment "CODE"
.org $1A96
read_numeric_choice_controller_and_dispatch_button_actions:
    sep #$10
    jsl f:routine_008000
    rep #$10
    ldx a:$A182
    lda $43,X
    bne read_numeric_choice_controller_and_dispatch_button_actions_c01aac
    .a8
    lda #$02
    trb a:$A187
    bra read_numeric_choice_controller_and_dispatch_button_actions_c01ace
read_numeric_choice_controller_and_dispatch_button_actions_c01aac:
    xba
    lda a:$A187
    .a8
    bit #$02
    bne read_numeric_choice_controller_and_dispatch_button_actions_c01ace
    xba
    .a8
    cmp #$80
    jsr confirm_numeric_choice_and_advance_selected_script
    .a8
    cmp #$40
    jsr cancel_numeric_choice_when_script_cancellation_is_available
    .a8
    cmp #$02
    jsr move_numeric_choice_up_with_native_wraparound
    .a8
    cmp #$01
    jsr move_numeric_choice_down_with_native_wraparound
    .a8
    lda #$02
    tsb a:$A187
read_numeric_choice_controller_and_dispatch_button_actions_c01ace:
    rts
