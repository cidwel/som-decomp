.setcpu "65816"
.segment "CODE"
.org $7251
map_control_0d7251:
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
