.setcpu "65816"
.segment "CODE"
.org $1CD8
map_control_0d1cd8:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
