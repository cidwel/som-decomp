.setcpu "65816"
.segment "CODE"
.org $5FA6
map_control_0d5fa6:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
