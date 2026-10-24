.setcpu "65816"
.segment "CODE"
.org $F1FC
map_control_0ef1fc:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
