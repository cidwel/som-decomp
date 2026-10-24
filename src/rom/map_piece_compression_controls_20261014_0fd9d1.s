.setcpu "65816"
.segment "CODE"
.org $D9D1
map_control_0fd9d1:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
