; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F348
event_wait_for_all_active_actors_idle:
    rep #$10
    .i16
    ldx #$1600
    bit $ED
    bpl event_wait_for_all_active_actors_idle_c1f35b
    .i16
    ldx #$0A00
    bit $5C
    bpl event_wait_for_all_active_actors_idle_c1f35b
    .i16
    ldx #$0400
event_wait_for_all_active_actors_idle_c1f35b:
    lda a:$E000,X
    beq event_wait_for_all_active_actors_idle_c1f368
    bmi event_wait_for_all_active_actors_idle_c1f368
    lda a:$E042,X
    beq event_wait_for_all_active_actors_idle_c1f368
    rts
event_wait_for_all_active_actors_idle_c1f368:
    rep #$20
    txa
    sec
    .a16
    sbc #$0200
    tax
    sep #$20
    bpl event_wait_for_all_active_actors_idle_c1f35b
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
