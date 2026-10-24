.setcpu "65816"
.segment "CODE"
.org $19CB
map_control_0d19cb:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
