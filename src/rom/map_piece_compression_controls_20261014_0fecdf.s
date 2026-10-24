.setcpu "65816"
.segment "CODE"
.org $ECDF
map_control_0fecdf:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
