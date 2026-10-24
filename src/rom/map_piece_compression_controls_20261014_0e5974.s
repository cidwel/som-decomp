.setcpu "65816"
.segment "CODE"
.org $5974
map_control_0e5974:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
