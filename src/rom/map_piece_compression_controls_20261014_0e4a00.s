.setcpu "65816"
.segment "CODE"
.org $4A00
map_control_0e4a00:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
