.setcpu "65816"
.segment "CODE"
.org $C04F
map_control_0ec04f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
