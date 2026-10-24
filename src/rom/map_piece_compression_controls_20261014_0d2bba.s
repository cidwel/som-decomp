.setcpu "65816"
.segment "CODE"
.org $2BBA
map_control_0d2bba:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
