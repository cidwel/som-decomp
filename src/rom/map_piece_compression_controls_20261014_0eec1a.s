.setcpu "65816"
.segment "CODE"
.org $EC1A
map_control_0eec1a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
