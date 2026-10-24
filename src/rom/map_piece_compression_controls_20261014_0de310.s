.setcpu "65816"
.segment "CODE"
.org $E310
map_control_0de310:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
