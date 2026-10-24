; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

close_native_ring_dialogue_and_restore_shadow_palette = $6608
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
request_native_menu_vertical_inventory_transition = $6740
routine_c067a8 = $67A8
update_native_menu_horizontal_repeat_and_description_request = $66F3
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $666F
poll_and_update_complete_native_shop_ring_until_closed:
poll_and_update_complete_native_shop_ring_until_closed_c0666f:
    jsr wait_vblank_before_polling_native_menu_input
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    sep #$30
    lda a:$1812
    bne poll_and_update_complete_native_shop_ring_until_closed_c0668c
    lda a:$1847
    .a8
    cmp #$02
    bne poll_and_update_complete_native_shop_ring_until_closed_c06686
    jsr request_native_menu_vertical_inventory_transition
poll_and_update_complete_native_shop_ring_until_closed_c06686:
    jsr update_native_menu_horizontal_repeat_and_description_request
    jsr routine_c067a8
poll_and_update_complete_native_shop_ring_until_closed_c0668c:
    rep #$30
    lda a:$1826
    bne poll_and_update_complete_native_shop_ring_until_closed_c0666f
    jmp close_native_ring_dialogue_and_restore_shadow_palette
