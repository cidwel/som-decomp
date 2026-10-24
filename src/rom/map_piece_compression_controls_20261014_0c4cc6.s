.setcpu "65816"
.segment "CODE"
.org $4CC6
map_control_0c4cc6:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
