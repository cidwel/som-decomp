; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

await_menu_vblank_then_fall_through_to_text_transition = $D572
routine_d0d5ce = $D5CE
run_selected_menu_window_script_through_real_vblank_completion = $D5B2

.segment "CODE"
.org $D576
await_prior_dialogue_or_start_native_menu_window_open:
    sep #$20
    lda a:$1847
    bne await_prior_dialogue_or_start_native_menu_window_open_d0d592
    lda a:$1D04
    .a8
    bit #$01
    bne await_menu_vblank_then_fall_through_to_text_transition
    lda a:$1D12
    .a8
    bit #$20
    beq await_prior_dialogue_or_start_native_menu_window_open_d0d592
    .a8
    lda #$01
    tsb a:$1803
    bra routine_d0d5ce
await_prior_dialogue_or_start_native_menu_window_open_d0d592:
    rep #$30
    .i16
    ldx #$D5D1
    bra run_selected_menu_window_script_through_real_vblank_completion
