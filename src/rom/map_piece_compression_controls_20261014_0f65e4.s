.setcpu "65816"
.segment "CODE"
.org $65E4
map_control_0f65e4:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
