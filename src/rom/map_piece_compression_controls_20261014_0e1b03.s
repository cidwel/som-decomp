.setcpu "65816"
.segment "CODE"
.org $1B03
map_control_0e1b03:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
