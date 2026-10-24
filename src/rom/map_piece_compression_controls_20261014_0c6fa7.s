.setcpu "65816"
.segment "CODE"
.org $6FA7
map_control_0c6fa7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
