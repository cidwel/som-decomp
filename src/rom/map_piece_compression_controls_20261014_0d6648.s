.setcpu "65816"
.segment "CODE"
.org $6648
map_control_0d6648:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
