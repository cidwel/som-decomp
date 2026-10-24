; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F31C
event_wait_for_selected_actor_pad_press:
    rep #$10
    ldx $D4
    lda a:$E02C,X
    beq event_wait_for_selected_actor_pad_press_c1f32c
    dec
    .a8
    cmp #$03
    bne event_wait_for_selected_actor_pad_press_c1f32c
    .a8
    lda #$02
event_wait_for_selected_actor_pad_press_c1f32c:
    sep #$10
    tax
    .a8
    lda #$FC
    bit $CC,X
    bne event_wait_for_selected_actor_pad_press_c1f336
    rts
event_wait_for_selected_actor_pad_press_c1f336:
    .a8
    lda #$00
    sta $CC,X
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
