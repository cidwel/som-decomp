; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

enter_public_shop_sale_ring_or_exit_when_inventory_is_empty = $663E

.segment "CODE"
.org $6414
forward_native_sale_ring_menu_to_saved_context_entry:
    jmp enter_public_shop_sale_ring_or_exit_when_inventory_is_empty
