; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c30198 = $0198
routine_c305f3 = $05F3
send_non_music_audio_command_packet = $059F

.segment "CODE"
.org $0160
audio_command_sender_save_dispatch_restore:
    phb
    phd
    php
    rep #$20
    rep #$10
    pha
    phx
    phy
    sep #$20
    .a8
    lda #$00
    pha
    plb
    .i16
    ldx #$1E00
    phx
    pld
    sep #$20
    lda $00
    stz $00
    beq audio_command_sender_save_dispatch_restore_c3018d
    bmi audio_command_sender_save_dispatch_restore_c30187
    .a8
    cmp #$01
    beq routine_c30198
    .a8
    cmp #$70
    bcs audio_command_sender_save_dispatch_restore_c3018a
audio_command_sender_save_dispatch_restore_c30187:
    jmp send_non_music_audio_command_packet
audio_command_sender_save_dispatch_restore_c3018a:
    jmp routine_c305f3
audio_command_sender_save_dispatch_restore_c3018d:
    rep #$20
    rep #$10
    ply
    plx
    pla
    plp
    pld
    plb
    rtl
