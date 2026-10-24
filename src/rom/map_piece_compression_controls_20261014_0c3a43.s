.setcpu "65816"
.segment "CODE"
.org $3A43
map_control_0c3a43:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
