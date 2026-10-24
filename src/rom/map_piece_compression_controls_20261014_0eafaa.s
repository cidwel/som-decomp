.setcpu "65816"
.segment "CODE"
.org $AFAA
map_control_0eafaa:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
