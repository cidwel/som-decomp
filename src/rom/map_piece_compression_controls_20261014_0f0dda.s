.setcpu "65816"
.segment "CODE"
.org $0DDA
map_control_0f0dda:
    .byte $D1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
