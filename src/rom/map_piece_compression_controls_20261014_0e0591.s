.setcpu "65816"
.segment "CODE"
.org $0591
map_control_0e0591:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
