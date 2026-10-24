.setcpu "65816"
.segment "CODE"
.org $4423
map_control_0d4423:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
