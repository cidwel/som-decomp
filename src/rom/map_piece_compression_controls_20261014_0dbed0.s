.setcpu "65816"
.segment "CODE"
.org $BED0
map_control_0dbed0:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
