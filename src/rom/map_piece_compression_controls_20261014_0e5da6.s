.setcpu "65816"
.segment "CODE"
.org $5DA6
map_control_0e5da6:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
