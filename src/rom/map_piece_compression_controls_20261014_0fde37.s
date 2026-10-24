.setcpu "65816"
.segment "CODE"
.org $DE37
map_control_0fde37:
    .byte $D7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
