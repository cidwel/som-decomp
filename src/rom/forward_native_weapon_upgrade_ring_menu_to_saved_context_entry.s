; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-public.md.
.setcpu "65816"
.smart
.a8
.i16

enter_public_weapon_upgrade_ring_at_first_weapon = $6653

.segment "CODE"
.org $6417
forward_native_weapon_upgrade_ring_menu_to_saved_context_entry:
    jmp enter_public_weapon_upgrade_ring_at_first_weapon
