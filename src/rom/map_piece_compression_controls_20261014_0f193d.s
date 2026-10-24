.setcpu "65816"
.segment "CODE"
.org $193D
map_control_0f193d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
