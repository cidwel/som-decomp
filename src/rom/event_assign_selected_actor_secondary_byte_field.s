; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F010
event_assign_selected_actor_secondary_byte_field:
    rep #$30
    .i16
    ldy #$0002
    lda [$D1],Y
    sta $00
    lda $D1
    clc
    .a16
    adc #$0004
    sta $D1
    ldx $D4
    lda $05
    .a16
    and #$00FF
    beq event_assign_selected_actor_secondary_byte_field_c1f035
    ldx $3A
    .a16
    bit #$0080
    bne event_assign_selected_actor_secondary_byte_field_c1f035
    dec
    asl
    xba
    tax
event_assign_selected_actor_secondary_byte_field_c1f035:
    stx $02
    lda $00
    .a16
    and #$00FF
    clc
    .a16
    adc #$0100
    ora $02
    tax
    sep #$20
    lda $01
    sta a:$E000,X
    rts
