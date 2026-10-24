; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3
jump_public_event_inventory_command = $C00051

.segment "CODE"
.org $EB50
event_insert_inventory_operand_then_continue_script:
    rep #$10
    ldx $D1
    inx
    inx
    stx $D1
    ldx $D4
    lda $05
    jsl f:jump_public_event_inventory_command
    brl dispatch_native_event_opcode_or_wait_state
