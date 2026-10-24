.setcpu "65816"
.segment "CODE"
.org $8ED5
map_control_0e8ed5:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
