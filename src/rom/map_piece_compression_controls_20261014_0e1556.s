.setcpu "65816"
.segment "CODE"
.org $1556
map_control_0e1556:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
