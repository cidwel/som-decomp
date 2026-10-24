.setcpu "65816"
.segment "CODE"
.org $0E0E
map_control_0d0e0e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
