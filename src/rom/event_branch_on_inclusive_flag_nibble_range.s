; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-flags.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F140
event_branch_on_inclusive_flag_nibble_range:
    .i8
    ldy #$02
    lda [$D1],Y
    sta $01
    .a8
    and #$0F
    sta $00
    lda $01
    lsr
    lsr
    lsr
    lsr
    sta $01
    ldx $05
    rep #$10
    ldy $D1
    iny
    iny
    iny
    lda a:$CF00,X
    cmp $01
    bcc event_branch_on_inclusive_flag_nibble_range_c1f168
    cmp $00
    beq event_branch_on_inclusive_flag_nibble_range_c1f16a
    bcc event_branch_on_inclusive_flag_nibble_range_c1f16a
event_branch_on_inclusive_flag_nibble_range_c1f168:
    iny
    iny
event_branch_on_inclusive_flag_nibble_range_c1f16a:
    sty $D1
    brl dispatch_native_event_opcode_or_wait_state
