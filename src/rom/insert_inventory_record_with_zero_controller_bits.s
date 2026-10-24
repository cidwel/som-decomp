; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16

insert_or_increment_inventory_record_by_native_category = $64D1
normalize_menu_native_direct_page_and_bank = $C064A4
routine_c0645c = $645C

.segment "CODE"
.org $64BD
insert_inventory_record_with_zero_controller_bits:
    php
    phb
    phd
    sep #$20
    stz a:$1821
    sta a:$1820
    jsl f:normalize_menu_native_direct_page_and_bank
    jsr insert_or_increment_inventory_record_by_native_category
    bra routine_c0645c
