.setcpu "65816"
.segment "CODE"
.org $DCD6
map_control_0fdcd6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
