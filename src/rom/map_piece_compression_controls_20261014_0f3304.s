.setcpu "65816"
.segment "CODE"
.org $3304
map_control_0f3304:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
