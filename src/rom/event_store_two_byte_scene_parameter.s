; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EFB8
event_store_two_byte_scene_parameter:
    rep #$10
    .i16
    ldy #$0002
    lda [$D1],Y
    xba
    ldy $D1
    iny
    iny
    iny
    sty $D1
    lda $05
    rep #$20
    sta a:$0600
    brl dispatch_native_event_opcode_or_wait_state
