.setcpu "65816"
.segment "CODE"
.org $A2C6
map_control_0ea2c6:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
