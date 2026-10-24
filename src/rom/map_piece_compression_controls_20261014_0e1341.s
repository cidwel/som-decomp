.setcpu "65816"
.segment "CODE"
.org $1341
map_control_0e1341:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
