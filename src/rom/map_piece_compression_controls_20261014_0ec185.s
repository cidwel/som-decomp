.setcpu "65816"
.segment "CODE"
.org $C185
map_control_0ec185:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
