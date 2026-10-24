.setcpu "65816"
.segment "CODE"
.org $3AD5
map_control_0f3ad5:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
