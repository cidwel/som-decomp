.setcpu "65816"
.segment "CODE"
.org $903F
map_control_0e903f:
    .byte $C9 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
