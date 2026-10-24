.setcpu "65816"
.segment "CODE"
.org $21D8
map_control_0c21d8:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
