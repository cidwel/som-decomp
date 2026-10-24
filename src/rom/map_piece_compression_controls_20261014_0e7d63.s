.setcpu "65816"
.segment "CODE"
.org $7D63
map_control_0e7d63:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
