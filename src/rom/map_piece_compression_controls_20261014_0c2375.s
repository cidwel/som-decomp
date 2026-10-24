.setcpu "65816"
.segment "CODE"
.org $2375
map_control_0c2375:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
