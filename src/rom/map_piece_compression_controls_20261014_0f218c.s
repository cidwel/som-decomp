.setcpu "65816"
.segment "CODE"
.org $218C
map_control_0f218c:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
