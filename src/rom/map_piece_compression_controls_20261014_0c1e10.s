.setcpu "65816"
.segment "CODE"
.org $1E10
map_control_0c1e10:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
