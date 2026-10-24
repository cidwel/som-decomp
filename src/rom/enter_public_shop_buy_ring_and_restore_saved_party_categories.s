; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

finish_native_ring_public_menu_and_restore_saved_context = $65BE
initialize_event_menu_controller_and_descriptor = $6AA5
initialize_event_menu_mode_and_saved_coordinates = $6696
initialize_native_ring_palette_text_graphics_input_and_list = $66B5
poll_and_update_complete_native_shop_ring_until_closed = $666F

.segment "CODE"
.org $6617
enter_public_shop_buy_ring_and_restore_saved_party_categories:
    php
    phb
    phd
    jsr initialize_event_menu_mode_and_saved_coordinates
    sep #$20
    .a8
    lda #$01
    sta a:$1847
    jsr initialize_event_menu_controller_and_descriptor
    jsr initialize_native_ring_palette_text_graphics_input_and_list
    jsr poll_and_update_complete_native_shop_ring_until_closed
    rep #$30
    lda a:$1860
    sta a:$1870
    lda a:$1862
    sta a:$1872
    jmp finish_native_ring_public_menu_and_restore_saved_context
