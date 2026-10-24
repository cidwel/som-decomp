; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_native_inventory_insert_command = $6420

.segment "CODE"
.org $0051
jump_public_event_inventory_command:
    jmp jump_native_inventory_insert_command
