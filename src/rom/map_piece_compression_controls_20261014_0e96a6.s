.setcpu "65816"
.segment "CODE"
.org $96A6
map_control_0e96a6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
