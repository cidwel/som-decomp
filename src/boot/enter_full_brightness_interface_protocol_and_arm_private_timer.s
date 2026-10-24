; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-entry.md.
.setcpu "65816"
.smart
.a8
.i16

render_and_queue_native_interface_protocol_overlay = $D52F
routine_7eace9 = $ACE9
routine_7ecb86 = $CB86
routine_7ecc16 = $CC16
routine_c30004 = $C30004

.segment "CODE"
.org $AE53
enter_full_brightness_interface_protocol_and_arm_private_timer:
    .a8
    lda #$F6
    sta f:$001E00
    jsl f:routine_c30004
    jsr routine_7eace9
    jsr routine_7ecb86
    stx $02
    .a8
    lda #$FF
    sta $01
    lda $01
    jsr render_and_queue_native_interface_protocol_overlay
    .i16
    ldy #$0030
    ldx $02
    jsr routine_7ecc16
