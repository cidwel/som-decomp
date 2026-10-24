.setcpu "65816"
.segment "CODE"
.org $8322
map_control_0f8322:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
