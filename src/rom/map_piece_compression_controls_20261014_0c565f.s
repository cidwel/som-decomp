.setcpu "65816"
.segment "CODE"
.org $565F
map_control_0c565f:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
