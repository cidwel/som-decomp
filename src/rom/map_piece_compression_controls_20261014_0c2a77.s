.setcpu "65816"
.segment "CODE"
.org $2A77
map_control_0c2a77:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
