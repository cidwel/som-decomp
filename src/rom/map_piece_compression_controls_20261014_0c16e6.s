.setcpu "65816"
.segment "CODE"
.org $16E6
map_control_0c16e6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
