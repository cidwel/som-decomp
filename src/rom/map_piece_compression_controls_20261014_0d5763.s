.setcpu "65816"
.segment "CODE"
.org $5763
map_control_0d5763:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
