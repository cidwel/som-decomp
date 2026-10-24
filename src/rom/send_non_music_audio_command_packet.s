; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c3018d = $018D

.segment "CODE"
.org $059F
send_non_music_audio_command_packet:
    sep #$20
    xba
    lda $03
    sta a:$2143
    lda $02
    sta a:$2142
    lda $01
    sta a:$2141
    xba
send_non_music_audio_command_packet_c305b2:
    cmp a:$2140
    beq send_non_music_audio_command_packet_c305b2
    sta a:$2140
    .a8
    cmp #$F0
    bcc send_non_music_audio_command_packet_c305d2
    .a8
    cmp #$F2
    bcs send_non_music_audio_command_packet_c305d2
    xba
    lda $05
    bmi send_non_music_audio_command_packet_c305cd
    sta $09
    ldx $06
    stx $0A
send_non_music_audio_command_packet_c305cd:
    .a8
    lda #$FF
    sta $05
    xba
send_non_music_audio_command_packet_c305d2:
    cmp a:$2140
    bne send_non_music_audio_command_packet_c305d2
    .a8
    lda #$00
    sta a:$2140
    jmp routine_c3018d
