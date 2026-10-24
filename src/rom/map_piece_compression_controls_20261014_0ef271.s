.setcpu "65816"
.segment "CODE"
.org $F271
map_control_0ef271:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
