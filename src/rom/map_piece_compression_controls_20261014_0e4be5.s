.setcpu "65816"
.segment "CODE"
.org $4BE5
map_control_0e4be5:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
