; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16

event_advance_word_cursor_and_return = $EAEB

.segment "CODE"
.org $EAA3
event_remember_current_map_destination:
    rep #$20
    lda a:$010E
    sta a:$0108
    bra event_advance_word_cursor_and_return
