; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_actor_tile_state = $DF37

.segment "CODE"
.org $DF26
initialize_party_tile_state:
    rep #$10
    .i16
    ldx #$0000
    jsr initialize_actor_tile_state
    .i16
    ldx #$0200
    jsr initialize_actor_tile_state
    .i16
    ldx #$0400
