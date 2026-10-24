.setcpu "65816"
.segment "CODE"
.org $1FC7
map_control_0f1fc7:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
