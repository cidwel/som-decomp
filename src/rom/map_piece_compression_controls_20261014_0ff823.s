.setcpu "65816"
.segment "CODE"
.org $F823
map_control_0ff823:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
