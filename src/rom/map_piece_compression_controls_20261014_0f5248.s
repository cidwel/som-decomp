.setcpu "65816"
.segment "CODE"
.org $5248
map_control_0f5248:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
