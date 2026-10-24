; Recovered Secret of Mana USA routine; behaviour documented in docs/event-map-redraw.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00caff = $CAFF

.segment "CODE"
.org $EA99
event_reload_map_pieces_and_redraw:
    rep #$20
    inc $D1
    sec
    jsl f:routine_00caff
    rts
