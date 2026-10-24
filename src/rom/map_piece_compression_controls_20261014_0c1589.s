.setcpu "65816"
.segment "CODE"
.org $1589
map_control_0c1589:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
