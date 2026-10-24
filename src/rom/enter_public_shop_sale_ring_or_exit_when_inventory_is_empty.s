; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_event_menu_mode_and_saved_coordinates = $6696
routine_c06624 = $6624
routine_c0662d = $662D
routine_d9fc90 = $D9FC90

.segment "CODE"
.org $663E
enter_public_shop_sale_ring_or_exit_when_inventory_is_empty:
    php
    phb
    phd
    jsr initialize_event_menu_mode_and_saved_coordinates
    jsl f:routine_d9fc90
    beq routine_c0662d
    sep #$20
    .a8
    lda #$02
    sta a:$1847
    bra routine_c06624
