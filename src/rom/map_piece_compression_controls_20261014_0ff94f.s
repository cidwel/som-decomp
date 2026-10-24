.setcpu "65816"
.segment "CODE"
.org $F94F
map_control_0ff94f:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
