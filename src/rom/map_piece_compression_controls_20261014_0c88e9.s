.setcpu "65816"
.segment "CODE"
.org $88E9
map_control_0c88e9:
    .byte $D4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
