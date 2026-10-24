.setcpu "65816"
.segment "CODE"
.org $40AB
map_control_0d40ab:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
