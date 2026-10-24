; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

run_native_dialogue_public_jump = $C00092
set_native_menu_dialogue_script_and_close_prior_window = $D5D7
wait_menu_vblank_through_native_long_wrapper = $C0693F

.segment "CODE"
.org $D5B2
run_selected_menu_window_script_through_real_vblank_completion:
    .a16
    lda #$00D0
    jsr set_native_menu_dialogue_script_and_close_prior_window
    sep #$20
    stz a:$1D13
    jsl f:run_native_dialogue_public_jump
run_selected_menu_window_script_through_real_vblank_completion_d0d5c1:
    jsl f:wait_menu_vblank_through_native_long_wrapper
    sep #$20
    .a8
    lda #$01
    bit a:$1D04
    bne run_selected_menu_window_script_through_real_vblank_completion_d0d5c1
    rep #$20
    rtl
