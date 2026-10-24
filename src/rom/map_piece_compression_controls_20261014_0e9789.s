.setcpu "65816"
.segment "CODE"
.org $9789
map_control_0e9789:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
