.setcpu "65816"
.segment "CODE"
.org $E0C6
map_control_0de0c6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
