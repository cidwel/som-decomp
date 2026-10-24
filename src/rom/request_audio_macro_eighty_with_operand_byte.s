; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-callers.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $310A
request_audio_macro_eighty_with_operand_byte:
    sep #$20
    sta f:$001E01
    .a8
    lda #$80
    sta f:$001E00
    jsl f:audio_command_sender_public_jump
    rep #$20
    rts
