.setcpu "65816"
.segment "CODE"
.org $5373
map_control_0c5373:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
