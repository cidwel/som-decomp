.setcpu "65816"
.segment "CODE"
.org $53C9
map_control_0f53c9:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
