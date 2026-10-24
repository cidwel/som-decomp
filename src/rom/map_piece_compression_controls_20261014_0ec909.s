.setcpu "65816"
.segment "CODE"
.org $C909
map_control_0ec909:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
