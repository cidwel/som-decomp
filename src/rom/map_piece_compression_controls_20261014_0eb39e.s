.setcpu "65816"
.segment "CODE"
.org $B39E
map_control_0eb39e:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
