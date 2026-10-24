.setcpu "65816"
.segment "CODE"
.org $E696
map_control_0de696:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
