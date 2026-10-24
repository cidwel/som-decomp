.setcpu "65816"
.segment "CODE"
.org $F7FE
map_control_0ef7fe:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
