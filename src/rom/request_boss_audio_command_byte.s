; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $30FD
request_boss_audio_command_byte:
    sep #$20
    sta f:$001E00
    jsl f:audio_command_sender_public_jump
    rep #$20
    rts
