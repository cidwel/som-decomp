.setcpu "65816"
.segment "CODE"
.org $F509
map_control_0df509:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
