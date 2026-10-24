.setcpu "65816"
.segment "CODE"
.org $2A45
map_control_0e2a45:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
