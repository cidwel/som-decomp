.setcpu "65816"
.segment "CODE"
.org $5A51
map_control_0c5a51:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
