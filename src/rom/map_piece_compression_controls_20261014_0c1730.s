.setcpu "65816"
.segment "CODE"
.org $1730
map_control_0c1730:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
