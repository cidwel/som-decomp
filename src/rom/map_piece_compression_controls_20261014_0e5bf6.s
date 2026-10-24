.setcpu "65816"
.segment "CODE"
.org $5BF6
map_control_0e5bf6:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
