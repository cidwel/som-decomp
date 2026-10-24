; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-movement.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EE8C
event_assign_flag_byte_preserving_previous_upper_nibble:
    .i8
    ldy #$02
    lda [$D1],Y
    sta $00
    ldx $05
    lda a:$CF00,X
    .a8
    and #$F0
    ora $00
    sta a:$CF00,X
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0003
    sta $D1
    rts
