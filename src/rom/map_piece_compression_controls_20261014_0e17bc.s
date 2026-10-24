.setcpu "65816"
.segment "CODE"
.org $17BC
map_control_0e17bc:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
