.setcpu "65816"
.segment "CODE"
.org $3081
map_control_0e3081:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
