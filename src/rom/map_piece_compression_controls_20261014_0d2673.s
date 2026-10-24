.setcpu "65816"
.segment "CODE"
.org $2673
map_control_0d2673:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
