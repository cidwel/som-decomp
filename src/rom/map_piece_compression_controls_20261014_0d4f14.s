.setcpu "65816"
.segment "CODE"
.org $4F14
map_control_0d4f14:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
