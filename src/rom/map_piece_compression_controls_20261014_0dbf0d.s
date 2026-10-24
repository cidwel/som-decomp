.setcpu "65816"
.segment "CODE"
.org $BF0D
map_control_0dbf0d:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
