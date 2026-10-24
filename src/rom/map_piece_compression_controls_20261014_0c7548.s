.setcpu "65816"
.segment "CODE"
.org $7548
map_control_0c7548:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
