.setcpu "65816"
.segment "CODE"
.org $2396
map_control_0c2396:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
