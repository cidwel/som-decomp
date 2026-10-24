.setcpu "65816"
.segment "CODE"
.org $30FF
map_control_0c30ff:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
