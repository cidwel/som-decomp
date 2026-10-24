.setcpu "65816"
.segment "CODE"
.org $004C
map_control_0e004c:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
