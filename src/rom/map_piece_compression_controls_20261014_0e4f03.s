.setcpu "65816"
.segment "CODE"
.org $4F03
map_control_0e4f03:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
