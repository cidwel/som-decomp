.setcpu "65816"
.segment "CODE"
.org $DE93
map_control_0fde93:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
