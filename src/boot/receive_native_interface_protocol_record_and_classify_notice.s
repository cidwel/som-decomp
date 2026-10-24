; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-messages.md.
.setcpu "65816"
.smart
.a8
.i16

discard_interface_notices_toggle_overlay_or_release_protocol = $AE95
routine_00ae9a = $AE9A
routine_00aea5 = $AEA5
routine_7ea814 = $A814
routine_7eb2fb = $B2FB

.segment "CODE"
.org $AE76
receive_native_interface_protocol_record_and_classify_notice:
    jsr routine_7ea814
    .a8
    and #$40
    beq routine_00aea5
    jsr routine_7eb2fb
    lda a:$0002,X
    .a8
    cmp #$FF
    beq routine_00ae9a
    .a8
    cmp #$FE
    beq discard_interface_notices_toggle_overlay_or_release_protocol
