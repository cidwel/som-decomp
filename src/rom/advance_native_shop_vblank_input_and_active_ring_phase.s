; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-dialogue.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $7E80
advance_native_shop_vblank_input_and_active_ring_phase:
    jsr wait_vblank_before_polling_native_menu_input
    sep #$20
    .a8
    lda #$40
    bit a:$1803
    beq advance_native_shop_vblank_input_and_active_ring_phase_c07e8f
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
advance_native_shop_vblank_input_and_active_ring_phase_c07e8f:
    rep #$20
    lda a:$1800
    rts
