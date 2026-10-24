.setcpu "65816"
.segment "CODE"
.org $5DA0
map_control_0d5da0:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
