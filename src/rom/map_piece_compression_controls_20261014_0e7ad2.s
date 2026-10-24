.setcpu "65816"
.segment "CODE"
.org $7AD2
map_control_0e7ad2:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
