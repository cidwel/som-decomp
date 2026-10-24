; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_save_dispatch_restore = $0160

.segment "CODE"
.org $0004
audio_command_sender_public_jump:
    jmp audio_command_sender_save_dispatch_restore
