.setcpu "65816"
.segment "CODE"
.org $9472
map_control_0d9472:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
