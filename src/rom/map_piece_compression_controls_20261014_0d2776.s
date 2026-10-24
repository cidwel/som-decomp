.setcpu "65816"
.segment "CODE"
.org $2776
map_control_0d2776:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
