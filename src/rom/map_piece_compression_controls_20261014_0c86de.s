.setcpu "65816"
.segment "CODE"
.org $86DE
map_control_0c86de:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
