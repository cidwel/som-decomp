.setcpu "65816"
.segment "CODE"
.org $2C72
map_control_0f2c72:
    .byte $D7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
