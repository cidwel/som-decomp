; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F0C6
event_branch_on_leading_assigned_controller_count:
    .i8
    ldx #$00
    lda $D9
    beq event_branch_on_leading_assigned_controller_count_c1f0d7
    inx
    lda $DA
    beq event_branch_on_leading_assigned_controller_count_c1f0d7
    inx
    lda $DB
    beq event_branch_on_leading_assigned_controller_count_c1f0d7
    inx
event_branch_on_leading_assigned_controller_count_c1f0d7:
    txa
    rep #$10
    ldy $D1
    iny
    iny
    cmp $05
    beq event_branch_on_leading_assigned_controller_count_c1f0e4
    iny
    iny
event_branch_on_leading_assigned_controller_count_c1f0e4:
    sty $D1
    brl dispatch_native_event_opcode_or_wait_state
