.setcpu "65816"
.segment "CODE"
.org $8427
map_control_0d8427:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
