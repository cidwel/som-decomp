.setcpu "65816"
.segment "CODE"
.org $2C5C
map_control_0e2c5c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
