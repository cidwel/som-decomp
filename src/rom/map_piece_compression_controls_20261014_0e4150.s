.setcpu "65816"
.segment "CODE"
.org $4150
map_control_0e4150:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
