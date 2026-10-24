.setcpu "65816"
.segment "CODE"
.org $F9BC
map_control_0ef9bc:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
