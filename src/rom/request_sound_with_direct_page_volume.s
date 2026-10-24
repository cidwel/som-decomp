; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-callers.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $8142
request_sound_with_direct_page_volume:
    sep #$20
    sta a:$1E01
    .a8
    lda #$02
    sta a:$1E00
    stz a:$1E02
    lda $F5
    sta a:$1E03
    jsl f:audio_command_sender_public_jump
    rts
