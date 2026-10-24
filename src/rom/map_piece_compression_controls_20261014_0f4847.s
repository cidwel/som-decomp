.setcpu "65816"
.segment "CODE"
.org $4847
map_control_0f4847:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
