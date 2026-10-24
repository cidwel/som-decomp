.setcpu "65816"
.segment "CODE"
.org $8261
map_control_0e8261:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
