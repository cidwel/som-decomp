.setcpu "65816"
.segment "CODE"
.org $FCA2
map_control_0dfca2:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
