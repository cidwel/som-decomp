.setcpu "65816"
.segment "CODE"
.org $DA0D
map_control_0fda0d:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
