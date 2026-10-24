.setcpu "65816"
.segment "CODE"
.org $BF97
map_control_0dbf97:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
