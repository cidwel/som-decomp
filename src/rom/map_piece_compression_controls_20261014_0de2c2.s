.setcpu "65816"
.segment "CODE"
.org $E2C2
map_control_0de2c2:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
