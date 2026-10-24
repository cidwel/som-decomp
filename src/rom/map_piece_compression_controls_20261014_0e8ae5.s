.setcpu "65816"
.segment "CODE"
.org $8AE5
map_control_0e8ae5:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
