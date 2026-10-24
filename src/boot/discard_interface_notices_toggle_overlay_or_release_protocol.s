; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-messages.md.
.setcpu "65816"
.smart
.a8
.i16

receive_native_interface_protocol_record_and_classify_notice = $AE76
release_native_timer_registration = $CBCA
routine_00ae69 = $AE69
routine_7eb1dd = $B1DD
routine_7ed52f = $D52F
routine_c30004 = $C30004

.segment "CODE"
.org $AE95
discard_interface_notices_toggle_overlay_or_release_protocol:
    jsr routine_7eb1dd
    bra receive_native_interface_protocol_record_and_classify_notice
    jsr routine_7eb1dd
    lda $01
    .a8
    eor #$FF
    sta $01
    bra routine_00ae69
    lda $01
    beq discard_interface_notices_toggle_overlay_or_release_protocol_aeae
    .a8
    eor #$FF
    jsr routine_7ed52f
discard_interface_notices_toggle_overlay_or_release_protocol_aeae:
    ldx $02
    jsr release_native_timer_registration
    .a8
    lda #$F7
    sta f:$001E00
    jsl f:routine_c30004
