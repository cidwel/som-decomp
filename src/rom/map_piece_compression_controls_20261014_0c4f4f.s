.setcpu "65816"
.segment "CODE"
.org $4F4F
map_control_0c4f4f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
