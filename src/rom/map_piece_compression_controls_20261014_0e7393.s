.setcpu "65816"
.segment "CODE"
.org $7393
map_control_0e7393:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
