; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_audio_0e = $D0CF08

.segment "CODE"
.org $747F
prepare_native_equipment_mode_two_and_dispatch_transaction:
    jsl f:request_native_menu_audio_0e
    sep #$20
    .a8
    lda #$02
    sta a:$19F0
