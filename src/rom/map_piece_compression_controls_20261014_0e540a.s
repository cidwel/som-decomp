.setcpu "65816"
.segment "CODE"
.org $540A
map_control_0e540a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
