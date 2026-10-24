.setcpu "65816"
.segment "CODE"
.org $A11B
map_control_0da11b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
