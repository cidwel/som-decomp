.setcpu "65816"
.segment "CODE"
.org $9013
map_control_0e9013:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
