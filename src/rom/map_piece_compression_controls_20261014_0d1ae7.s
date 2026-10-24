.setcpu "65816"
.segment "CODE"
.org $1AE7
map_control_0d1ae7:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
