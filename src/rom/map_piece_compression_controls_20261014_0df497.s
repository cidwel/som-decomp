.setcpu "65816"
.segment "CODE"
.org $F497
map_control_0df497:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
