.setcpu "65816"
.segment "CODE"
.org $3296
map_control_0e3296:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
