; Recovered Secret of Mana USA routine; behaviour documented in docs/event-audio-requests.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $F0EC
event_read_audio_request_and_dispatch_native_sender:
    lda $05
    sta a:$1E00
    .i8
    ldy #$02
    lda [$D1],Y
    sta a:$1E01
    rep #$20
    .i8
    ldy #$03
    lda [$D1],Y
    sta a:$1E02
    lda $D1
    clc
    .a16
    adc #$0005
    sta $D1
    jsl f:audio_command_sender_public_jump
    rts
