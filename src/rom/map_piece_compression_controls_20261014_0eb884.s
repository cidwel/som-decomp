.setcpu "65816"
.segment "CODE"
.org $B884
map_control_0eb884:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
