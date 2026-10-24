; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_native_pair_of_equipment_flight_records = $DCF0
request_native_menu_audio_28 = $D0CF38
request_native_menu_audio_4b = $D0CF30
update_both_native_equipment_flight_records = $DDB0
wait_menu_vblank_through_native_long_wrapper = $C0693F
wait_vblank_and_poll_menu_through_native_long_wrapper = $C0695A

.segment "CODE"
.org $DCBE
finish_native_equipment_exchange_with_two_sprite_flights:
    php
    rep #$30
    sep #$20
    lda a:$19F0
    .a8
    cmp #$02
    bne finish_native_equipment_exchange_with_two_sprite_flights_d0dcee
    .a8
    lda #$20
    bit a:$1804
    beq finish_native_equipment_exchange_with_two_sprite_flights_d0dcee
    jsr initialize_native_pair_of_equipment_flight_records
    jsl f:request_native_menu_audio_4b
finish_native_equipment_exchange_with_two_sprite_flights_d0dcd8:
    jsl f:wait_vblank_and_poll_menu_through_native_long_wrapper
    jsr update_both_native_equipment_flight_records
    sep #$30
    lda a:$1826
    beq finish_native_equipment_exchange_with_two_sprite_flights_d0dcd8
    jsl f:wait_menu_vblank_through_native_long_wrapper
    jsl f:request_native_menu_audio_28
finish_native_equipment_exchange_with_two_sprite_flights_d0dcee:
    plp
    rtl
