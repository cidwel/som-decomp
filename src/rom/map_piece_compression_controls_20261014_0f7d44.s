.setcpu "65816"
.segment "CODE"
.org $7D44
map_control_0f7d44:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
