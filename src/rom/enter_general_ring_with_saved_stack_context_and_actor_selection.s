; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-general.md.
.setcpu "65816"
.smart
.a8
.i16

finish_native_equipment_exchange_with_two_sprite_flights = $D0DCBE
initialize_event_menu_mode_and_saved_coordinates = $6696
initialize_native_ring_palette_text_graphics_input_and_list = $66B5
poll_general_ring_and_dispatch_actor_navigation_until_exit = $65D7
publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank = $D0DE29
restore_menu_actor_and_controller_selection_from_coordinates = $69F0
routine_c065d4 = $65D4

.segment "CODE"
.org $6594
enter_general_ring_with_saved_stack_context_and_actor_selection:
    php
    phb
    phd
    rep #$20
    sta a:$1820
    tsc
    sta a:$19CE
    lda a:$1820
    sep #$20
    stz a:$1847
    jsr initialize_event_menu_mode_and_saved_coordinates
    jsr restore_menu_actor_and_controller_selection_from_coordinates
    bne routine_c065d4
    jsl f:publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank
    jsr initialize_native_ring_palette_text_graphics_input_and_list
    jsr poll_general_ring_and_dispatch_actor_navigation_until_exit
    jsl f:finish_native_equipment_exchange_with_two_sprite_flights
