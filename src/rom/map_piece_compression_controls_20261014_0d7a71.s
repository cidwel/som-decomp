.setcpu "65816"
.segment "CODE"
.org $7A71
map_control_0d7a71:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
