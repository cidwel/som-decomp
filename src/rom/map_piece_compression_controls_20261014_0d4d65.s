.setcpu "65816"
.segment "CODE"
.org $4D65
map_control_0d4d65:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
