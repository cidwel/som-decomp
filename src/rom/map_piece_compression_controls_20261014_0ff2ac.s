.setcpu "65816"
.segment "CODE"
.org $F2AC
map_control_0ff2ac:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
