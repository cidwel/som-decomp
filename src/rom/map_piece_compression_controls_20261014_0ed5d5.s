.setcpu "65816"
.segment "CODE"
.org $D5D5
map_control_0ed5d5:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
