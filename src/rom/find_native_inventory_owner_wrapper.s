; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-ownership.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c076d5 = $76D5

.segment "CODE"
.org $76C7
find_native_inventory_owner_wrapper:
    php
    sep #$30
    bra routine_c076d5
