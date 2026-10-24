.setcpu "65816"
.segment "CODE"
.org $0599
map_control_0e0599:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
