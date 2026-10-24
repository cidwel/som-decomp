.setcpu "65816"
.segment "CODE"
.org $0E7E
map_control_0e0e7e:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
