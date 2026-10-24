.setcpu "65816"
.segment "CODE"
.org $DEC2
map_control_0ddec2:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
