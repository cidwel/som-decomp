; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1BBD
exchange_dialogue_tilemap_entry_with_zero_tile:
    .i16
    ldx #$0000
