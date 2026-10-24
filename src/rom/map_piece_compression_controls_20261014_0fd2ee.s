.setcpu "65816"
.segment "CODE"
.org $D2EE
map_control_0fd2ee:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
