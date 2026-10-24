.setcpu "65816"
.segment "CODE"
.org $5B82
map_control_0d5b82:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
