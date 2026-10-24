.setcpu "65816"
.segment "CODE"
.org $F852
map_control_0ef852:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
