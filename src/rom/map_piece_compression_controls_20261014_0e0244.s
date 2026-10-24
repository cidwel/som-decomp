.setcpu "65816"
.segment "CODE"
.org $0244
map_control_0e0244:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $46 ; distance low bit/count
