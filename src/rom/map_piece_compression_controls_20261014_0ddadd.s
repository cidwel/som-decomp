.setcpu "65816"
.segment "CODE"
.org $DADD
map_control_0ddadd:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
