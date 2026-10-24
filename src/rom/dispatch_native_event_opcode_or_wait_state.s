; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E8D3
dispatch_native_event_opcode_or_wait_state:
    sep #$30
    lda $E2
    .a8
    and #$01
    ora $FF
    ora $52
    beq dispatch_native_event_opcode_or_wait_state_c1e8e0
dispatch_native_event_opcode_or_wait_state_c1e8df:
    rts
dispatch_native_event_opcode_or_wait_state_c1e8e0:
    lda $E8
    .a8
    and #$04
    bne dispatch_native_event_opcode_or_wait_state_c1e8df
    lda $D0
    bpl dispatch_native_event_opcode_or_wait_state_c1e8ef
    asl
    tax
    jmp ($E902,X)
dispatch_native_event_opcode_or_wait_state_c1e8ef:
    rep #$20
    lda [$D1]
    sta $04
    sep #$20
    .a8
    cmp #$50
    bcc dispatch_native_event_opcode_or_wait_state_c1e8fd
    .a8
    lda #$50
dispatch_native_event_opcode_or_wait_state_c1e8fd:
    asl
    tax
    jmp ($E922,X)
