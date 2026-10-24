.setcpu "65816"
.segment "CODE"
.org $1879
map_control_0e1879:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
