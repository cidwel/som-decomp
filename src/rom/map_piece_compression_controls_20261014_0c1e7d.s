.setcpu "65816"
.segment "CODE"
.org $1E7D
map_control_0c1e7d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
