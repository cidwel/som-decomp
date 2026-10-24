; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16

insert_inventory_record_with_zero_controller_bits = $64BD

.segment "CODE"
.org $6420
jump_native_inventory_insert_command:
    jmp insert_inventory_record_with_zero_controller_bits
