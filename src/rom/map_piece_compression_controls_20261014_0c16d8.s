.setcpu "65816"
.segment "CODE"
.org $16D8
map_control_0c16d8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
