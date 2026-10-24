; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EAEB
event_advance_word_cursor_and_return:
    rep #$20
    inc $D1
    rts
