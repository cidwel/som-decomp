.setcpu "65816"
.segment "CODE"
.org $554D
map_control_0d554d:
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
