.setcpu "65816"
.segment "CODE"
.org $9A4C
map_control_0f9a4c:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
