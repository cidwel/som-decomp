.setcpu "65816"
.segment "CODE"
.org $21D9
map_control_0e21d9:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
