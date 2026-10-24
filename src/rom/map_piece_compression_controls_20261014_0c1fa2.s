.setcpu "65816"
.segment "CODE"
.org $1FA2
map_control_0c1fa2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
