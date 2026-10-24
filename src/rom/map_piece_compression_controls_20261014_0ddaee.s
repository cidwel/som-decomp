.setcpu "65816"
.segment "CODE"
.org $DAEE
map_control_0ddaee:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
