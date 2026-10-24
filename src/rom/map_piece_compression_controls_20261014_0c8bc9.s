.setcpu "65816"
.segment "CODE"
.org $8BC9
map_control_0c8bc9:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
