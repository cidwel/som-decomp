.setcpu "65816"
.segment "CODE"
.org $2695
map_control_0f2695:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
