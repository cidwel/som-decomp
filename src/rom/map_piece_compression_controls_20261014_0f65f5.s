.setcpu "65816"
.segment "CODE"
.org $65F5
map_control_0f65f5:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
