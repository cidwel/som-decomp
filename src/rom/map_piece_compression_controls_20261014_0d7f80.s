.setcpu "65816"
.segment "CODE"
.org $7F80
map_control_0d7f80:
    .byte $D4 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
