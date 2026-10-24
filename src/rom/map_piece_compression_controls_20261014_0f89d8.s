.setcpu "65816"
.segment "CODE"
.org $89D8
map_control_0f89d8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
