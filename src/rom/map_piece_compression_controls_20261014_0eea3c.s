.setcpu "65816"
.segment "CODE"
.org $EA3C
map_control_0eea3c:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
