.setcpu "65816"
.segment "CODE"
.org $19E7
map_control_0c19e7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
