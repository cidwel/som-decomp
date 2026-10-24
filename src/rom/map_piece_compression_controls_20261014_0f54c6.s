.setcpu "65816"
.segment "CODE"
.org $54C6
map_control_0f54c6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
