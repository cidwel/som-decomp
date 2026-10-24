.setcpu "65816"
.segment "CODE"
.org $6CB4
map_control_0c6cb4:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
