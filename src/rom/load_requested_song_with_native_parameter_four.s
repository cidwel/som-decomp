; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $30C2
load_requested_song_with_native_parameter_four:
    sep #$20
    xba
    .a8
    lda #$01
    sta f:$001E00
    xba
    sta f:$001E01
    .a8
    lda #$04
    sta f:$001E02
    .a8
    lda #$0F
    sta f:$001E03
    jsl f:audio_command_sender_public_jump
    rep #$20
    rts
