.setcpu "65816"
.segment "CODE"
.org $70A9
map_control_0e70a9:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
