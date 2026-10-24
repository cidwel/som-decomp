; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-wait-flag-decrement.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EC1A
event_wait_for_ticks_or_selected_controller:
    lda $05
    bne event_wait_for_ticks_or_selected_controller_c1ec39
    .a8
    lda #$83
    sta $D0
    rep #$10
    ldx $D4
    lda a:$E02C,X
    dec
    .a8
    cmp #$03
    bne event_wait_for_ticks_or_selected_controller_c1ec30
    .a8
    lda #$02
event_wait_for_ticks_or_selected_controller_c1ec30:
    sep #$20
    tax
    .a8
    lda #$00
    sta $CC,X
    bra event_wait_for_ticks_or_selected_controller_c1ec3f
event_wait_for_ticks_or_selected_controller_c1ec39:
    sta $4F
    .a8
    lda #$82
    sta $D0
event_wait_for_ticks_or_selected_controller_c1ec3f:
    rep #$20
    inc $D1
    inc $D1
    rts
