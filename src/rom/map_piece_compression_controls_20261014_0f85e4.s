.setcpu "65816"
.segment "CODE"
.org $85E4
map_control_0f85e4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CC ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
