.setcpu "65816"
.segment "CODE"
.org $397B
map_control_0e397b:
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
