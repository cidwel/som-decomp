.setcpu "65816"
.segment "CODE"
.org $DCD0
map_control_0fdcd0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
