.setcpu "65816"
.segment "CODE"
.org $14C9
map_control_0d14c9:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
