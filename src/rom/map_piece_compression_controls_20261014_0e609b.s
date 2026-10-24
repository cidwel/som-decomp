.setcpu "65816"
.segment "CODE"
.org $609B
map_control_0e609b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
