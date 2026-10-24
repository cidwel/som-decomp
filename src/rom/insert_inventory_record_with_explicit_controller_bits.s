; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c064c5 = $64C5

.segment "CODE"
.org $64B3
insert_inventory_record_with_explicit_controller_bits:
    php
    phb
    phd
    sep #$30
    stx a:$1821
    bra routine_c064c5
