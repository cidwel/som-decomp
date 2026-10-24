.setcpu "65816"
.segment "CODE"
.org $3B55
map_control_0c3b55:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
