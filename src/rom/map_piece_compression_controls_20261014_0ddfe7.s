.setcpu "65816"
.segment "CODE"
.org $DFE7
map_control_0ddfe7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
