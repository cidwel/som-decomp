.setcpu "65816"
.segment "CODE"
.org $F74A
map_control_0ff74a:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
