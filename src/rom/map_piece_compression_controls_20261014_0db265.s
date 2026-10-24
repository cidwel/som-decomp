.setcpu "65816"
.segment "CODE"
.org $B265
map_control_0db265:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
