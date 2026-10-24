.setcpu "65816"
.segment "CODE"
.org $0290
map_control_0e0290:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
