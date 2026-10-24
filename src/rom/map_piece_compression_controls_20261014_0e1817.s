.setcpu "65816"
.segment "CODE"
.org $1817
map_control_0e1817:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
