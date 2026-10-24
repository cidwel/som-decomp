.setcpu "65816"
.segment "CODE"
.org $EA2C
map_control_0dea2c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
