; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_complete_native_menu_item_price = $D8E8

.segment "CODE"
.org $D8DE
calculate_menu_item_price_preserving_register_context:
    phx
    phy
    php
    jsr calculate_complete_native_menu_item_price
    plp
    ply
    plx
    rts
