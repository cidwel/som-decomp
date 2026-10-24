; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $0FD5
request_audio_macro_eighty_with_parameter_thirty_two:
    .a16
    lda #$2080
    sta f:$001E00
    jsl f:audio_command_sender_public_jump
    rts
