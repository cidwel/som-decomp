.setcpu "65816"
.segment "CODE"
.org $6763
map_control_0c6763:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
