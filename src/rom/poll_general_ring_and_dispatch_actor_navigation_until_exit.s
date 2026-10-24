; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-general.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_ring_cursor_direct_page_words = $6610
close_native_ring_dialogue_and_restore_shadow_palette = $6608
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
request_event_menu_loop_and_initialize_input_state = $692D
request_native_menu_vertical_inventory_transition = $6740
routine_c06775 = $6775
update_native_menu_horizontal_repeat_and_description_request = $66F3
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $65D7
poll_general_ring_and_dispatch_actor_navigation_until_exit:
poll_general_ring_and_dispatch_actor_navigation_until_exit_c065d7:
    jsr wait_vblank_before_polling_native_menu_input
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    sep #$30
    lda a:$1812
    bne poll_general_ring_and_dispatch_actor_navigation_until_exit_c065ed
    jsr request_native_menu_vertical_inventory_transition
    jsr update_native_menu_horizontal_repeat_and_description_request
    jsr routine_c06775
poll_general_ring_and_dispatch_actor_navigation_until_exit_c065ed:
    sep #$20
    lda a:$19F0
    .a8
    cmp #$C0
    beq poll_general_ring_and_dispatch_actor_navigation_until_exit_c065fd
    lda a:$1826
    beq close_native_ring_dialogue_and_restore_shadow_palette
    bra poll_general_ring_and_dispatch_actor_navigation_until_exit_c065d7
poll_general_ring_and_dispatch_actor_navigation_until_exit_c065fd:
    lda a:$19F1
    bmi clear_native_ring_cursor_direct_page_words
    jsr request_event_menu_loop_and_initialize_input_state
    stz a:$1826
