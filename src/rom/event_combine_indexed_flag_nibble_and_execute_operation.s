; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-indexed-flag.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1f175 = $F175

.segment "CODE"
.org $F1CF
event_combine_indexed_flag_nibble_and_execute_operation:
    .i8
    ldy #$02
    lda [$D1],Y
    sta $04
    iny
    lda [$D1],Y
    tax
    lda $05
    .a8
    and #$F0
    sta $05
    lda a:$CF00,X
    .a8
    and #$0F
    ora $05
    sta $05
    rep #$20
    inc $D1
    sep #$20
    brl routine_c1f175
