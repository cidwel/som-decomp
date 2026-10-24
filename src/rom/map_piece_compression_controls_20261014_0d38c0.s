.setcpu "65816"
.segment "CODE"
.org $38C0
map_control_0d38c0:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
