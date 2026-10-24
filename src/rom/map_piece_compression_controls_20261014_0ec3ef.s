.setcpu "65816"
.segment "CODE"
.org $C3EF
map_control_0ec3ef:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
