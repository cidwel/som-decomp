.setcpu "65816"
.segment "CODE"
.org $21A8
map_control_0c21a8:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
