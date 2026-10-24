.setcpu "65816"
.segment "CODE"
.org $AA18
map_control_0faa18:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
