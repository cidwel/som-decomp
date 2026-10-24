.setcpu "65816"
.segment "CODE"
.org $7F48
map_control_0f7f48:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
