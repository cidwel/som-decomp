.setcpu "65816"
.segment "CODE"
.org $1E91
map_control_0c1e91:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
