.setcpu "65816"
.segment "CODE"
.org $6427
map_control_0c6427:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
