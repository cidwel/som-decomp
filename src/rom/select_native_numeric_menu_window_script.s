; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

run_selected_menu_window_script_through_real_vblank_completion = $D5B2

.segment "CODE"
.org $D599
select_native_numeric_menu_window_script:
    rep #$30
    .i16
    ldx #$D5D5
    bra run_selected_menu_window_script_through_real_vblank_completion
