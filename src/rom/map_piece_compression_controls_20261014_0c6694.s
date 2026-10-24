.setcpu "65816"
.segment "CODE"
.org $6694
map_control_0c6694:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
