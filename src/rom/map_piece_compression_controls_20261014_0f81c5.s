.setcpu "65816"
.segment "CODE"
.org $81C5
map_control_0f81c5:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
