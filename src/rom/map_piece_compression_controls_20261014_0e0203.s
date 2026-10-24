.setcpu "65816"
.segment "CODE"
.org $0203
map_control_0e0203:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
