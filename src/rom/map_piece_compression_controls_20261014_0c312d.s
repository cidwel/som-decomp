.setcpu "65816"
.segment "CODE"
.org $312D
map_control_0c312d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
