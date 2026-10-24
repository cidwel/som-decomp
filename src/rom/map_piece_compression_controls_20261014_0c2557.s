.setcpu "65816"
.segment "CODE"
.org $2557
map_control_0c2557:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
