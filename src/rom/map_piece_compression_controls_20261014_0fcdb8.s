.setcpu "65816"
.segment "CODE"
.org $CDB8
map_control_0fcdb8:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
