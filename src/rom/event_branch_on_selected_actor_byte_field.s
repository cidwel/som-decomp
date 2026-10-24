; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-field-branches.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F1F1
event_branch_on_selected_actor_byte_field:
    .i8
    ldy #$02
    rep #$20
    lda [$D1],Y
    sta $02
    rep #$10
    ldx $D4
    lda $05
    .a16
    and #$00FF
    beq event_branch_on_selected_actor_byte_field_c1f20f
    ldx $3A
    .a16
    cmp #$0080
    bcs event_branch_on_selected_actor_byte_field_c1f20f
    dec
    asl
    xba
    tax
event_branch_on_selected_actor_byte_field_c1f20f:
    txa
    .a16
    ora #$0100
    sep #$20
    lda $02
    tax
    lda a:$E000,X
    sta $02
    lda $04
    .a8
    and #$07
    dec
    beq event_branch_on_selected_actor_byte_field_c1f240
    dec
    beq event_branch_on_selected_actor_byte_field_c1f248
    dec
    beq event_branch_on_selected_actor_byte_field_c1f252
    dec
    beq event_branch_on_selected_actor_byte_field_c1f25a
    dec
    beq event_branch_on_selected_actor_byte_field_c1f238
    lda $02
    cmp $03
    beq event_branch_on_selected_actor_byte_field_c1f26c
    bra event_branch_on_selected_actor_byte_field_c1f260
event_branch_on_selected_actor_byte_field_c1f238:
    lda $02
    eor $03
    bne event_branch_on_selected_actor_byte_field_c1f26c
    beq event_branch_on_selected_actor_byte_field_c1f260
event_branch_on_selected_actor_byte_field_c1f240:
    lda $02
    cmp $03
    bcs event_branch_on_selected_actor_byte_field_c1f26c
    bcc event_branch_on_selected_actor_byte_field_c1f260
event_branch_on_selected_actor_byte_field_c1f248:
    lda $02
    cmp $03
    beq event_branch_on_selected_actor_byte_field_c1f26c
    bcs event_branch_on_selected_actor_byte_field_c1f260
    bcc event_branch_on_selected_actor_byte_field_c1f26c
event_branch_on_selected_actor_byte_field_c1f252:
    lda $02
    and $03
    bne event_branch_on_selected_actor_byte_field_c1f26c
    beq event_branch_on_selected_actor_byte_field_c1f260
event_branch_on_selected_actor_byte_field_c1f25a:
    lda $02
    ora $03
    bne event_branch_on_selected_actor_byte_field_c1f26c
event_branch_on_selected_actor_byte_field_c1f260:
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0006
    sta $D1
    bra event_branch_on_selected_actor_byte_field_c1f274
event_branch_on_selected_actor_byte_field_c1f26c:
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0004
event_branch_on_selected_actor_byte_field_c1f274:
    sta $D1
    brl dispatch_native_event_opcode_or_wait_state
