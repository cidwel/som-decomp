.setcpu "65816"
.segment "CODE"
.org $352E
map_control_0f352e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
