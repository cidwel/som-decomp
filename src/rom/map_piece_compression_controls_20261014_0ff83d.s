.setcpu "65816"
.segment "CODE"
.org $F83D
map_control_0ff83d:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
