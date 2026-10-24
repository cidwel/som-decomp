.setcpu "65816"
.segment "CODE"
.org $1767
map_control_0c1767:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
