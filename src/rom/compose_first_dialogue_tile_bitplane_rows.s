; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c01526 = $1526

.segment "CODE"
.org $151A
compose_first_dialogue_tile_bitplane_rows:
    .i16
    ldy #$0000
    .a8
    lda #$0E
    bra routine_c01526
