.setcpu "65816"
.segment "CODE"
.org $9BB0
map_control_0e9bb0:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
