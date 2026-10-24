.setcpu "65816"
.segment "CODE"
.org $D08E
map_control_0dd08e:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
