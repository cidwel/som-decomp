.setcpu "65816"
.segment "CODE"
.org $339F
map_control_0e339f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
