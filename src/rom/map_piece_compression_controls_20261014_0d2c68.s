.setcpu "65816"
.segment "CODE"
.org $2C68
map_control_0d2c68:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
