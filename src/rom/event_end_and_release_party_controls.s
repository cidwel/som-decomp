; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E9C4
event_end_and_release_party_controls:
    stz $F1
    stz $D0
    stz $4E
    stz $3A
    stz $3B
    stz $CC
    stz $CD
    stz $CE
    lda $D9
    .a8
    and #$7F
    sta $D9
    lda $DA
    .a8
    and #$7F
    sta $DA
    lda $DB
    .a8
    and #$7F
    sta $DB
    rts
