.setcpu "65816"
.segment "CODE"
.org $3B55
map_control_0e3b55:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
