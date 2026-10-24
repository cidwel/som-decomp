; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DD8F
initialize_equipment_flight_origin_from_actor_coordinates:
    sep #$20
    lda f:$7EE020,X
    sec
    .a8
    sbc #$08
    sta a:$0000,Y
    lda f:$7EE022,X
    sec
    .a8
    sbc #$18
    sta a:$0001,Y
    .a8
    lda #$00
    sta a:$0002,Y
    .a8
    lda #$50
    sta a:$0003,Y
    rts
