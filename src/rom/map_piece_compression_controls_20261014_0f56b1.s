.setcpu "65816"
.segment "CODE"
.org $56B1
map_control_0f56b1:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
