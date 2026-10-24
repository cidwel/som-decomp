.setcpu "65816"
.segment "CODE"
.org $16F0
map_control_0e16f0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
