.setcpu "65816"
.segment "CODE"
.org $3631
map_control_0d3631:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
