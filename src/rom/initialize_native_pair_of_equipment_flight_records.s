; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16

assign_selected_inventory_oam_slot_to_flight_record = $DD38
derive_opposed_native_fixed_point_flight_steps = $DD44
initialize_equipment_flight_origin_from_actor_coordinates = $DD8F

.segment "CODE"
.org $DCF0
initialize_native_pair_of_equipment_flight_records:
    rep #$30
    stz a:$1826
    sep #$20
    ldx a:$184F
    .i16
    ldy #$1832
    jsr initialize_equipment_flight_origin_from_actor_coordinates
    ldx a:$1851
    .i16
    ldy #$1842
    jsr initialize_equipment_flight_origin_from_actor_coordinates
    .i16
    ldx #$1832
    lda a:$1842
    sta a:$1821
    lda a:$1832
    jsr derive_opposed_native_fixed_point_flight_steps
    .i16
    ldx #$1836
    lda a:$1843
    sta a:$1821
    lda a:$1833
    jsr derive_opposed_native_fixed_point_flight_steps
    rep #$30
    .i16
    ldx #$1832
    lda a:$185C
    jsr assign_selected_inventory_oam_slot_to_flight_record
    .i16
    ldx #$1842
    lda a:$180A
