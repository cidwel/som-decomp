.setcpu "65816"
.segment "CODE"
.org $1910
map_control_0d1910:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
