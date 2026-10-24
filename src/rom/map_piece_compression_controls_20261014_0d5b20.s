.setcpu "65816"
.segment "CODE"
.org $5B20
map_control_0d5b20:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
