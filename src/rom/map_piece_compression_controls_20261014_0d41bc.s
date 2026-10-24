.setcpu "65816"
.segment "CODE"
.org $41BC
map_control_0d41bc:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
