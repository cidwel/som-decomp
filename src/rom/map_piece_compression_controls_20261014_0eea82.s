.setcpu "65816"
.segment "CODE"
.org $EA82
map_control_0eea82:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
