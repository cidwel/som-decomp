.setcpu "65816"
.segment "CODE"
.org $B8C2
map_control_0fb8c2:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
