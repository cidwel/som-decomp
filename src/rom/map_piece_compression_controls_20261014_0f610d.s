.setcpu "65816"
.segment "CODE"
.org $610D
map_control_0f610d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
