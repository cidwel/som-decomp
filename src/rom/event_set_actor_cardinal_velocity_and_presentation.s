; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-movement.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EEEA
event_set_actor_cardinal_velocity_and_presentation:
    rep #$10
    .i16
    ldy #$0002
    lda [$D1],Y
    sta $00
    ldy $D1
    iny
    iny
    iny
    sty $D1
    ldx $D4
    lda $05
    beq event_set_actor_cardinal_velocity_and_presentation_c1ef0c
    bpl event_set_actor_cardinal_velocity_and_presentation_c1ef06
    ldx $3A
    bra event_set_actor_cardinal_velocity_and_presentation_c1ef0c
event_set_actor_cardinal_velocity_and_presentation_c1ef06:
    dec
    asl
    xba
    .a8
    lda #$00
    tax
event_set_actor_cardinal_velocity_and_presentation_c1ef0c:
    stz a:$E01C,X
    stz a:$E013,X
    .a8
    lda #$FF
    sta $01
    lda $00
    .a8
    and #$3F
    bne event_set_actor_cardinal_velocity_and_presentation_c1ef20
    stz $01
    .a8
    lda #$01
event_set_actor_cardinal_velocity_and_presentation_c1ef20:
    sta a:$E00A,X
    stz a:$E067,X
    .a8
    lda #$01
    sta a:$E042,X
    lda $00
    .a8
    and #$C0
    beq event_set_actor_cardinal_velocity_and_presentation_c1ef69
    .a8
    cmp #$40
    beq event_set_actor_cardinal_velocity_and_presentation_c1ef81
    .a8
    cmp #$80
    beq event_set_actor_cardinal_velocity_and_presentation_c1ef51
    .a8
    lda #$82
    and $01
    sta a:$E006,X
    .a8
    lda #$00
    sta a:$E007,X
    .a8
    lda #$82
    sta a:$E010,X
    .i16
    cpx #$0600
    bcc event_set_actor_cardinal_velocity_and_presentation_c1efb5
    bra event_set_actor_cardinal_velocity_and_presentation_c1ef97
event_set_actor_cardinal_velocity_and_presentation_c1ef51:
    .a8
    lda #$02
    and $01
    sta a:$E006,X
    .a8
    lda #$00
    sta a:$E007,X
    .a8
    lda #$02
    sta a:$E010,X
    .i16
    cpx #$0600
    bcc event_set_actor_cardinal_velocity_and_presentation_c1efb5
    bra event_set_actor_cardinal_velocity_and_presentation_c1ef97
event_set_actor_cardinal_velocity_and_presentation_c1ef69:
    .a8
    lda #$00
    sta a:$E006,X
    .a8
    lda #$82
    and $01
    sta a:$E007,X
    .a8
    lda #$00
    sta a:$E010,X
    .i16
    cpx #$0600
    bcc event_set_actor_cardinal_velocity_and_presentation_c1efb5
    bra event_set_actor_cardinal_velocity_and_presentation_c1ef97
event_set_actor_cardinal_velocity_and_presentation_c1ef81:
    .a8
    lda #$00
    sta a:$E006,X
    .a8
    lda #$02
    and $01
    sta a:$E007,X
    .a8
    lda #$01
    sta a:$E010,X
    .i16
    cpx #$0600
    bcc event_set_actor_cardinal_velocity_and_presentation_c1efb5
event_set_actor_cardinal_velocity_and_presentation_c1ef97:
    .a8
    lda #$FF
    sta a:$E030,X
    lda a:$E071,X
    .a8
    and #$60
    beq event_set_actor_cardinal_velocity_and_presentation_c1efae
    .a8
    and #$40
    beq event_set_actor_cardinal_velocity_and_presentation_c1efaa
    stz a:$E010,X
event_set_actor_cardinal_velocity_and_presentation_c1efaa:
    .a8
    lda #$00
    bra event_set_actor_cardinal_velocity_and_presentation_c1efb2
event_set_actor_cardinal_velocity_and_presentation_c1efae:
    .a8
    lda #$01
    and $01
event_set_actor_cardinal_velocity_and_presentation_c1efb2:
    sta a:$E011,X
event_set_actor_cardinal_velocity_and_presentation_c1efb5:
    brl dispatch_native_event_opcode_or_wait_state
