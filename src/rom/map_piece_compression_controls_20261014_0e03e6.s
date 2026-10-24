.setcpu "65816"
.segment "CODE"
.org $03E6
map_control_0e03e6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
