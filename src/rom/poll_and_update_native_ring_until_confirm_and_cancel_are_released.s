; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $6896
poll_and_update_native_ring_until_confirm_and_cancel_are_released:
poll_and_update_native_ring_until_confirm_and_cancel_are_released_c06896:
    jsr wait_vblank_before_polling_native_menu_input
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    rep #$20
    lda a:$1800
    .a16
    and #$C000
    bne poll_and_update_native_ring_until_confirm_and_cancel_are_released_c06896
    rts
