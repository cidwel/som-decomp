.setcpu "65816"
.segment "CODE"
.org $3C08
map_control_0d3c08:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
