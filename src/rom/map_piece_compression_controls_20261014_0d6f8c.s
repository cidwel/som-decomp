.setcpu "65816"
.segment "CODE"
.org $6F8C
map_control_0d6f8c:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $D2 ; same-value copy count/distance
