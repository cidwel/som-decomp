.setcpu "65816"
.segment "CODE"
.org $88E0
map_control_0e88e0:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
