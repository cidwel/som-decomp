.setcpu "65816"
.segment "CODE"
.org $7DE7
map_control_0d7de7:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
