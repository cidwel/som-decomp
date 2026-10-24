.setcpu "65816"
.segment "CODE"
.org $50E0
map_control_0c50e0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
