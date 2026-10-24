.setcpu "65816"
.segment "CODE"
.org $1551
map_control_0e1551:
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
