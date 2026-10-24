; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_event_menu_controller_and_descriptor = $6AA5
initialize_event_menu_mode_and_saved_coordinates = $6696
routine_c06627 = $6627

.segment "CODE"
.org $6653
enter_public_weapon_upgrade_ring_at_first_weapon:
    php
    phb
    phd
    jsr initialize_event_menu_mode_and_saved_coordinates
    sep #$20
    .a8
    lda #$03
    sta a:$1847
    stz a:$1846
    jsr initialize_event_menu_controller_and_descriptor
    sep #$20
    .a8
    lda #$03
    sta a:$1809
    bra routine_c06627
