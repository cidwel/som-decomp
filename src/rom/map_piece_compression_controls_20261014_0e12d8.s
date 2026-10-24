.setcpu "65816"
.segment "CODE"
.org $12D8
map_control_0e12d8:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
