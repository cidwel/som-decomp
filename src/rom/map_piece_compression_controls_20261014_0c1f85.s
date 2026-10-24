.setcpu "65816"
.segment "CODE"
.org $1F85
map_control_0c1f85:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
