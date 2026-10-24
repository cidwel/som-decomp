.setcpu "65816"
.segment "CODE"
.org $1BC0
map_control_0d1bc0:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
