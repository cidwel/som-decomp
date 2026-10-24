.setcpu "65816"
.segment "CODE"
.org $6368
map_control_0d6368:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
