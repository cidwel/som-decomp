.setcpu "65816"
.segment "CODE"
.org $0387
map_control_0e0387:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
