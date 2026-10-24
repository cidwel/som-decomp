.setcpu "65816"
.segment "CODE"
.org $CF83
map_control_0fcf83:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
