.setcpu "65816"
.segment "CODE"
.org $1580
map_control_0e1580:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
