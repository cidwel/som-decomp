; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

forward_native_buy_ring_menu_to_saved_context_entry = $6411

.segment "CODE"
.org $0048
public_buy_ring_menu_alias:
    jmp forward_native_buy_ring_menu_to_saved_context_entry
