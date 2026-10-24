.setcpu "65816"
.segment "CODE"
.org $CCFF
map_control_0eccff:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
