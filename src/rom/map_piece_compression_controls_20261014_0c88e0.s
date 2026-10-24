.setcpu "65816"
.segment "CODE"
.org $88E0
map_control_0c88e0:
    .byte $D4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
