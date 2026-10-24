; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

forward_native_sale_ring_menu_to_saved_context_entry = $6414

.segment "CODE"
.org $004B
public_sale_ring_menu_alias:
    jmp forward_native_sale_ring_menu_to_saved_context_entry
