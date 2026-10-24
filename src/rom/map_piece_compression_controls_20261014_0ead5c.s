.setcpu "65816"
.segment "CODE"
.org $AD5C
map_control_0ead5c:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
