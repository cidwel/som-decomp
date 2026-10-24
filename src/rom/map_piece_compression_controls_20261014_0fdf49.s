.setcpu "65816"
.segment "CODE"
.org $DF49
map_control_0fdf49:
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
