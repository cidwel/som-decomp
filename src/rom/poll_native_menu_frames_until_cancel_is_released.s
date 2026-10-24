; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16

wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $6922
poll_native_menu_frames_until_cancel_is_released:
poll_native_menu_frames_until_cancel_is_released_c06922:
    rep #$20
    jsr wait_vblank_before_polling_native_menu_input
    .a16
    and #$4000
    bne poll_native_menu_frames_until_cancel_is_released_c06922
    rts
