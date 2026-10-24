.setcpu "65816"
.segment "CODE"
.org $1621
map_control_0c1621:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
