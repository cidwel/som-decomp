.setcpu "65816"
.segment "CODE"
.org $1166
map_control_0e1166:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
