; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

await_prior_dialogue_or_start_native_menu_window_open = $D0D576
build_native_menu_ring_list_without_initial_category_step = $6F72
initialize_palette_then_fall_through_to_native_menu_dimming = $D0CD27
poll_native_menu_controller_and_publish_input_word = $6961
request_event_menu_loop_and_initialize_input_state = $692D
upload_ten_menu_graphics_blocks_with_dma5 = $D0CDF9

.segment "CODE"
.org $66B5
initialize_native_ring_palette_text_graphics_input_and_list:
    jsl f:initialize_palette_then_fall_through_to_native_menu_dimming
    jsl f:await_prior_dialogue_or_start_native_menu_window_open
    jsl f:upload_ten_menu_graphics_blocks_with_dma5
    jsr request_event_menu_loop_and_initialize_input_state
    jsr poll_native_menu_controller_and_publish_input_word
    sep #$20
    xba
    .a8
    bit #$40
    beq initialize_native_ring_palette_text_graphics_input_and_list_c066d3
    .a8
    lda #$08
    tsb a:$1804
initialize_native_ring_palette_text_graphics_input_and_list_c066d3:
    rep #$30
    .a16
    lda #$0005
    sta a:$1812
    .a16
    lda #$FFFF
    sta a:$1814
    stz a:$1830
    lda a:$1870
    sta a:$1860
    lda a:$1872
    sta a:$1862
    jmp build_native_menu_ring_list_without_initial_category_step
