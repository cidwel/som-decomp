.setcpu "65816"
.segment "CODE"
.org $252B
map_control_0c252b:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
