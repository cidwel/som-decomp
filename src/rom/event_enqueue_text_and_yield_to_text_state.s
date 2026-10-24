; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F27A
event_enqueue_text_and_yield_to_text_state:
    lda $D1
    sta a:$1D01
    lda $D2
    sta a:$1D02
    lda $D3
    sta a:$1D03
    lda $B8
    asl
    rol
    rol
    .a8
    and #$03
    sta a:$1D05
    .a8
    lda #$01
    sta $48
    .a8
    lda #$81
    sta $D0
    rts
