.setcpu "65816"
.segment "CODE"
.org $EA97
map_control_0eea97:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
