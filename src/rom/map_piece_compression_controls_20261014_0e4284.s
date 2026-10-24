.setcpu "65816"
.segment "CODE"
.org $4284
map_control_0e4284:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
