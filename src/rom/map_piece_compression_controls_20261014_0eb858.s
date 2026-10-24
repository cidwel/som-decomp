.setcpu "65816"
.segment "CODE"
.org $B858
map_control_0eb858:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
