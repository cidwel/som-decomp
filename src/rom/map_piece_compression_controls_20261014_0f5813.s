.setcpu "65816"
.segment "CODE"
.org $5813
map_control_0f5813:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
