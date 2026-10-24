.setcpu "65816"
.segment "CODE"
.org $6D52
map_control_0c6d52:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
