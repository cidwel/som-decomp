.setcpu "65816"
.segment "CODE"
.org $0E70
map_control_0d0e70:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
