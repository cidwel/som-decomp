.setcpu "65816"
.segment "CODE"
.org $2707
map_control_0c2707:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
