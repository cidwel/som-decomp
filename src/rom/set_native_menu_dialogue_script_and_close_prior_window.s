; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

close_dialogue_public_jump = $C00095

.segment "CODE"
.org $D5D7
set_native_menu_dialogue_script_and_close_prior_window:
    rep #$10
    sep #$20
    pha
    phx
    .a8
    lda #$01
    bit a:$1D04
    beq set_native_menu_dialogue_script_and_close_prior_window_d0d5e8
    jsl f:close_dialogue_public_jump
set_native_menu_dialogue_script_and_close_prior_window_d0d5e8:
    plx
    pla
    sta a:$1D03
    stx a:$1D01
    rep #$20
    rts
