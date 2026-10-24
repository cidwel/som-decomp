.setcpu "65816"
.segment "CODE"
.org $76CF
map_control_0e76cf:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
