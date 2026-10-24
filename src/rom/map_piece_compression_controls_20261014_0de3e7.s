.setcpu "65816"
.segment "CODE"
.org $E3E7
map_control_0de3e7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
