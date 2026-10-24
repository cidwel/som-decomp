.setcpu "65816"
.segment "CODE"
.org $F90C
map_control_0ff90c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
