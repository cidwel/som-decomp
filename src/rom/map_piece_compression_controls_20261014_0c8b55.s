.setcpu "65816"
.segment "CODE"
.org $8B55
map_control_0c8b55:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
