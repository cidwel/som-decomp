; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_menu_native_direct_page_and_bank = $C064A4
request_event_menu_loop_and_initialize_input_state = $692D

.segment "CODE"
.org $6696
initialize_event_menu_mode_and_saved_coordinates:
    jsl f:normalize_menu_native_direct_page_and_bank
    sep #$20
    sta a:$1820
    stz a:$1802
    stz a:$1803
    stz a:$1804
    jsr request_event_menu_loop_and_initialize_input_state
    stz a:$1826
    stx a:$183E
    sty a:$1840
    rts
