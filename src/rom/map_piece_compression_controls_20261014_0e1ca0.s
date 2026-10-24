.setcpu "65816"
.segment "CODE"
.org $1CA0
map_control_0e1ca0:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
