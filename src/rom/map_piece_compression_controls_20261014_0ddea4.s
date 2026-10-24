.setcpu "65816"
.segment "CODE"
.org $DEA4
map_control_0ddea4:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
