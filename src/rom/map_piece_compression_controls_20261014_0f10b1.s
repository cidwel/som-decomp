.setcpu "65816"
.segment "CODE"
.org $10B1
map_control_0f10b1:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
