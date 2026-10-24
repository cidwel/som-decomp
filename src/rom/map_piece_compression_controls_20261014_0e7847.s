.setcpu "65816"
.segment "CODE"
.org $7847
map_control_0e7847:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
