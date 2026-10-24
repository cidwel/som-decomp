.setcpu "65816"
.segment "CODE"
.org $7C34
map_control_0e7c34:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
