.setcpu "65816"
.segment "CODE"
.org $7833
map_control_0c7833:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
