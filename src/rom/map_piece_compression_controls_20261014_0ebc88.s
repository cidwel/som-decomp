.setcpu "65816"
.segment "CODE"
.org $BC88
map_control_0ebc88:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
