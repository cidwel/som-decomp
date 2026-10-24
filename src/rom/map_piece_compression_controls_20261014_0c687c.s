.setcpu "65816"
.segment "CODE"
.org $687C
map_control_0c687c:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
