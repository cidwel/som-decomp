.setcpu "65816"
.segment "CODE"
.org $3418
map_control_0e3418:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
