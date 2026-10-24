.setcpu "65816"
.segment "CODE"
.org $D0A3
map_control_0dd0a3:
    .byte $CA ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
