.setcpu "65816"
.segment "CODE"
.org $7C60
map_control_0e7c60:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
