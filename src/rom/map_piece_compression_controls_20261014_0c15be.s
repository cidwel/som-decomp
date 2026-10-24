.setcpu "65816"
.segment "CODE"
.org $15BE
map_control_0c15be:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
