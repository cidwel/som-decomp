.setcpu "65816"
.segment "CODE"
.org $4470
map_control_0d4470:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
