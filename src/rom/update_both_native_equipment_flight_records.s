; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16

integrate_native_equipment_flight_and_publish_or_hide_oam = $DDBD

.segment "CODE"
.org $DDB0
update_both_native_equipment_flight_records:
    rep #$30
    .i16
    ldx #$1832
    jsr integrate_native_equipment_flight_and_publish_or_hide_oam
    rep #$30
    .i16
    ldx #$1842
