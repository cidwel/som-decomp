.setcpu "65816"
.segment "CODE"
.org $4712
map_control_0e4712:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
