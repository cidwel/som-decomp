.setcpu "65816"
.segment "CODE"
.org $2697
map_control_0e2697:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
