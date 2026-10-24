.setcpu "65816"
.segment "CODE"
.org $C117
map_control_0ec117:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
