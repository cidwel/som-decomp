.setcpu "65816"
.segment "CODE"
.org $0A9E
map_control_0d0a9e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
