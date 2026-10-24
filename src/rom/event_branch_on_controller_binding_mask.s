; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F06F
event_branch_on_controller_binding_mask:
    lda $05
    .a8
    and #$0F
    .a8
    cmp #$03
    bne event_branch_on_controller_binding_mask_c1f079
    .a8
    lda #$04
event_branch_on_controller_binding_mask_c1f079:
    sta $02
    lda $05
    lsr
    lsr
    lsr
    lsr
    bne event_branch_on_controller_binding_mask_c1f08f
    lda $D9
    bmi event_branch_on_controller_binding_mask_c1f079
    lda $DA
    bmi event_branch_on_controller_binding_mask_c1f079
    lda $DB
    bra event_branch_on_controller_binding_mask_c1f09f
event_branch_on_controller_binding_mask_c1f08f:
    dec
    bne event_branch_on_controller_binding_mask_c1f096
    lda $D9
    bra event_branch_on_controller_binding_mask_c1f09f
event_branch_on_controller_binding_mask_c1f096:
    dec
    bne event_branch_on_controller_binding_mask_c1f09d
    lda $DA
    bra event_branch_on_controller_binding_mask_c1f09f
event_branch_on_controller_binding_mask_c1f09d:
    lda $DB
event_branch_on_controller_binding_mask_c1f09f:
    sta $03
    lda $02
    beq event_branch_on_controller_binding_mask_c1f0ab
    and $03
    bne event_branch_on_controller_binding_mask_c1f0b9
    beq event_branch_on_controller_binding_mask_c1f0af
event_branch_on_controller_binding_mask_c1f0ab:
    lda $03
    beq event_branch_on_controller_binding_mask_c1f0b9
event_branch_on_controller_binding_mask_c1f0af:
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0004
    bra event_branch_on_controller_binding_mask_c1f0c1
event_branch_on_controller_binding_mask_c1f0b9:
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0002
event_branch_on_controller_binding_mask_c1f0c1:
    sta $D1
    brl dispatch_native_event_opcode_or_wait_state
