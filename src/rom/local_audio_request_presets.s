.setcpu "65816"

AUDIO_COMMAND_EFFECT = $02
AUDIO_COMMAND_MUSIC = $01

.segment "CODE"
.org $2A34
local_audio_request_presets:
    ; Four-byte records: command, effect/song ID, parameter, volume.
    .byte AUDIO_COMMAND_EFFECT, $13, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $14, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $07, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $A4, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $0C, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $0D, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $0E, $0F, $00
    .byte AUDIO_COMMAND_EFFECT, $A3, $0F, $00
    .byte AUDIO_COMMAND_MUSIC, $12, $02, $FF
