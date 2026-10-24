; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DD38
assign_selected_inventory_oam_slot_to_flight_record:
    .a16
    and #$00FF
    asl
    asl
    clc
    .a16
    adc #$0848
    sta $0C,X
    rts
