.setcpu "65816"
.segment "CODE"
.org $DFF3
map_control_0ddff3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
