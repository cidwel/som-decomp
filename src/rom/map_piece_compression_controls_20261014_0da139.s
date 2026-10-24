.setcpu "65816"
.segment "CODE"
.org $A139
map_control_0da139:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
