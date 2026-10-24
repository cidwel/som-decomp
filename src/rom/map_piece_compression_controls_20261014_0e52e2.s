.setcpu "65816"
.segment "CODE"
.org $52E2
map_control_0e52e2:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
