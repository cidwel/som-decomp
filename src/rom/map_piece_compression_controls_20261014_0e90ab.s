.setcpu "65816"
.segment "CODE"
.org $90AB
map_control_0e90ab:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
