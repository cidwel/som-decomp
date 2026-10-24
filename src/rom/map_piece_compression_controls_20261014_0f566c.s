.setcpu "65816"
.segment "CODE"
.org $566C
map_control_0f566c:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
