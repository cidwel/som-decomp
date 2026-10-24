.setcpu "65816"
.segment "CODE"
.org $1D37
map_control_0d1d37:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
