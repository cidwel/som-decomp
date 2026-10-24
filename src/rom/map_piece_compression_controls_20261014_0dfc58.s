.setcpu "65816"
.segment "CODE"
.org $FC58
map_control_0dfc58:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
