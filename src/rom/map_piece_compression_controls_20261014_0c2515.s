.setcpu "65816"
.segment "CODE"
.org $2515
map_control_0c2515:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
