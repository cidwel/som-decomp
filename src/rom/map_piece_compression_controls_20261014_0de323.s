.setcpu "65816"
.segment "CODE"
.org $E323
map_control_0de323:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
