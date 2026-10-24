.setcpu "65816"
.segment "CODE"
.org $F519
map_control_0ef519:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
