.setcpu "65816"
.segment "CODE"
.org $E5D5
map_control_0de5d5:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
