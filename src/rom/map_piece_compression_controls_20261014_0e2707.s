.setcpu "65816"
.segment "CODE"
.org $2707
map_control_0e2707:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
