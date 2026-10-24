.setcpu "65816"
.segment "CODE"
.org $3A48
map_control_0d3a48:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
