.setcpu "65816"
.segment "CODE"
.org $E317
map_control_0de317:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
