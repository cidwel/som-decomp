.setcpu "65816"
.segment "CODE"
.org $E32E
map_control_0de32e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
