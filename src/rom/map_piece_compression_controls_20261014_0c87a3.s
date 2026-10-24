.setcpu "65816"
.segment "CODE"
.org $87A3
map_control_0c87a3:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
