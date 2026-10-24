.setcpu "65816"
.segment "CODE"
.org $AA57
map_control_0eaa57:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
