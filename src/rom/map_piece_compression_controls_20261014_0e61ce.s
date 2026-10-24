.setcpu "65816"
.segment "CODE"
.org $61CE
map_control_0e61ce:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
