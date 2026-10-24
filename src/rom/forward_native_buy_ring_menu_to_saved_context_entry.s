; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

enter_public_shop_buy_ring_and_restore_saved_party_categories = $6617

.segment "CODE"
.org $6411
forward_native_buy_ring_menu_to_saved_context_entry:
    jmp enter_public_shop_buy_ring_and_restore_saved_party_categories
