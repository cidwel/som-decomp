.setcpu "65816"
.segment "CODE"
.org $7D73
map_control_0c7d73:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
