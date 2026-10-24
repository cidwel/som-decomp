.setcpu "65816"
.segment "CODE"
.org $3799
map_control_0d3799:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
