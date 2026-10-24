.setcpu "65816"
.segment "CODE"
.org $5484
map_control_0e5484:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
