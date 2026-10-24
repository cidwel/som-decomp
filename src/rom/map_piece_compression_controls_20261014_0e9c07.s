.setcpu "65816"
.segment "CODE"
.org $9C07
map_control_0e9c07:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
