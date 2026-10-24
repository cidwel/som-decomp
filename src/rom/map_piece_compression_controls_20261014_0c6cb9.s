.setcpu "65816"
.segment "CODE"
.org $6CB9
map_control_0c6cb9:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
