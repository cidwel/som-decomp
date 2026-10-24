; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0d5ce = $D5CE
wait_menu_vblank_through_native_long_wrapper = $C0693F

.segment "CODE"
.org $D5A0
select_native_menu_window_close_script_when_needed:
    sep #$20
    .a8
    lda #$01
    bit a:$1803
    bne routine_d0d5ce
    rep #$30
    jsl f:wait_menu_vblank_through_native_long_wrapper
    .i16
    ldx #$D5D3
