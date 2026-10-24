.setcpu "65816"
.segment "CODE"
.org $DF32
map_control_0ddf32:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
