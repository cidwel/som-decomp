.setcpu "65816"
.segment "CODE"
.org $72F1
map_control_0e72f1:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
