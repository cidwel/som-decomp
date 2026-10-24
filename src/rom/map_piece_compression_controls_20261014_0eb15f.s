.setcpu "65816"
.segment "CODE"
.org $B15F
map_control_0eb15f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
