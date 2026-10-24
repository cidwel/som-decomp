; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $645C
restore_inventory_menu_direct_page_bank_and_status:
    pld
    plb
    plp
    rtl
